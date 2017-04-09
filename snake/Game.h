#pragma once 

#include <memory>
#include <SFML/Graphics.hpp>
#include "Gameplay.h"
#include "Window.h"
#include "World.h"
#include "Snake.h"
#include "TextBox.h"

class Snake;
class World;
class Gameplay;
class Game : public std::enable_shared_from_this<Game> {
public:
    Game();
    virtual ~Game() {}

    void Setup();
    void HandleInput();
    void Update();
    void Render();
    std::shared_ptr<Window> GetWindow() const;
    sf::Time GetElapsed() const;
    void RestartClock();
    void IncreaseScore();
    void Lose();

private:
    std::shared_ptr<Window> m_window;
    std::shared_ptr<Gameplay> m_gameplay;
    std::shared_ptr<World> m_world;
    std::shared_ptr<Snake> m_snake;
    std::shared_ptr<TextBox> m_textbox;
    sf::Clock m_clock;
    sf::Time m_elapsed;
    int m_speed;
    int m_score;
    int m_lives;
    bool m_lost; // Losing state.
};
