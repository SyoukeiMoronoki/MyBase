#include "VertexBuffer.h"

// =================================================================
// Factory Method
// =================================================================
UniqueRef<rcVertexBuffer> rcVertexBuffer::Create(T_UINT32 vertex_count, T_UINT32 format)
{
  return NativeProcess::Resource::CreateVertexBuffer(vertex_count, format);
}