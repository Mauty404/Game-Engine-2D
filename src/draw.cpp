#include "engine.hpp"
#include "Primitives/PrimitiveRenderer.hpp"

void Engine::draw() {

    if (drawPrimitives) {
        window.draw(PrimitiveRenderer::DrawCircle(50, 150, 0, sf::Color::Blue));
        window.draw(PrimitiveRenderer::DrawRectangle(300, 0, 50, 100, sf::Color::Green));
        window.draw(PrimitiveRenderer::DrawTriangle(400, 0, 50, sf::Color::Yellow));
        window.draw(PrimitiveRenderer::DrawLine(50, 0, 150, 100, sf::Color::Magenta), 2, sf::Lines);
    }

    if (drawLine) {
        window.draw(PrimitiveRenderer::DrawLineIncremental(0, 0, 100, 100, sf::Color::White));
        window.draw(PrimitiveRenderer::DrawLineIncremental(10, 0, 10, 100, sf::Color::White));
    }

    if (drawPoint1) {
        window.draw(Point2d::DrawPoint(*point1));
    }

    if (drawLinePoints) {
        window.draw(lineSegment->DrawLine());
    }

    if (drawCircle) {
        window.draw(PrimitiveRenderer::DrawCircleAlg(60, 150, 40, sf::Color::Yellow));
        window.draw(PrimitiveRenderer::DrawElipseAlg(200, 150, 70, 40, sf::Color::Yellow));
    }

    if (drawEmptyPrimitives) {
        window.draw(PrimitiveRenderer::DrawLine(350, 110, 500, 110, sf::Color::Magenta), 2, sf::Lines);
        window.draw(PrimitiveRenderer::DrawLine(500, 110, 500, 200, sf::Color::Magenta), 2, sf::Lines);
        window.draw(PrimitiveRenderer::DrawLine(500, 200, 350, 200, sf::Color::Magenta), 2, sf::Lines);
        window.draw(PrimitiveRenderer::DrawLine(350, 200, 350, 110, sf::Color::Magenta), 2, sf::Lines);
    }

    if (borderFill) {
        PrimitiveRenderer::BorderFill(450, 150, sf::Color::Magenta, sf::Color::Blue, &window);
    }

    if (floodFill) {
        PrimitiveRenderer::FloodFill(450, 150, backgroundColor, sf::Color::Blue, &window);
    }

    if (drawLine2) {
        window.draw(lineSegment2->DrawLine());
    }

    player->currentSprite.setPosition(player->x, player->y);

    window.draw(player->currentSprite);

    window.display();
    window.clear(backgroundColor);
}