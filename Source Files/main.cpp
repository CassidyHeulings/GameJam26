//
// Created by Cassidy Heulings on 1/27/26.
//

#include <SFML/Graphics.hpp>
using namespace sf;

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

    // initialize game variables
    Vector2f mouseWorldPosition;
    Vector2i mouseScreenPosition;
    IntRect world;

    // game loop
    while (window.isOpen()) {

    }
    return 0;
}