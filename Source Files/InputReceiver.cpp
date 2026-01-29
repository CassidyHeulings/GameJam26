//
// Created by Cassidy Heulings on 1/29/26.
//

#include "../Header Files/InputReceiver.hpp"

void InputReceiver::addEvent(sf::Event event) {
    m_Events.push_back(event); // add event vector of events
}

std::vector<sf::Event> &InputReceiver::getEvents() {
    return m_Events;
}

void InputReceiver::clearEvents() {
    m_Events.clear();
}
