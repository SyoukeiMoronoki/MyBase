#pragma once

#include <Cereal/cereal.hpp>
#include <Converter/AssetConverterFactory.h>

class ModelMaterialAssetConverterFactory : public AssetConverterFactory
{
  // =================================================================
  // Constructor / Destructor
  // =================================================================
public:
  ModelMaterialAssetConverterFactory() = default;

  // =================================================================
  // Methods
  // =================================================================
public:
  IAssetConverter* Create(AssetConverterContext* context) const override;

  // =================================================================
  // Serializer
  // =================================================================
public:
  template<class Archive>
  void serialize(Archive& ar, std::uint32_t const version)
  {
  }

  // =================================================================
  // Data Members
  // =================================================================
private:

};
CEREAL_CLASS_VERSION(ModelMaterialAssetConverterFactory, 1);