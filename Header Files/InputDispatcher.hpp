//
// Created by Cassidy Heulings on 1/29/26.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "InputReceiver.hpp"

class InputDispatcher {
public:
    InputDispatcher(sf::RenderWindow* window); // use inputs from window
    void dispatchInputEvents(); // send out events
    void registerNewInputReceiver(InputReceiver* ir); // make input receivers
private:
    sf::RenderWindow* m_Window; // address of window
    std::vector<InputReceiver*> m_InputReceivers; // pointers to address of receivers
};