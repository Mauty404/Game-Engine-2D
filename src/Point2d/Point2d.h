#ifndef LAB_POINT2D_H
#define LAB_POINT2D_H

#include <SFML/Graphics/CircleShape.hpp>
#include "../TransformableObject.h"


class Point2d : public TransformableObject {
public:

    int x, y;


    Point2d();
    Point2d(int x, int y);
    int GetX();
    int GetY();
    void SetPoint(int, int);
    static sf::CircleShape DrawPoint(Point2d);

    void Translate(int x, int y) override;
    void Rotate(float alpha) override;
    void Rotate(int x, int y, float alpha) override;
};

#endif //LAB_POINT2D_H
