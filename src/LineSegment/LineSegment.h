#ifndef LAB_LINESEGMENT_H
#define LAB_LINESEGMENT_H

#include "../Point2d/Point2d.h"

class LineSegment : public TransformableObject {
public:
    LineSegment();
    LineSegment(Point2d, Point2d);

    sf::VertexArray DrawLine();

    void Translate(int x, int y) override;
    void Rotate(float alpha) override;
    void Rotate(int x, int y, float alpha) override;
    void Scale(float k) override;
    void Scale(int x, int y, float k) override;

private:
    Point2d startLine, endLine;
};

#endif //LAB_LINESEGMENT_H
