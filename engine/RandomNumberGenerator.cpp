#include "RandomNumberGenerator.hpp"
#include <random>

static std::random_device randomDevice;
static std::default_random_engine randomEngine(randomDevice());

int GetRandomInt(int lowerBound, int upperBound) {
    std::uniform_int_distribution<int> uniform_dist(lowerBound, upperBound);
    return uniform_dist(randomEngine);
}

float GetRandomNormalizedFloat() {
    return GetRandomInt(1, 500000) / (float)500000;
}
