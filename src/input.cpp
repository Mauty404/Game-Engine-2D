#include "engine.hpp"

/// input - obsługa klawiatury
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
       borderFill = true;
    }

    if (Keyboard::isKeyPressed(Keyboard::L) && drawEmptyPrimitives) {
        borderFill = true;
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

    if (Keyboard::isKeyPressed(Keyboard::V)) {
        lineSegment2->Rotate(0.01);
    }

    if (Keyboard::isKeyPressed(Keyboard::B)) {
        lineSegment2->Rotate(600, 600, 0.01);
    }

    if (Keyboard::isKeyPressed(Keyboard::N) && translateLine) {
        lineSegment2->Translate(100, 100);
        translateLine = false;
    }

    if (Keyboard::isKeyPressed(Keyboard::E)) {
        drawPrimitives = false;
        drawLine = false;
        drawPoint1 = false;
        drawLinePoints = false;
        drawCircle = false;
        drawEmptyPrimitives = false;
        drawLine2 = false;
    }

    if (Keyboard::isKeyPressed(Keyboard::Q)) {
        drawPrimitives = true;
        drawLine = true;
        drawPoint1 = true;
        drawLinePoints = true;
        drawCircle = true;
        drawEmptyPrimitives = true;
        drawLine2 = true;
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