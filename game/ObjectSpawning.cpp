#include "ObjectSpawning.hpp"
#include "../engine/AssetLoading.hpp"
#include "../engine/ObjectManagement.hpp"
#include "../engine/RandomNumberGenerator.hpp"
#include "../engine/components/behaviors/KinematicBehavior.hpp"
#include "../engine/components/renderers/TextureRenderer.hpp"
#include "behaviors/coffee/CoffeeBehavior.hpp"
#include "behaviors/coffee/CoffeeCollisionBehavior.hpp"
#include "behaviors/enemy/EnemyBehavior.hpp"
#include "behaviors/enemy/EnemyCollisionBehavior.hpp"
#include <cmath>
#include <memory>

void SpawnCoffee(float velocityX) {
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
            64, 64, "textures/objects/coffee_paper_cup.png");
    coffee->RegisterComponent(coffeeRenderer);

    std::shared_ptr<KinematicBehavior> coffeeKinematics =
        std::make_shared<KinematicBehavior>();
    coffee->RegisterComponent(coffeeKinematics);

    coffee->getVelocity()->setX(-velocityX);

    EnqueueRegisterGameObject(coffee);
}

void SpawnEnemy(float velocityX) {
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
        std::make_shared<TextureRenderer>(64, 64, "textures/objects/bug.png");
    enemy->RegisterComponent(enemyRenderer);

    std::shared_ptr<KinematicBehavior> enemyKinematics =
        std::make_shared<KinematicBehavior>();
    enemy->RegisterComponent(enemyKinematics);

    enemy->getVelocity()->setX(-velocityX);

    EnqueueRegisterGameObject(enemy);
}
