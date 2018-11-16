#pragma once

#include <Entity/File/Raw/RawAssetEntity.h>
#include <Entity/File/Raw/RawAssetConverterFactory.h>

class ShaderAssetEntity : public RawAssetEntity<rcShader>
{
  // =================================================================
  // GGG Statement
  // =================================================================
  ENTITY_ID(ID_SHADER);
  GG_OBJECT(ShaderAssetEntity);
  GG_CREATE_FUNC_1(ShaderAssetEntity, AssetInfo*)
  {
    return AssetEntity::Init(arg0);
  }

public:
  static inline IAssetConverter* CreateConverter()
  {
    return RawAssetConverterFactory::Create<ShaderAssetEntity>("Shader", "rcShader", "cso");
  }

};