#include "ScoreCounterBehavior.hpp"
#include "../../../engine/Time.hpp"
#include "../../../engine/components/renderers/FontRenderer.hpp"

/**
 * @brief The time since the game has been started
 */
static long long TimeSinceGameStart = 0;

/**
 * @brief Get the player score at the current time.
 *
 * @return The current playerscore
 */
static inline long long GetPlayerScore() { return TimeSinceGameStart / 1000; }

void ScoreCounterBehavior::OnTick() {
    TimeSinceGameStart += GetDeltaTime();
    this->parent->GetFirstComponent<FontRenderer>()->setText(
        "Score: " + std::to_string(GetPlayerScore()));
}

void ScoreCounterBehavior::OnStart() { TimeSinceGameStart = 0; }
