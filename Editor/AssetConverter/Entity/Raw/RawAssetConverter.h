#pragma once

#include <Converter/AssetConverter.h>
#include "RawAssetConverterSetting.h"

template <class Asset_>
class RawAssetConverter : public AssetConverter
{
  // =================================================================
  // Constructor / Destructor
  // =================================================================
public:
  RawAssetConverter(
    const std::string& id,
    const std::string& class_name,
    std::initializer_list<std::string> extensions
  )
    : AssetConverter(
      id,
      class_name,
      extensions,
      1, 0
    )
  {}

  // =================================================================
  // Methods from AssetConverter
  // =================================================================
public:
  virtual bool CanCreateNewInstance() const override
  {
    return false;
  }

  virtual bool CreateNewInstance(const URI& uri) const
  {
    return false;
  }

  virtual IAssetDataContainer* ImportFromCache(const SharedRef<AssetEntity>& entity, AssetConverterContext* context) const override
  {
    return nullptr;
  }

  virtual void RegisterAssetManager(const SharedRef<AssetEntity>& entity) const override
  {
    AssetMetaData* meta_data = entity->GetMetaData();
    AssetManager::AddAsset<Asset_>(
      meta_data->GetUniqueID(),
      meta_data->GetURI().GetExtension(),
      Asset_::CreateFromFile(meta_data->GetInputPath().c_str())
      );
  }

  virtual IAssetDataContainer* ImportProcess(const SharedRef<AssetEntity>& entity, AssetConverterContext* context) const override
  {
    return entity->GetDataContainer();
  }

  virtual void ExportProcess(const SharedRef<AssetEntity>& entity, const AssetConverterContext* context) const
  {
    FileUtil::CopyRawAsset(entity->GetMetaData());
  }

  virtual std::unique_ptr<ConverterSetting> CreateSetting() const
  {
    return std::unique_ptr<ConverterSetting>(new RawAssetConverterSetting(this->GetId()));
  }

  virtual SharedRef<AssetViewerBehavior> CreateViewerBehavior() const override
  {
    return nullptr;
  }

  virtual bool IsTargetAsset(const std::string& asset_name) const override
  {
    return asset_name == Asset_::ObjectName();
  }

};
