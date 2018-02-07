#include "SpineResource.h"
#include "UserResourcePool.h"

const SpineResource* SpineResource::DynamicLoad(const char* path)
{
  return UserResourcePool::GetInstance().DynamicLoad<SpineResource>(path);
}

SpineResource::SpineResource(const char* path)
  : FileResource("SpineData", path)
{
}

SpineData* SpineResource::NativeLoadProcess(const std::string& path)
{
  return SpineData::CreateFromFile(path.c_str());
}
