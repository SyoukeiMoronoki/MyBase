#pragma once

#include <Entity/File/FileAssetConverter.h>

class ShaderAssetConverter : public FileAssetConverter<rcShader, ShaderData>
{
  // =================================================================
  // Constructor / Destructor
  // =================================================================
public:
  ShaderAssetConverter(
    const std::string& id,
    const std::string& class_name,
    const std::vector<std::string>& extensions,
    T_UINT32 skip_head, T_UINT32 skip_tail
  )
    : FileAssetConverter(id, class_name, extensions, skip_head, skip_tail)
  {}

  // =================================================================
  // Methods from AssetConverter
  // =================================================================
public:
  virtual IAssetDataContainer* ImportProcess(AssetMetaData* meta, AssetConverterContext* context) const override;

};