#ifndef LAB_ENGINE_HPP
#define LAB_ENGINE_HPP

#include "SFML/Graphics.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

using namespace sf;
using namespace std;


class Engine {
private:
    //Window
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
};


#endif //LAB_ENGINE_HPP
