#include <string>
#include "Window.h"

Window::Window() { 
    Setup("Window", sf::Vector2u(640,480)); 
}

Window::Window(const std::string& l_title, const sf::Vector2u& l_size) {
    Setup(l_title,l_size);
}

Window::~Window() { 
    Destroy(); 
}

void Window::Setup(const std::string& l_title, const sf::Vector2u& l_size) {
    m_windowTitle = l_title;
    m_windowSize = l_size;
    m_isDone = false;
    Create();

    m_isFocused = true; // Default value for focused flag.
    m_eventManager = new EventManager();
    m_eventManager->AddCallback(StateType(0),"Window_close", &Window::Close, this);
}

void Window::Create() {
    m_window.create({m_windowSize.x, m_windowSize.y, 32}, m_windowTitle, sf::Style::Default);
}

void Window::Destroy() {
    m_window.close();
}

void Window::Update() {
    sf::Event event;

    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::LostFocus) {
            m_isFocused = false;
            m_eventManager->SetFocus(false);
        } else if (event.type == sf::Event::GainedFocus) {
            m_isFocused = true;
            m_eventManager->SetFocus(true);
        }

        m_eventManager->HandleEvent(event);
    }
    
    m_eventManager->Update();
}

void Window::BeginDraw() { 
    m_window.clear(sf::Color::Black); 
}

void Window::EndDraw() { 
    m_window.display(); 
}

bool Window::IsDone() { return m_isDone; }
sf::Vector2u Window::GetWindowSize() { return m_windowSize; }

void Window::Draw(sf::Drawable& l_drawable) {
    m_window.draw(l_drawable);
}

void Window::Close(EventDetails* l_details) { m_isDone = true; }


sf::RenderWindow* Window::GetRenderWindow() {
    return &m_window;
}

EventManager* Window::GetEventManager() {
    return m_eventManager;
}
