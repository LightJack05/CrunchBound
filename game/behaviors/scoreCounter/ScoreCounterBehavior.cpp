#include "ScoreCounterBehavior.hpp"
#include "../../../engine/Time.hpp"
#include "../../../engine/components/renderers/FontRenderer.hpp"

static long long TimeSinceGameStart = 0;

static inline long long GetPlayerScore() { return TimeSinceGameStart / 1000; }

void ScoreCounterBehavior::OnTick() {
    TimeSinceGameStart += GetDeltaTime();
    this->parent->GetFirstComponent<FontRenderer>()->setText(
        "Score: " + std::to_string(GetPlayerScore()));
}

void ScoreCounterBehavior::OnStart() { TimeSinceGameStart = 0; }
