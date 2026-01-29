//
// Created by Cassidy Heulings on 1/29/26.
//

#pragma once
#include <iostream>
using namespace std;

// data container for describing type of component
class Component {
public:
    bool m_IsGraphics = false;
    bool m_IsUpdate = false;
};