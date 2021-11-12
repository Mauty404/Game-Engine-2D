#include "engine.hpp"

const sf::Time Engine::TimePerFrame = seconds(1.f/60.f);

Engine::Engine(unsigned int x, unsigned int y) {
    resolution = Vector2f(x, y);
    window.create(VideoMode(resolution.x, resolution.y), "BomberMan", Style::Default);
    window.setFramerateLimit(FPS);
    float radius = circleShape.getRadius();
    circleShape.setFillColor(Color::Magenta);
    circleShape.setPosition((float(window.getSize().x)/2.f-radius),float(window.getSize().y)/2-radius);
}


void Engine::run() {
    //Main loop - runs until the window is closed
    while (window.isOpen())
    {
        input();
        draw();
    }
}