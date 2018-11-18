#pragma once

#include <Entity/File/Raw/RawAssetEntity.h>
#include <Entity/File/Raw/RawAssetConverterFactory.h>

class JsonAssetEntity : public RawAssetEntity<rcJsonData>
{
  // =================================================================
  // GGG Statement
  // =================================================================
  ENTITY_ID(ID_JSON);
  GG_OBJECT(JsonAssetEntity);
  GG_CREATE_FUNC_1(JsonAssetEntity, AssetMetaData*)
  {
    return AssetEntity::Init(arg0);
  }

  // =================================================================
  // Methods from RawAssetEntity
  // =================================================================
public:
  static inline IAssetConverter* CreateConverter()
  {
    return RawAssetConverterFactory::Create<JsonAssetEntity>("Json", "rcJsonData", "json");
  }

};
