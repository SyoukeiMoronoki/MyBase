#pragma once

#include "AssetConverterFactory.h"

#include "Cereal/cereal.hpp"

class ModelMeshAssetConverterFactory : public AssetConverterFactory
{
  // =================================================================
  // Constructor / Destructor
  // =================================================================
public:
  ModelMeshAssetConverterFactory() = default;

  // =================================================================
  // Methods
  // =================================================================
public:
  IAssetConverter* Create() const override;

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
CEREAL_CLASS_VERSION(ModelMeshAssetConverterFactory, 1);
