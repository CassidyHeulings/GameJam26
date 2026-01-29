//
// Created by Cassidy Heulings on 1/29/26.
//

#include "../Header Files/PlayerGraphics.hpp"
#include "../Header Files/PlayerUpdate.hpp"
using namespace sf;
using namespace std;

void PlayerGraphics::assemble(VertexArray &canvas, std::shared_ptr<Update> genericUpdate, IntRect texCoords) {
    // turn the base class update instance into a child class PlayerUpdate instance
    m_PlayerUpdate = static_pointer_cast<PlayerUpdate>(genericUpdate);
    // get the position pointer of the player update instance
    m_Position = m_PlayerUpdate->getPositionPointer();

    // initialize the start index of the canvas
    m_VertexStartIndex = canvas.getVertexCount();
    // add space to the canvas for another quad
    canvas.resize(canvas.getVertexCount() + 4);

    // initialize players texture coordinates (passed in by params)
    canvas[m_VertexStartIndex].texCoords.x = texCoords.left;
    canvas[m_VertexStartIndex].texCoords.y = texCoords.top;
    canvas[m_VertexStartIndex + 1].texCoords.x = texCoords.left + texCoords.width;
    canvas[m_VertexStartIndex + 1].texCoords.y = texCoords.top;
    canvas[m_VertexStartIndex + 2].texCoords.x = texCoords.left + texCoords.width;
    canvas[m_VertexStartIndex + 2].texCoords.y = texCoords.top + texCoords.height;
    canvas[m_VertexStartIndex + 3].texCoords.x = texCoords.left;
    canvas[m_VertexStartIndex + 3].texCoords.y = texCoords.top + texCoords.height;
}

void PlayerGraphics::draw(VertexArray &canvas) {
    // use position and scale to set positions of the player character's vertices in VertexArray
    const Vector2f& position = m_Position->getPosition();
    const Vector2f& scale = m_Position->getSize();
    canvas[m_VertexStartIndex].position = position;
    canvas[m_VertexStartIndex + 1].position = position + Vector2f(scale.x, 0);
    canvas[m_VertexStartIndex + 2].position = position + scale;
    canvas[m_VertexStartIndex + 3].position = position + Vector2f(0, scale.y);
}
