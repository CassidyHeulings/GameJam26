//
// Created by Cassidy Heulings on 1/27/26.
//

#include <SFML/Graphics.hpp>
#include "../Header Files/Factory.hpp"
#include "../Header Files/GameObject.hpp"
#include "../Header Files/InputDispatcher.hpp"
using namespace sf;
using namespace std;

// TODO add states to other classes
// TODO add mouse position to other classes

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
    VertexArray canvas(Quads);
    InputDispatcher inputDispatcher(&window); // dispatch events to objects
    vector <GameObject> gameObjects; // vector to hold game objects
    Factory factory(&window); // factory to construct game objects
    factory.loadLevel(gameObjects, canvas, inputDispatcher); // send game elements to factory to set up game

    // initialize game variables
    Vector2f mouseWorldPosition;
    Vector2i mouseScreenPosition;
    Clock clock;
    IntRect world;

    // game loop
    while (window.isOpen()) {
        float dt = clock.restart().asSeconds(); // time per frame
        inputDispatcher.dispatchInputEvents(); // dispatch input to objects
        window.clear(); // clear frame
        // update game objects
        for (auto& gameObject : gameObjects) {
            gameObject.update(dt);
        }
        // draw game objects to canvas
        for (auto& gameObject : gameObjects) {
            gameObject.draw(canvas);
        }
        window.display(); // show next frame
    }

    return 0;
}