#include "Point2d.h"
#include "../Primitives/PrimitiveRenderer.hpp"

Point2d::Point2d() {}

Point2d::Point2d(int x, int y) {
    this->x = x;
    this->y = y;
}

int Point2d::GetX() {
    return x;
}

int Point2d::GetY() {
    return y;
}

void Point2d::SetPoint(int x, int y) {
    this->x = x;
    this->y = y;
}

sf::CircleShape Point2d::DrawPoint(Point2d point) {
    return PrimitiveRenderer::DrawCircle(3, point.x, point.y, sf::Color::White);
}
