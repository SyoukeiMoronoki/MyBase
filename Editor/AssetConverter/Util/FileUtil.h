#pragma once

#include <string>
#include <functional>

class URI;
class AssetMetaData;

namespace FileUtil
{

void PrepareDefaultDirectories();
void PrepareDirectory(const URI& uri);

const std::string& GetInputPath();
const std::string& GetCachePath();

std::string GetSettingPath();
std::string GetMidDataUniqueIdTablePath();
std::string GetArchiveUniqueIdTablePath();

std::string CreateFileName(const std::string& path, const std::string& extension);
std::string CreateProjectFilePath(const std::string& path);
std::string CreateInputPath(const URI& uri);
std::string CreateInputDirectoryPath(const URI& uri);
std::string CreateSettingPath(const URI& uri);
std::string CreateCachePath(const URI& uri);
std::string CreateArchivePath(const AssetMetaData* meta_data);
std::string CreateOutputPath(const std::string& filename);
std::string CreateRuntimeAssetPath(const URI& uri);
std::string CreateSolutionPath(const std::string& path);

void CopyRawAsset(const AssetMetaData* meta_data);

std::string GetTimeStamp(const std::string& path);

void CrawlInputDirectory(std::function<void(const URI& uri)> process);
void CrawlCacheDirectory(std::function<void(const URI& uri)> process);

}