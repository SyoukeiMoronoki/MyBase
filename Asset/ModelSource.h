//#pragma once
//
//#include "Model.h"
//#include "ModelData.h"
//#include "rcMaterial.h"
//#include "StaticMesh.h"
//
////=============================================================================
//// NodeNode
////=============================================================================
//class ModelNodeSource
//{
//public:
//  ModelNodeSource(ModelSource* model, ModelNodeData* data);
//  ~ModelNodeSource();
//
//public:
//  ModelNode* Create();
//
//private:
//  ModelNodeData* data_;
//
//  T_UINT32 child_count_;
//  ModelNodeSource** children_;
//
//  rcMaterial* materials_;
//  StaticMesh* meshes_;
//
//};
//
////=============================================================================
//// Model
////=============================================================================
//class ModelSource
//{
//public:
//  ModelSource(ModelData* data);
//  ~ModelSource();
//
//public:
//  Model* Create();
//
//private:
//  ModelData* data_;
//
//  ModelNodeSource* root_;
//
//  rcMaterial** materials_;
//  StaticMesh* master_mesh_;
//
//};