#include "GameManagerBehavior.hpp"
#include "../../../engine/AssetLoading.hpp"
#include "../../../engine/GameManagement.hpp"
#include "../../../engine/RandomNumberGenerator.hpp"
#include "../../../engine/Time.hpp"
#include "../../../engine/components/behaviors/KinematicBehavior.hpp"
#include "../../../engine/components/renderers/TextureRenderer.hpp"
#include "../enemy/EnemyBehavior.hpp"
#include "../enemy/EnemyCollisionBehavior.hpp"
#include <cmath>
#include <iostream>
#include <memory>

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
        2000, (GetRandomNormalizedFloat() * 200) + 900));

    std::shared_ptr<EnemyCollisionBehavior> enemyCollider =
        std::make_shared<EnemyCollisionBehavior>(15, 15);
    enemy->RegisterComponent(enemyCollider);

    std::shared_ptr<EnemyBehavior> enemyBehavior =
        std::make_shared<EnemyBehavior>();
    enemy->RegisterComponent(enemyBehavior);

    std::shared_ptr<TextureRenderer> enemyRenderer =
        std::make_shared<TextureRenderer>(
            32, 32, GetAssetPath("textures/objects/bug.png"));
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
