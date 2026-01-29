//
// Created by Cassidy Heulings on 1/29/26.
//

#include "../Header Files/PlayerUpdate.hpp"
#include "../Header Files/LevelUpdate.hpp"
using namespace sf;
using namespace std;

FloatRect* PlayerUpdate::getPositionPointer() {
    return &m_Position; // return position of player
}

float* PlayerUpdate::getRotationPointer() {
    return &m_Rotation;
}

void PlayerUpdate::handleInput() {
    // clear events ready for next iteration of loop
    m_InputReceiver.clearEvents();
}

InputReceiver* PlayerUpdate::getInputReceiver() {
    return &m_InputReceiver; // return the instance of input receiver
}

void PlayerUpdate::assemble(std::shared_ptr<LevelUpdate> levelUpdate, std::shared_ptr<PlayerUpdate> playerUpdate) {
    // player dimensions
    m_Position.width = PLAYER_WIDTH;
    m_Position.height = PLAYER_HEIGHT;
    // level update shared pointer initialized paused var by checking if game is paused
    // tells when to update the level
    m_IsPaused = levelUpdate->getIsPausedPointer();
}

void PlayerUpdate::update(float timeTakenThisFrame) {
    // calls the players specific handle input function
    handleInput();
}