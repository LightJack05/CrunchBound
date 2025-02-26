#ifndef OBJECTSPAWNING_HPP
#define OBJECTSPAWNING_HPP

#include <cmath>

/**
 * @brief Calculate the difficulty at the specified game uptime
 *
 * @param timestamp The time since game start to calculate the difficulty at
 * @return The game difficulty at the specified time
 */
inline float GetGameDifficultyAtTime(long long timestamp) {
    return ((float)std::sqrt(((timestamp + 10000) * 0.5) + 4000));
}
/**
 * @brief Spawn a new coffee object.
 *
 * @param velocityX The velocity the coffee should have
 */
void SpawnCoffee(float velocityX);
/**
 * @brief Spawn a new enemy
 *
 * @param velocityX The velocity of the new enemy
 */
void SpawnEnemy(float velocityX);

#endif // OBJECTSPAWNING_HPP
