#include "headers/Figure.h"

Figure::Figure(std::shared_ptr<Window> w, sf::Vector2u c) : coords(c), window(w) {
    blocks = FigureBlocks[0];
    color  = FigureColors[0];
}

void Figure::render() {
    for (int i; i < 16; i++) {
        if (blocks[i] == 1) {
            rect.setFillColor(color);
            rect.setPosition(coords.x * Game::BLOCK_SIZE, coords.y * Game::BLOCK_SIZE);
            window->draw(rect); 
        }
    }
}
