#pragma once

#include <array>
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "Window.h"

class Window;
class Board {
public:
    explicit Board(std::shared_ptr<Window> window);
    virtual ~Board() {}

    void update();
    void render(const int, const int);
private:
    void drawGrid();
    void drawLabels(const int, const int);
    void drawText(sf::Text &label, const std::string text, const int offsetX, const int offsetY);

    std::shared_ptr<Window> window;
    sf::Font font;
    sf::Color recordColor;
    sf::Text score;
    sf::Text level;
    int blockSize; // size of one block
    std::array<std::array<int, 10>, 20> grid;

    static const int blocksHor  = 10;
    static const int blocksVert = 20;
};
