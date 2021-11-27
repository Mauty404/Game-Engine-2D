#include "Point2d.h"
#include "../Primitives/PrimitiveRenderer.hpp"
#include "math.h"

Point2d::Point2d() {}

/// LineSegment - konstruktor, ustaw współrzędne punktu bazując na przekazanych współrzędnych
/// @param x pozycja pozioma punktu
/// @param y pozycja pionowa punktu
Point2d::Point2d(int x, int y) {
    this->x = x;
    this->y = y;
}

/// GetX - pobierz pozycję poziomą punktu
int Point2d::GetX() {
    return x;
}

/// GetX - pobierz pozycję pionową punktu
int Point2d::GetY() {
    return y;
}

/// SetPoint - ustaw współrzędne punktu
/// @param x pozycja pozioma punktu
/// @param y pozycja pionowa punktu
void Point2d::SetPoint(int x, int y) {
    this->x = x;
    this->y = y;
}

/// DrawPoint -  wywołuje funkcję DrawCircle dodającą współrzędne punkt, który chcemy narysować, do CircleShape
/// @param point punkt, który chcemy narysować
/// @return CircleShape, w którym zapisane są współrzędne punktu, który chcemy narysować oraz jego promień i kolor
sf::CircleShape Point2d::DrawPoint(Point2d point) {
    return PrimitiveRenderer::DrawCircle(3, point.x, point.y, sf::Color::White);
}

/// Translate - przemieszcza punkt o podaną liczbę pikseli
/// @param x liczba pikseli do przesunięcia w poziomie
/// @param y liczba pikseli do przesunięcia w pionie
void Point2d::Translate(int x, int y) {
    this->x += x;
    this->y += y;
}

/// Rotate - obraca punkt o dany kąt względem początku układu współrzędnych
/// @param alpha kąt obrotu
void Point2d::Rotate(float alpha) {
    float tmpX, tmpY;
    tmpX = x*cos(alpha)-y*sin(alpha);
    tmpY = x*sin(alpha)+y*cos(alpha);

    this->x = tmpX;
    this->y = tmpY;
}

/// Rotate - obraca punkt o dany kąt względem podanego punktu
/// @param x pozycja pozioma punktu
/// @param y pozycja pionowa punktu
/// @param alpha kąt obrotu
void Point2d::Rotate(int x, int y, float alpha) {
    float tmpX, tmpY;

    tmpX = (float)x+(float)(this->x-x)*cos(alpha)-(float)(this->y-y)*sin(alpha);
    tmpY = (float)y+(float)(this->x-x)*sin(alpha)+(float)(this->y-y)*cos(alpha);

    this->x = tmpX;
    this->y = tmpY;
}




