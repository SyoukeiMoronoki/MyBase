#include "DefaultMeshAssetConverterFactory.h"

#include "DefaultMeshAssetEntity.h"
#include "DefaultMeshAssetExporter.h"
#include <Entity/Default/DefaultAsset.h>
#include <Converter/AssetConverter.h>

// =================================================================
// Methods
// =================================================================
IAssetConverter* DefaultMeshAssetConverterFactory::Create(AssetConverterContext* context) const
{
  DefaultMeshAssetExporter* exporter = new DefaultMeshAssetExporter();
  AssetProgramGenerator<DefaultMeshAssetEntity>* program_generator = new AssetProgramGenerator<DefaultMeshAssetEntity>(2, 0);
  program_generator->AddAsset("DefaultMesh", "rcMesh");
  AssetConverter<DefaultMeshAssetEntity>* ret = new AssetConverter<DefaultMeshAssetEntity>(nullptr, nullptr, exporter, program_generator);

  using namespace DefaultAsset;
  ret->AddEntity(DefaultMeshAssetEntity::Create(AssetInfo::Create(MESH_PATH_CUBE, context), this->cube_.CreateMesh()));
  ret->AddEntity(DefaultMeshAssetEntity::Create(AssetInfo::Create(MESH_PATH_PLANE, context), this->plane_.CreateMesh()));
  return ret;
}
