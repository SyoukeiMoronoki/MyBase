#pragma once

#include <Converter/IAssetConverter.h>
#include <Entity/AssetEntity.h>
#include <Entity/AssetImporter.h>
#include <Entity/AssetEditor.h>
#include <Entity/AssetExporter.h>
#include <ProgramGenerator/AssetProgramGenerator.h>

template <class Entity_>
class AssetConverter : public IAssetConverter
{
  // =================================================================
  // Constructor / Destructor
  // =================================================================
public:
  AssetConverter(
    AssetImporter<Entity_>* importer,
    AssetEditor<Entity_>* editor,
    AssetExporter<Entity_>* exporter,
    AssetProgramGenerator<Entity_>* program_generator
  );

  virtual ~AssetConverter();

  // =================================================================
  // Methods
  // =================================================================
public:
  inline T_UINT32 GetID() const override;

  inline bool Reserve(const URI& uri, const URI& source, AssetConverterContext* context) override;

  inline void Import(AssetConverterContext* context) override;
  inline bool ImportOnce(AssetConverterContext* context) override;
  inline bool ImportImmediately(const URI& uri, AssetConverterContext* context, bool reload) override;


  inline void AddEntity(const SharedRef<Entity_>& entity);
  inline SharedRef<Entity_> GetEntity(const URI& uri, const AssetConverterContext* context);
  inline SharedRef<Entity_> GetEntity(const AssetInfo* info);

  inline void Export(const AssetConverterContext* context) const override;

  inline void CreateHeaderProgram(std::string* dest) const override;
  inline void CreateCppProgram(std::string* dest) const override;

  inline void VisitAllEntity(const std::function<void(const SharedRef<AssetEntity>&)>& func) override;
  inline SharedRef<AssetEntity> FindAllEntity(const std::function<bool(const SharedRef<AssetEntity>&)>& func) override;

  // =================================================================
  // Data Members
  // =================================================================
private:
  std::unordered_map<T_UINT32, SharedRef<Entity_>> entities_;
  AssetImporter<Entity_>* importer_;
  AssetEditor<Entity_>* editor_;
  //AssetViewer<Entity_>* viewer_;
  AssetExporter<Entity_>* exporter_;
  AssetProgramGenerator<Entity_>* program_generator_;

};

// =================================================================
// Constructor / Destructor
// =================================================================
template<class Entity_>
inline AssetConverter<Entity_>::AssetConverter(AssetImporter<Entity_>* importer, AssetEditor<Entity_>* editor, AssetExporter<Entity_>* exporter, AssetProgramGenerator<Entity_>* program_generator)
  : importer_(importer)
  , editor_(editor)
  , exporter_(exporter)
  , program_generator_(program_generator)
{}

template<class Entity_>
inline AssetConverter<Entity_>::~AssetConverter()
{
  delete this->importer_;
  delete this->editor_;
  delete this->exporter_;
  delete this->program_generator_;
}

// =================================================================
// Methods
// =================================================================
template<class Entity_>
inline T_UINT32 AssetConverter<Entity_>::GetID() const
{
  return Entity_::ID;
}

template<class Entity_>
inline bool AssetConverter<Entity_>::Reserve(const URI& uri, const URI& source, AssetConverterContext* context)
{
  const auto& itr = this->entities_.find(context->GetUniqueID(uri));
  if (itr != this->entities_.end())
  {
    return true;
  }
  return this->importer_ ? this->importer_->Reserve(uri, source, context) : false;
}

template<class Entity_>
inline void AssetConverter<Entity_>::Import(AssetConverterContext* context)
{
  if (this->importer_) this->importer_->Import(&this->entities_, context);
}

template<class Entity_>
inline bool AssetConverter<Entity_>::ImportOnce(AssetConverterContext* context)
{
  return this->importer_ ? this->importer_->ImportOnce(&this->entities_, context) : false;
}

template<class Entity_>
inline bool AssetConverter<Entity_>::ImportImmediately(const URI& uri, AssetConverterContext* context, bool reload)
{
  const auto& itr = this->entities_.find(context->GetUniqueID(uri));
  if (!reload && itr != this->entities_.end())
  {
    return true;
  }
  if (!this->importer_)
  {
    return false;
  }
  const SharedRef<Entity_>& entity = this->importer_->ImportImmediately(uri, context);
  if (!entity)
  {
    return false;
  }
  this->AddEntity(entity);
  return true;
}

template<class Entity_>
inline void AssetConverter<Entity_>::AddEntity(const SharedRef<Entity_>& entity)
{
  this->entities_[entity->GetAssetInfo()->GetUniqueID()] = entity;
}

template<class Entity_>
inline SharedRef<Entity_> AssetConverter<Entity_>::GetEntity(const URI& uri, const AssetConverterContext* context)
{
  const auto& itr = this->entities_.find(context->GetUniqueID(uri));
  if (itr != this->entities_.end())
  {
    return itr->second;
  }
  return nullptr;
}

template<class Entity_>
inline SharedRef<Entity_> AssetConverter<Entity_>::GetEntity(const AssetInfo* info)
{
  const auto& itr = this->entities_.find(info->GetUniqueID());
  if (itr != this->entities_.end())
  {
    return itr->second;
  }
  return nullptr;
}

template<class Entity_>
inline void AssetConverter<Entity_>::Export(const AssetConverterContext* context) const
{
  this->exporter_->Export(this->entities_, context);
}

template<class Entity_>
inline void AssetConverter<Entity_>::CreateHeaderProgram(std::string* dest) const
{
  if (this->program_generator_) this->program_generator_->CreateHeaderProgram(this->entities_, dest);
}

template<class Entity_>
inline void AssetConverter<Entity_>::CreateCppProgram(std::string* dest) const
{
  if (this->program_generator_) this->program_generator_->CreateCppProgram(this->entities_, dest);
}

template<class Entity_>
inline void AssetConverter<Entity_>::VisitAllEntity(const std::function<void(const SharedRef<AssetEntity>&)>& func)
{
  for (const auto& pair : this->entities_)
  {
    func(pair.second);
  }
}

template<class Entity_>
inline SharedRef<AssetEntity> AssetConverter<Entity_>::FindAllEntity(const std::function<bool(const SharedRef<AssetEntity>&)>& func)
{
  for (const auto& pair : this->entities_)
  {
    if (func(pair.second))
    {
      return pair.second;
    }
  }
  return nullptr;
}
