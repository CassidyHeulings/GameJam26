//
// Created by Cassidy Heulings on 1/29/26.
//

#include "../Header Files/Factory.hpp"
#include <iostream>
using namespace sf;
using namespace std;

// TODO test texture here

Factory::Factory(RenderWindow *window) {
    m_Window = window;
    // allocate space for a new texture
    m_Texture = new Texture();
    // check if texture loads in
    if (!m_Texture->loadFromFile("((FILL IN HERE))")) {
        cout << "Texture not loaded";
        return;
    }
}

void Factory::loadLevel(vector<GameObject> &gameObjects, VertexArray &canvas,
    InputDispatcher &inputDispatcher) {
    // fill in later
}