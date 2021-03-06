#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "EventManager.h"

class EventManager;
struct EventDetails;
class Window {
    public:
    Window();
    Window(const std::string& l_title,const sf::Vector2u& l_size);
    virtual ~Window();
    void BeginDraw(); // Clear the window.
    void EndDraw(); // Display the changes.
    void Update();
    bool IsDone();
    sf::Vector2u GetWindowSize();
    void Draw(sf::Drawable& l_drawable);
    bool IsFocused();
    EventManager* GetEventManager();
    sf::RenderWindow* GetRenderWindow();
    void Close(EventDetails* l_details = nullptr);
    sf::FloatRect GetViewSpace();

    private:
    void Setup(const std::string& l_title, const sf::Vector2u& l_size);
    void Destroy();
    void Create();
    sf::RenderWindow m_window;
    sf::Vector2u m_windowSize;
    std::string m_windowTitle;
    bool m_isDone;
    EventManager* m_eventManager;
    bool m_isFocused;
};
