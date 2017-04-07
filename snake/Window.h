#pragma once

#include <string>
#include <memory>
#include <SFML/Graphics.hpp>

class Window {
public:
    Window();
    Window(const std::string& l_title,const sf::Vector2u& l_size);
    virtual ~Window();
    void BeginDraw(); // Clear the window.
    void EndDraw(); // Display the changes.
    void Update();
    bool IsDone();
    bool IsFullscreen();
    sf::Vector2u GetWindowSize();
    void ToggleFullscreen();
    void Draw(sf::Drawable& l_drawable);
    std::shared_ptr<sf::RenderWindow> GetRenderWindow();

private:
    void Setup(const std::string& l_title, const sf::Vector2u& l_size);
    void Destroy();
    void Create();
    std::shared_ptr<sf::RenderWindow> m_window;
    sf::Vector2u m_windowSize;
    std::string m_windowTitle;
    bool m_isDone;
    bool m_isFullscreen;
};
