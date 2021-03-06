#include <Util/FileUtil.h>

#define NOMINMAX
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <direct.h>

#include <ToolUtil.h>

#include <Entity/AssetMetaData.h>
#include <Setting/Setting.h>
#include <Util/Logger.h>

static const std::string SETTING_FILE_NAME = "ConvertSetting.json";

static const std::string CURRENT_DIRECTORY = "../";

static const std::string PROJECT_PATH = CURRENT_DIRECTORY + "Project";
static const std::string ASSET_PATH = CURRENT_DIRECTORY + "Asset";
static const std::string RUNTIME_DIRECTORY_PATH = CURRENT_DIRECTORY + "Game";

static const std::string INPUT_PATH = ASSET_PATH + "/Raw";
static const std::string MIDDATA_PATH = ASSET_PATH + "/Cache";
static const std::string ARCHIVE_PATH = ASSET_PATH + "/Archive";
static const std::string SETTING_PATH = ASSET_PATH + "/Setting";

void FileUtil::PrepareDefaultDirectories()
{
  _mkdir(PROJECT_PATH.c_str());
  _mkdir(ASSET_PATH.c_str());
  _mkdir(INPUT_PATH.c_str());
  _mkdir(MIDDATA_PATH.c_str());
  _mkdir(ARCHIVE_PATH.c_str());
  _mkdir(SETTING_PATH.c_str());
  _mkdir(RUNTIME_DIRECTORY_PATH.c_str());
  _mkdir((RUNTIME_DIRECTORY_PATH + "/" + Directory::GetAssetDirectory()).c_str());
}

void FileUtil::PrepareDirectory(const URI& uri)
{
  if (uri.GetFullPath().length() == 0)
  {
    return;
  }
  FileUtil::PrepareDirectory(uri.GetDirectoryPath());
  if (uri.GetExtension().length() == 0)
  {
    _mkdir(uri.GetFullPath().c_str());
  }
}

const std::string& FileUtil::GetInputPath()
{
  return INPUT_PATH;
}

const std::string& FileUtil::GetCachePath()
{
  return MIDDATA_PATH;
}

std::string FileUtil::GetSettingPath()
{
  return CreateSettingPath(SETTING_FILE_NAME);
}

std::string FileUtil::GetMidDataUniqueIdTablePath()
{
  return CreateSettingPath(Directory::GetUniqueIdTableFileName("json"));
}

std::string FileUtil::GetArchiveUniqueIdTablePath()
{
  return Directory::GetArchiveUniqueIdTablePath();
}

std::string FileUtil::CreateFileName(const std::string& path, const std::string& extension)
{
  return path + "." + extension;
}

std::string FileUtil::CreateProjectFilePath(const std::string& path)
{
  return PROJECT_PATH + "/" + path;
}

std::string FileUtil::CreateInputPath(const URI& uri)
{
  return INPUT_PATH + "/" + uri.GetFullPath();
}

std::string FileUtil::CreateInputDirectoryPath(const URI& uri)
{
  return INPUT_PATH + "/" + uri.GetDirectoryPath();
}

std::string FileUtil::CreateSettingPath(const URI& uri)
{
  return SETTING_PATH + "/" + uri.GetFullPath();
}

std::string FileUtil::CreateCachePath(const URI & uri)
{
  return MIDDATA_PATH + "/" + uri.GetFullPath() + ".cache";
}

std::string FileUtil::CreateArchivePath(const AssetMetaData* meta_data)
{
  //return ARCHIVE_PATH + "/" + std::to_string(meta->GetUniqueID()) + "." + meta->GetURI().GetExtension();
  return RUNTIME_DIRECTORY_PATH + "/" + Directory::CreateArchivePath(std::to_string(meta_data->GetUniqueID()) + "." + meta_data->GetURI().GetExtension());
}

std::string FileUtil::CreateOutputPath(const std::string& filename)
{
  //return ARCHIVE_PATH + "/" + std::to_string(meta->GetUniqueID()) + "." + meta->GetURI().GetExtension();
  return RUNTIME_DIRECTORY_PATH + "/" + filename;
}

std::string FileUtil::CreateRuntimeAssetPath(const URI& uri)
{
  return uri.GetFullPath();
}

std::string FileUtil::CreateSolutionPath(const std::string& path)
{
  return path.substr(CURRENT_DIRECTORY.size(), path.size() - CURRENT_DIRECTORY.size());
}

void FileUtil::CopyRawAsset(const AssetMetaData* meta_data)
{
  HRESULT hr = CopyFile(
    meta_data->GetInputPath().c_str(),
    meta_data->GetOutputPath().c_str(),
    false
  );
  GG_ASSERT(SUCCEEDED(hr), "コピーに失敗しました");
  Logger::CopyAssetLog(meta_data);
}

std::string FileUtil::GetTimeStamp(const std::string& path)
{
  HANDLE source_file = CreateFile(path.c_str(), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
  FILETIME ft;
  SYSTEMTIME st;
  GetFileTime(source_file, NULL, NULL, &ft);
  CloseHandle(source_file);
  FileTimeToSystemTime(&ft, &st);

  std::string ret = std::string();
  ret.append(std::to_string(st.wYear));
  ret.append("/");
  ret.append(std::to_string(st.wMonth));
  ret.append("/");
  ret.append(std::to_string(st.wDay));
  ret.append(" ");
  ret.append(std::to_string(st.wHour));
  ret.append(":");
  ret.append(std::to_string(st.wMinute));
  ret.append(":");
  ret.append(std::to_string(st.wSecond));
  return ret;
}

void FileUtil::CrawlInputDirectory(std::function<void(const URI& uri)> process)
{
  ToolUtil::Crawl(INPUT_PATH + "/", "", process);
}

void FileUtil::CrawlCacheDirectory(std::function<void(const URI&uri)> process)
{
  ToolUtil::Crawl(MIDDATA_PATH + "/", "", process);
}
