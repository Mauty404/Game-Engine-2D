#include "engine.hpp"

const sf::Time Engine::TimePerFrame = seconds(1.f / 60.f);

Engine::Engine() {
    backgroundColor = sf::Color::Black;
}

void Engine::instantiate() {
    window.create(VideoMode(666, 95), "BomberMan", Style::Default);
    window.setFramerateLimit(FPS);

    res1.loadFromFile("assets/res1.png");
    res2.loadFromFile("assets/res2.png");
    res3.loadFromFile("assets/res3.png");
    res4.loadFromFile("assets/res4.png");

    res1s.setTexture(res1);
    res2s.setTexture(res2);
    res3s.setTexture(res3);
    res4s.setTexture(res4);

    res1s.setPosition(2, 2);
    res2s.setPosition(168, 2);
    res3s.setPosition(334, 2);
    res4s.setPosition(500, 2);

    while (window.isOpen()) {
        window.draw(res1s);
        window.draw(res2s);
        window.draw(res3s);
        window.draw(res4s);

        Window1Input();
        window.display();
        window.clear(sf::Color::Black);
    }

}


void Engine::run(int x, int y, Uint32 s) {
    window.create(VideoMode(x, y), "BomberMan", s);
    window.setFramerateLimit(FPS);

    player = new Player();
    player->x = window.getSize().x / 2;
    player->y = window.getSize().y / 2;

    this->point1 = new Point2d(530, 50);
    this->lineSegment = new LineSegment(Point2d(550, 30), Point2d(660, 90));

    this->lineSegment2 = new LineSegment(Point2d(300, 300), Point2d(400, 350));

    //Main loop - runs until the window is closed
    while (window.isOpen()) {
        input();
        draw();
    }
}

void Engine::Window1Input() {
    Event event;
    window.setKeyRepeatEnabled(false);

    while (window.pollEvent(event)) {
        //Close window
        if (event.type == Event::Closed) {
            window.close();
        }

        //Keyboard input
        if (event.type == Event::KeyPressed) {
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                window.close();
            }
        }

        if (res1s.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) &&
            sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            run(800, 600, sf::Style::Default);
        }

        if (res2s.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) &&
            sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            run(1024, 768, sf::Style::Default);
        }

        if (res3s.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) &&
            sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            run(1360, 768, sf::Style::Default);
        }

        if (res4s.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) &&
            sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            run(1920, 1080, sf::Style::Fullscreen);
        }
    }
}