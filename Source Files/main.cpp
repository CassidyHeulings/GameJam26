//
// Created by Cassidy Heulings on 1/27/26.
//

#include <SFML/Graphics.hpp>
#include "../Header Files/Player.hpp"

using namespace sf;
using namespace std;

int main() {
    // initialize game states
    enum class State { GAME_OVER, CRAFTING, PLAYING };
    State state = State::GAME_OVER; // start game in game over state

    // create window with screen resolution
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    RenderWindow window(VideoMode(resolution.x, resolution.y), "Mask", Style::Fullscreen);
    View mainView(FloatRect(0,0, resolution.x, resolution.y));

    // vertex array to hold all graphics
    VertexArray canvas(Quads, 0);
    // TODO fill these in when classes are created
    // dispatch events to objects
    // vector to hold game objects
    // factory to construct game objects
    // send game elements to factory to set up game

    // initialize game variables
    Vector2f mouseWorldPosition;
    Vector2i mouseScreenPosition;
    Clock clock;
    IntRect world;

    // game loop
    while (window.isOpen()) {
        float dt = clock.restart().asSeconds(); // time per frame
        // TODO fill these in when classes are made
        // dispatch input to objects
        window.clear(); // clear frame
        // update game objects
        // draw game objects to canvas
        window.display(); // show next frame
    }

    return 0;
}