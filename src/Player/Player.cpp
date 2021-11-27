#include "Player.h"

///Player - konstruktor, ładuje z plików wygląd postaci i wycina sprite'y
Player::Player() {
    upT.loadFromFile("assets/player/walk_back.png");
    downT.loadFromFile("assets/player/walk_front.png");
    rightT.loadFromFile("assets/player/walk_right.png");
    leftT.loadFromFile("assets/player/walk_left.png");


    for (int i=0; i<6; i++) {
        rightS[i].setTexture(rightT);
        rightS[i].setTextureRect(sf::IntRect(i*64,0,64,64));
        leftS[i].setTexture(leftT);
        leftS[i].setTextureRect(sf::IntRect(i*64,0,64,64));
        downS[i].setTexture(downT);
        downS[i].setTextureRect(sf::IntRect(i*64,29,64,35));
        upS[i].setTexture(upT);
        upS[i].setTextureRect(sf::IntRect(i*64,29,64,35));
    }

    currentSprite = downS[0];
}

///MoveRight - Przesuń postać w prawo
///@param delta O ile pikseli przesunąć postać
void Player::MoveRight(int delta) {

    x += delta;
    currentSprite = rightS[SetFrame()];
}

///MoveLeft - Przesuń postać w lewo
///@param delta O ile pikseli przesunąć postać
void Player::MoveLeft(int delta) {
    x -= delta;
    currentSprite = leftS[SetFrame()];
}

///MoveUp - Przesuń postać w górę
///@param delta O ile pikseli przesunąć postać
void Player::MoveUp(int delta) {
    y -= delta;
    currentSprite = upS[SetFrame()];
}

///MoveDown - Przesuń postać w dół
///@param delta O ile pikseli przesunąć postać
void Player::MoveDown(int delta) {
    y += delta;
    currentSprite = downS[SetFrame()];
}

///SetFrame - Ustaw odpowiednią klatkę w zależności od czasu, który upłynął
///@return nr klatki, która ma się wyświetlić
int Player::SetFrame() {
    float time = clock.getElapsedTime().asSeconds();

    if (time > 0.0 && time <= 0.1) return 0;
    if (time > 0.1 && time <= 0.2) return 1;
    if (time > 0.2 && time <= 0.3) return 2;

    clock.restart();
    return 3;
}