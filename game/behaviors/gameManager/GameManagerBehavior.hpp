#ifndef GAMEMANAGERBEHAVIOR_HPP
#define GAMEMANAGERBEHAVIOR_HPP

#include "../../../engine/components/behaviors/Behavior.hpp"
#include <cmath>

/**
 * @class GameManagerBehavior
 * @brief The base game manager behavior
 *
 */
class GameManagerBehavior : public Behavior {
  protected:
    /**
     * @brief Calculate the difficulty at the specified game uptime
     *
     * @param timestamp The time since game start to calculate the difficulty at
     * @return The game difficulty at the specified time
     */
    float GetGameDifficultyAtTime(long long timestamp) {
        return ((float)std::sqrt(((timestamp + 10000) * 0.5) + 4000));
    }
    /**
     * @brief The time the last enemy has been spawned at
     */
    long long timeOfLastEnemy = 0;
    /**
     * @brief The delay until the next enemy will be spawned, from the last
     * enemy spawn
     */
    long long enemySpawnDelay = 3000;
    /**
     * @brief The time the last coffee has been spawned at
     */
    long long timeOfLastCoffee = 0;
    /**
     * @brief The delay until the next coffee will be spawned, from the last
     * coffee spawn
     */
    long long coffeeSpawnDelay = 3000;

    /**
     * @brief Return the velocity of an object at the current time
     *
     * @return A slightly randomized velocity of an object that should be
     * spawned.
     */
    float GetObjectVelocity();

  public:
    virtual void OnTick() override;
    virtual void OnStart() override;
};

#endif // GAMEMANAGERBEHAVIOR_HPP
