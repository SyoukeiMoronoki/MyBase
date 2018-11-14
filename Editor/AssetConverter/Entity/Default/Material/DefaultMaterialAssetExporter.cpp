#include "DefaultMaterialAssetExporter.h"

// =================================================================
// Methods
// =================================================================
void DefaultMaterialAssetExporter::ExportProcess(const SharedRef<DefaultMaterialAssetEntity>& entity, const AssetConverterContext* context)
{
  CerealIO::Binary::Export(entity->GetAssetInfo()->GetOutputPath().c_str(), entity->GetData());
  Logger::ConvertAssetLog(entity->GetAssetInfo());
}
