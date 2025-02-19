#include "Init.hpp"
#include "../engine/GameManagement.hpp"
#include "../engine/GameObject.hpp"
#include "../engine/components/behaviors/GravityBehavior.hpp"
#include "../engine/components/behaviors/KinematicBehavior.hpp"
#include "../engine/components/renderers/RectangleRenderer.hpp"
#include "behaviors/enemy/EnemyCollisionBehavior.hpp"
#include "behaviors/gameManager/GameManagerKeyboardHandler.hpp"
#include "behaviors/player/PlayerBehavior.hpp"
#include "behaviors/player/PlayerCollisionBehavior.hpp"
#include "behaviors/player/PlayerKeyboardBehavior.hpp"
#include <iostream>
#include <memory>

static void SpawnPlayer() {
    std::shared_ptr<GameObject> player = std::make_shared<GameObject>();
    player->setPosition(std::make_shared<Vector2>(100, 200));
    player->setTag("player");
    std::shared_ptr<KinematicBehavior> playerKinematic =
        std::make_shared<KinematicBehavior>();
    player->RegisterComponent(playerKinematic);
    std::shared_ptr<RectangleRenderer> playerRenderer =
        std::make_shared<RectangleRenderer>(100, 300);
    player->RegisterComponent(playerRenderer);
    std::shared_ptr<PlayerCollisionBehavior> playerCollider =
        std::make_shared<PlayerCollisionBehavior>(100, 300);
    player->RegisterComponent(playerCollider);
    std::shared_ptr<GravityBehavior> playerGravity =
        std::make_shared<GravityBehavior>();
    player->RegisterComponent(playerGravity);
    std::shared_ptr<PlayerBehavior> playerBehavior =
        std::make_shared<PlayerBehavior>();
    player->RegisterComponent(playerBehavior);
    std::shared_ptr<PlayerKeyboardBehavior> playerKeyboardBehavior =
        std::make_shared<PlayerKeyboardBehavior>();
    player->RegisterComponent(playerKeyboardBehavior);

    RegisterGameObject(player);
}

static void CreateFloor() {
    std::shared_ptr<GameObject> floor = std::make_shared<GameObject>();
    floor->setPosition(std::make_shared<Vector2>(0, ScreenHeight - 50));
    std::shared_ptr<RectangleRenderer> floorRenderer =
        std::make_shared<RectangleRenderer>(ScreenWidth, 50);
    floorRenderer->setColor(0, 255, 0, 255);
    floor->RegisterComponent(floorRenderer);
    std::shared_ptr<CollisionBehavior> floorCollider =
        std::make_shared<CollisionBehavior>(ScreenWidth, 50);
    floor->RegisterComponent(floorCollider);
    floor->setTag("floor");

    RegisterGameObject(floor);
}

static void SetupWindowbackground() {
    WindowBackgroundColor.r = 255;
    WindowBackgroundColor.b = 255;
    WindowBackgroundColor.g = 255;
    WindowBackgroundColor.a = 255;
}

static void SpawnEnemy() {
    std::shared_ptr<GameObject> enemy1 = std::make_shared<GameObject>();
    enemy1->setTag("enemy");
    enemy1->setPosition(std::make_shared<Vector2>(900, 900));
    std::shared_ptr<EnemyCollisionBehavior> enemy1Collider =
        std::make_shared<EnemyCollisionBehavior>(100, 100);
    enemy1->RegisterComponent(enemy1Collider);

    std::shared_ptr<RectangleRenderer> enemy1Renderer =
        std::make_shared<RectangleRenderer>(100, 100);
    enemy1Renderer->setColor(255, 0, 0, 255);
    enemy1->RegisterComponent(enemy1Renderer);

    std::shared_ptr<KinematicBehavior> enemy1Kinematics =
        std::make_shared<KinematicBehavior>();
    enemy1->RegisterComponent(enemy1Kinematics);

    enemy1->getVelocity()->setX(-0.3);

    RegisterGameObject(enemy1);
}

static void CreateGameManager() {
    std::shared_ptr<GameObject> gameManager = std::make_shared<GameObject>();

    std::shared_ptr<GameManagerKeyboardBehavior> gmKeyboard =
        std::make_shared<GameManagerKeyboardBehavior>();
    gameManager->RegisterComponent(gmKeyboard);

    GameManager = gameManager;
}

static void CreateInitialGameObjects() {
    GameObjects.push_back(GameManager);
    SetupWindowbackground();
    SpawnEnemy();

    CreateFloor();
    SpawnPlayer();
}

void InitializeGame() {
    CreateGameManager();

    CreateInitialGameObjects();
}

void ResetGame() {
    std::cout << "Reset!" << std::endl;
    GameObjects.clear();
    CreateInitialGameObjects();
}
