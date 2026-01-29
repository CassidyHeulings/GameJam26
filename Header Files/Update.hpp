//
// Created by Cassidy Heulings on 1/29/26.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "Component.hpp"

class LevelUpdate;
class PlayerUpdate;

class Update : public Component {
public:
    Update();
    // used in level update in factory class
    virtual void assemble(
        std::shared_ptr<LevelUpdate> level_update,
        std::shared_ptr<PlayerUpdate> player_update) = 0;
    // will be implemented individually depending on game object instance
    virtual void update(float timeSinceLastUpdate) = 0;
};