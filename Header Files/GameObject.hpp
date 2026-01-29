//
// Created by Cassidy Heulings on 1/29/26.
//

#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Component.hpp"

class GameObject {
public:
    // add a component to the vector
    void addComponent(std::shared_ptr<Component> newComponent);
    void update(float dt);
    void draw(sf::VertexArray& canvas);
private:
    // holds component instances
    std::vector<std::shared_ptr<Component>> m_Components;
};