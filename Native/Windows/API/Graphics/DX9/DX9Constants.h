#pragma once

#include <d3d9.h>

namespace DX9
{

static D3DFORMAT INDEX_FORMATS[static_cast<T_UINT32>(Vertex::IndexFormat::INDEX_FMT_DATANUM)] =
{
  D3DFMT_INDEX16,
  D3DFMT_INDEX32,
};

static const D3DPRIMITIVETYPE PRIMITIVE_TYPES[static_cast<T_UINT32>(Vertex::PrimitiveType::DATANUM)] =
{
  D3DPT_POINTLIST,
  D3DPT_LINELIST,
  D3DPT_LINESTRIP,
  D3DPT_TRIANGLELIST,
  D3DPT_TRIANGLESTRIP,
  D3DPT_TRIANGLEFAN,
};

static D3DFORMAT TEXTURE_FORMATS[static_cast<T_UINT32>(Graphics::PixelFormat::FORMAT_DATANUM)] =
{
  D3DFMT_D16,
  D3DFMT_D24S8,
  D3DFMT_D32,
  D3DFMT_A8B8G8R8,
  D3DFMT_A16B16G16R16,
  D3DFMT_A16B16G16R16F,
};

}