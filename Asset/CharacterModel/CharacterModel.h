#pragma once

#include <Asset/Mesh/Mesh.h>
#include <Asset/Material/Material.h>

struct CharacterNodeData
{
  // =================================================================
  // GGG Statement
  // =================================================================
  GG_SERIALIZABLE(ModelMeshData)
  {
    archive(mesh_index_);
    archive(material_indices_);
    archive(position_);
    archive(scale_);
    archive(rotation_);
    archive(children_);
  }

  // =================================================================
  // Data Member
  // =================================================================
public:
  T_FIXED_UINT32 mesh_index_;
  std::vector<T_FIXED_UINT32> material_indices_;
  TVec3f position_;
  TVec3f scale_;
  TVec3f rotation_;
  std::vector<CharacterNodeData> children_;
};


struct CharacterModelData
{
  // =================================================================
  // GGG Statement
  // =================================================================
  GG_SERIALIZABLE(CharacterModelData)
  {
    archive(root_node_);
    archive(mesh_unique_ids_);
    archive(material_unique_ids_);
  }

  // =================================================================
  // Data Member
  // =================================================================
public:
  CharacterNodeData root_node_;
  std::vector<T_FIXED_UINT32> mesh_unique_ids_;
  std::vector<T_FIXED_UINT32> material_unique_ids_;
};


class rcCharacterModel : public GGAssetObject
{
  // =================================================================
  // GGG Statement
  // =================================================================
  GG_ASSET(rcCharacterModel, CharacterModelData);

  // =================================================================
  // Setter / Getter
  // =================================================================
public:
  GG_INLINE const CharacterNodeData& GetRootNode()
  {
    return this->root_node_;
  }

  GG_INLINE SharedRef<const rcMesh> GetMesh(T_UINT32 index) const
  {
    return this->meshes_.at(index);
  }

  GG_INLINE T_UINT32 GetMeshCount() const
  {
    return (T_UINT32)this->meshes_.size();
  }

  GG_INLINE SharedRef<const rcMaterial> GetMaterial(T_UINT32 index) const
  {
    return this->materials_.at(index);
  }

  GG_INLINE T_UINT32 GetMaterialCount() const
  {
    return (T_UINT32)this->materials_.size();
  }

  // =================================================================
  // Data Member
  // =================================================================
protected:
  CharacterNodeData root_node_;
  std::vector<SharedRef<const rcMesh>> meshes_;
  std::vector<SharedRef<const rcMaterial>> materials_;

};