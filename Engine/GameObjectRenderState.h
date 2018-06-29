#pragma once

#include <map>
#include <vector>
#include "NativeType.h"
#include "BlendFunction.h"
#include "NativeMatrixStack.h"

class Camera;
class Renderer;
class SubMesh;
class Material;

class GameObjectRenderState
{
private:
  class DrawParam
  {
  public:
    Renderer* renderer;
    T_FLOAT distance;
  };

  // =================================================================
  // Constructor / Destructor
  // =================================================================
public:
  GameObjectRenderState(Camera* camera);
  virtual ~GameObjectRenderState();

  // =================================================================
  // Method
  // =================================================================
public:
  virtual void Init();
  void PushMatrix(const Matrix4x4& matrix);
  void PopMatrix();

  void AddZCheckOrder(T_UINT8 level, Renderer* renderer);
  void DrawZOrderedGameObject();

  // =================================================================
  // Setter / Getter
  // =================================================================
public:
  const Matrix4x4& GetWorldViewProjToMaterial();
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
    layer_state_ &= ~(1 << layer_id);
  }
  inline void ClearTargetLayerIds()
  {
    layer_state_ = 0x00000000;
  }
  inline bool IsTargetedLayer(T_UINT8 layer_id)
  {
    return layer_state_ & (1 << layer_id);
  }
  inline const Camera* GetCamera() const
  {
    return this->camera_;
  }
  inline const Matrix4x4& GetViewProjMatrix() const
  {
    return this->view_proj_matrix_;
  }

  // =================================================================
  // Data Member
  // =================================================================
private:
  Camera* camera_;
  T_UINT32 layer_state_;
  LP_DEVICE render_object_;
  INativeMatrixStack* matrix_stack_;
  Matrix4x4 view_proj_matrix_;
  Matrix4x4 world_view_proj_matrix_;

  //std::map<int, std::vector<PostDrawParam>> post_draw_map_;
  std::map<Material*, std::vector<DrawParam>> draw_map_;
  std::map<int, std::map<Material*, std::vector<DrawParam>>> post_draw_map_;
};
