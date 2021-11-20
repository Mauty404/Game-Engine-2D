#include "LineSegment.h"
#include "../Primitives/PrimitiveRenderer.hpp"

LineSegment::LineSegment(Point2d start, Point2d end) {

    startLine = Point2d(start.x, end.y);
    endLine = Point2d(end.x, end.y);
}

sf::VertexArray LineSegment::DrawLine() {
    return PrimitiveRenderer::DrawLineIncremental(startLine.x, startLine.y, endLine.x, endLine.y, sf::Color::Red);
}
