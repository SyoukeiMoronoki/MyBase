#pragma once

#include "NativeType.h"
#include "NativeAssert.h"

#include "ResourceManager.h"

/*
  Resource�̓��t�@�����X�J�E���^�ŊǗ������
  shared_ptr���g�p���Ă��Ȃ��̂́A��X�񓯊�Load/Unload�����������
  Resource���p������N���X�͐ړ�����rc���t���B
  rc���t���Ă�N���X�𗘗p����ۂ̓��t�@�����X�J�E���g�ɒ��ӂ��鎖�B
*/

class Resource
{
  friend class ResourceManager;

  // =================================================================
  // Constructor / Destructor
  // =================================================================
protected:
  Resource()
  {}

  virtual ~Resource()
  {}

  // =================================================================
  // noncopyable
  // =================================================================
private:
  Resource(const Resource&) = delete;
  Resource& operator = (const Resource&) = delete;
  Resource(Resource&&) = delete;
  Resource& operator = (Resource&&) = delete;

  // =================================================================
  // Methods
  // =================================================================
public:
  inline void Retain() const
  {
    ++const_cast<Resource*>(this)->reference_count_;
  }

  inline void Release() const
  {
    NATIVE_ASSERT(this->reference_count_ > 0, "���t�@�����X�J�E���^��0�̎���Release���܂���");
    --const_cast<Resource*>(this)->reference_count_;
  }

protected:
  inline void Init()
  {
    this->Retain();
    ResourceManager::GetInstance().Manage(this);
  }

  // =================================================================
  // Setter / Getter
  // =================================================================
public:
  inline T_UINT16 GetReferenceCount() const
  {
    return this->reference_count_;
  }

  virtual size_t GetMemorySize() const
  {
    return sizeof(Resource);
  }
  virtual size_t GetVideoMemorySize() const
  {
    return 0;
  }

  // =================================================================
  // Data Members
  // =================================================================
private:
  T_UINT16 reference_count_;

};