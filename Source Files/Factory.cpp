//
// Created by Cassidy Heulings on 1/29/26.
//

#include "../Header Files/Factory.hpp"
#include <iostream>
#include "../Header Files/InputDispatcher.hpp"
#include "../Header Files/LevelUpdate.hpp"
#include "../Header Files/PlayerGraphics.hpp"
#include "../Header Files/PlayerUpdate.hpp"
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
    // build a level game object
    GameObject level;
    // allocates a LevelUpdate object, stores that shared pointer in levelUpdate variable
    shared_ptr<LevelUpdate> levelUpdate = make_shared<LevelUpdate>();
    level.addComponent(levelUpdate); // level object has level update component
    gameObjects.push_back(level); // level is on the game objects vector

    // build a player object
    GameObject player;
    shared_ptr<PlayerUpdate> playerUpdate = make_shared<PlayerUpdate>();
    playerUpdate->assemble(levelUpdate, nullptr); // player update class does not need a copy of itself
    player.addComponent(playerUpdate); // player has player update component
    // player update instance receives input based on the input receiver
    inputDispatcher.registerNewInputReceiver(playerUpdate->getInputReceiver());
    // create player graphics instance
    shared_ptr<PlayerGraphics> playerGraphics = make_shared<PlayerGraphics>();
    // player graphics will be drawn to the canvas based on player update
    /**
    playerGraphics->assemble(
        canvas, playerUpdate,
        IntRect(
            PLAYER_TEX_LEFT,
            PLAYER_TEX_TOP,
            PLAYER_TEX_WIDTH,
            PLAYER_TEX_HEIGHT));
    */
    player.addComponent(playerGraphics); // player has player graphics component
    gameObjects.push_back(player); // player is a game object
    // make the LevelUpdate aware of the player
    levelUpdate->assemble(nullptr, playerUpdate);

    // set up graphics placement
    canvas.resize(m_WorldWidth * m_WorldHeight * 4);
    // Start at the beginning of the vertex array
    int currVertex = 0;
    // position each vertex in current quad
    for (int w = 0; w < m_WorldWidth; w++) {
        for (int h = 0; h < m_WorldHeight; h++) {
            // set coordinates of vertices
            // upper left
            canvas[currVertex].position = Vector2f(w * TILE_SIDE, h * TILE_SIDE);
            // upper right corner
            canvas[currVertex + 1].position = Vector2f(w * TILE_SIDE + TILE_SIDE, h * TILE_SIDE);
            // bottom right corner
            canvas[currVertex + 2].position = Vector2f(w * TILE_SIDE + TILE_SIDE, h * TILE_SIDE + TILE_SIDE);
            // bottom left corner
            canvas[currVertex + 3].position = Vector2f(w * TILE_SIDE, h * TILE_SIDE + TILE_SIDE);

            // TODO wall texture
            // define position in texture for current quad
            // use wall texture for border tiles (bottom right corner
            if (h == 0 || h == m_WorldHeight - 1 || w == 0 || w == m_WorldWidth - 1) {
                // assign texture coords to vertices
                canvas[currVertex].texCoords = Vector2f((TILE_TYPES - 1) * TILE_SIDE, (TILE_TYPES - 1) * TILE_SIDE);
                canvas[currVertex + 1].texCoords = Vector2f(TILE_TYPES * TILE_SIDE, (TILE_TYPES - 1) * TILE_SIDE);
                canvas[currVertex + 2].texCoords = Vector2f(TILE_TYPES * TILE_SIDE, TILE_TYPES * TILE_SIDE);
                canvas[currVertex + 3].texCoords = Vector2f((TILE_TYPES - 1) * TILE_SIDE, TILE_TYPES * TILE_SIDE);
            }

            else {
                // TODO randomize biome not tile
                // TODO randomize size of biome
                /**
                // randomize tile type
                int rand()
                // vertical reference point within sprite sheet dependent on type num
                int verticalOffset = groundType * TILE_SIDE;
                // assign texture coords to vertices
                canvas[currVertex].texCoords = Vector2f(0, verticalOffset);
                canvas[currVertex + 1].texCoords = Vector2f(TILE_SIDE, verticalOffset);
                canvas[currVertex + 2].texCoords = Vector2f(TILE_SIDE, verticalOffset + TILE_SIDE);
                canvas[currVertex + 3].texCoords = Vector2f(0, verticalOffset + TILE_SIDE);
                */
            }
            // move onto next set of vertices for next tile
            currVertex += 4;
        }
    }
}