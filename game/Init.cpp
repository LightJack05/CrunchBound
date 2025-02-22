#include "Init.hpp"
#include "../engine/GameManagement.hpp"
#include "../engine/GameObject.hpp"
#include "../engine/components/behaviors/GravityBehavior.hpp"
#include "../engine/components/behaviors/KinematicBehavior.hpp"
#include "../engine/components/renderers/FontRenderer.hpp"
#include "../engine/components/renderers/RectangleRenderer.hpp"
#include "behaviors/gameManager/GameManagerBehavior.hpp"
#include "behaviors/gameManager/GameManagerKeyboardHandler.hpp"
#include "behaviors/player/PlayerBehavior.hpp"
#include "behaviors/player/PlayerCollisionBehavior.hpp"
#include "behaviors/player/PlayerKeyboardBehavior.hpp"
#include "behaviors/scoreCounter/ScoreCounterBehavior.hpp"
#include <memory>

static const int PlayerHeight = 150;
static const int PlayerWidth = 50;

/**
 * @brief Create the score counter and register it.
 */
static void CreateScoreCounter() {
    std::shared_ptr<GameObject> scoreCounter = std::make_shared<GameObject>();
    scoreCounter->setPosition(std::make_shared<Vector2>(10, 10));
    std::shared_ptr<ScoreCounterBehavior> scoreCounterBehavior =
        std::make_shared<ScoreCounterBehavior>();
    scoreCounter->RegisterComponent(scoreCounterBehavior);

    std::shared_ptr<FontRenderer> scoreRenderer =
        std::make_shared<FontRenderer>("fonts/RobotoMono-Regular.ttf", 500);
    scoreCounter->RegisterComponent(scoreRenderer);

    RegisterGameObject(scoreCounter);
}

/**
 * @brief Create the left wall and register it.
 */
static void SpawnLeftWall() {
    std::shared_ptr<GameObject> leftWall = std::make_shared<GameObject>();
    leftWall->setTag("left-wall");
    leftWall->setPosition(std::make_shared<Vector2>(-80, -80));
    std::shared_ptr<CollisionBehavior> leftWallCollider =
        std::make_shared<CollisionBehavior>(80, ScreenHeight + 80);
    leftWall->RegisterComponent(leftWallCollider);

    RegisterGameObject(leftWall);
}
/**
 * @brief Create the right wall and register it.
 */
static void SpawnRightWall() {
    std::shared_ptr<GameObject> rightWall = std::make_shared<GameObject>();
    rightWall->setTag("right-wall");
    rightWall->setPosition(std::make_shared<Vector2>(ScreenWidth + 1, -80));
    std::shared_ptr<CollisionBehavior> rightWallCollider =
        std::make_shared<CollisionBehavior>(80, ScreenHeight + 80);
    rightWall->RegisterComponent(rightWallCollider);

    RegisterGameObject(rightWall);
}

/**
 * @brief Create the player and register it.
 */
static void SpawnPlayer() {
    std::shared_ptr<GameObject> player = std::make_shared<GameObject>();
    player->setPosition(std::make_shared<Vector2>(100, 200));
    player->setTag("player");

    std::shared_ptr<KinematicBehavior> playerKinematic =
        std::make_shared<KinematicBehavior>();
    player->RegisterComponent(playerKinematic);

    std::shared_ptr<RectangleRenderer> playerRenderer =
        std::make_shared<RectangleRenderer>(PlayerWidth, PlayerHeight);
    player->RegisterComponent(playerRenderer);

    std::shared_ptr<PlayerCollisionBehavior> playerCollider =
        std::make_shared<PlayerCollisionBehavior>(PlayerWidth, PlayerHeight);
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

/**
 * @brief Create the floor and register it.
 */
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

/**
 * @brief Set the window background to white.
 */
static void SetupWindowbackground() {
    WindowBackgroundColor.r = 255;
    WindowBackgroundColor.b = 255;
    WindowBackgroundColor.g = 255;
    WindowBackgroundColor.a = 255;
}

/**
 * @brief Create the game manager object and register it.
 */
void CreateGameManager() {
    std::shared_ptr<GameObject> gameManager = std::make_shared<GameObject>();
    gameManager->setTag("GameManager");

    std::shared_ptr<GameManagerKeyboardBehavior> gmKeyboard =
        std::make_shared<GameManagerKeyboardBehavior>();
    gameManager->RegisterComponent(gmKeyboard);

    std::shared_ptr<GameManagerBehavior> gbBehavior =
        std::make_shared<GameManagerBehavior>();
    gameManager->RegisterComponent(gbBehavior);

    GameManager = gameManager;
}

void CreateInitialGameObjects() {
    GameObjects.push_back(GameManager);
    SetupWindowbackground();
    CreateFloor();
    SpawnPlayer();
    SpawnLeftWall();
    SpawnRightWall();
    CreateScoreCounter();
}
