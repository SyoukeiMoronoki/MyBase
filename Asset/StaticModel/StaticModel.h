#pragma once

#include <Asset/Mesh/Mesh.h>
#include <Asset/Material/Material.h>

struct StaticModelData
{
  // =================================================================
  // GGG Statement
  // =================================================================
  GG_SERIALIZABLE(CharacterModelData)
  {
    archive(mesh_unique_id_);
    archive(material_unique_ids_);
  }

  // =================================================================
  // Data Member
  // =================================================================
public:
  T_FIXED_UINT32 mesh_unique_id_;
  std::vector<T_FIXED_UINT32> material_unique_ids_;

};

class rcStaticModel : public GGAssetObject
{
  // =================================================================
  // GGG Statement
  // =================================================================
  GG_ASSET(rcStaticModel, StaticModelData);

  // =================================================================
  // Setter / Getter
  // =================================================================
public:
  GG_INLINE SharedRef<const rcMesh> GetMesh() const
  {
    return this->mesh_;
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
  SharedRef<const rcMesh> mesh_;
  std::vector<SharedRef<const rcMaterial>> materials_;

};