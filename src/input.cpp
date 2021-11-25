#include "engine.hpp"

void Engine::input() {
    Event event;
    window.setKeyRepeatEnabled(false);
    static int delta = 2;

    while (window.pollEvent(event)) {
        //Close window
        if (event.type == Event::Closed) {
            window.close();
        }

        //Keyboard input
        if (event.type == Event::KeyPressed) {
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                window.close();
            }
        }
    }


    if (Keyboard::isKeyPressed(Keyboard::T)) {
        point1->Rotate(0.01);
    }

    if (Keyboard::isKeyPressed(Keyboard::Y)) {
        point2->Rotate(350, 350, 0.01);
    }

    if (Keyboard::isKeyPressed(Keyboard::U)) {
        lineSegment->Rotate(0.01);
    }

    if (Keyboard::isKeyPressed(Keyboard::I)) {
        lineSegment->Rotate(600, 600, 0.01);
    }

    if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left)) {
        player->MoveLeft(delta);
    }
    else if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right)) {
        player->MoveRight(delta);
    }
    else if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up)) {
        player->MoveUp(delta);
    }
    else if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down)) {
        player->MoveDown(delta);
    }
}