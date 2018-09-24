#pragma once

#include "AssetConverterFactory.h"

class RawAssetConverterFactory : public AssetConverterFactory
{
  // =================================================================
  // Constructor / Destructor
  // =================================================================
public:
  RawAssetConverterFactory() = default;

  // =================================================================
  // Methods
  // =================================================================
public:
  IAssetConverter* Create() const override;

  // =================================================================
  // Serealizer
  // =================================================================
public:

  // =================================================================
  // Data Members
  // =================================================================
private:

};