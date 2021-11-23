#ifndef LAB_ENGINE_HPP
#define LAB_ENGINE_HPP

#include "SFML/Graphics.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "../src/Point2d/Point2d.h"
#include "../src/LineSegment/LineSegment.h"


using namespace sf;
using namespace std;


class Engine {
private:
    //GameWindow
    RenderWindow window;
    Vector2f resolution;
    CircleShape circleShape;
    const unsigned int FPS = 60;
    static const Time TimePerFrame;

public:
    Engine(unsigned int x, unsigned int y);
    void input();
    void draw();

    // The main loop in run func
    void run();

    Point2d *point1;
    Point2d *point2;
    LineSegment *lineSegment;
};


#endif //LAB_ENGINE_HPP
