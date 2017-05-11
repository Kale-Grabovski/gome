#include "Gameplay.h"

void Gameplay::IncreaseScore() const {
    game->IncreaseScore();
}

void Gameplay::Lose() const {
    game->Lose();
}
