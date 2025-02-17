#include "Init.hpp"
#include "../engine/GameManagement.hpp"
#include "../engine/GameObject.hpp"
#include "../engine/components/behaviors/GravityBehavior.hpp"
#include "../engine/components/renderers/RectangleRenderer.hpp"
#include "../engine/components/behaviors/KinematicBehavior.hpp"
#include "Behaviors/PlayerBehavior.hpp"
#include "Behaviors/PlayerCollisionBehavior.hpp"
#include <memory>

void InitializeGame() {
    windowBackgroundColor.r = 255;
    windowBackgroundColor.b = 255;
    windowBackgroundColor.g = 255;
    windowBackgroundColor.a = 255;

    std::shared_ptr<GameObject> player = std::make_shared<GameObject>();
    player->setPosition(std::make_shared<Vector2>(100, 200));
    player->setTag("player");
    std::shared_ptr<KinematicBehavior> playerKinematic = std::make_shared<KinematicBehavior>();
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

    RegisterGameObject(player);

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
