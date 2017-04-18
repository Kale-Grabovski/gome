#pragma once 

#include <memory>
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Board.h"
#include "Figure.h"

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
    int score = 0;
    int level = 1;
    bool lost;
    std::shared_ptr<Figure> currentFigure;
    std::shared_ptr<Figure> nextFigure;
};
