#pragma once

#include "ApplicationOption.h"
#include <Core/Application/Platform/Platform.h>
#include <Core/Application/Activity/Activity.h>
#include <Core/Application/Event/UpdateEventState.h>

class IApplicationBehavior;
class IApplicationSetting;

/*!
 * @brief �A�N�e�B�r�e�B��API�𓮍삳����N���X
 * �A�N�e�B�r�e�B�̊Ǘ����s��
 */
class Application
{
  // =================================================================
  // GGG Statement
  // =================================================================
  GG_SINGLETON(Application);

  // =================================================================
  // Methods
  // =================================================================
public:
  static void Run(IApplicationBehavior* behavior, IApplicationSetting* setting);

  // =================================================================
  // Setter / Getter
  // =================================================================
public:
  static GG_INLINE const ApplicationOption& GetOption()
  {
    return Self().option_;
  }
  
  static GG_INLINE const UpdateEventState& GetUpdateEventState()
  {
    return Self().update_event_state_;
  }

  static GG_INLINE SharedRef<Platform> GetPlatform()
  {
    return Self().platform_;
  }

  static GG_INLINE SharedRef<Activity> GetMainActivity()
  {
    return Self().main_activity_;
  }

  // =================================================================
  // Data Members
  // =================================================================
private:
  ApplicationOption option_;
  UpdateEventState update_event_state_;
  SharedRef<Platform> platform_;
  SharedRef<Activity> main_activity_;

};