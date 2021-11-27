#include "engine.hpp"

void Engine::input() {
    Event event;
    window.setKeyRepeatEnabled(false);
    static int delta = 1;

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


    if (Keyboard::isKeyPressed(Keyboard::R)) {
        backgroundColor = sf::Color::Red;
    }

    if (Keyboard::isKeyPressed(Keyboard::T)) {
        backgroundColor = sf::Color::Green;
    }

    if (Keyboard::isKeyPressed(Keyboard::Y)) {
        backgroundColor = sf::Color::Blue;
    }

    if (Keyboard::isKeyPressed(Keyboard::U)) {
        backgroundColor = sf::Color::Black;
    }

    if (Keyboard::isKeyPressed(Keyboard::I)) {
        if (drawPrimitives) drawPrimitives = false;
        else drawPrimitives = true;
    }

    if (Keyboard::isKeyPressed(Keyboard::O)) {
        if (drawLine) drawLine = false;
        else drawLine = true;
    }

    if (Keyboard::isKeyPressed(Keyboard::P)) {
        if (drawPoint1) drawPoint1 = false;
        else drawPoint1 = true;
    }

    if (Keyboard::isKeyPressed(Keyboard::G)) {
        if (drawLinePoints) drawLinePoints = false;
        else drawLinePoints = true;
    }

    if (Keyboard::isKeyPressed(Keyboard::H)) {
        if (drawCircle) drawCircle = false;
        else drawCircle = true;
    }

    if (Keyboard::isKeyPressed(Keyboard::J)) {
        if (drawEmptyPrimitives) drawEmptyPrimitives = false;
        else drawEmptyPrimitives = true;
    }

    if (Keyboard::isKeyPressed(Keyboard::K) && drawEmptyPrimitives) {
        if (borderFill) borderFill = false;
        else borderFill = true;
    }

    if (Keyboard::isKeyPressed(Keyboard::Z)) {
        if (drawLine2) drawLine2 = false;
        else drawLine2 = true;
    }

    if (Keyboard::isKeyPressed(Keyboard::X) && scaleLine1) {
        lineSegment2->Scale(0.5);
        scaleLine1 = false;
    }

    if (Keyboard::isKeyPressed(Keyboard::C) && scaleLine2) {
        lineSegment2->Scale(900, 0, 0.3);
        scaleLine2 = false;
    }



//    if (Keyboard::isKeyPressed(Keyboard::T)) {
//        point1->Rotate(0.01);
//    }
//
//    if (Keyboard::isKeyPressed(Keyboard::Y)) {
//        point2->Rotate(350, 350, 0.01);
//    }
//
//    if (Keyboard::isKeyPressed(Keyboard::U)) {
//        lineSegment->Rotate(0.01);
//    }
//
//    if (Keyboard::isKeyPressed(Keyboard::I)) {
//        lineSegment->Rotate(600, 600, 0.01);
//    }

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