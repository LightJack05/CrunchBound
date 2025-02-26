#include "ScoreCounterBehavior.hpp"
#include "../../../engine/components/renderers/FontRenderer.hpp"

void ScoreCounterBehavior::OnTick() {
    this->parent->GetFirstComponent<FontRenderer>()->setText(
        "Score: " + std::to_string(GetPlayerScore()));
}

void ScoreCounterBehavior::OnStart() {}
