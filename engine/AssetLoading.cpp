#include "AssetLoading.hpp"
#include <string>

static const std::string LocalAssetPath = "assets/";
static const std::string InstalledAssetPath = "/usr/share/crunchbound/assets/";
static const char *appdir = std::getenv("APPDIR");

std::string GetAssetPath(std::string basePath) {
#ifdef DEVELOPMENT
    return LocalAssetPath + basePath;
#else
    return std::string(appdir ?: "") + InstalledAssetPath + basePath;
#endif // DEVELOPMENT
}
