#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "Gameplay.h"

struct SnakeSegment {
    SnakeSegment(int x, int y) : position(x, y) {}
    sf::Vector2i position;
};

enum class Direction{ None, Up, Down, Left, Right };

using SnakeContainer = std::vector<SnakeSegment>;

class Gameplay;
class Snake {
public:
    explicit Snake(std::shared_ptr<Gameplay> m_gameplay, int l_blockSize);
    virtual ~Snake();

    // Helper methods.
    void SetDirection(Direction l_dir);
    Direction GetPhysicalDirection();
    sf::Vector2i GetPosition();
    void IncreaseScore();

    void Extend(); // Grow the snake.
    void Reset(); // Reset to starting position.
    void Destroy();

    void Move(); // Movement method.
    void Tick(); // Update method.
    void Cut(int l_segments); // Method for cutting snake.
    void Render(std::shared_ptr<sf::RenderWindow> l_window);
private:
    void CheckCollision(); // Checking for collisions.
    SnakeContainer m_snakeBody; // Segment vector.
    std::shared_ptr<Gameplay> gameplay; // Mediator pointer

    int m_size; // Size of the graphics.
    Direction m_dir; // Current direction.
    int m_collisionsLeft; // Number of collisions left to itself
    sf::RectangleShape m_bodyRect; // Shape used in rendering.
};