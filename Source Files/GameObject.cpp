//
// Created by Cassidy Heulings on 1/29/26.
//

#include "../Header Files/GameObject.hpp"
#include <SFML/Graphics.hpp>
#include "../Header Files/Graphics.hpp"
#include "../Header Files/Update.hpp"
using namespace std;
using namespace sf;

void GameObject::addComponent(shared_ptr<Component> newComponent) {
    m_Components.push_back(newComponent); // add the component
}

void GameObject::update(float dt) {
    // loop through each component
    for (auto component : m_Components) {
        // checks if component is updatable
        if (component->m_IsUpdate) {
            // component instance will execute its own version of update function
            static_pointer_cast<Update>(component)->update(dt);
        }
    }
}

void GameObject::draw(VertexArray &canvas) {
    // loop through each component
    for (auto component : m_Components) {
        // check if component is drawable
        if (component->m_IsGraphics) {
            // component instance will execute its own version of draw function
            static_pointer_cast<Graphics>(component)->draw(canvas);
        }
    }
}