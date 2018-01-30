#include "AnimatedSprite.h"
#include "EngineAsset.h"

// =================================================================
// Factory Method
// =================================================================
AnimatedSprite* AnimatedSprite::Create()
{
  AnimatedSprite* ret = new AnimatedSprite();
  ret->SetRenderer(new AnimatedSpriteRenderer());
  ret->Init();
  return ret;
}

AnimatedSprite* AnimatedSprite::CreateWithTextureRegion(TiledTextureRegion* region)
{
  AnimatedSprite* ret = AnimatedSprite::Create();
  AnimatedSpriteRenderer* renderer = ret->GetAnimatedSpriteRenderer();
  renderer->SetTextureRegion(region);
  renderer->SetAnimateRange(0, region->GetTileCount() - 1);
  renderer->FitToTexture();
  return ret;
}

AnimatedSprite* AnimatedSprite::CreateWithMaterial(Material& material, T_UINT8 x_num, T_UINT8 y_num)
{
  TiledTextureRegion* region = TiledTextureRegion::CreateWithMaterial(material, x_num, y_num);
  AnimatedSprite* ret = AnimatedSprite::CreateWithTextureRegion(region);
  AnimatedSpriteRenderer* renderer = ret->GetAnimatedSpriteRenderer();
  renderer->SetMaterial(material);
  return ret;
}

AnimatedSprite* AnimatedSprite::CreateWithTexture(const Texture& texture, T_UINT8 x_num, T_UINT8 y_num)
{
  TiledTextureRegion* region = TiledTextureRegion::CreateWithTexture(texture, x_num, y_num);
  AnimatedSprite* ret = AnimatedSprite::CreateWithTextureRegion(region);
  AnimatedSpriteRenderer* renderer = ret->GetAnimatedSpriteRenderer();
  return ret;
}
