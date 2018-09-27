#include "ModelAssetConverterFactory.h"

#include "ModelAssetEntity.h"
#include "ModelAssetImporter.h"
#include "ModelAssetExporter.h"
#include "AssetProgramGenerator.h"
#include "AssetConverter.h"

// =================================================================
// Methods
// =================================================================
IAssetConverter* ModelAssetConverterFactory::Create() const
{
  ModelAssetImporter* importer = new ModelAssetImporter(this->target_extensions_);
  ModelAssetExporter* exporter = new ModelAssetExporter();
  AssetProgramGenerator<ModelAssetEntity>* program_generator = new AssetProgramGenerator<ModelAssetEntity>();
  program_generator->AddAsset("Model", "ModelAsset");
  return new AssetConverter<ModelAssetEntity>(importer, nullptr, exporter, program_generator);
}
