#pragma once

#include "NativeType.h"
#include "BlendFunction.h"
#include "NativeMatrix.h"
#include "NativeMatrixStack.h"

class GameObjectRenderState
{
  // =================================================================
  // Constructor / Destructor
  // =================================================================
public:
  GameObjectRenderState();
  ~GameObjectRenderState();

  // =================================================================
  // Method
  // =================================================================
public:
  virtual void Init();
  void PushMatrix(INativeMatrix* matrix);
  void PopMatrix();

  // =================================================================
  // Setter / Getter
  // =================================================================
public:
  inline LP_DEVICE GetRenderObject() const
  {
    return this->render_object_;
  }
  inline INativeMatrixStack* GetMatrixStack()
  {
    return this->matrix_stack_;
  }
  inline void AddTargetLayerId(T_UINT8 layer_id)
  {
    layer_state_ |= 1 << layer_id;
  }
  inline void AddAllTargetLayerIds()
  {
    layer_state_ = 0xffffffff;
  }
  inline void RemoveTargetLayerId(T_UINT8 layer_id)
  {
    layer_state_ |= 1 << layer_id;
  }
  inline void ClearTargetLayerIds()
  {
    layer_state_ = 0x00000000;
  }
  inline bool IsTargetedLayer(T_UINT8 layer_id)
  {
    return layer_state_ & (1 << layer_id);
  }

  // =================================================================
  // Data Member
  // =================================================================
private:
  T_UINT32 layer_state_;
  LP_DEVICE render_object_;
  INativeMatrixStack* matrix_stack_;

};
