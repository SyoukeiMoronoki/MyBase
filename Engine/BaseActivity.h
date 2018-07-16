#ifndef HAL_ENGINE_ACTIVITY_BASEACTIVITY_H_
#define HAL_ENGINE_ACTIVITY_BASEACTIVITY_H_

#include "Engine.h"
#include "EngineInput.h"

class BaseActivity
{
  // =================================================================
  // Constructor / Destructor
  // =================================================================
public:
  BaseActivity();
  virtual ~BaseActivity();

  // =================================================================
  // Method
  // =================================================================
public:
  bool Run(IEngineSetting* setting);

protected:
  virtual bool ApplyEngineOption(const EngineOption* option) = 0;
  virtual bool Init(const EngineOption* option) = 0;
  virtual bool Uninit() = 0;
  virtual bool FrameEnabled() = 0;
  virtual void ImGuiNewFrame() = 0;
  virtual bool ContinueEnabled() = 0;
  virtual bool PreDraw() = 0;
  virtual void PostDraw() = 0;
  virtual void ImGuiEndFrame() = 0;
  virtual void InputProcess(EngineInputState* state) = 0;
  bool Update();
  bool Draw();
  
  // =================================================================
  // Setter / Getter
  // =================================================================
public:
  virtual LP_DEVICE GetDevice() const = 0;

  // =================================================================
  // Data Member
  // =================================================================
private:
  Engine* engine_;

};

#endif//HAL_ENGINE_ACTIVITY_BASEACTIVITY_H_
