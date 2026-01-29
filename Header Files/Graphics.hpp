//
// Created by Cassidy Heulings on 1/29/26.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "Component.hpp"

class Update;

class Graphics : public Component {
public:
    Graphics();
    // any class that extends this class must implement:
    // assemble graphic function definition
    virtual void assemble(
        sf::VertexArray& canvas,
        // data from update will correspond to graphics instance
        std::shared_ptr<Update> genericUpdate,
        // needed to be called by load level function in Factory class
        sf::IntRect textCoords) = 0;
    // draw function definition
    virtual void draw(sf::VertexArray& canvas) = 0;
};