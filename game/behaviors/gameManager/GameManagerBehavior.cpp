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
    if (GetTimeSinceGameStart() - timeOfLastEnemy > enemySpawnDelay) {
        SpawnEnemy(GetObjectVelocity());
        timeOfLastEnemy = GetTimeSinceGameStart();
        enemySpawnDelay = (GetRandomInt(2000, 7000) /
                           GetGameDifficultyAtTime(GetTimeSinceGameStart())) *
                          50;
    }
    if (GetTimeSinceGameStart() - timeOfLastCoffee > coffeeSpawnDelay) {
        SpawnCoffee(GetObjectVelocity());
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
