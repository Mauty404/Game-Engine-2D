#include "engine.hpp"
#include "LineSegment/LineSegment.h"
#include "Primitives/PrimitiveRenderer.hpp"

const sf::Time Engine::TimePerFrame = seconds(1.f/60.f);

Engine::Engine(unsigned int x, unsigned int y) {

}

void Engine::instantiate() {
    window.create(VideoMode(600, 800), "BomberMan", Style::Default);
    window.setFramerateLimit(FPS);

    while(window.isOpen()) {
        Window1Input();
    }

    run();
}


void Engine::run() {
    window.create(VideoMode(600, 800), "BomberMan", Style::Default);
    window.setFramerateLimit(FPS);
    float radius = circleShape.getRadius();
    circleShape.setFillColor(Color::Magenta);
    circleShape.setPosition((float(window.getSize().x)/2.f-radius),float(window.getSize().y)/2-radius);

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

void Engine::Window1Input() {
    Event event;
    window.setKeyRepeatEnabled(false);

    while (window.pollEvent(event))
    {
        //Close window
        if(event.type == Event::Closed)
        {
            window.close();
        }

        //Keyboard input
        if(event.type == Event::KeyPressed)
        {
            if(Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window.close();
            }
            if(Keyboard::isKeyPressed(Keyboard::Enter))
            {
                circleShape.setRadius(60);
            }

        }
    }
}