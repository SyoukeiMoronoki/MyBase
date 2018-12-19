#include "Material.h"

#include <Asset/Shader/Shader.h>

// =================================================================
// GGG Statement
// =================================================================
GG_INIT_FUNC_IMPL_1(rcMaterial, const MaterialData& data)
{
  this->data_offset_table_ = data.data_offset_table_;
  this->data_ = data.data_;

  this->texture_index_table_ = data.texture_index_table_;
  const T_UINT32 texture_count = (T_UINT32)data.textures_.size();
  this->textures_.resize(texture_count);
  for (T_UINT32 i = 0; i < texture_count; ++i)
  {
    this->textures_[i] = AssetManager::Load<rcTexture>(data.textures_[i]);
  }

  this->constant_buffer_ = rcConstantBuffer::Create(
    Shader::ConstantBufferId::kProperty,
    (T_UINT32)this->data_.size()
  );
  this->constant_buffer_->CommitChanges(this->data_.data());

  return this->Init(
    data.shader_unique_id_ != 0 ?
    AssetManager::Load<rcShader>(data.shader_unique_id_) :
    AssetManager::Load<rcShader>(DefaultUniqueID::SHADER_NO_SHADING)
  );

  return true;
}

GG_INIT_FUNC_IMPL_1(rcMaterial, const SharedRef<rcShader>& shader)
{
  this->shader_ = shader;

  using namespace Shader;

  T_UINT32 data_offset = 0;
  for (const ScalaPropertyData& data : shader->GetScalaPropertyDatas())
  {
    this->data_offset_table_[data.name_] = data_offset;
    VariableType type = static_cast<VariableType>(data.variable_type_);
    (*(T_FLOAT*)&this->data_[data_offset]) = data.init_value_;
    data_offset += sizeof(T_FLOAT);
  }
  for (const VectorPropertyData& data : shader->GetVectorPropertyDatas())
  {
    this->data_offset_table_[data.name_] = data_offset;
    VariableType type = static_cast<VariableType>(data.variable_type_);
    ((T_FLOAT*)&this->data_[data_offset])[0] = data.init_value0_;
    ((T_FLOAT*)&this->data_[data_offset])[1] = data.init_value1_;
    ((T_FLOAT*)&this->data_[data_offset])[2] = data.init_value2_;
    ((T_FLOAT*)&this->data_[data_offset])[3] = data.init_value3_;
    data_offset += sizeof(T_FLOAT) * 4;
  }
  for (const ColorPropertyData& data : shader->GetColorPropertyDatas())
  {
    this->data_offset_table_[data.name_] = data_offset;
    ((T_FLOAT*)&this->data_[data_offset])[0] = data.init_r_;
    ((T_FLOAT*)&this->data_[data_offset])[1] = data.init_g_;
    ((T_FLOAT*)&this->data_[data_offset])[2] = data.init_b_;
    ((T_FLOAT*)&this->data_[data_offset])[3] = data.init_a_;
    data_offset += sizeof(T_FLOAT) * 4;
  }
  //TODO: SamplerPropertyも追加する

  this->constant_buffer_ = rcConstantBuffer::Create(
    Shader::ConstantBufferId::kProperty,
    (T_UINT32)this->data_.size()
  );
  this->constant_buffer_->CommitChanges(this->data_.data());

  return true;
}

GG_INIT_FUNC_IMPL_1(rcMaterial, const rcMaterial& o)
{
  this->shader_ = o.shader_;
  this->data_offset_table_ = o.data_offset_table_;
  this->data_ = o.data_;
  this->texture_index_table_ = o.texture_index_table_;
  this->textures_ = o.textures_;

  this->constant_buffer_ = rcConstantBuffer::Create(
    Shader::ConstantBufferId::kProperty,
    (T_UINT32)this->data_.size()
  );
  this->constant_buffer_->CommitChanges(this->data_.data());

  return true;
}

// =================================================================
// Methods
// =================================================================
UniqueRef<rcMaterial> rcMaterial::Clone() const
{
  return rcMaterial::Create(*this);
}

UniqueRef<rcMaterial> rcMaterial::InitialClone() const
{
  return rcMaterial::Create(this->shader_);
}

void rcMaterial::CommitChanges()
{
  this->constant_buffer_->CommitChanges(this->data_.data());
}

void rcMaterial::SetBuffer() const
{
  this->constant_buffer_->SetBuffer();
}
