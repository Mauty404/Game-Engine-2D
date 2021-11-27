#include "PrimitiveRenderer.hpp"
#include <cmath>
#include <queue>
#include <iostream>

/// DrawLineIncremental - rysowanie linii algorytmem inkrementacyjnym
/// @param x0 współrzędna pozioma punktu początkowego
/// @param y0 współrzędna pionowa punktu początkowego
/// @param x1 współrzędna pozioma punktu końcowego
/// @param y1 współrzędna pionowa punktu końcowego
/// @param color kolor linii
/// @return VertexArray, czyli tablica wierzchołków, w której zapisane są punkty linii do narysowania
sf::VertexArray PrimitiveRenderer::DrawLineIncremental(int x0, int y0, int x1, int y1, sf::Color color) {

    if(x0>x1) swap(x0, x1);
    if(y0>y1) swap(y0, y1);

    sf::Vector2 startPoint(x0, y0);
    sf::Vector2 endPoint(x1, y1);
    float dy, dx, y, x, m;

    dy = abs(y1 - y0);
    dx = abs(x1 - x0);
    m = dy / dx;
    y = y0;
    x = x0;

    if (abs(m) <= 1) {
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
    } else {
        m = dx/dy;
        sf::VertexArray pointMap(sf::Points, dy);

        pointMap[0].position = sf::Vector2f(x0, y0);
        pointMap[0].color = color;

        int i =1;

        for(int y = y0;y < y1 && i < dy;y++) {
            pointMap[i].position = sf::Vector2f(x, y);
            pointMap[i].color = color;
            x += m;
            i++;
        }

        return pointMap;
    }


}

/// DrawLine - rysowanie linii metodą z biblioteki SFML
/// @param x0 współrzędna pozioma punktu początkowego
/// @param y0 współrzędna pionowa punktu początkowego
/// @param x1 współrzędna pozioma punktu końcowego
/// @param y1 współrzędna pionowa punktu końcowego
/// @param color kolor linii
/// @return Vertex* wskaźnik na tablicę Vertex, która zawiera punkty, do linii którą chcemy narysować
sf::Vertex* PrimitiveRenderer::DrawLine(int x0, int y0, int x1, int y1, sf::Color color) {
    sf::Vertex* line = new sf::Vertex[2];
    line[0].position = sf::Vector2f(x0,y0);
    line[0].color = color;
    line[1].position = sf::Vector2f(x1,y1);
    line[1].color = color;
    return line;
}

/// DrawCircle - rysowanie koła metodą z biblioteki SFML
/// @param radius promień koła
/// @param x współrzędna pozioma środka koła
/// @param y współrzędna pionowa środka koła
/// @param color kolor linii
/// @return CircleShape, w którym zapisane są współrzędne punktu, który chcemy narysować oraz jego promień i kolor
sf::CircleShape PrimitiveRenderer::DrawCircle(int radius, int x, int y, sf::Color color) {
    sf::CircleShape circle(radius);
    circle.setFillColor(color);
    circle.setPosition(x,y);
    return circle;
}

/// DrawCircle - rysowanie prostokąta metodą z biblioteki SFML
/// @param x współrzędna pozioma początku prostokąta (lewy górny róg)
/// @param y współrzędna pionowa początku prostokąta (lewy górny róg)
/// @param width szerokość prostokąta
/// @param height wysokość prostokąta
/// @param color kolor linii
/// @return RectangleShape, w którym zapisane są współrzędne punktu, który chcemy narysować oraz jego kolor, wysokość i szerokość
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

sf::VertexArray PrimitiveRenderer::DrawCircleAlg(int x0, int y0, int r, sf::Color color) {
    float step;
    int x, y;

    queue<int> xList;
    queue<int> yList;

    step = (float)1.0/r;
    float b = M_PI/2;

    int i = 0;
    for(float a=0; a < M_PI/2; a+=step) {
        x = x0+r*cos(a)+0,5;
        y = y0+r*sin(a)+0,5;

        xList.push(x);
        yList.push(y);
        i++;
    }

    sf::VertexArray pointMap(sf::Points, 4*i);

    int deltaX, deltaY;
    for(int j=0; j<i; j++) {
        deltaX = xList.front()-x0;
        deltaY = yList.front()-y0;
        pointMap[j].position = sf::Vector2f(xList.front(),yList.front());
        pointMap[j].color = color;
        pointMap[j+i].position = sf::Vector2f(xList.front(),yList.front()-2*deltaY);
        pointMap[j+i].color = color;
        pointMap[j+2*i].position = sf::Vector2f(xList.front()-2*deltaX,yList.front()-2*deltaY);
        pointMap[j+2*i].color = color;
        pointMap[j+3*i].position = sf::Vector2f(xList.front()-2*deltaX,yList.front());
        pointMap[j+3*i].color = color;
        xList.pop();
        yList.pop();
    }

    return pointMap;
}

sf::VertexArray PrimitiveRenderer::DrawElipseAlg(int x0, int y0, int r1, int r2, sf::Color color) {

    float step;
    int x, y;

    queue<int> xList;
    queue<int> yList;

    step = (float)1.0/r1;
    float b = M_PI/2;

    int i = 0;
    for(float a=0; a < M_PI/2; a+=step) {
        x = x0+r1*cos(a)+0,5;
        y = y0+r2*sin(a)+0,5;

        xList.push(x);
        yList.push(y);
        i++;
    }

    sf::VertexArray pointMap(sf::Points, 4*i);

    int deltaX, deltaY;
    for(int j=0; j<i; j++) {
        deltaX = xList.front()-x0;
        deltaY = yList.front()-y0;
        pointMap[j].position = sf::Vector2f(xList.front(),yList.front());
        pointMap[j].color = color;
        pointMap[j+i].position = sf::Vector2f(xList.front(),yList.front()-2*deltaY);
        pointMap[j+i].color = color;
        pointMap[j+2*i].position = sf::Vector2f(xList.front()-2*deltaX,yList.front()-2*deltaY);
        pointMap[j+2*i].color = color;
        pointMap[j+3*i].position = sf::Vector2f(xList.front()-2*deltaX,yList.front());
        pointMap[j+3*i].color = color;
        xList.pop();
        yList.pop();
    }

    return pointMap;
}

void PrimitiveRenderer::BorderFill(int x, int y, sf::Color boundaryColor, sf::Color fillColor, RenderWindow* window) {

//    auto color = window->capture().getPixel(x,y);
//    if (color != sf::Color::Black && color != fillColor) {
//        sf::Vertex point(sf::Vector2f(x, y), fillColor);
//        window->draw(&point, 1, sf::Points);
//
//        BoundaryFill(x+1, y, boundaryColor, fillColor, window);
//        BoundaryFill(x, y+1, boundaryColor, fillColor, window);
//        BoundaryFill(x-1, y, boundaryColor, fillColor, window);
//        BoundaryFill(x, y-1, boundaryColor, fillColor, window);
//    }

    auto seedColor = window->capture().getPixel(x,y);
    queue<Point2d> points;
    points.push(Point2d(x,y));

    while (!points.empty()) {
        window->display();
        Point2d point = points.front();
        points.pop();

        auto color = window->capture().getPixel(point.x, point.y);

        if (color == fillColor || color == boundaryColor) continue;

        sf::Vertex toColor(sf::Vector2f(point.x, point.y), fillColor);
        window->draw(&toColor, 1, sf::Points);

        points.push(Point2d(point.x+1, point.y));
        points.push(Point2d(point.x-1, point.y));
        points.push(Point2d(point.x, point.y+1));
        points.push(Point2d(point.x, point.y-1));
    }


//    const auto color = window->capture().getPixel(x,y);
//    queue<Point2d> points;
//    points.push(Point2d(x,y));
//
//    while (!points.empty()) {
//
//
//        Point2d point2D(points.front());
//        cout << point2D.x << "\n" ;
//        points.pop();
//
//        if (color == boundaryColor || color == fillColor) continue;
//
//        sf::Vertex point(sf::Vector2f(point2D.x, point2D.y), fillColor);
//        window->draw(&point, 1, sf::Points);
//
//        points.push(Point2d(point2D.x+1, point2D.y));
//        points.push(Point2d(point2D.x-1, point2D.y));
//        points.push(Point2d(point2D.x, point2D.y+1));
//        points.push(Point2d(point2D.x, point2D.y-1));
//
//        window->display();
//    }
//
//    return;
}

void PrimitiveRenderer::FloodFill(int x, int y, sf::Color backgroundColor, sf::Color fillColor, RenderWindow *window) {
    auto seedColor = window->capture().getPixel(x,y);
    queue<Point2d> points;
    points.push(Point2d(x,y));

    while (!points.empty()) {
        window->display();
        Point2d point = points.front();
        points.pop();

        auto color = window->capture().getPixel(point.x, point.y);

        if (color == fillColor || color != backgroundColor) continue;

        sf::Vertex toColor(sf::Vector2f(point.x, point.y), fillColor);
        window->draw(&toColor, 1, sf::Points);

        points.push(Point2d(point.x+1, point.y));
        points.push(Point2d(point.x-1, point.y));
        points.push(Point2d(point.x, point.y+1));
        points.push(Point2d(point.x, point.y-1));
    }
}

