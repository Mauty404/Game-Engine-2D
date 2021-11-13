#ifndef LAB_POINT2D_H
#define LAB_POINT2D_H

#include <SFML/Graphics/CircleShape.hpp>

class Point2d{
public:
    Point2d(int x, int y);
    Point2d GetPoint();
    void SetPoint(int, int);
    static sf::CircleShape DrawPoint(Point2d);

    int x, y;

private:

};

#endif //LAB_POINT2D_H
