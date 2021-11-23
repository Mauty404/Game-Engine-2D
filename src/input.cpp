#include "engine.hpp"

void Engine::input() {
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


    if(Keyboard::isKeyPressed(Keyboard::T)) {
        point1->Rotate(0.01);
    }

    if(Keyboard::isKeyPressed(Keyboard::Y)) {
        point2->Rotate(350, 350, 0.01);
    }

    if(Keyboard::isKeyPressed(Keyboard::U)) {
        lineSegment->Rotate(0.01);
    }

    if(Keyboard::isKeyPressed(Keyboard::I)) {
        lineSegment->Rotate(600, 600, 0.01);
    }

    if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
    {
        if(circleShape.getPosition().x == 0)
        {
            circleShape.setPosition(circleShape.getPosition().x, circleShape.getPosition().y);
        }
        else
        {
            circleShape.move(-10, 0.f);
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
    {
        if(circleShape.getPosition().x == window.getSize().x - circleShape.getRadius()*2)
        {
            circleShape.setPosition(circleShape.getPosition().x, circleShape.getPosition().y);
        }
        else
        {
            circleShape.move(10, 0.f);
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up))
    {
        if(circleShape.getPosition().y == 0)
        {
            circleShape.setPosition(circleShape.getPosition().x, circleShape.getPosition().y);
        }
        else
        {
            circleShape.move(0.f, -10);
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down))
    {
        if(circleShape.getPosition().y == window.getSize().y - circleShape.getRadius()*2)
        {
            circleShape.setPosition(circleShape.getPosition().x, circleShape.getPosition().y);
        }
        else
        {
            circleShape.move(0.f, 10);
        }
    }
}