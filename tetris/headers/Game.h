#pragma once 

#include <memory>
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Board.h"

class Game {
public:
    Game();
    virtual ~Game() {}

    void setup();
    void handleInput();
    void update();
    void render();
    std::shared_ptr<Window> getWindow() const;
    sf::Time getElapsed() const;
    void restartClock();
    void increaseScore();
    void lose();

private:
    std::shared_ptr<Window> window;
    std::shared_ptr<Board> board;
    sf::Clock clock;
    sf::Time elapsed;
    int score;
    int speed;
    bool lost;
};
