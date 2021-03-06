#pragma once

class GameObject;

class EntityModifierAttribute
{
public:
  enum ID
  {
    MODIFIER_ATTR_TRANSLATE_X,
    MODIFIER_ATTR_TRANSLATE_Y,
    MODIFIER_ATTR_TRANSLATE_Z,
    MODIFIER_ATTR_SCALE_X,
    MODIFIER_ATTR_SCALE_Y,
    MODIFIER_ATTR_SCALE_Z,
    MODIFIER_ATTR_ROTATE_X,
    MODIFIER_ATTR_ROTATE_Y,
    MODIFIER_ATTR_ROTATE_Z,
    MODIFIER_ATTR_COLOR_R,
    MODIFIER_ATTR_COLOR_G,
    MODIFIER_ATTR_COLOR_B,
    MODIFIER_ATTR_COLOR_A,

    MODIFIER_ATTR_DATANUM,
  };

public:
  static const EntityModifierAttribute* Create(T_UINT8 id);

public:
  virtual void SetValue(GameObject* entity, const T_FLOAT next) const = 0;
  virtual T_FLOAT GetValue(GameObject* entity) const = 0;
};