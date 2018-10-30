#include "NativeShader.h"

// =================================================================
// Constructor / Destructor
// =================================================================
NativeShader::NativeShader(LPD3DXEFFECT effect)
{
  this->effect_ = effect;
}

NativeShader::~NativeShader()
{
  this->effect_->Release();
}

// =================================================================
// Method for/from SuperClass/Interfaces
// =================================================================
T_UINT8 NativeShader::Begin()
{
  UINT path_count;
  HRESULT hr = this->effect_->Begin(&path_count, 0);
  GG_ASSERT(SUCCEEDED(hr), "�V�F�[�_�[�̊J�n�Ɏ��s���܂���");
  return path_count;
}

void NativeShader::BeginPass(T_UINT8 path_id)
{
  HRESULT hr = this->effect_->BeginPass(path_id);
  GG_ASSERT(SUCCEEDED(hr), "�V�F�[�_�[�p�X�̎��s�Ɏ��s���܂���");
}

void NativeShader::CommitChanges()
{
  HRESULT hr = this->effect_->CommitChanges();
  GG_ASSERT(SUCCEEDED(hr), "�V�F�[�_�[�v���p�e�B�̓]���Ɏ��s���܂���");
}

void NativeShader::EndPass()
{
  HRESULT hr = this->effect_->EndPass();
  GG_ASSERT(SUCCEEDED(hr), "�V�F�[�_�[�p�X�̏I���Ɏ��s���܂���");
}

void NativeShader::End()
{
  HRESULT hr = this->effect_->End();
  GG_ASSERT(SUCCEEDED(hr), "�V�F�[�_�[�̊J�n�Ɏ��s���܂���");
}

void NativeShader::SetTechnique(const std::string& technique)
{
  HRESULT hr = this->effect_->SetTechnique(technique.c_str());
  GG_ASSERT(SUCCEEDED(hr), "�e�N�j�b�N�̐ݒ�Ɏ��s���܂���");
}

void NativeShader::SetBool(const std::string& property_name, bool val)
{
  D3DXHANDLE handle = GetHandle(property_name);
  if (!handle)
  {
    return;
  }
  HRESULT hr = this->effect_->SetBool(handle, val);
  GG_ASSERT(SUCCEEDED(hr), "bool�v���p�e�B�̓]���Ɏ��s���܂���");
}

void NativeShader::SetInt(const std::string& property_name, T_INT32 val)
{
  D3DXHANDLE handle = GetHandle(property_name);
  if (!handle)
  {
    return;
  }
  HRESULT hr = this->effect_->SetInt(handle, val);
  GG_ASSERT(SUCCEEDED(hr), "int�v���p�e�B�̓]���Ɏ��s���܂���");
}

void NativeShader::SetFloat(const std::string& property_name, T_FLOAT val)
{
  D3DXHANDLE handle = GetHandle(property_name);
  if (!handle)
  {
    return;
  }
  HRESULT hr = this->effect_->SetFloat(handle, val);
  GG_ASSERT(SUCCEEDED(hr), "float�v���p�e�B�̓]���Ɏ��s���܂���");
}

void NativeShader::SetVec2f(const std::string& property_name, const TVec2f& vec)
{
  D3DXHANDLE handle = GetHandle(property_name);
  if (!handle)
  {
    return;
  }
  HRESULT hr = this->effect_->SetFloatArray(handle, vec.data, 2);
  GG_ASSERT(SUCCEEDED(hr), "TVec2f�v���p�e�B�̓]���Ɏ��s���܂���");
}

void NativeShader::SetVec3f(const std::string& property_name, const TVec3f& vec)
{
  D3DXHANDLE handle = GetHandle(property_name);
  if (!handle)
  {
    return;
  }
  HRESULT hr = this->effect_->SetFloatArray(handle, vec.data, 3);
  GG_ASSERT(SUCCEEDED(hr), "TVec3f�v���p�e�B�̓]���Ɏ��s���܂���");
}

void NativeShader::SetVec4f(const std::string& property_name, const TVec4f& vec)
{
  D3DXHANDLE handle = GetHandle(property_name);
  if (!handle)
  {
    return;
  }
  HRESULT hr = this->effect_->SetFloatArray(handle, vec.data, 4);
  GG_ASSERT(SUCCEEDED(hr), "TVec4f�v���p�e�B�̓]���Ɏ��s���܂���");
}

void NativeShader::SetColor(const std::string& property_name, const TColor& color)
{
  D3DXHANDLE handle = GetHandle(property_name);
  if (!handle)
  {
    return;
  }
  HRESULT hr = this->effect_->SetFloatArray(handle, color.data, 4);
  GG_ASSERT(SUCCEEDED(hr), "TColor�v���p�e�B�̓]���Ɏ��s���܂���");
}

void NativeShader::SetMatrix(const std::string& property_name, const Matrix4x4& matrix)
{
  D3DXHANDLE handle = GetHandle(property_name);
  if (!handle)
  {
    return;
  }
  HRESULT hr = this->effect_->SetMatrix(handle, (const D3DXMATRIX*)&matrix);
  GG_ASSERT(SUCCEEDED(hr), "Matrix4x4�v���p�e�B�̓]���Ɏ��s���܂���");
}

void NativeShader::SetTexture(const std::string& property_name, const SharedRef<const rcTexture>& texture)
{
  D3DXHANDLE handle = GetHandle(property_name);
  if (!handle)
  {
    return;
  }
  HRESULT hr = this->effect_->SetTexture(handle, texture ? (LPDIRECT3DTEXTURE9)texture->GetNativeObject() : nullptr);
  GG_ASSERT(SUCCEEDED(hr), "rcTexture�v���p�e�B�̓]���Ɏ��s���܂���");
}

void NativeShader::GetBool(const std::string& property_name, bool* dest)
{
  D3DXHANDLE handle = GetHandle(property_name);
  if (!handle)
  {
    return;
  }
  BOOL ret;
  this->effect_->GetBool(handle, &ret);
  *dest = ret;
}

void NativeShader::GetInt(const std::string& property_name, T_INT32* dest)
{
  D3DXHANDLE handle = GetHandle(property_name);
  if (!handle)
  {
    return;
  }
  this->effect_->GetInt(handle, dest);
}

void NativeShader::GetFloat(const std::string& property_name, T_FLOAT* dest)
{
  D3DXHANDLE handle = GetHandle(property_name);
  if (!handle)
  {
    return;
  }
  this->effect_->GetFloat(handle, dest);
}

void NativeShader::GetVec2f(const std::string& property_name, TVec2f* dest)
{
  D3DXHANDLE handle = GetHandle(property_name);
  if (!handle)
  {
    return;
  }
  this->effect_->GetFloatArray(handle, dest->data, 2);
}

void NativeShader::GetVec3f(const std::string& property_name, TVec3f* dest)
{
  D3DXHANDLE handle = GetHandle(property_name);
  if (!handle)
  {
    return;
  }
  this->effect_->GetFloatArray(handle, dest->data, 3);
}

void NativeShader::GetVec4f(const std::string& property_name, TVec4f* dest)
{
  D3DXHANDLE handle = GetHandle(property_name);
  if (!handle)
  {
    return;
  }
  this->effect_->GetFloatArray(handle, dest->data, 4);
}

void NativeShader::GetColor(const std::string& property_name, TColor* dest)
{
  D3DXHANDLE handle = GetHandle(property_name);
  if (!handle)
  {
    return;
  }
  this->effect_->GetFloatArray(handle, dest->data, 4);
}

void NativeShader::GetMatrix(const std::string& property_name, Matrix4x4* dest)
{
  D3DXHANDLE handle = GetHandle(property_name);
  if (!handle)
  {
    return;
  }
  this->effect_->GetMatrix(handle, (D3DXMATRIX*)dest);
}

void NativeShader::GetTexture(const std::string& property_name, void* dest)
{
  D3DXHANDLE handle = GetHandle(property_name);
  if (!handle)
  {
    return;
  }
  GG_ASSERT(false, "�܂��ł��Ă��܂���I");
  this->effect_->GetTexture(handle, (LPDIRECT3DBASETEXTURE9*)(&(dest)));
}

D3DXHANDLE NativeShader::GetHandle(const std::string& property_name)
{
  if (this->bad_property_ids_.find(property_name) != this->bad_property_ids_.end())
  {
    return NULL;
  }
  auto pair = this->property_handles_.find(property_name);
  //�v���p�e�B���o�^����Ă�����n���h����Ԃ�
  if (pair != this->property_handles_.end())
  {
    return pair->second;
  }
  D3DXHANDLE ret = this->effect_->GetParameterByName(NULL, property_name.c_str());
  if (ret)
  {
    this->property_handles_.emplace(
      std::piecewise_construct,
      std::forward_as_tuple(property_name),
      std::forward_as_tuple(ret));
    return ret;
  }
  this->bad_property_ids_.insert(property_name);
  return NULL;
}