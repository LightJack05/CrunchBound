#ifndef ASSETLOADING_HPP
#define ASSETLOADING_HPP

#include <string>
/**
 * @brief Return the correct asset path for the asset depending on the current environment
 *
 * @param basePath The base path of the asset inside the assets/ folder
 */
std::string GetAssetPath(std::string basePath);

#endif // ASSETLOADING_HPP
