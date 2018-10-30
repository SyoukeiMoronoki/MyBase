#pragma once

#include <Engine/Component/GameComponent.h>
#include <Engine/GameObject/GameObject3D.h>
#include <Engine/GameObject/Transform/Transform3D.h>

class Collider3D_Sphare;
//class Collider3D_Capsule;

class Collider3D : public GameComponent
{
  // =================================================================
  // Constructor / Destructor
  // =================================================================
public:
  Collider3D(GameObject3D* entity);
  Collider3D(GameObject3D* entity, const TVec3f& offset);

  // =================================================================
  // Methods
  // =================================================================
public:
  virtual bool Collision(Collider3D_Sphare& other) = 0;
  //virtual bool Collision(const Collider3D_Capsule& other) = 0;

protected:
  bool RoughCheck(const Collider3D& other);

  // =================================================================
  // Setter / Getter
  // =================================================================
public:
  GG_INLINE const TVec3f GetPosition() const
  {
    return this->offset_ + this->entity_->GetTransform()->GetWorldPosition();
  }
  GG_INLINE void SetOffset(const TVec3f& offset)
  {
    this->offset_ = offset;
  }
  GG_INLINE const TVec3f& GetOffset() const
  {
    return this->offset_;
  }
  virtual T_FLOAT GetBoundRadius() const = 0;

protected:
  GameObject3D* entity_;
  TVec3f offset_;
};

// =================================================================
// Sphare
// =================================================================
class Collider3D_Sphare : public Collider3D
{
  // =================================================================
  // Constructor / Destructor
  // =================================================================
public:
  Collider3D_Sphare(GameObject3D* entity);

  // =================================================================
  // Methods
  // =================================================================
public:
  virtual bool Collision(Collider3D_Sphare& other) override;
  //virtual bool Collision(const Collider3D_Capsule & other) override;

protected:
  virtual T_FLOAT GetBoundRadius() const override;

  // =================================================================
  // Setter / Getter
  // =================================================================
public:
  GG_INLINE T_FLOAT GetRadius() const
  {
    return this->radius_;
  }
  GG_INLINE void SetRadius(T_FLOAT radius)
  {
    this->radius_ = radius;
  }

  // =================================================================
  // Data Member
  // =================================================================
private:
  T_FLOAT radius_;
};

//// =================================================================
//// Capsule
//// =================================================================
//class Collider3D_Capsule : public Collider3D
//{
//  // =================================================================
//  // Constructor / Destructor
//  // =================================================================
//public:
//  Collider3D_Capsule(GameObject3D* entity);
//
//  // =================================================================
//  // Setter / Getter
//  // =================================================================
//private:
//
//};
//