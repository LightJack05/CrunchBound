#include "GameManagerBehavior.hpp"
#include "../../../engine/GameManagement.hpp"
#include "../../../engine/Time.hpp"
#include "../../../engine/components/behaviors/KinematicBehavior.hpp"
#include "../../../engine/components/renderers/RectangleRenderer.hpp"
#include "../enemy/EnemyCollisionBehavior.hpp"
#include <cmath>
#include <iostream>

static long long TimeSinceGameStart = 0;
static long long TimeOfLastEnemy = 0;

static inline float GetEnemyVelocityAtTime(long long timestamp) {
    return ((float)std::sqrt(timestamp + 4000)) / 300;
}

static void SpawnEnemy(float velocityX) {
    std::shared_ptr<GameObject> enemy = std::make_shared<GameObject>();
    enemy->setTag("enemy");
    enemy->setPosition(std::make_shared<Vector2>(2000, 900));
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
    std::cout << "Spawning enemy " << enemy << " with velocity " << velocityX << " at " << TimeSinceGameStart << std::endl;

    EnqueueRegisterGameObject(enemy);
}

void GameManagerBehavior::OnTick() {
    TimeSinceGameStart += GetDeltaTime();
    if (TimeSinceGameStart - TimeOfLastEnemy > 5000) {
        SpawnEnemy(GetEnemyVelocityAtTime(TimeSinceGameStart));
        TimeOfLastEnemy = TimeSinceGameStart;
    }
}

void GameManagerBehavior::OnStart() {
    TimeSinceGameStart = 0;
    TimeOfLastEnemy = 0;
}
