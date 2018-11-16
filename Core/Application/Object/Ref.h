#pragma once

#include "ObjectManager.h"

template <class Obj_>
class GGRef
{
  // =================================================================
  // Constructor / Destructor
  // =================================================================
protected:
  /*!
   * @brief �f�t�H���g�R���X�g���N�^�B
   * ���L���������Ȃ��A���Ref���\�z����B
   */
  GG_INLINE constexpr GGRef() noexcept = default;

  /*!
   * @brief �f�X�g���N�^�B���L����j������B
   */
  GG_INLINE ~GGRef()
  {
    if (this->ptr_)
    {
      this->ptr_->Release();
    }
  }

  /*!
   * @brief ���|�C���^�̏��L�����󂯎��A
   * �I�u�W�F�N�g�Ǘ��N���X�֒ǉ��B
   */
  GG_INLINE explicit GGRef(Obj_* ptr)
  {
    ptr->Retain();
    GGObjectManager::Manage(ptr);
    this->ptr_ = ptr;
  }

  /*!
   * @brief ���L���������Ȃ����Ref�̍쐬�B
   */
  GG_INLINE constexpr GGRef(nullptr_t p)
    : ptr_()
  {}

  // =================================================================
  // operator
  // =================================================================
public:
  /*!
   * @brief �R�s�[����֎~�B
   */
  GG_INLINE GGRef& operator = (const GGRef&) = delete;

  /*!
   * @brief �����o�A�N�Z�X
   */
  GG_INLINE Obj_* operator -> () const noexcept
  {
    return this->ptr_;
  }

  /*!
   * @brief �ԐڎQ��
   */
  GG_INLINE Obj_& operator*() const noexcept
  {
    return *this->ptr_;
  }

  /*!
   * @brief �L���ȃ��\�[�X�����L���Ă��邩���肷��
   */
  GG_INLINE explicit operator bool() const noexcept
  {
    return this->ptr_ != nullptr;
  }

  /*!
   * @brief ���l��r
   */
  template <class Other_>
  GG_INLINE bool operator== (const GGRef<Other_>& o) const noexcept
  {
    return this->ptr_ == o.ptr_;
  }

  /*!
   * @brief nullptr���l��r
   */
  GG_INLINE bool operator== (nullptr_t o) const noexcept
  {
    return this->ptr_ == o;
  }

  /*!
   * @brief �񓙒l��r
   */
  template <class Other_>
  GG_INLINE bool operator!= (const GGRef<Other_>& o) const noexcept
  {
    return this->ptr_ != o.ptr_;
  }

  /*!
   * @brief nullptr�񓙒l��r
   */
  GG_INLINE bool operator!= (nullptr_t o) const noexcept
  {
    return this->ptr_ != o;
  }

  /*!
   * @brief <��r
   */
  template <class Other_>
  GG_INLINE bool operator< (const GGRef<Other_>& o) const noexcept
  {
    return this->ptr_ < o.ptr_;
  }

  /*!
   * @brief <=��r
   */
  template <class Other_>
  GG_INLINE bool operator<= (const GGRef<Other_>& o) const noexcept
  {
    return this->ptr_ <= o.ptr_;
  }

  /*!
   * @brief >��r
   */
  template <class Other_>
  GG_INLINE bool operator> (const GGRef<Other_>& o) const noexcept
  {
    return this->ptr_ > o.ptr_;
  }

  /*!
   * @brief >��r
   */
  template <class Other_>
  GG_INLINE bool operator>= (const GGRef<Other_>& o) const noexcept
  {
    return this->ptr_ >= o.ptr_;
  }


  // =================================================================
  // Data Members
  // =================================================================
protected:
  Obj_* ptr_;

};