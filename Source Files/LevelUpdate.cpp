//
// Created by Cassidy Heulings on 1/29/26.
//

#include "../Header Files/LevelUpdate.hpp"
#include "../Header Files/PlayerUpdate.hpp"
#include "../Header Files/SoundEngine.hpp"
using namespace sf;
using namespace std;

bool* LevelUpdate::getIsPausedPointer() {
    return &m_IsPaused;
}

void LevelUpdate::update(float timeSinceLastUpdate) {
    // update level when not paused
    if (!m_IsPaused) {
        // game over update
        if (m_GameOver) {
            // start game
            m_GameOver = false;
            // calls start of game platform positioning
            positionLevelAtStart();
        }
        // game is running
    }
}

void LevelUpdate::assemble(shared_ptr<LevelUpdate> levelUpdate, shared_ptr<PlayerUpdate> playerUpdate) {
    // update players position in class based on player position
    m_PlayerPosition = playerUpdate->getPositionPointer();
    //temp
    SoundEngine::startMusic();
}

void LevelUpdate::positionLevelAtStart() {
    // TODO position player correctly
    m_PlayerPosition->left = m_PlayerPosition->top = 0;
}
