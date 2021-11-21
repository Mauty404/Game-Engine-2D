 #include "engine.hpp"
#include "Primitives/PrimitiveRenderer.hpp"
#include "Point2d/Point2d.h"
#include "LineSegment/LineSegment.h"

void Engine::draw() {
    window.draw(PrimitiveRenderer::DrawLineIncremental(0, 0, 100,100, sf::Color::White));
    window.draw(PrimitiveRenderer::DrawLineIncremental(10, 0, 10,100, sf::Color::White));
    window.draw(PrimitiveRenderer::DrawLine(50,0, 150,100, sf::Color::Magenta), 2, sf::Lines);
    window.draw(PrimitiveRenderer::DrawCircle(50, 150, 0, sf::Color::Blue));
    window.draw(PrimitiveRenderer::DrawRectangle(300,0,50,100,sf::Color::Green));
    window.draw(PrimitiveRenderer::DrawTriangle(400, 0, 50, sf::Color::Yellow));


    window.draw(lineSegment->DrawLine());

    window.draw(PrimitiveRenderer::DrawCircleAlg(60, 150, 40, sf::Color::Yellow));
    window.draw(PrimitiveRenderer::DrawElipseAlg(200, 150, 70, 40, sf::Color::Yellow));


    window.draw(PrimitiveRenderer::DrawLine(50,300, 150,300, sf::Color::Magenta), 2, sf::Lines);
    window.draw(PrimitiveRenderer::DrawLine(150,300, 150,400, sf::Color::Magenta), 2, sf::Lines);
    window.draw(PrimitiveRenderer::DrawLine(150,400, 50,400, sf::Color::Magenta), 2, sf::Lines);
    window.draw(PrimitiveRenderer::DrawLine(50,400, 50,300, sf::Color::Magenta), 2, sf::Lines);

    //PrimitiveRenderer::BoundaryFill(60, 350,sf::Color::Magenta, sf::Color::Blue, &window);

    window.draw(Point2d::DrawPoint(*point1));
    window.draw(Point2d::DrawPoint(*point2));

    Engine::circleShape.setRadius(20);
    window.draw(circleShape);

    window.display();
    window.clear(Color::Black);
}