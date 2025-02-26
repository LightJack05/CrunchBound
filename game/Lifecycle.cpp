#include "Lifecycle.hpp"
#include "../engine/GameManagement.hpp"
#include "../engine/ObjectManagement.hpp"
#include "../engine/Time.hpp"
#include "Init.hpp"
#include <iostream>

void InitializeGame() {
    CreateGameManager();
    CreateInitialGameObjects();
    OnGameStart();
}

void GameOver() { EnqueueGameReset(); }

void ResetGame() {
    GameObjects.clear();
    ResetTimeSinceGameStart();
    CreateInitialGameObjects();
    OnGameStart();
}
