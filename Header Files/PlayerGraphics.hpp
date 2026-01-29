//
// Created by Cassidy Heulings on 1/29/26.
//

#pragma once
#include "Graphics.hpp"

//class Animator;
class PlayerUpdate;

class PlayerGraphics : public Graphics {
public:
    // from GraphicsComponent : Component
    void assemble(sf::VertexArray& canvas,
        std::shared_ptr<Update> genericUpdate,
        sf::IntRect texCoords) override;
    void draw(sf::VertexArray& canvas) override;
private:
    // pointer to position of player
    sf::FloatRect* m_Position = nullptr;
    // TODO fix this start index
    // position in the vertex array where the quad representing the player will start
    int m_VertexStartIndex = -999;
    // we will come back to this soon
    //Animator* m_Animator;
    // holds the integer texture coordinates within the texture atlas
    // of the current frame of animation for the player
    sf::IntRect* m_SectionToDraw = new sf::IntRect;
    // texture coordinates for when player is not moving
    sf::IntRect* m_StandingStillSectionToDraw = new sf::IntRect;
    // points to player update instance
    // will allow class to call all public functions/variables of PlayerUpdate class
    std::shared_ptr<PlayerUpdate> m_PlayerUpdate;
    // keeps track of side player is facing
    // used for animating
    char m_LastFacingDirection = 'S';
};