#include <iostream>
#include "headers/Board.h"

Board::Board(std::shared_ptr<Window> w) : window(w) {
    font.loadFromFile("arial.ttf");
    recordColor = sf::Color(56, 122, 122);

    // Fill out the grid with zeros
    for (int i; i < Game::BLOCKS_VERT; i++) {
        for (int j; j < Game::BLOCKS_HOR; j++) {
            grid[i][j] = 0;
        }
    }
}

void Board::update() {
/*    if (l_player->GetPosition() == m_item) {
        l_player->Extend();
        l_player->IncreaseScore();
    }

    int gridSize_x = windowSize.x / Game::BLOCK_SIZE;
    int gridSize_y = windowSize.y / Game::BLOCK_SIZE;

    if (l_player->GetPosition().x <= 0 || 
        l_player->GetPosition().y <= 0 ||
        l_player->GetPosition().x >= gridSize_x - 1 || 
        l_player->GetPosition().y >= gridSize_y - 1) {
        m_gameplay->Lose();
    }
*/}

void Board::render(const int gameScore, const int gameLevel) {
    drawLabels(gameScore, gameLevel);
    drawGrid();
}

void Board::drawText(sf::Text &label, const std::string text, const int offsetX, const int offsetY) {
    label.setPosition(window->getSize().x / 2 + offsetX, offsetY);
    label.setFont(font);
    label.setString(text);
    label.setCharacterSize(20);

    window->draw(label);
}

void Board::drawLabels(const int gameScore, const int gameLevel) {
    sf::Text scoreLabel;
    sf::Text levelLabel;
    sf::Text nextLabel;

    drawText(scoreLabel, "Score:", 70, 20);
    drawText(levelLabel, "Level:", 71, 50);
    drawText(nextLabel,  "Next:",  70, 80);

    drawText(score, std::to_string(gameScore), 135, 20);
    drawText(level, std::to_string(gameLevel), 135, 50);
}

void Board::drawGrid() {
    // +2 for border lines
    sf::VertexArray horLines(sf::Lines, Game::BLOCKS_VERT * 2);
    sf::VertexArray vertLines(sf::Lines, Game::BLOCKS_HOR * 2);
    sf::RectangleShape border;

    for (uint i = 0; i < Game::BLOCKS_VERT * 2; i += 2) {
        horLines[i].position = sf::Vector2f(0, Game::BLOCK_SIZE * i);
        horLines[i].color = sf::Color(50, 50, 50);

        horLines[i + 1].position = sf::Vector2f(Game::BLOCK_SIZE * Game::BLOCKS_VERT, Game::BLOCK_SIZE * i);
        horLines[i + 1].color = sf::Color(50, 50, 50);
    }

    for (uint i = 0; i < Game::BLOCKS_HOR * 2; i += 2) {
        vertLines[i].position = sf::Vector2f(Game::BLOCK_SIZE * i, 0);
        vertLines[i].color = sf::Color(50, 50, 50);

        vertLines[i + 1].position = sf::Vector2f(Game::BLOCK_SIZE * i, Game::BLOCK_SIZE * Game::BLOCKS_VERT * 2);
        vertLines[i + 1].color = sf::Color(50, 50, 50);
    }

    // Draw border line
    border.setSize(sf::Vector2f(2, Game::BLOCK_SIZE * Game::BLOCKS_VERT * 2));
    border.setFillColor(sf::Color(100, 100, 100));
    border.setPosition(Game::BLOCK_SIZE * Game::BLOCKS_HOR * 2, 0);

    window->draw(horLines);
    window->draw(vertLines);
    window->draw(border);
}

