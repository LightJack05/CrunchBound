#include "GameManagerBehavior.hpp"
#include "../../../engine/AssetLoading.hpp"
#include "../../../engine/GameManagement.hpp"
#include "../../../engine/RandomNumberGenerator.hpp"
#include "../../../engine/Time.hpp"
#include "../../../engine/components/behaviors/KinematicBehavior.hpp"
#include "../../../engine/components/renderers/TextureRenderer.hpp"
#include "../coffee/CoffeeBehavior.hpp"
#include "../coffee/CoffeeCollisionBehavior.hpp"
#include "../enemy/EnemyBehavior.hpp"
#include "../enemy/EnemyCollisionBehavior.hpp"
#include <cmath>
#include <iostream>
#include <memory>

/**
 * @brief The time since the game has started
 */
static long long TimeSinceGameStart = 0;
/**
 * @brief The time the last enemy has been spawned at
 */
static long long TimeOfLastEnemy = 0;
/**
 * @brief The delay until the next enemy will be spawned, from the last enemy
 * spawn
 */
static long long EnemySpawnDelay = 3000;
/**
 * @brief The time the last coffee has been spawned at
 */
static long long TimeOfLastCoffee = 0;
/**
 * @brief The delay until the next coffee will be spawned, from the last coffee
 * spawn
 */
static long long CoffeeSpawnDelay = 3000;

/**
 * @brief Calculate the difficulty at the specified game uptime
 *
 * @param timestamp The time since game start to calculate the difficulty at
 * @return The game difficulty at the specified time
 */
static inline float GetGameDifficultyAtTime(long long timestamp) {
    return ((float)std::sqrt(((timestamp + 10000) * 0.5) + 4000));
}

/**
 * @brief Return the velocity of an object at the current time
 *
 * @return A slightly randomized velocity of an object that should be spawned.
 */
static float GetObjectVelocity() {
    return (GetGameDifficultyAtTime(TimeSinceGameStart) / 300) *
           (0.5 + GetRandomNormalizedFloat());
}

/**
 * @brief Spawn a new coffee object.
 *
 * @param velocityX The velocity the coffee should have
 */
static void SpawnCoffee(float velocityX) {
    std::shared_ptr<GameObject> coffee = std::make_shared<GameObject>();
    coffee->setTag("coffee");
    coffee->setPosition(std::make_shared<Vector2>(
        2000, (GetRandomNormalizedFloat() * 350) + 700));

    std::shared_ptr<CoffeeCollisionBehavior> coffeeCollider =
        std::make_shared<CoffeeCollisionBehavior>(64, 64);
    coffee->RegisterComponent(coffeeCollider);

    std::shared_ptr<CoffeeBehavior> coffeeBehavior =
        std::make_shared<CoffeeBehavior>();
    coffee->RegisterComponent(coffeeBehavior);

    std::shared_ptr<TextureRenderer> coffeeRenderer =
        std::make_shared<TextureRenderer>(
            64, 64, GetAssetPath("textures/objects/coffee_paper_cup.png"));
    coffee->RegisterComponent(coffeeRenderer);

    std::shared_ptr<KinematicBehavior> coffeeKinematics =
        std::make_shared<KinematicBehavior>();
    coffee->RegisterComponent(coffeeKinematics);

    coffee->getVelocity()->setX(-velocityX);

    EnqueueRegisterGameObject(coffee);
}

/**
 * @brief Spawn a new enemy
 *
 * @param velocityX The velocity of the new enemy
 */
static void SpawnEnemy(float velocityX) {
    std::shared_ptr<GameObject> enemy = std::make_shared<GameObject>();
    enemy->setTag("enemy");
    enemy->setPosition(std::make_shared<Vector2>(
        2000, (GetRandomNormalizedFloat() * 350) + 700));

    std::shared_ptr<EnemyCollisionBehavior> enemyCollider =
        std::make_shared<EnemyCollisionBehavior>(64, 64);
    enemy->RegisterComponent(enemyCollider);

    std::shared_ptr<EnemyBehavior> enemyBehavior =
        std::make_shared<EnemyBehavior>();
    enemy->RegisterComponent(enemyBehavior);

    std::shared_ptr<TextureRenderer> enemyRenderer =
        std::make_shared<TextureRenderer>(
            64, 64, GetAssetPath("textures/objects/bug.png"));
    enemy->RegisterComponent(enemyRenderer);

    std::shared_ptr<KinematicBehavior> enemyKinematics =
        std::make_shared<KinematicBehavior>();
    enemy->RegisterComponent(enemyKinematics);

    enemy->getVelocity()->setX(-velocityX);

    EnqueueRegisterGameObject(enemy);
}

void GameManagerBehavior::OnTick() {
    TimeSinceGameStart += GetDeltaTime();
    if (TimeSinceGameStart - TimeOfLastEnemy > EnemySpawnDelay) {
        SpawnEnemy(GetObjectVelocity());
        TimeOfLastEnemy = TimeSinceGameStart;
        EnemySpawnDelay = (GetRandomInt(2000, 7000) /
                           GetGameDifficultyAtTime(TimeSinceGameStart)) *
                          50;
    }
    if (TimeSinceGameStart - TimeOfLastCoffee > CoffeeSpawnDelay) {
        SpawnCoffee(GetObjectVelocity());
        TimeOfLastCoffee = TimeSinceGameStart;
        CoffeeSpawnDelay = (GetRandomInt(15000, 20000) /
                            GetGameDifficultyAtTime(TimeSinceGameStart)) *
                           50;
    }
}

void GameManagerBehavior::OnStart() {
    TimeSinceGameStart = 0;
    TimeOfLastEnemy = 0;
    TimeOfLastCoffee = 0;
}
