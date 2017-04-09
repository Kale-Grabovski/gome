#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Gameplay.h"

class Gameplay;
class Snake;
class World {
public:
    explicit World(std::shared_ptr<Gameplay> gameplay, sf::Vector2u l_windSize);
    virtual ~World() {}

    int GetBlockSize();
    void RespawnApple();
    void DestroyApple();
    void Update(std::shared_ptr<Snake> l_player);
    void Render(std::shared_ptr<sf::RenderWindow> l_window);
private:
    sf::Vector2u m_windowSize;
    sf::Vector2i m_item;
    int m_blockSize;
    sf::CircleShape m_appleShape;
    sf::RectangleShape m_bounds[4];
    std::shared_ptr<Gameplay> m_gameplay;
};
