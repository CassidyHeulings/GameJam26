//
// Created by Cassidy Heulings on 1/29/26.
//

#include "../Header Files/InputDispatcher.hpp"
using namespace sf;

InputDispatcher::InputDispatcher(RenderWindow *window) {
    m_Window = window; // sets window pointer to game window
}
// send out events to receivers
void InputDispatcher::dispatchInputEvents() {
    Event event;
    // get all events from window
    while (m_Window->pollEvent(event)) {
        // TODO temporary close game
        if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
          m_Window->close(); // close game window
        }
        // iterate through each object in input receiver vector
        for (const auto& ir : m_InputReceivers) {
            ir->addEvent(event); // call add event function
        }
    }
}
// add input receiver to dispatcher list
void InputDispatcher::registerNewInputReceiver(InputReceiver* ir) {
    m_InputReceivers.push_back(ir);
}