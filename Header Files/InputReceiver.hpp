//
// Created by Cassidy Heulings on 1/29/26.
//

#pragma once
#include <SFML/Graphics.hpp>

class InputReceiver {
public:
    void addEvent(sf::Event event); // receive new event
    std::vector<sf::Event>& getEvents(); // return address of event vector
    void clearEvents();
private:
    std::vector<sf::Event> m_Events;
};