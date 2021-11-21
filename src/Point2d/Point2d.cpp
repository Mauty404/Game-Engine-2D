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

void Point2d::RotateOrigin(float alpha) {
    float tmpX, tmpY;
    tmpX = x*cos(alpha)-y*sin(alpha);
    tmpY = x*sin(alpha)+y*cos(alpha);

    this->x = tmpX;
    this->y = tmpY;
}

void Point2d::RotatePoint(int xPoint, int yPoint, float alpha) {
    float tmpX, tmpY;

    tmpX = (float)xPoint+(float)(x-xPoint)*cos(alpha)-(float)(y-yPoint)*sin(alpha);
    tmpY = (float)yPoint+(float)(x-xPoint)*sin(alpha)+(float)(y-yPoint)*cos(alpha);
//    tmpX = (float)xPoint+(float)(x-xPoint)*cos(alpha)-(float)(y-yPoint)*sin(alpha);
//    tmpY = (float)yPoint+(float)(x-xPoint)*sin(alpha)-(float)(y-yPoint)*cos(alpha);

    this->x = tmpX;
    this->y = tmpY;
}


