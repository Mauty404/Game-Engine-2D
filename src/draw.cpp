#include "engine.hpp"
#include "Primitives/PrimitiveRenderer.hpp"
#include "Point2d/Point2d.h"

void Engine::draw() {
    window.draw(PrimitiveRenderer::DrawLineIncremental(100, 100, 500,500, sf::Color::White));
    window.draw(PrimitiveRenderer::DrawLine(30,0, 130,130, sf::Color::Magenta), 2, sf::Lines);
    window.draw(PrimitiveRenderer::DrawCircle(40, 100, 100, sf::Color::Blue));
    window.draw(PrimitiveRenderer::DrawRectangle(400,400,50,100,sf::Color::Green));
    window.draw(PrimitiveRenderer::DrawTriangle(500, 30, 30, sf::Color::Yellow));

    Point2d point2D(76, 76);
    window.draw(Point2d::DrawPoint(point2D));

    Engine::circleShape.setRadius(20);
    window.draw(circleShape);

    window.display();
    window.clear(Color::Black);
}