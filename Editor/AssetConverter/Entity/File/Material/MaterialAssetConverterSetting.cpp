#include "MaterialAssetConverterSetting.h"

// =================================================================
// Methods from ConverterSetting
// =================================================================
bool MaterialAssetConverterSetting::EditWithImGuiProcess(AssetConverterContext* context)
{
  return this->editor.EditWithImGui(context);
}
