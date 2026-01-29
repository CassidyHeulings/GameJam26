//
// Created by Cassidy Heulings on 1/29/26.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "InputReceiver.hpp"
#include "Update.hpp"

class PlayerUpdate : public Update {
public:
    // set and unset according to how the player interacts with the keyboard
    bool m_RightIsHeldDown = false;
    bool m_LeftIsHeldDown = false;
    bool m_UpIsHeldDown = false;
    bool m_DownIsHeldDown = false;
    // TODO do I need stopDirection()?
    // provides access to m_Position for classes that want it
    sf::FloatRect* getPositionPointer();
    // use input receiver to handle input data received in each frame
    void handleInput();
    InputReceiver* getInputReceiver();
    // from Update : Component
    // prepare player update class for action
    void assemble(
        std::shared_ptr<LevelUpdate> levelUpdate,
        std::shared_ptr<PlayerUpdate> playerUpdate) override;
    // update player function
    void update(float timeTakenThisFrame) override;
private:
    // player dimensions in game units
    // TODO do I need these?
    const float PLAYER_WIDTH = 20.f;
    const float PLAYER_HEIGHT = 16.f;
    // players location
    sf::FloatRect m_Position;
    bool* m_IsPaused = nullptr;
    // speed player can move while on a platform
    const float m_START_SPEED = 150;
    // instance of input receiver class
    InputReceiver m_InputReceiver;
};