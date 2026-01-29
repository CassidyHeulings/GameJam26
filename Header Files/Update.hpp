//
// Created by Cassidy Heulings on 1/29/26.
//

#pragma once
#include "../Header Files/Component.hpp"
#include "SFML/Graphics.hpp"

class LevelUpdate;
class PlayerUpdate;

class Update : public Component {
public:
    Update();
    // used in level update in factory class
    virtual void assemble(
        shared_ptr<LevelUpdate> level_update,
        shared_ptr<PlayerUpdate> player_update) = 0;
    // will be implemented individually depending on game object instance
    virtual void update(float timeSinceLastUpdate) = 0;
};