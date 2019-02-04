#pragma once

struct ImGuiContext;
class Platform;

/*!
 * @brief アクティビティの状態や情報など
 * プラットフォーム側の情報や処理を受け持つ
 */
class ActivityContext : public GGObject
{
  friend class Activity;

  // =================================================================
  // Methods
  // =================================================================
private:
  /*!
   * @brief アクティビティ初期化処理
   */
  void Start(const ActivityOption& ao);

  /*!
   * @brief アクティビティ終了処理
   */
  void End();

  /*!
   * @brief フレームの最初に呼び出す処理
   */
  void NewFrame(const SharedRef<Platform>& platform);

  /*!
   * @brief フレームの最後に呼び出す処理
   */
  void EndFrame();

  /*!
   * @brief 描画処理が有効かどうかの判定
   * @param 経過時間(秒)
   * @return falseなら画面のアップデートを行わない
   */
  bool DrawEnabled();

protected:
  /*!
   * @brief 派生先(プラットフォーム)で定義するActivityContext初期化処理
   */
  virtual void OnStart(const ActivityOption& ao) = 0;

  /*!
   * @brief 派生先(プラットフォーム)で定義するActivityContext終了処理
   */
  virtual void OnEnd() = 0;

  /*!
   * @brief 派生先(プラットフォーム)で定義するフレームの最初に呼び出す処理
   */
  virtual void OnNewFrame() = 0;

  // =================================================================
  // Setter / Getter
  // =================================================================
public:
  /*!
   * @brief アクティビティがアクティブ状態か確かめる
   * @return falseならアクティブ状態ではない
   */
  virtual bool IsActive() const = 0;

  /*!
   * @brief アクティビティが表示状態か確かめる
   * @return falseなら表示状態ではない
   */
  virtual bool IsVisible() const = 0;

  /*!
   * @brief アクティビティが生存状態か確かめる
   * @return falseなら生存状態ではない
   */
  virtual bool IsEnabled() const = 0;

  /*!
   * @brief アクティビティを一意に認識できるIDを取得する。
   * HWNDなど、プラットフォーム固有の値があればそれを使用する
   * @return ID
   */
  virtual T_UINT64 GetActivityID() const = 0;

  GG_INLINE const ActivityOption& GetOption() const
  {
    return this->option_;
  }

  GG_INLINE const TVec2f& GetScreenSize()
  {
    return this->option_.window_size;
  }

  GG_INLINE T_FLOAT GetScreenWidth()
  {
    return this->option_.window_size.width;
  }

  GG_INLINE T_FLOAT GetScreenHeight()
  {
    return this->option_.window_size.height;
  }

  GG_INLINE const std::unique_ptr<ImGuiContext>& GetImGuiContext()
  {
    return this->imgui_context_;
  }

  // =================================================================
  // Data Member
  // =================================================================
private:
  ActivityOption option_;
  std::unique_ptr<ImGuiContext> imgui_context_;
  T_FLOAT elapsed_time_;

};
