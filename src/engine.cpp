#include "engine.hpp"
#include "LineSegment/LineSegment.h"

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
    this->lineSegment = new LineSegment(Point2d(300,300), Point2d(400, 300));
    this->point1 = new Point2d(5,5);
    point1->Translate(100,100);
    this->point2 = new Point2d(300,300);

    //lineSegment->Scale(0.1);
    lineSegment->Scale(900,0,0.3);

    //Main loop - runs until the window is closed
    while (window.isOpen())
    {
        input();
        draw();
    }
}