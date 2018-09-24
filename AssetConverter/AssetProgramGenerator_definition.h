#pragma once

#include <string>

#include "AssetInfo.h"

class DefinitionGenerator
{
public:
  DefinitionGenerator(const std::string& asset_name, const std::string& class_name);
  ~DefinitionGenerator();

public:
  std::string CreateHeaderProgram(const AssetInfo* info) const;
  std::string CreateCppProgram(const AssetInfo* info) const;
  std::string CreateTypeName() const;
  std::string CreateTypeNameAlias() const;
  std::string CreateContainerNameAlias() const;

public:
  inline const std::string& GetAssetName() const
  {
    return this->asset_name_;
  }

  inline const std::string& GetClassName() const
  {
    return this->class_name_;
  }

private:
  std::string asset_name_;
  std::string class_name_;
};

