#pragma once 

#include <memory>
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "World.h"
#include "Snake.h"

class Game {
public:
    Game();
    virtual ~Game();

    void HandleInput();
    void Update();
    void Render();
    std::shared_ptr<Window> GetWindow();
    sf::Time GetElapsed();
    void RestartClock();

private:
    std::shared_ptr<Window> m_window;
    std::shared_ptr<World> m_world;
    std::shared_ptr<Snake> m_snake;
    sf::Clock m_clock;
    sf::Time m_elapsed;
};
