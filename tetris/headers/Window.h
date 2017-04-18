#pragma once

#include <string>
#include <memory>
#include <SFML/Graphics.hpp>

class Window {
public:
    Window();
    Window(const std::string& l_title, const sf::Vector2u& l_size);
    virtual ~Window();
    
    void beginDraw();
    void endDraw();
    void update();
    bool getIsDone();
    sf::Vector2u getSize();
    void draw(sf::Drawable& drawable);
    std::shared_ptr<sf::RenderWindow> getWindow();

private:
    void setup(const std::string& title, const sf::Vector2u& size);
    void destroy();
    void create();
    std::shared_ptr<sf::RenderWindow> window;
    sf::Vector2u windowSize;
    std::string windowTitle;
    bool isDone;
};
