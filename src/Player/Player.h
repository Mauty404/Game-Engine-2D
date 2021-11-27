
#ifndef GAME_ENGINE_2D_PLAYER_H
#define GAME_ENGINE_2D_PLAYER_H

#include "SFML/Graphics.hpp"

class Player {
public:
    sf::Sprite currentSprite;
    int x;
    int y;

    class RigidBody{
    public:
        int width;
        int height;
    };

    RigidBody rb;

private:
    sf::Texture upT;
    sf::Texture downT;
    sf::Texture leftT;
    sf::Texture rightT;

    sf::Sprite upS[6];
    sf::Sprite downS[6];
    sf::Sprite leftS[6];
    sf::Sprite rightS[8];

    sf::Clock clock;

public:
    Player();
    void MoveUp(int delta);
    void MoveDown(int delta);
    void MoveLeft(int delta);
    void MoveRight(int delta);

private:
    int SetFrame();
};

#endif //GAME_ENGINE_2D_PLAYER_H
