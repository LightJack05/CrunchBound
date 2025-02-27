#include "Lifecycle.hpp"
#include "../engine/GameManagement.hpp"
#include "../engine/ObjectManagement.hpp"
#include "../engine/Time.hpp"
#include "Init.hpp"

void InitializeGame() {
    // Create the initial gameobjects, including the game manager
    CreateGameManager();
    CreateInitialGameObjects();
    // Run the OnStart method on all components
    OnGameStart();
}

void GameOver() { EnqueueGameReset(); }

void ResetGame() {
    GameObjects.clear();
    ResetTimeSinceGameStart();
    CreateInitialGameObjects();
    OnGameStart();
}
