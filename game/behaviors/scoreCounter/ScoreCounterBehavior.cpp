#include "ScoreCounterBehavior.hpp"
#include "../../../engine/Time.hpp"
#include "../../../engine/components/renderers/FontRenderer.hpp"

void ScoreCounterBehavior::OnTick() {
    timeSinceGameStart += GetDeltaTime();
    this->parent->GetFirstComponent<FontRenderer>()->setText(
        "Score: " + std::to_string(GetPlayerScore()));
}

void ScoreCounterBehavior::OnStart() { timeSinceGameStart = 0; }
