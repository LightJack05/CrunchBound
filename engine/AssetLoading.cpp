#include "AssetLoading.hpp"
#include <string>

// The local path to the assets folder
static const std::string LocalAssetPath = "assets/";
// The path to the assets folder when installed on a Linux system
static const std::string InstalledAssetPath = "/usr/share/crunchbound/assets/";
// The APPDIR environment variable gets set by an AppImage. An appimage has a
// filestructure emulating a Linux system, and therefore this variable must be
// inserted before the installed path.
static const char *appdir = std::getenv("APPDIR");

std::string GetAssetPath(std::string basePath) {
    // If the DEVELOPMENT macro is defined, we are in development, and load
    // assets from the local folder
#ifdef DEVELOPMENT
    return LocalAssetPath + basePath;
#else
    // Otherwise, we have an installed version, or are running in an appimage.
    // If the AppDir is not set, ignore it, otherwise prepend it to the path.
    return std::string(appdir ?: "") + InstalledAssetPath + basePath;
#endif // DEVELOPMENT
}
