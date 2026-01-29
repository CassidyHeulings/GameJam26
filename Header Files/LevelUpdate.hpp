//
// Created by Cassidy Heulings on 1/29/26.
//

#pragma once
#include "Update.hpp"

// uses updateComponent as a base class
class LevelUpdate : public Update {
public:
    // returns pointer to the paused variable
    // TODO enum class for game state?
    bool* getIsPausedPointer();
    // methods from update : component
    // receives time duration that the last loop of the game took to execute
    // needed for timing all actions in update function
    void update(float timeSinceLastUpdate) override;
    // used in factory to prepare the component for use
    void assemble(
        std::shared_ptr<LevelUpdate> levelUpdate,
        std::shared_ptr<PlayerUpdate> playerUpdate) override;
private:
    // pause status
    // TODO change to enum game state?
    bool m_IsPaused = true;
    // pointer to the FloatRect that holds the position of player
    sf::FloatRect* m_PlayerPosition;
    // game over state
    bool m_GameOver = true;
    // sets initial position of all game objects at start of each game
    void positionLevelAtStart();
};