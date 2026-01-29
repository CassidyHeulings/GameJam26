//
// Created by Cassidy Heulings on 1/29/26.
//

#pragma once
#include "../Header Files/Component.hpp"
#include <SFML/Graphics.hpp>
using namespace sf;

class Update;

class Graphics : public Component {
public:
    Graphics();
    // any class that extends this class must implement:
    // assemble graphic function definition
    virtual void assemble(
        VertexArray& canvas,
        // data from update will correspond to graphics instance
        shared_ptr<Update> genericUpdate,
        // needed to be called by load level function in Factory class
        IntRect textCoords) = 0;
    // draw function definition
    virtual void draw(VertexArray& canvas) = 0;
};