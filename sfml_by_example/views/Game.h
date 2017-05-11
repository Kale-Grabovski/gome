#pragma once 

#include <SFML/Graphics.hpp>
#include "Window.h"
#include "states/StateManager.h"
#include "ResourceManager.hpp"

class Game {
public:
    Game();
    ~Game();
    void HandleInput();
    void Update();
    void Render();
    Window* GetWindow();
    sf::Time GetElapsed();
    void RestartClock();
    void MoveSprite(EventDetails* l_details);
    void RefreshSprite(EventDetails* l_details);
    void LateUpdate();

private:
    void MoveMushroom();
    Window m_window;
    sf::Sprite m_mushroom;
    sf::Vector2i m_increment;
    sf::Texture m_mushroomTexture;
    sf::Clock m_clock;
    sf::Time m_elapsed;
    StateManager m_stateManager;
    SharedContext m_context;
};
