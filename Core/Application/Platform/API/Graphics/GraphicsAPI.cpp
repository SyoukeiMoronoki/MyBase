#include "GraphicsAPI.h"
#include <Core/Application/Activity/Activity.h>
#include <imgui/imgui.h>

void GraphicsAPI::SetupModules()
{
  this->texture_module_ = this->CreateTextureModule();
}

// =================================================================
// Methods
// =================================================================
bool GraphicsAPI::Draw(const SharedRef<Activity>& activity, const std::function<void()>& draw_method)
{
  if (this->PreDraw(activity))
  {
    this->SetRenderTarget(activity);
    const TVec2f& screen_size = activity->GetContext().GetOption().window_size;
    this->SetViewport(0.0f, 0.0f, screen_size.width, screen_size.height, 0.0f, 1.0f);
    this->ViewportClear(activity->GetContext(), TColor::BLACK);
    draw_method();
    ImGuiContext* context = ImGui::GetCurrentContext();
    ImGui::SetCurrentContext(activity->GetContext().GetImGuiContext().get());
    ImGui::Render();
    ImGui::SetCurrentContext(context);
    this->PostDraw(activity);
  }
  return true;
}
