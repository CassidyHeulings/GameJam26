//
// Created by Cassidy Heulings on 1/29/26.
//

#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class InputDispatcher;

class Factory {
public:
    Factory(sf::RenderWindow* window);
    // create level
    /**
    void loadLevel(
        std::vector <GameObject>& gameObjects,
        sf::VertexArray& canvas,
        InputDispatcher& inputDispatcher);
        */
    sf::Texture* m_Texture;
private:
    // pointer to game window
    sf::RenderWindow* m_Window;
};