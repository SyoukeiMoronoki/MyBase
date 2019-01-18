#include "AssetConverter.h"
#include "AssetConverterContext.h"
#include <Util/Logger.h>
#include <ProgramGenerator/AssetProgramGenerator.h>

// =================================================================
// Constructor / Destructor
// =================================================================
AssetConverter::AssetConverter(
  const std::string& id,
  const std::string& class_name,
  const std::vector<std::string>& extensions,
  T_UINT32 skip_head, T_UINT32 skip_tail
)
  : id_(id)
  , target_extensions_(extensions)
  , program_generator_(new AssetProgramGenerator(id, class_name, skip_head, skip_tail))
{}

AssetConverter::~AssetConverter()
{
  delete this->program_generator_;
}

// =================================================================
// Methods
// =================================================================
bool AssetConverter::IsTarget(const URI& uri) const
{
  return std::find(this->target_extensions_.begin(), this->target_extensions_.end(), uri.GetExtension()) != this->target_extensions_.end();
}

IAssetDataContainer* AssetConverter::ImportImmediately(AssetMetaData* meta_data, AssetConverterContext* context) const
{
  // �R���o�[�^�[�ݒ肪�o�^����Ă��Ȃ����A�O�܂ŕʂ̃R���o�[�^�[���g�p���Ă����ꍇ��
  // ���g�̃R���o�[�^�[�ݒ�ŏ㏑������B
  const std::unique_ptr<ConverterSetting>& setting = meta_data->GetConverterSetting();
  if (!setting || setting->GetConverterID() != this->GetId())
  {
    meta_data->SetConverterSetting(this->CreateSetting());
  }
  return this->ImportProcess(meta_data, context);
}

void AssetConverter::ExportImmediately(const SharedRef<AssetEntity>& entity, const AssetConverterContext* context) const
{
  //�ϊ���t�@�C���������Ă��邩
  AssetMetaData* meta_data = entity->GetMetaData();
  const bool output_file_exists = std::ifstream(FileUtil::CreateArchivePath(meta_data)).is_open();
  const bool asset_changed = meta_data->UpdateTimeStamp();

  //�ϊ��Ώۃt�@�C���̃^�C���X�^���v����v���Ă��邩
  if (output_file_exists && !asset_changed)
  {
    Logger::ExportSkipAssetLog(meta_data);
    return;
  }
  this->ExportProcess(entity, context);
}

void AssetConverter::CreateProgram(const std::vector<SharedRef<AssetEntity>>& entities, std::string * cpp, std::string * header) const
{
  if (!this->program_generator_)
  {
    return;
  }
  this->program_generator_->CreateHeaderProgram(entities, header);
  this->program_generator_->CreateCppProgram(entities, cpp);
}