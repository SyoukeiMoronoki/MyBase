#pragma once

#include "NativeType.h"
#include "Resource.h"

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Color.h"

#include "VertexBuffer.h"
#include "IndexBuffer.h"

#include "MeshData.h"

#include "GraphicsConstants.h"

class rcMesh : public Resource
{
  // =================================================================
  // Factory Method
  // =================================================================
public:
  static rcMesh* CreateFromFile(const char* path);
  static rcMesh* Create();
  static rcMesh* Create(const MeshData* data);

  // =================================================================
  // Constructor / Destructor
  // =================================================================
protected:
  rcMesh();
  virtual ~rcMesh();

  // =================================================================
  // Methods
  // =================================================================
public:
  void Clear();
  void ClearVertices(bool clear_buffer);
  void ClearIndices(bool clear_buffer);

  rcMesh* Clone(bool read_only);

  void CreateVertices(T_UINT32 vertex_count, T_UINT32 polygon_count, T_UINT32 format, Graphics::PrimitiveType primitive_type = Graphics::PRIMITIVE_TRIANGLES);
  inline void CreateVerticesWithIndex(T_UINT32 vertex_count, T_UINT32 index_count, T_UINT32 format, Graphics::PrimitiveType primitive_type = Graphics::PRIMITIVE_TRIANGLES)
  {
    CreateVertices(vertex_count, Graphics::PRIMITIVE_SURF_NUM(primitive_type, index_count), format, primitive_type);
  }
  inline void CreateIndices(T_UINT32 index_count)
  {
    this->CreateIndices(1, &index_count);
  }
  void CreateIndices(T_UINT8 submesh_count, T_UINT32* index_counts);

  void CommitChanges(bool read_only);
  void RecalculateNormals(bool save_face_normals = false);
  void RecalculateTangents();

  void SetStreamSource() const;
  void DrawSubset(T_UINT8 index) const;

  // =================================================================
  // setter/getter
  // =================================================================
public:
  virtual size_t GetMemorySize() const override;
  virtual size_t GetVideoMemorySize() const override;

  inline void SetPrimitiveType(Graphics::PrimitiveType type)
  {
    this->primitive_type_ = type;
  }

  inline T_UINT32 GetFaceCount() const
  {
    return this->polygon_count_;
  }
  inline const TVec3f& GetFaceNormal(T_UINT32 index) const
  {
    return this->face_normals_[index];
  }

  //Vertex Buffer
  void SetVertex(T_UINT32 vertex_index, const TVec3f& vertex);
  void SetVertices(const TVec3f* vertices);
  inline const TVec3f& GetVertex(T_UINT32 vertex_index) const
  {
    NATIVE_ASSERT(this->HasVertices(), "頂点フォーマットで定義されていない属性が呼び出されました");
    return this->vertices_[vertex_index];
  }
  inline const TVec3f* GetVertices() const
  {
    NATIVE_ASSERT(this->HasVertices(), "頂点フォーマットで定義されていない属性が呼び出されました");
    return this->vertices_;
  }
  inline bool HasVertices() const
  {
    return this->vertices_;
  }

  void SetNormal(T_UINT32 vertex_index, const TVec3f& normal);
  void SetNormals(const TVec3f* normals);
  inline const TVec3f& GetNormal(T_UINT32 vertex_index) const
  {
    NATIVE_ASSERT(this->HasNormals(), "頂点フォーマットで定義されていない属性が呼び出されました");
    return this->normals_[vertex_index];
  }
  inline const TVec3f* GetNormals() const
  {
    NATIVE_ASSERT(this->HasNormals(), "頂点フォーマットで定義されていない属性が呼び出されました");
    return this->normals_;
  }
  inline bool HasNormals() const
  {
    return this->normals_;
  }

  void SetUv(T_UINT32 vertex_index, const TVec2f& uv);
  void SetUvs(const TVec2f* uvs);
  inline const TVec2f& GetUv(T_UINT32 vertex_index) const
  {
    NATIVE_ASSERT(this->HasUvs(), "頂点フォーマットで定義されていない属性が呼び出されました");
    return this->uvs_[vertex_index];
  }
  inline const TVec2f* GetUvs() const
  {
    NATIVE_ASSERT(this->HasUvs(), "頂点フォーマットで定義されていない属性が呼び出されました");
    return this->uvs_;
  }
  inline bool HasUvs() const
  {
    return this->uvs_;
  }

  void SetUv2(T_UINT32 vertex_index, const TVec2f& uv2);
  void SetUv2s(const TVec2f* uv2s);
  inline const TVec2f& GetUv2(T_UINT32 vertex_index) const
  {
    NATIVE_ASSERT(this->HasUv2s(), "頂点フォーマットで定義されていない属性が呼び出されました");
    return this->uv2s_[vertex_index];
  }
  inline const TVec2f* GetUv2s() const
  {
    NATIVE_ASSERT(this->HasUv2s(), "頂点フォーマットで定義されていない属性が呼び出されました");
    return this->uv2s_;
  }
  inline bool HasUv2s() const
  {
    return this->uv2s_;
  }

  void SetUv3(T_UINT32 vertex_index, const TVec2f& uv3);
  void SetUv3s(const TVec2f* uv3s);
  inline const TVec2f& GetUv3(T_UINT32 vertex_index) const
  {
    NATIVE_ASSERT(this->HasUv3s(), "頂点フォーマットで定義されていない属性が呼び出されました");
    return this->uv3s_[vertex_index];
  }
  inline const TVec2f* GetUv3s() const
  {
    NATIVE_ASSERT(this->HasUv3s(), "頂点フォーマットで定義されていない属性が呼び出されました");
    return this->uv3s_;
  }
  inline bool HasUv3s() const
  {
    return this->uv3s_;
  }

  void SetUv4(T_UINT32 vertex_index, const TVec2f& uv4);
  void SetUv4s(const TVec2f* uv4s);
  inline const TVec2f& GetUv4(T_UINT32 vertex_index) const
  {
    NATIVE_ASSERT(this->HasUv4s(), "頂点フォーマットで定義されていない属性が呼び出されました");
    return this->uv4s_[vertex_index];
  }
  inline const TVec2f* GetUv4s() const
  {
    NATIVE_ASSERT(this->HasUv4s(), "頂点フォーマットで定義されていない属性が呼び出されました");
    return this->uv4s_;
  }
  inline bool HasUv4s() const
  {
    return this->uv4s_;
  }

  void SetTangent(T_UINT32 vertex_index, const TVec4f& tangent);
  void SetTangents(const TVec4f* tangents);
  inline const TVec4f& GetTangent(T_UINT32 vertex_index) const
  {
    NATIVE_ASSERT(this->HasTangents(), "頂点フォーマットで定義されていない属性が呼び出されました");
    return this->tangents_[vertex_index];
  }
  inline const TVec4f* GetTangents() const
  {
    NATIVE_ASSERT(this->HasTangents(), "頂点フォーマットで定義されていない属性が呼び出されました");
    return this->tangents_;
  }
  inline bool HasTangents() const
  {
    return this->tangents_;
  }

  void SetColor(T_UINT32 vertex_index, const TColor& tangent);
  void SetColors(const TColor* colors);
  inline const TColor& GetColor(T_UINT32 vertex_index) const
  {
    NATIVE_ASSERT(this->HasColors(), "頂点フォーマットで定義されていない属性が呼び出されました");
    return this->colors_[vertex_index];
  }
  inline const TColor* GetColors() const
  {
    NATIVE_ASSERT(this->HasColors(), "頂点フォーマットで定義されていない属性が呼び出されました");
    return this->colors_;
  }
  inline bool HasColors() const
  {
    return this->colors_;
  }

  inline const T_UINT32 GetVertexCount()
  {
    return this->vertex_count_;
  }

  //Index Buffer
  void SetIndex(T_UINT8 submesh_index, T_UINT32 index_index, T_UINT32 index);
  void SetIndices(T_UINT8 submesh_index, T_UINT32* indices);
  inline T_UINT32 GetIndex(T_UINT8 submesh_index, T_UINT32 index_index) const
  {
    NATIVE_ASSERT(submesh_index < this->submesh_count_, "インデックス指定がサブメッシュの最大個数を超過しました。");
    return this->indices_[submesh_index][index_index];
  }

  inline void SetIndex(T_UINT32 index_index, T_UINT32 index)
  {
    this->SetIndex(0, index_index, index);
  }
  inline void SetIndices(T_UINT32* indices)
  {
    this->SetIndices(0, indices);
  }
  inline T_UINT32 GetIndex(T_UINT32 index_index) const
  {
    return this->GetIndex(0, index_index);
  }

  inline const T_UINT32* GetIndices(T_UINT8 submesh_index = 0) const
  {
    NATIVE_ASSERT(submesh_index < this->submesh_count_, "インデックス指定がサブメッシュの最大個数を超過しました。");
    return this->indices_[submesh_index];
  }
  inline T_UINT32 GetIndexCount(T_UINT8 submesh_index = 0) const
  {
    NATIVE_ASSERT(submesh_index < this->submesh_count_, "インデックス指定がサブメッシュの最大個数を超過しました。");
    return this->index_counts_[submesh_index];
  }

  inline Graphics::PrimitiveType GetPrimitiveType() const
  {
    return this->primitive_type_;
  }
  inline rcVertexBuffer* GetVertexBuffer()
  {
    return this->vertex_buffer_;
  }
  inline const rcVertexBuffer* GetVertexBuffer() const
  {
    return this->vertex_buffer_;
  }
  inline rcIndexBuffer* GetIndexBuffer(T_UINT8 submesh_index)
  {
    NATIVE_ASSERT(submesh_index < this->submesh_count_, "インデックス指定がサブメッシュの最大個数を超過しました。");
    return this->index_buffers_[submesh_index];
  }
  inline const rcIndexBuffer* GetIndexBuffer(T_UINT8 submesh_index = 0) const
  {
    NATIVE_ASSERT(submesh_index < this->submesh_count_, "インデックス指定がサブメッシュの最大個数を超過しました。");
    return this->index_buffers_[submesh_index];
  }
  inline T_UINT8 GetSubmeshCount() const
  {
    return this->submesh_count_;
  }

  // =================================================================
  // Data Member
  // =================================================================
protected:
  const rcMesh* orginal_;

  bool read_only_;

  T_UINT32 format_;
  T_UINT32 polygon_count_;
  TVec3f* face_normals_;

  T_UINT32 vertex_count_;
  TVec3f* vertices_;
  TVec3f* normals_;
  TVec2f* uvs_;
  TVec2f* uv2s_;
  TVec2f* uv3s_;
  TVec2f* uv4s_;
  //wは法線マップのミラーリングに使用(Unityを参考)
  TVec4f* tangents_;
  TColor* colors_;
  //bindPoses
  //boneWeights
  //bounds
  bool vertices_dirty_;

  T_UINT32* index_counts_;
  T_UINT32** indices_;
  bool* indices_dirties_;

  Graphics::PrimitiveType primitive_type_;
  rcVertexBuffer* vertex_buffer_;

  T_UINT8 submesh_count_;
  rcIndexBuffer** index_buffers_;

};
