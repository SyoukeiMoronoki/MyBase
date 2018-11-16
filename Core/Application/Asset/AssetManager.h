#pragma once

#include "AssetLoader.h"
#include "UniqueIdTable.h"

/*!
 * @brief AssetConverter�ŕϊ����ꂽ�A�Z�b�g���Ǘ�����N���X
 * UniqueID��^�������[�h��A���[�h��������s���Ȃ��悤�ɃL���b�V������@�\�Ȃǂ�����B
 */
class AssetManager
{
  GG_SINGLETON(AssetManager);

  friend class IAssetLoader;

  // =================================================================
  // Methods
  // =================================================================
public:
  static void Init();
  static void Init(UniqueIdTable* table);
  static void Uninit();
  static void UnloadCaches();

  /*!
   * @brief ���j�[�NID����A�Z�b�g���擾����B
   * ���j�[�NID�œo�^����Ă���A�Z�b�g�ƌ^�����̃A�Z�b�g�̌^���Ⴄ�ꍇ�̓���͖���`
   */
  template<class Asset_>
  static GG_INLINE SharedRef<Asset_> Load(T_UINT32 uid)
  {
    AssetManager* const self = &Self();
    GG_ASSERT(uid != 0, "�����ȃA�Z�b�gID�����͂���܂���");
    if (uid > DefaultUniqueID::DEFAULT_UID_BEGIN)
    {
      return ((AssetLoader<Asset_>*)self->loaders_.at(self->unique_id_table_->GetDefaultAssetUniqueID(uid)))->CreateFromFile();
    }
    return ((AssetLoader<Asset_>*)self->loaders_.at(uid))->CreateFromFile();
  }

  /*!
  * @brief �t�@�C���p�X����A�Z�b�g���擾����B
  * UniqueID�e�[�u���ɓo�^����Ă���p�X�ȊO�̃p�X���w�肳���ƃG���[
  * ���j�[�NID�œo�^����Ă���A�Z�b�g�ƌ^�����̃A�Z�b�g�̌^���Ⴄ�ꍇ�̓���͖���`
  */
  template<class Asset_>
  static GG_INLINE SharedRef<Asset_> Load(const std::string& path)
  {
    AssetManager* const self = &Self();
    const T_UINT32 uid = self->unique_id_table_->GetID(path);
    GG_ASSERT(uid != 0, "�����ȃt�@�C���p�X�����͂���܂���");
    return ((AssetLoader<Asset_>*)self->loaders_.at(uid))->CreateFromFile();
  }

  /*!
  * @brief �t�@�C���p�X����AssetLoader���擾����B
  * ���j�[�NID�œo�^����Ă���A�Z�b�g�ƌ^�����̃A�Z�b�g�̌^���Ⴄ�ꍇ�̓���͖���`
  */
  template<class Asset_>
  static GG_INLINE const AssetLoader<Asset_>& GetLoader(T_UINT32 uid)
  {
    AssetManager* const self = &Self();
    GG_ASSERT(uid != 0, "�����ȃA�Z�b�gID�����͂���܂���");
    if (uid > DefaultUniqueID::DEFAULT_UID_BEGIN)
    {
      return (const AssetLoader<Asset_>&)*self->loaders_.at(self->unique_id_table_->GetDefaultAssetUniqueID(uid));
    }
    return (const AssetLoader<Asset_>&)*self->loaders_.at(uid);
  }

  /*!
  * @brief �t�@�C���p�X����AssetLoader���擾����B
  * UniqueID�e�[�u���ɓo�^����Ă���p�X�ȊO�̃p�X���w�肳���ƃG���[
  * ���j�[�NID�œo�^����Ă���A�Z�b�g�ƌ^�����̃A�Z�b�g�̌^���Ⴄ�ꍇ�̓���͖���`
  */
  template<class Asset_>
  static GG_INLINE const AssetLoader<Asset_>& GetLoader(const std::string& path)
  {
    AssetManager* const self = &Self();
    return (const AssetLoader<Asset_>&)*self->loaders_.at(Self().unique_id_table_->GetID(path));
  }

  /*!
   * @brief AssetLoader��o�^����B
   * ���̏�����AssetConverter���������������R�[�h�ōs����ׁA
   * ���[�U�[�����g�p���鎖�͖����B
   * ���[�U�[�����g�p�����ۂ̓���͖���`
   */
  template<class Asset_>
  static GG_INLINE const AssetLoader<Asset_>& AddAsset(T_UINT32 uid, const std::string& extension)
  {
    AssetManager* const self = &Self();
    self->loaders_.emplace(uid, new AssetLoader<Asset_>(uid, std::to_string(uid) + "." + extension));
    return (const AssetLoader<Asset_>&)*self->loaders_.at(uid);
  }
  
  /*!
   * @brief AssetLoader��o�^����B
   * ��������ɂ���f�[�^�����[�_�[�ɒ��ړo�^����
   * ���ɃA�Z�b�g���������ꍇ�͂��̃A�Z�b�g���㏑������
   */
  template<class Asset_>
  static GG_INLINE const AssetLoader<Asset_>& AddAsset(T_UINT32 uid, const std::string& extension, const SharedRef<Asset_>& asset)
  {
    AssetManager* const self = &Self();
    const auto& itr = self->loaders_.find(uid);
    if (itr != self->loaders_.end())
    {
      delete self->loaders_[uid];
      self->loaders_.erase(uid);
    }
    self->loaders_[uid] = new AssetLoader<Asset_>(uid, std::to_string(uid) + "." + extension, asset);
    return (const AssetLoader<Asset_>&)*self->loaders_.at(uid);
  }
  // =================================================================
  // Data Members
  // =================================================================
private:
  std::unordered_map<T_UINT32, IAssetLoader*> loaders_;
  UniqueIdTable* unique_id_table_;

};