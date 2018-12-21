#pragma once

namespace Shader
{
/*!
 * @brief �g�ݍ��ݕϐ�
 */
enum class BuiltinVariable : T_UINT8
{
  kMatrix_MVP,
  kMatrix_MV,
  kMatrix_V,
  kMatrix_P,
  kMatrix_ObjToWorld,
  kMatrix_WorldToObj,

  kMatrix_Time,
  kMatrix_SinTime,
  kMatrix_CosTime,
  kMatrix_DeltaTime,

  DATANUM,
};

/*!
 * @brief �p�X�̃��C�g���[�h
 */
enum class LightMode : T_UINT8
{
  kAlways,
  kForwardBase,
  kForwardAdd,
  kDeferred,
  kShadowCaster,
  kMotionVector,

  DATANUM,
};

/*!
 * @brief �J�����O���[�h
 */
enum class CullMode : T_UINT8
{
  kBack,
  kFront,
  kOff,

  DATANUM,
};

/*!
 * @brief Z�o�b�t�@�������݃��[�h
 */
enum class ZWrite : T_UINT8
{
  kOn,
  kOff,

  DATANUM,
};

/*!
 * @brief ��r�֐�
 */
enum class ComparasionFunc : T_UINT8
{
  kLess,
  kGreater,
  kLEqual,
  kGEqual,
  kEqual,
  kNotEqual,
  kAlways,

  DATANUM,
};

/*!
 * @brief �u�����h���[�h�W��
 */
enum class BlendFactor : T_UINT8
{
  kOne,
  kZero,
  kSrcColor,
  kSrcAlpha,
  kDstColor,
  kDstAlpha,
  kInvSrcColor,
  kInvSrcAlpha,
  kInvDstColor,
  kInvDstAlpha,

  DATANUM,
};

/*!
 * @brief �u�����h���[�h���Z�q
 */
enum class BlendOp : T_UINT8
{
  kAdd,
  kSub,
  kRevSub,
  kMin,
  kMax,

  DATANUM,
};

/*!
 * @brief �X�e���V���e�X�g�ʉߎ��̑���
 */
enum class StencilOperation : T_UINT8
{
  kKeep,
  kZero,
  kReplace,
  kIncrSaturate,
  kDecrSaturate,
  kInvert,
  kIncrWrap,
  kDecrWrap,

  DATANUM,
};

/*!
 * @brief �ϐ��̃^�C�v
 */
enum class VariableType : T_UINT8
{
  kBool,
  kInt,
  kUint,
  kFloat,
  kColor,

  DATANUM,
};

/*!
 * @brief �ϐ��̃^�C�v
 */
enum class ColorType : T_UINT8
{
  kColor,
  kColorHDR,

  DATANUM,
};

/*!
 * @brief �T���v���[�̃^�C�v
 */
enum class SamplerType : T_UINT8
{
  kSampler2D,
  kSamplerCube,
  kSampler3D,

  DATANUM,
};

/*!
 * @brief �f�t�H���g�e�N�X�`���̃^�C�v
 */
enum class DefaultTextureType : T_UINT8
{
  kWhite,
  kBlack,
  kGray,

  DATANUM,
};

/*!
 * @brief RenderQueue�̃^�C�v
 */
enum class RenderQueue : T_UINT8
{
  kBackGround,
  kGeometry,
  kAlphaTest,
  kTransparent,
  kOverlay,

  DATANUM,
};

/*!
 * @brief �`��^�C�v
 */
enum class RenderType : T_UINT8
{
  kOpaque,
  kTransparent,
  kTransparentCutout,
  kBackground,
  kOverlay,

  DATANUM,
};

/*!
 * @brief �R���X�^���g�o�b�t�@��ID
 */
enum class ConstantBufferId : T_UINT8
{
  kRendererBuiltin,
  kRenderStateBuiltin,
  kProperty,

  DATANUM,
};

/*!
 * @brief �R���X�^���g�o�b�t�@��ID
 */
//enum class ConstantBufferId : T_UINT8
//{
//  kRendererBuiltin,
//  kRenderStateBuiltin,
//  kProperty,
//
//  DATANUM,
//};

} // namespace Shader