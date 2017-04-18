#include <iostream>
#include "headers/Game.h"

Game::Game() 
    : window(std::make_shared<Window>("Tetris", sf::Vector2u(500, 600))),
    board(std::make_shared<Board>(window)) {}

void Game::setup() {
    time(NULL);
}

void Game::update() {
    sf::Time timestep = sf::seconds(1.0f / level);

    if (elapsed >= timestep) {
        board->update();
        elapsed -= timestep;
    }

    window->update();
}

void Game::render() {
    window->beginDraw();
    board->render(score, level);
    window->endDraw();
}

std::shared_ptr<Window> Game::getWindow() const { return window; }

sf::Time Game::getElapsed() const { 
    return elapsed; 
}

void Game::restartClock() {
    elapsed += clock.restart();
}

void Game::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        // rotate
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        // speed up falling
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        // go left
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        // go right
    }

    // later space for pause
}

void Game::increaseScore() {
    score += 10;
}

void Game::lose() {}
