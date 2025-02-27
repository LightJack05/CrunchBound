#include "GameManagerBehavior.hpp"
#include "../../../engine/RandomNumberGenerator.hpp"
#include "../../../engine/Time.hpp"
#include "../../ObjectSpawning.hpp"
#include <cmath>

/**
 * @brief Return the velocity of an object at the current time
 *
 * @return A slightly randomized velocity of an object that should be spawned.
 */
float GameManagerBehavior::GetObjectVelocity() {
    return (GetGameDifficultyAtTime(GetTimeSinceGameStart()) / 300) *
           (0.5 + GetRandomNormalizedFloat());
}

void GameManagerBehavior::OnTick() {
    // If it is time to spawn a new enemy, do so.
    if (GetTimeSinceGameStart() - timeOfLastEnemy > enemySpawnDelay) {
        SpawnEnemy(GetObjectVelocity());
        timeOfLastEnemy = GetTimeSinceGameStart();
        enemySpawnDelay = (GetRandomInt(2000, 7000) /
                           GetGameDifficultyAtTime(GetTimeSinceGameStart())) *
                          50;
    }
    // If it is time to spawn a new coffee, do so.
    if (GetTimeSinceGameStart() - timeOfLastCoffee > coffeeSpawnDelay) {
        SpawnCoffee(GetObjectVelocity());
        // Set the time of the last coffee to now, and generate a new random
        // spawn delay, based on the difficulty curve.
        timeOfLastCoffee = GetTimeSinceGameStart();
        coffeeSpawnDelay = (GetRandomInt(15000, 20000) /
                            GetGameDifficultyAtTime(GetTimeSinceGameStart())) *
                           50;
    }
}

void GameManagerBehavior::OnStart() {
    timeOfLastEnemy = 0;
    timeOfLastCoffee = 0;
}
