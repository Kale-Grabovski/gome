#pragma once 

#include <memory>
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Board.h"
#include "Figure.h"

class Figure;
class Board;
class Game {
public:
    Game();

    void setup();
    void handleInput();
    void update();
    void render();
    std::shared_ptr<Window> getWindow() const;
    sf::Time getElapsed() const;
    void restartClock();
    void increaseScore();
    void lose();

    static const int BLOCKS_HOR = 10;
    static const int BLOCKS_VERT = 20;
    static const int WINDOW_WIDTH = 500;
    static const int WINDOW_HEIGHT = 600;
    static const int BLOCK_SIZE = WINDOW_HEIGHT / 2 / BLOCKS_VERT;

private:
    std::shared_ptr<Window> window;
    std::shared_ptr<Board> board;
    std::shared_ptr<Figure> currentFigure;
    sf::Clock clock;
    sf::Time elapsed;
    int score = 0;
    int level = 1;
    bool lost;
};
