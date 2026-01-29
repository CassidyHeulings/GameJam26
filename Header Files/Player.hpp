//
// Created by Cassidy Heulings on 1/29/26.
//

#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
    Player();
    void spawn(sf::IntRect worldSize, sf::Vector2f res, int sizeTile);
    void resetPlayerStats(); // call end of game
    sf::FloatRect getPosition(); // players pos
    sf::Vector2f getCenter(); // center of player
    float getRotation(); // angle player facing
    sf::Sprite getSprite(); // senf copy to main function
    // movement
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    // stop player from moving in direction
    void stopLeft();
    void stopRight();
    void stopUp();
    void stopDown();
    // TODO add more here
private:
    const float START_SPEED = 200;
    sf::Vector2f position;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f resolution;
    sf::IntRect worldRect;
    // direction player moving
    int tileSize;
    bool upPressed;
    bool downPressed;
    bool rightPressed;
    bool leftPressed;
    float speed; // px/s
};