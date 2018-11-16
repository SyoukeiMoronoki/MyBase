#pragma once

class IAssetConverter;
template<class Entity_>
class AssetConverter;

class AssetEntity;

class AssetConverterManager
{
  // =================================================================
  // Constructor / Destructor
  // =================================================================
public:
  AssetConverterManager();
  ~AssetConverterManager();

  // =================================================================
  // Methods
  // =================================================================
public:
  //�C�x���g���󗝂���(�߂�l��true���A���Ă���)Converter�ɑ΂��Ă̂ݏ������s��
  bool Fire(const std::function<bool(IAssetConverter*)>& func);

  template <class Entity_>
  bool Fire(const std::function<bool(AssetConverter<Entity_>*)>& func);

  //�S�Ă�Converter�ɑ΂��ď������s��
  void VisitAll(const std::function<void(IAssetConverter*)>& func);
  void VisitAll(const std::function<void(const IAssetConverter*)>& func) const;

  template <class Entity_>
  void VisitAll(const std::function<void(AssetConverter<Entity_>*)>& func);

  template <class Entity_>
  void VisitAll(const std::function<void(const AssetConverter<Entity_>*)>& func) const;

  void VisitAllEntity(const std::function<void(const SharedRef<AssetEntity>&)>& func);
  SharedRef<AssetEntity> FindAllEntity(const std::function<bool(const SharedRef<AssetEntity>&)>& func);

  //�l���A���Ă���܂Ō�������
  template <class Entity_>
  SharedRef<Entity_> Find(const std::function<SharedRef<Entity_>(IAssetConverter*)>& func);
  SharedRef<AssetEntity> Find(const std::function<SharedRef<AssetEntity>(IAssetConverter*)>& func);

  template <class Entity_>
  SharedRef<Entity_> Find(const std::function<SharedRef<Entity_>(AssetConverter<Entity_>*)>& func);

  inline void AddConverter(IAssetConverter* converter);

  // =================================================================
  // Data Members
  // =================================================================
private:
  std::unordered_map<T_UINT32, IAssetConverter*> converter_map_;

};

#include <Converter/AssetConverter.h>

//�C�x���g���󗝂���(�߂�l��true���A���Ă���)Converter�ɑ΂��Ă̂ݏ������s��
template<class Entity_>
inline bool AssetConverterManager::Fire(const std::function<bool(AssetConverter<Entity_>*)>& func)
{
  return func((AssetConverter<Entity_>*)this->converter_map_.at(Entity_::ID));
}

//�S�Ă�Converter�ɑ΂��ď������s��
template<class Entity_>
inline void AssetConverterManager::VisitAll(const std::function<void(AssetConverter<Entity_>*)>& func)
{
  func((AssetConverter<Entity_>*)this->converter_map_.at(Entity_::ID));
}

template<class Entity_>
inline void AssetConverterManager::VisitAll(const std::function<void(const AssetConverter<Entity_>*)>& func) const
{
  func((AssetConverter<Entity_>*)this->converter_map_.at(Entity_::ID));
}

//�l���A���Ă���܂Ō�������
template<class Entity_>
inline SharedRef<Entity_> AssetConverterManager::Find(const std::function<SharedRef<Entity_>(IAssetConverter*)>& func)
{
  for (auto& pair : this->converter_map_)
  {
    const SharedRef<Entity_>& val = func(pair.second);
    if (val)
    {
      return val;
    }
  }
  return nullptr;
}

template<class Entity_>
inline SharedRef<Entity_> AssetConverterManager::Find(const std::function<SharedRef<Entity_>(AssetConverter<Entity_>*)>& func)
{
  return func((AssetConverter<Entity_>*)this->converter_map_.at(Entity_::ID));
}

inline void AssetConverterManager::AddConverter(IAssetConverter* converter)
{
  GG_ASSERT(this->converter_map_.find(converter->GetID()) == this->converter_map_.end(), "����AssetEntity��ΏۂƂ��镡���̃R���o�[�^�[�����݂��܂�");
  this->converter_map_[converter->GetID()] = converter;
}