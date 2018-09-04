#include "VertexBuffer.h"
#include "NativeProcess.h"

// =================================================================
// Factory Method
// =================================================================
rcVertexBuffer* rcVertexBuffer::Create(T_UINT16 vertex_count, T_UINT16 polygon_count, T_UINT32 format)
{
  rcVertexBuffer* ret = NativeProcess::Resource::CreateVertexBuffer(vertex_count, polygon_count, format);
  ret->Resource::Init();
  return ret;
}