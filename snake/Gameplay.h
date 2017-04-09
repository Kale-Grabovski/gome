#pragma once

#include <memory>
#include "Game.h"

class Game;
class Gameplay {
public:
    explicit Gameplay(std::shared_ptr<Game> mGame) : game(mGame) {}
    virtual ~Gameplay() {}
    void IncreaseScore() const;
    void Lose() const;
private:
    std::shared_ptr<Game> game;
};
