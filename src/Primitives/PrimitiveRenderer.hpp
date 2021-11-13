#ifndef LAB_PRIMITIVERENDERER_HPP
#define LAB_PRIMITIVERENDERER_HPP

#include "SFML/Graphics.hpp"
#include "engine.hpp"

class PrimitiveRenderer {
private:
    sf::VertexArray fillColors;
public:
    static sf::VertexArray DrawLineIncremental(int x0, int y0, int x1, int y1, sf::Color);
    static sf::Vertex* DrawLine(int x0, int y0, int x1, int y1, sf::Color color);
    static sf::CircleShape DrawCircle(int radius, int x, int y, sf::Color);
    static sf::RectangleShape DrawRectangle(int x, int y, int width, int height, sf::Color color);
    static sf::CircleShape DrawTriangle(int x, int y, int radius, sf::Color color);
    static sf::VertexArray DrawCircleAlg(int x0, int y0, int r, sf::Color color);
    static sf::VertexArray DrawElipseAlg(int x0, int y0, int r1, int r2, sf::Color color);
    static void BoundaryFill(int x, int y, sf::Color boundaryColor, sf::Color fillColor, RenderWindow* window);
};

#endif //LAB_PRIMITIVERENDERER_HPP
