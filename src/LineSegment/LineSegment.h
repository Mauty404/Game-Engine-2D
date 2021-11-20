#ifndef LAB_LINESEGMENT_H
#define LAB_LINESEGMENT_H

#include "../Point2d/Point2d.h"

class LineSegment{
public:
    LineSegment(Point2d, Point2d);
    sf::VertexArray DrawLine();

private:
    Point2d startLine, endLine;
};

#endif //LAB_LINESEGMENT_H
