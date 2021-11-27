#include "LineSegment.h"
#include "../Primitives/PrimitiveRenderer.hpp"
#include "math.h"

LineSegment::LineSegment() {}

/// LineSegment - konstruktor, tworzy linię bazując na punkcie początkowym i końcowym
/// @param start punkt startowy
/// @param end punkt końcowy
LineSegment::LineSegment(Point2d start, Point2d end) {

    startLine = Point2d(start.x, start.y);
    endLine = Point2d(end.x, end.y);
}

/// DrawLine - wywołuje funkcję DrawLineIncremental dodającą punkty linii, którą chcemy narysować, do VertexArray
/// @return VertexArray, czyli tablica wierzchołków, w której zapisane są punkty linii do narysowania
sf::VertexArray LineSegment::DrawLine() {
    return PrimitiveRenderer::DrawLineIncremental(startLine.x, startLine.y, endLine.x, endLine.y, sf::Color::Red);
}

/// Translate - przemieszcza linię o podaną liczbę pikseli
/// @param x liczba pikseli do przesunięcia w poziomie
/// @param y liczba pikseli do przesunięcia w pionie
void LineSegment::Translate(int x, int y) {
    startLine.x += x;
    startLine.y += y;
    endLine.x += x;
    endLine.y += y;
}

/// Rotate - obraca linię o dany kąt względem początku układu współrzędnych
/// @param alpha kąt obrotu
void LineSegment::Rotate(float alpha) {
    float tmpX, tmpY;
    tmpX = startLine.x*cos(alpha)-startLine.y*sin(alpha);
    tmpY = startLine.x*sin(alpha)+startLine.y*cos(alpha);

    startLine.x = tmpX;
    startLine.y = tmpY;

    tmpX = endLine.x*cos(alpha)- endLine.y*sin(alpha);
    tmpY = endLine.x*sin(alpha)+endLine.y*cos(alpha);

    endLine.x = tmpX;
    endLine.y = tmpY;
}

/// Rotate - obraca linię o dany kąt względem podanego punktu
/// @param x pozycja pozioma punktu
/// @param y pozycja pionowa punktu
/// @param alpha kąt obrotu
void LineSegment::Rotate(int x, int y, float alpha) {
    float tmpX, tmpY;

    tmpX = (float)x+(float)(startLine.x-x)*cos(alpha)-(float)(startLine.y-y)*sin(alpha);
    tmpY = (float)y+(float)(startLine.x-x)*sin(alpha)+(float)(startLine.y-y)*cos(alpha);

    startLine.x = tmpX;
    startLine.y = tmpY;

    tmpX = (float)x+(float)(endLine.x-x)*cos(alpha)-(float)(endLine.y-y)*sin(alpha);
    tmpY = (float)y+(float)(endLine.x-x)*sin(alpha)+(float)(endLine.y-y)*cos(alpha);

    endLine.x = tmpX;
    endLine.y = tmpY;
}

/// Scale - przeskalowanie linii o podaną wartość względem początku układu współrzędnych
/// @param k wartość, o jaką należy przeskalować linię
void LineSegment::Scale(float k) {
    startLine.x *= k;
    startLine.y *= k;
    endLine.x *= k;
    endLine.y *= k;
}

/// Scale - przeskalowanie linii o podaną wartość względem podanego punktu
/// @param x pozycja pozioma punktu
/// @param y pozycja pionowa punktu
/// @param k wartość, o jaką należy przeskalować linię
void LineSegment::Scale(int x, int y, float k) {
    startLine.x = startLine.x*k+(1-k)*x;
    startLine.y = startLine.y*k+(1-k)*y;
    endLine.x = endLine.x*k+(1-k)*x;
    endLine.y = endLine.y*k+(1-k)*y;
}
