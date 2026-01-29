//
// Created by Cassidy Heulings on 1/29/26.
//

#include "../Header Files/InputReceiver.hpp"
using namespace sf;

void InputReceiver::addEvent(Event event) {
    m_Events.push_back(event); // add event vector of events
}

std::vector<Event> &InputReceiver::getEvents() {
    return m_Events;
}

void InputReceiver::clearEvents() {
    m_Events.clear();
}
