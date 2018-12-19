#pragma once

#include <Util/FileUtil.h>

#include <Cereal/cereal.hpp>
#include <Cereal/archives/json.hpp>
#include <Cereal/types/string.hpp>
#include <Cereal/types/unordered_set.hpp>
#include <Cereal/types/utility.hpp>

#include "URI.h"

class AssetConverterContext;

class AssetMetaData
{
  // =================================================================
  // Factory Method
  // =================================================================
public:
  static AssetMetaData* Create(const URI& uri, AssetConverterContext* context);
  static AssetMetaData* Create(const URI& uri, T_UINT32 source_unique_id, AssetConverterContext* context);

  // =================================================================
  // Constructor / Destructor
  // =================================================================
public:
  AssetMetaData(const URI& uri, T_UINT32 source_unique_id, AssetConverterContext* context);
  AssetMetaData() = default;

  // =================================================================
  // Methods
  // =================================================================
public:
  void Save();

  AssetMetaData* CreateChild(const std::string& child_path, AssetConverterContext* context);

  void ResetTimeStamp();
  bool UpdateTimeStamp();

  // =================================================================
  // Setter / Getter
  // =================================================================
public:
  inline T_UINT32 GetUniqueID() const
  {
    return this->unique_id_;
  }

  inline T_UINT32 GetSourceUniqueId() const
  {
    return this->source_unique_id_;
  }

  inline const std::string& GetTimeStamp() const
  {
    return this->time_stamp_;
  }

  inline const URI& GetURI() const
  {
    return this->uri_;
  }

  inline std::string GetInputPath() const
  {
    return FileUtil::CreateInputPath(this->GetURI());
  }
  
  inline std::string GetInputDirectoryPath() const
  {
    return FileUtil::CreateInputDirectoryPath(this->GetURI());
  }

  inline std::string GetOutputPath() const
  {
    return FileUtil::CreateArchivePath(this);
  }

  // =================================================================
  // Serialize Method
  // =================================================================
public:
  template<class Archive>
  void serialize(Archive& ar, std::uint32_t const version)
  {
    ar(CEREAL_NVP(uri_));
    ar(CEREAL_NVP(unique_id_));
    ar(CEREAL_NVP(source_unique_id_));
    ar(CEREAL_NVP(related_unique_ids_));
    ar(CEREAL_NVP(time_stamp_));
  }

  // =================================================================
  // Data Members
  // =================================================================
private:
  URI uri_;
  T_UINT32 unique_id_;
  T_UINT32 source_unique_id_;
  std::unordered_set<T_UINT32> related_unique_ids_;

  std::string time_stamp_;

};
