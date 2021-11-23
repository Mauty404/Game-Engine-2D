#include "Point2d.h"
#include "../Primitives/PrimitiveRenderer.hpp"
#include "math.h"

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

void Point2d::Translate(int x, int y) {
    this->x += x;
    this->y += y;
}

void Point2d::Rotate(float alpha) {
    float tmpX, tmpY;
    tmpX = x*cos(alpha)-y*sin(alpha);
    tmpY = x*sin(alpha)+y*cos(alpha);

    this->x = tmpX;
    this->y = tmpY;
}

void Point2d::Rotate(int x, int y, float alpha) {
    float tmpX, tmpY;

    tmpX = (float)x+(float)(this->x-x)*cos(alpha)-(float)(this->y-y)*sin(alpha);
    tmpY = (float)y+(float)(this->x-x)*sin(alpha)+(float)(this->y-y)*cos(alpha);

    this->x = tmpX;
    this->y = tmpY;
}




