#include "headers/Window.h"

Window::Window(const std::string& title, const sf::Vector2u& size) {
    setup(title, size);
}

Window::~Window() { 
    destroy(); 
}

void Window::setup(const std::string& title, const sf::Vector2u& size) {
    window      = std::make_shared<sf::RenderWindow>();
    windowTitle = title;
    windowSize  = size;
    isDone      = false;
    create();
}

void Window::create() {
    window->create({windowSize.x, windowSize.y, 32}, windowTitle, sf::Style::Close);
}

void Window::update() {
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            isDone = true;
        }
    }
}

void Window::destroy() {
    window->close();
}

void Window::beginDraw() { 
    window->clear(sf::Color::Black); 
}

void Window::endDraw() { 
    window->display(); 
}

void Window::draw(sf::Drawable& l_drawable) {
    window->draw(l_drawable);
}

bool Window::getIsDone() { return isDone; }
sf::Vector2u Window::getSize() { return windowSize; }
std::shared_ptr<sf::RenderWindow> Window::getWindow() { return window; }

