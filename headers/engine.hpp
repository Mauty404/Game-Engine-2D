#ifndef LAB_ENGINE_HPP
#define LAB_ENGINE_HPP

#include "SFML/Graphics.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "../src/Point2d/Point2d.h"
#include "../src/LineSegment/LineSegment.h"
#include "../src/Player/Player.h"


using namespace sf;
using namespace std;


class Engine {
private:
    //GameWindow
    RenderWindow window;
    Player* player;
    const unsigned int FPS = 60;
    static const Time TimePerFrame;
    sf::Color backgroundColor;

    sf::Texture res1;
    sf::Texture res2;
    sf::Texture res3;
    sf::Texture res4;

    sf::Sprite res1s;
    sf::Sprite res2s;
    sf::Sprite res3s;
    sf::Sprite res4s;

    bool drawPrimitives = false;
    bool drawLine = false;
    bool drawPoint1 = false;
    bool drawLinePoints = false;
    bool drawCircle = false;
    bool drawEmptyPrimitives = false;
    bool borderFill = false;
    bool floodFill = false;
    bool drawLine2 = false;
    bool scaleLine1 = true;
    bool scaleLine2 = true;
    bool translateLine = true;

public:
    Engine();
    void instantiate();
    void Window1Input();
    void input();
    void draw();

    // The main loop in run func
    void run(int x, int y, Uint32 s);

    Point2d *point1;
    Point2d *point2;
    LineSegment *lineSegment;
    LineSegment *lineSegment2;
};


#endif //LAB_ENGINE_HPP
