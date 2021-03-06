//#include "ParticleData.h"
//
//#include "ParticleSystem.h"
//#include "../Core/MathConstants.h"
//#include "Director.h"
//#include <algorithm>
//#include <stdlib.h>
//
//#include "../Core/NativeProcess.h"
//#include "../Asset/JsonParser.h"
//
//enum EmitterType
//{
//  EM_TYPE_GRAVITY,
//  EM_TYPE_RADIUS,
//};
//
//ParticleData* ParticleData::Create(const std::string& path)
//{
//  std::string str = NativeProcess::IO::TextFile_Read(path.c_str());
//  JsonParser parser;
//  JsonNode* json = parser.Parse(str.c_str());
//
//  T_UINT8 type = json->GetValue("emitterType")->IntValue();
//
//  ParticleData* data = nullptr;
//
//  if (type == EM_TYPE_GRAVITY)
//  {
//    ParticleData_Gravity* exdata = new ParticleData_Gravity();
//    data = exdata;
//
//    exdata->accel_rad = json->GetValue("radialAcceleration")->FloatValue();
//    exdata->accel_rad_variance = json->GetValue("radialAccelVariance")->FloatValue();
//
//    exdata->accel_tan = json->GetValue("tangentialAcceleration")->FloatValue();
//    exdata->accel_tan_variance = json->GetValue("tangentialAccelVariance")->FloatValue();
//
//    exdata->speed = json->GetValue("speed")->FloatValue();
//    exdata->speed_variance = json->GetValue("speedVariance")->FloatValue();
//
//    exdata->gravity_x = json->GetValue("gravityx")->FloatValue();
//    exdata->gravity_y = json->GetValue("gravityy")->FloatValue();
//
//    exdata->emission_variance_x = json->GetValue("sourcePositionVariancex")->FloatValue();
//    exdata->emission_variance_y = json->GetValue("sourcePositionVariancey")->FloatValue();
//  }
//  if (type == EM_TYPE_RADIUS)
//  {
//    ParticleData_Radius* exdata = new ParticleData_Radius();
//    data = exdata;
//
//    exdata->max_radius = json->GetValue("maxRadius")->FloatValue();
//    exdata->max_radius_variance = json->GetValue("maxRadiusVariance")->FloatValue();
//    exdata->min_radius = json->GetValue("minRadius")->FloatValue();
//    //exdata->min_radius_variance = json->GetValue("minRadiusVariance")->IntValue();
//    exdata->rotate_per_sec = json->GetValue("rotatePerSecond")->FloatValue();
//    exdata->rotate_per_sec_variance = json->GetValue("rotatePerSecondVariance")->FloatValue();
//  }
//  //data->region_ = this->atlas_->GetTextureRegion(json->GetString("textureFileName")->StringValue());
//
//  data->start_color_r = json->GetValue("startColorRed")->FloatValue();
//  data->start_color_g = json->GetValue("startColorGreen")->FloatValue();
//  data->start_color_b = json->GetValue("startColorBlue")->FloatValue();
//  data->start_color_a = json->GetValue("startColorAlpha")->FloatValue();
//
//  data->start_color_r_variance = json->GetValue("startColorVarianceRed")->FloatValue();
//  data->start_color_g_variance = json->GetValue("startColorVarianceGreen")->FloatValue();
//  data->start_color_b_variance = json->GetValue("startColorVarianceBlue")->FloatValue();
//  data->start_color_a_variance = json->GetValue("startColorVarianceAlpha")->FloatValue();
//
//  data->end_color_r = json->GetValue("finishColorRed")->FloatValue();
//  data->end_color_g = json->GetValue("finishColorGreen")->FloatValue();
//  data->end_color_b = json->GetValue("finishColorBlue")->FloatValue();
//  data->end_color_a = json->GetValue("finishColorAlpha")->FloatValue();
//
//  data->end_color_r_variance = json->GetValue("finishColorVarianceRed")->FloatValue();
//  data->end_color_g_variance = json->GetValue("finishColorVarianceGreen")->FloatValue();
//  data->end_color_b_variance = json->GetValue("finishColorVarianceBlue")->FloatValue();
//  data->end_color_a_variance = json->GetValue("finishColorVarianceAlpha")->FloatValue();
//
//  data->start_spin = MathConstants::DegToRad(json->GetValue("rotationStart")->FloatValue());
//  data->start_spin_variance = MathConstants::DegToRad(json->GetValue("rotationStartVariance")->FloatValue());
//  data->end_spin = MathConstants::DegToRad(json->GetValue("rotationEnd")->FloatValue());
//  data->end_spin_variance = MathConstants::DegToRad(json->GetValue("rotationEndVariance")->FloatValue());
//
//  data->start_size = json->GetValue("startParticleSize")->FloatValue();
//  data->start_size_variance = json->GetValue("startParticleSizeVariance")->FloatValue();
//  data->end_size = json->GetValue("finishParticleSize")->FloatValue();
//  data->end_size_variance = json->GetValue("finishParticleSizeVariance")->FloatValue();
//
//  data->angle = MathConstants::DegToRad(json->GetValue("angle")->FloatValue());
//  data->angle_variance = MathConstants::DegToRad(json->GetValue("angleVariance")->FloatValue());
//
//  data->duration = json->GetValue("duration")->FloatValue();
//
//  data->life_time = json->GetValue("particleLifespan")->FloatValue();
//  data->life_time_variance = json->GetValue("particleLifespanVariance")->FloatValue();
//
//  data->max_particles = json->GetValue("maxParticles")->IntValue();
//
//  return data;
//}
//
////===============================================================
//// ParticleSystem
////===============================================================
//ParticleData::ParticleData()
//  : region_(nullptr)
//  , duration(0)
//  , life_time(0)
//  , life_time_variance(0)
//
//  , max_particles(0)
//  , angle(0)
//  , angle_variance(0)
//
//  , start_size(0)
//  , start_size_variance(0)
//  , start_spin(0)
//  , start_spin_variance(0)
//  , start_color_r(0)
//  , start_color_r_variance(0)
//  , start_color_g(0)
//  , start_color_g_variance(0)
//  , start_color_b(0)
//  , start_color_b_variance(0)
//  , start_color_a(0)
//  , start_color_a_variance(0)
//
//  , end_size(0)
//  , end_size_variance(0)
//  , end_spin(0)
//  , end_spin_variance(0)
//  , end_color_r(0)
//  , end_color_r_variance(0)
//  , end_color_g(0)
//  , end_color_g_variance(0)
//  , end_color_b(0)
//  , end_color_b_variance(0)
//  , end_color_a(0)
//  , end_color_a_variance(0)
//{}
//
//T_FLOAT ParticleData::CalcValueByVariance(T_FLOAT value, T_FLOAT variance, T_FLOAT min, T_FLOAT max) const
//{
//  return std::min(max, std::max(min, (T_FLOAT)(value + (((T_DOUBLE)rand() / (RAND_MAX + 1)) * variance * 2) - variance)));
//}
//
////===============================================================
//// ParticleSystem_Gravity
////===============================================================
//ParticleData_Gravity::ParticleData_Gravity()
//  : speed(0)
//  , speed_variance(0)
//  , emission_variance_x(0)
//  , emission_variance_y(0)
//  , gravity_x(0)
//  , gravity_y(0)
//  , accel_rad(0)
//  , accel_rad_variance(0)
//  , accel_tan(0)
//  , accel_tan_variance(0)
//{}
//
//void ParticleData_Gravity::OnEmission(Particle* particle, const Transform2D* offset) const
//{
//  T_FLOAT offset_x = 0;
//  T_FLOAT offset_y = 0;
//  if (offset)
//  {
//    offset_x = offset->GetX();
//    offset_y = offset->GetY();
//  }
//
//  // velocity init
//  const T_FLOAT rad = this->CalcValueByVariance(this->angle, this->angle_variance);
//  const T_FLOAT speed = this->CalcValueByVariance(this->speed, this->speed_variance) * 0.01f;
//  const T_FLOAT normal_x = cosf(rad);
//  const T_FLOAT normal_y = sinf(rad);
//  particle->SetAttributeParam(ATTR_VELOCITY_X, normal_x * speed);
//  particle->SetAttributeParam(ATTR_VELOCITY_Y, -normal_y * speed);
//
//  // accel init
//  particle->SetAttributeParam(ATTR_ACCEL_RAD, this->CalcValueByVariance(this->accel_rad, this->accel_rad_variance) * 0.0002f);
//  particle->SetAttributeParam(ATTR_ACCEL_TAN, this->CalcValueByVariance(-this->accel_tan, this->accel_tan_variance) * 0.0004f);
//
//  // emission pos init
//  const T_FLOAT pos_x = this->CalcValueByVariance(0.0f, this->emission_variance_x) * 0.5f;
//  const T_FLOAT pos_y = this->CalcValueByVariance(0.0f, this->emission_variance_y) * 0.5f;
//  particle->GetTransform()->SetPositon(offset_x + pos_x, offset_y + pos_y);
//}
//
//bool ParticleData_Gravity::OnUpdate(Particle* particle, T_FLOAT progress, T_FLOAT dp) const
//{
//  T_FLOAT accel_x = this->gravity_x * 0.0003f;
//  T_FLOAT accel_y = -this->gravity_y * 0.0003f;
//
//  const T_FLOAT accel_rad = particle->GetAttributeParam(ATTR_ACCEL_RAD);
//  const T_FLOAT accel_tan = particle->GetAttributeParam(ATTR_ACCEL_TAN);
//
//  T_FLOAT velocity_x = particle->GetAttributeParam(ATTR_VELOCITY_X);
//  T_FLOAT velocity_y = particle->GetAttributeParam(ATTR_VELOCITY_Y);
//
//  if (accel_rad != 0.0f || accel_tan != 0.0f)
//  {
//    const T_FLOAT pos_x = -particle->GetOffsetX() + particle->GetTransform()->GetX();
//    const T_FLOAT pos_y = -particle->GetOffsetY() + particle->GetTransform()->GetY();
//    T_FLOAT normal_x = 0.0f;
//    T_FLOAT normal_y = 0.0f;
//    if (pos_x != 0.0f || pos_y != 0.0f)
//    {
//      T_FLOAT length = sqrtf(pos_x * pos_x + pos_y * pos_y);
//      normal_x = pos_x / length;
//      normal_y = pos_y / length;
//    }
//    if (accel_rad != 0.0f)
//    {
//      const T_FLOAT radial_x = normal_x * accel_rad;
//      const T_FLOAT radial_y = normal_y * accel_rad;
//      accel_x += radial_x;
//      accel_y += radial_y;
//    }
//    if (accel_tan != 0.0f)
//    {
//      const T_FLOAT tangential_x = -normal_y * accel_tan;
//      const T_FLOAT tangential_y = normal_x * accel_tan;
//      accel_x += tangential_x;
//      accel_y += tangential_y;
//    }
//  }
//
//  velocity_x += accel_x;
//  velocity_y += accel_y;
//
//  particle->GetTransform()->SetX(particle->GetTransform()->GetX() + velocity_x);
//  particle->GetTransform()->SetY(particle->GetTransform()->GetY() + velocity_y);
//
//  particle->SetAttributeParam(ATTR_VELOCITY_X, velocity_x);
//  particle->SetAttributeParam(ATTR_VELOCITY_Y, velocity_y);
//
//  return progress < 1.0f;
//}
//
////===============================================================
//// ParticleSystem_Radius
////===============================================================
//ParticleData_Radius::ParticleData_Radius()
//  : max_radius(0)
//  , max_radius_variance(0)
//  , min_radius(0)
//  , rotate_per_sec(0)
//  , rotate_per_sec_variance(0)
//{}
//
//void ParticleData_Radius::OnEmission(Particle* particle, const Transform2D* offset) const
//{
//  T_FLOAT offset_x = 0;
//  T_FLOAT offset_y = 0;
//  if (offset)
//  {
//    offset_x = offset->GetX();
//    offset_y = offset->GetY();
//  }
//
//  const T_FLOAT rad = (T_FLOAT)this->CalcValueByVariance(this->angle, this->angle_variance);
//  const T_FLOAT normal_x = cosf(rad);
//  const T_FLOAT normal_y = sinf(rad);
//
//  const T_FLOAT start_radius = (T_FLOAT)this->CalcValueByVariance(this->max_radius, this->max_radius_variance);
//  const T_FLOAT end_radius = (T_FLOAT)this->min_radius;
//
//  particle->SetAttributeParam(ATTR_START_RADIUS, start_radius);
//  particle->SetAttributeParam(ATTR_END_RADIUS, end_radius);
//  particle->SetAttributeParam(ATTR_ROTATE_PER_SECOND, (T_FLOAT)MathConstants::DegToRad((T_FLOAT)this->CalcValueByVariance(this->rotate_per_sec, this->rotate_per_sec_variance)) / Director::GetFrameRate());
//  particle->SetAttributeParam(ATTR_ROTATE, rad);
//
//  particle->GetTransform()->SetPositon(offset_x + normal_x * start_radius, offset_y + normal_y * start_radius);
//}
//
//bool ParticleData_Radius::OnUpdate(Particle* particle, T_FLOAT progress, T_FLOAT dp) const
//{
//  T_FLOAT rotate = particle->GetAttributeParam(ATTR_ROTATE);
//  const T_FLOAT rotate_per_second = particle->GetAttributeParam(ATTR_ROTATE_PER_SECOND);
//  const T_FLOAT second_elapsed = dp * particle->GetLifeTime();
//  rotate += rotate_per_second * second_elapsed;
//  particle->SetAttributeParam(ATTR_ROTATE, rotate);
//
//  const T_FLOAT start_radius = particle->GetAttributeParam(ATTR_START_RADIUS);
//  const T_FLOAT end_radius = particle->GetAttributeParam(ATTR_END_RADIUS);
//  const T_FLOAT radius = this->CalcValueByProgress(start_radius, end_radius, progress);
//  const T_FLOAT x = cosf(rotate) * radius;
//  const T_FLOAT y = sinf(rotate) * radius;
//
//  particle->GetTransform()->SetPositon(x, y);
//
//  return progress < 1.0f;
//}
