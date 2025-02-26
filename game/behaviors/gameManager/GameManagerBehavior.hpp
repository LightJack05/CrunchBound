#ifndef GAMEMANAGERBEHAVIOR_HPP
#define GAMEMANAGERBEHAVIOR_HPP

#include "../../../engine/components/behaviors/Behavior.hpp"

/**
 * @class GameManagerBehavior
 * @brief The base game manager behavior
 *
 */
class GameManagerBehavior : public Behavior {
  protected:
    /**
     * @brief The time since the game has started
     */
    long long timeSinceGameStart = 0;
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
