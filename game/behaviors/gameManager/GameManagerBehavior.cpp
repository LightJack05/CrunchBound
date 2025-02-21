#include "GameManagerBehavior.hpp"
#include "../../../engine/GameManagement.hpp"
#include "../../../engine/RandomNumberGenerator.hpp"
#include "../../../engine/Time.hpp"
#include "../../../engine/components/behaviors/KinematicBehavior.hpp"
#include "../../../engine/components/renderers/RectangleRenderer.hpp"
#include "../enemy/EnemyCollisionBehavior.hpp"
#include <cmath>
#include <iostream>

static long long TimeSinceGameStart = 0;
static long long TimeOfLastEnemy = 0;
static long long EnemySpawnDelay = 3000;

static inline float GetGameDifficultyAtTime(long long timestamp) {
    return ((float)std::sqrt(((timestamp + 10000) * 0.5) + 4000));
}

static float GetEnemyVelocity() {
    return (GetGameDifficultyAtTime(TimeSinceGameStart) / 300) *
           (0.5 + GetRandomNormalizedFloat());
}

static void SpawnEnemy(float velocityX) {
    std::shared_ptr<GameObject> enemy = std::make_shared<GameObject>();
    enemy->setTag("enemy");
    enemy->setPosition(std::make_shared<Vector2>(
        2000, (GetRandomNormalizedFloat() * 20) + 990));
    std::shared_ptr<EnemyCollisionBehavior> enemyCollider =
        std::make_shared<EnemyCollisionBehavior>(15, 15);
    enemy->RegisterComponent(enemyCollider);

    std::shared_ptr<RectangleRenderer> enemyRenderer =
        std::make_shared<RectangleRenderer>(15, 15);
    enemyRenderer->setColor(255, 0, 0, 255);
    enemy->RegisterComponent(enemyRenderer);

    std::shared_ptr<KinematicBehavior> enemyKinematics =
        std::make_shared<KinematicBehavior>();
    enemy->RegisterComponent(enemyKinematics);

    enemy->getVelocity()->setX(-velocityX);
    std::cout << "Spawning enemy " << enemy << " with velocity " << velocityX
              << " at " << TimeSinceGameStart << std::endl;

    EnqueueRegisterGameObject(enemy);
}

void GameManagerBehavior::OnTick() {
    TimeSinceGameStart += GetDeltaTime();
    if (TimeSinceGameStart - TimeOfLastEnemy > EnemySpawnDelay) {
        SpawnEnemy(GetEnemyVelocity());
        TimeOfLastEnemy = TimeSinceGameStart;
        EnemySpawnDelay = (GetRandomInt(2000, 7000) /
                           GetGameDifficultyAtTime(TimeSinceGameStart)) *
                          50;
    }
}

void GameManagerBehavior::OnStart() {
    TimeSinceGameStart = 0;
    TimeOfLastEnemy = 0;
}
