#pragma once

#include "Cereal\types\string.hpp"
#include "Cereal\archives\binary.hpp"

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4x4.h"
#include "Color.h"
#include "Bounds.h"

template <class Archive>
void serialize(Archive& archive, TVec2f& value)
{
  archive(cereal::binary_data(value.data, sizeof(T_FLOAT) * 2));
}

template <class Archive>
void serialize(Archive& archive, TVec3f& value)
{
  archive(cereal::binary_data(value.data, sizeof(T_FLOAT) * 3));
}

template <class Archive>
void serialize(Archive& archive, TVec4f& value)
{
  archive(cereal::binary_data(value.data, sizeof(T_FLOAT) * 4));
}

template <class Archive>
void serialize(Archive& archive, TColor& value)
{
  archive(cereal::binary_data(value.data, sizeof(T_FLOAT) * 4));
}

template <class Archive>
void serialize(Archive& archive, Matrix4x4& value)
{
  archive(cereal::binary_data(value.data, sizeof(T_FLOAT) * 16));
}

template <class Archive>
void serialize(Archive& archive, Bounds& data)
{
  archive(data.center);
  archive(data.extents);
}