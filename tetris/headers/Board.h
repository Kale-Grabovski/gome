#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "Window.h"

class Window;
class Board {
public:
    explicit Board(std::shared_ptr<Window> window);
    virtual ~Board() {}

    void update();
    int getBlockSize();
    void render();
private:
    std::shared_ptr<Window> window;
    int blockSize; // size of one block

    static const int blocksX = 10;
    static const int blocksY = 20;
};
