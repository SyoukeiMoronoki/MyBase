#pragma once

#include "GameObject3D.h"

class Cube3D : public GameObject3D
{
  // =================================================================
  // Factory Method
  // =================================================================
public:
  static Cube3D* Create();

  // =================================================================
  // Constructor / Destructor
  // =================================================================
protected:
  Cube3D() {}
  
};