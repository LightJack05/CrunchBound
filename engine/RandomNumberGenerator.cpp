#include "RandomNumberGenerator.hpp"
#include <random>

/**
 * @brief The random device used for RNG
 */
static std::random_device randomDevice;
/**
 * @brief The random engine created from the randomDevice.
 */
static std::default_random_engine randomEngine(randomDevice());

int GetRandomInt(int lowerBound, int upperBound) {
    std::uniform_int_distribution<int> uniform_dist(lowerBound, upperBound);
    return uniform_dist(randomEngine);
}

float GetRandomNormalizedFloat() {
    // generate a random float between 0 and 1
    return GetRandomInt(1, 500000) / (float)500000;
}
