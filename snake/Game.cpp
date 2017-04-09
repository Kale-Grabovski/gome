#include <iostream>
#include "Game.h"

Game::Game()
    : m_window(std::make_shared<Window>("Snake", sf::Vector2u(800, 600))),
    m_textbox(std::make_shared<TextBox>(5, 14, 350, sf::Vector2f(225, 0))) {}

void Game::Setup() {
    m_speed    = 15;
    m_lives    = 3;
    m_gameplay = std::make_shared<Gameplay>(shared_from_this());
    m_world    = std::make_shared<World>(m_gameplay, sf::Vector2u(800, 600));    
    m_snake    = std::make_shared<Snake>(m_gameplay, m_world->GetBlockSize());
    m_textbox->Add("Seeded random number generator with: " + std::to_string(time(NULL)));
}

void Game::Update() {
    sf::Time timestep = sf::seconds(1.0f / m_speed);

    if (m_elapsed >= timestep) {
        m_snake->Tick();
        m_world->Update(m_snake);
        m_elapsed -= timestep;
    }

    m_window->Update(); // Update window events.
}

void Game::Render(){
    m_window->BeginDraw();
    m_world->Render(m_window->GetRenderWindow());
    m_snake->Render(m_window->GetRenderWindow());
    m_textbox->Render(m_window->GetRenderWindow());
    m_window->EndDraw();
}

std::shared_ptr<Window> Game::GetWindow() const { 
    return m_window;
}

sf::Time Game::GetElapsed() const { 
    return m_elapsed; 
}

void Game::RestartClock() {
    m_elapsed += m_clock.restart();
}

void Game::HandleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) 
        && m_snake->GetPhysicalDirection() != Direction::Down) {
        m_snake->SetDirection(Direction::Up);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)  
        && m_snake->GetPhysicalDirection() != Direction::Up) {
        m_snake->SetDirection(Direction::Down);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
        && m_snake->GetPhysicalDirection() != Direction::Right) {
        m_snake->SetDirection(Direction::Left);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
        && m_snake->GetPhysicalDirection() != Direction::Left) {
        m_snake->SetDirection(Direction::Right);
    }
}

void Game::IncreaseScore() {
    m_score += 10;
    m_textbox->Add("Score: " + std::to_string(m_score));
}

void Game::Lose() { 
    if (--m_lives) {
        m_snake->Reset();
        m_textbox->Add("Lost, lives remains: " + std::to_string(m_lives));
    } else {
        m_snake->Destroy();
        m_world->DestroyApple();
        m_textbox->Add("Game Over");
    }
}
