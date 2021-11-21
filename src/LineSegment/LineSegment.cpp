#include "LineSegment.h"
#include "../Primitives/PrimitiveRenderer.hpp"

LineSegment::LineSegment() {}

LineSegment::LineSegment(Point2d start, Point2d end) {

    startLine = Point2d(start.x, start.y);
    endLine = Point2d(end.x, end.y);
}

sf::VertexArray LineSegment::DrawLine() {
    return PrimitiveRenderer::DrawLineIncremental(startLine.x, startLine.y, endLine.x, endLine.y, sf::Color::Red);
}

void LineSegment::Uniformity(float k) {
    startLine.x *= k;
    startLine.y *= k;
    endLine.x *= k;
    endLine.y *= k;
}

void LineSegment::Uniformity(int x, int y, float k) {
    startLine.x = startLine.x*k+(1-k)*x;
    startLine.y = startLine.y*k+(1-k)*y;
    endLine.x = endLine.x*k+(1-k)*x;
    endLine.y = endLine.y*k+(1-k)*y;
}
