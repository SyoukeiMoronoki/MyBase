#include "ActivityContext.h"
#include <imgui/imgui.h>
#include <imgui/imgui_ja_gryph_ranges.h>
#include <imgui/imgui_internal.h>

// =================================================================
// Methods
// =================================================================
void ActivityContext::Start(const ActivityOption& ao, const InputSetting& input_setting)
{
  this->option_ = ao;

  this->input_context_ = new InputContext(input_setting);

  IMGUI_CHECKVERSION();
  this->imgui_context_.reset(ImGui::CreateContext());
  ImGui::SetCurrentContext(this->imgui_context_.get());
  ImGui::StyleColorsDark(&this->imgui_context_->Style);
  ImGui::SetupJapaneseString(this->imgui_context_.get());

  this->OnStart(ao);
}

void ActivityContext::End()
{
  ImGui::SetCurrentContext(this->imgui_context_.get());
  this->OnEnd();
  ImGui::DestroyContext(this->imgui_context_.release());
  this->imgui_context_ = nullptr;
  
  delete this->input_context_;
  this->input_context_ = nullptr;
}

void ActivityContext::NewFrame(const SharedRef<Activity>& activity, const SharedRef<Platform>& platform)
{
  ImGui::SetCurrentContext(this->imgui_context_.get());

  this->OnNewFrame();
  platform->ImGuiNewFrame();
  platform->GetGraphicsAPI()->ImGuiNewFrame();
  ImGui::NewFrame();

  const T_FLOAT delta_time = Application::GetUpdateEventState().GetDeltaTime();

  this->elapsed_time_ += delta_time;

  this->input_context_->Update(activity, platform->GetInputAPI());
}

void ActivityContext::EndFrame()
{
  ImGui::SetCurrentContext(this->imgui_context_.get());
  if (this->DrawEnabled())
  {
    this->elapsed_time_ = fmodf(this->elapsed_time_, this->option_.render_cycle);
  }
  ImGui::EndFrame();
}

bool ActivityContext::DrawEnabled()
{
  return this->elapsed_time_ >= this->option_.render_cycle;
}
