#include "headers/Board.h"

Board::Board(std::shared_ptr<Window> win) : window(win) {
    blockSize = window->getSize().y / 2 / blocksY;
}

void Board::update() {
/*    if (l_player->GetPosition() == m_item) {
        l_player->Extend();
        l_player->IncreaseScore();
    }

    int gridSize_x = windowSize.x / blockSize;
    int gridSize_y = windowSize.y / blockSize;

    if (l_player->GetPosition().x <= 0 || 
        l_player->GetPosition().y <= 0 ||
        l_player->GetPosition().x >= gridSize_x - 1 || 
        l_player->GetPosition().y >= gridSize_y - 1) {
        m_gameplay->Lose();
    }
*/}

void Board::render() {
    // +2 for border lines
    sf::VertexArray horLines(sf::Lines, blocksY * 2);
    sf::VertexArray vertLines(sf::Lines, blocksX * 2);
    sf::RectangleShape border;

    for (uint i = 0; i < blocksY * 2; i += 2) {
        horLines[i].position = sf::Vector2f(0, blockSize * i);
        horLines[i].color = sf::Color(50, 50, 50);

        horLines[i + 1].position = sf::Vector2f(blockSize * blocksY, blockSize * i);
        horLines[i + 1].color = sf::Color(50, 50, 50);
    }

    for (uint i = 0; i < blocksX * 2; i += 2) {
        vertLines[i].position = sf::Vector2f(blockSize * i, 0);
        vertLines[i].color = sf::Color(50, 50, 50);

        vertLines[i + 1].position = sf::Vector2f(blockSize * i, blockSize * blocksY * 2);
        vertLines[i + 1].color = sf::Color(50, 50, 50);
    }

    // Draw border line
    border.setSize(sf::Vector2f(2, blockSize * blocksY * 2));
    border.setFillColor(sf::Color(100, 100, 100));
    border.setPosition(blockSize * blocksX * 2, 0);

    window->draw(horLines);
    window->draw(vertLines);
    window->draw(border);
}

int Board::getBlockSize() { return blockSize; }
