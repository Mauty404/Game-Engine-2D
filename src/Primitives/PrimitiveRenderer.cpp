#include "PrimitiveRenderer.hpp"

sf::VertexArray PrimitiveRenderer::DrawLineIncremental(int x0, int y0, int x1, int y1, sf::Color color) {
    sf::Vector2 startPoint(x0, y0);
    sf::Vector2 endPoint(x1, y1);
    float dy, dx, y, m;

    dy = abs(y1 - y0);
    dx = abs(x1 - x0);
    m = dy / dx;
    y = y0;

    sf::VertexArray pointMap(sf::Points, dx);

    pointMap[0].position = sf::Vector2f(x0, y0);
    pointMap[0].color = color;

    int i =1;

    for(int x = x0;x < x1 && i < dx;x++) {
        pointMap[i].position = sf::Vector2f(x, y);
        pointMap[i].color = color;
        y += m;
        i++;
    }

    return pointMap;
}

sf::Vertex* PrimitiveRenderer::DrawLine(int x0, int y0, int x1, int y1, sf::Color color) {
    sf::Vertex* line = new sf::Vertex[2];
    line[0].position = sf::Vector2f(x0,y0);
    line[0].color = color;
    line[1].position = sf::Vector2f(x1,y1);
    line[1].color = color;
    return line;
}

sf::CircleShape PrimitiveRenderer::DrawCircle(int radius, int x, int y, sf::Color color) {
    sf::CircleShape circle(radius);
    circle.setFillColor(color);
    circle.setPosition(x,y);
    return circle;
}

sf::RectangleShape PrimitiveRenderer::DrawRectangle(int x, int y, int width, int height, sf::Color color) {
    sf:RectangleShape rectangleShape(sf::Vector2f(width, height));
    rectangleShape.setFillColor(color);
    rectangleShape.setPosition(x, y);
    return rectangleShape;
}

sf::CircleShape PrimitiveRenderer::DrawTriangle(int x, int y, int radius, sf::Color color) {
    sf:CircleShape triangle(radius, 3);
    triangle.setFillColor(color);
    triangle.setPosition(x, y);
    return triangle;
}