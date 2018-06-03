#pragma once

#include "Renderer.h"
#include "Mesh.h"

class MeshRenderer : public Renderer
{
  // =================================================================
  // Factory Method
  // =================================================================
public:
  static MeshRenderer* Create(const Mesh& mesh, GameObject* entity);
  static MeshRenderer* Create(const Mesh* mesh, GameObject* entity);

  // =================================================================
  // Constructor / Destructor
  // =================================================================
protected:
  MeshRenderer(GameObject* entity);

  // =================================================================
  // Method
  // =================================================================
public:
  virtual void Draw(GameObjectRenderState* state) override;

private:
  virtual void SetStreamSource();
  virtual void DrawSubset(T_UINT8 material_index, T_UINT8 pass_index);

  // =================================================================
  // setter/getter
  // =================================================================
public:
  inline void SetMesh(const Mesh& mesh)
  {
    this->mesh_ = &mesh;
  }
  inline void SetMesh(const Mesh* mesh)
  {
    this->mesh_ = mesh;
  }

  // =================================================================
  // Data Member
  // =================================================================
private:
  const Mesh* mesh_;

};