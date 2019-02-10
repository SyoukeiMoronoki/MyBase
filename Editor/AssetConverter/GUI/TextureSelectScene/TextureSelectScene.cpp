#include "TextureSelectScene.h"
#include <Converter/AssetConverterContext.h>

// =================================================================
// GGG Statement
// =================================================================
GG_INIT_FUNC_IMPL(TextureSelectScene)
{
  return Scene::Init();
}

// =================================================================
// Methods from Scene
// =================================================================
void TextureSelectScene::OnLoad()
{
  this->camera_ = GameObject2D::Create();
  this->camera_->AddComponent<Camera2D>();
  this->AddChild2D(this->camera_);
}

void TextureSelectScene::OnUnload()
{
  this->ClearChildren();
  this->camera_ = nullptr;
}

void TextureSelectScene::OnShow()
{
  //this->asset_converter_context_->GetEntity();
}

void TextureSelectScene::OnHide()
{
}

void TextureSelectScene::Update(const ActivityContext& context)
{
}

void TextureSelectScene::Run(const SharedRef<rcTexture>& current_texture, const AssetConverterContext* context, const std::function<void(const SharedRef<rcTexture>& texture)>& callback)
{
  this->asset_converter_context_ = context;
  this->current_texture_ = current_texture;
  this->callback_ = callback;
  const SharedRef<GameActivity>& activity = GameActivity::Create();
  ActivityOption op = ActivityOption();
  op.activity_name = "テクスチャ選択";
  op.resize_window = false;
  op.sub_window = true;
  op.window_size = TVec2f(200.0f, 600.0f);
  Application::StartActivity(activity, op);
  activity->ChangeScene(SharedRef<Scene>(this));
}
