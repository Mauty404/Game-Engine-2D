#ifndef LAB_LINESEGMENT_H
#define LAB_LINESEGMENT_H

#include "../Point2d/Point2d.h"

class LineSegment{
private:
    Point2d startLine, endLine;

    void DrawLine(Point2d start, Point2d end);
};

#endif //LAB_LINESEGMENT_H
