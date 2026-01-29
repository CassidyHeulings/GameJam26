//
// Created by Cassidy Heulings on 1/29/26.
//

#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

class InputDispatcher;

class Factory {
public:
    Factory(sf::RenderWindow* window);
    // create level
    void loadLevel(
        std::vector <GameObject>& gameObjects,
        sf::VertexArray& canvas,
        InputDispatcher& inputDispatcher);
    sf::Texture* m_Texture;
private:
    // pointer to game window
    sf::RenderWindow* m_Window;
    // TODO texture coordinates of all images in texture atlas
    // player texture details
    const int PLAYER_TEX_LEFT = 0;
    const int PLAYER_TEX_TOP = 0;
    const int PLAYER_TEX_WIDTH = 0;
    const int PLAYER_TEX_HEIGHT = 0;
    // camera details
    const float CAM_VIEW_WIDTH = 300.f;
    const float CAM_SCREEN_RATIO_LEFT = 0.f;
    const float CAM_SCREEN_RATIO_TOP = 0.f;
    const float CAM_SCREEN_RATIO_WIDTH = 1.f;
    const float CAM_SCREEN_RATIO_HEIGHT = 1.f;
    // camera texture details
    const int CAM_TEX_LEFT = 610;
    const int CAM_TEX_TOP = 36;
    const int CAM_TEX_WIDTH = 40;
    const int CAM_TEX_HEIGHT = 30;
    // map details
    const float MAP_CAM_SCREEN_RATIO_LEFT = 0.3f;
    const float MAP_CAM_SCREEN_RATIO_TOP = 0.84f;
    const float MAP_CAM_SCREEN_RATIO_WIDTH = 0.4f;
    const float MAP_CAM_SCREEN_RATIO_HEIGHT = 0.15f;
    const float MAP_CAM_VIEW_WIDTH = 800.f;
    const float MAP_CAM_VIEW_HEIGHT = MAP_CAM_VIEW_WIDTH / 2;
    // map texture details
    const int MAP_CAM_TEX_LEFT = 665;
    const int MAP_CAM_TEX_TOP = 0;
    const int MAP_CAM_TEX_WIDTH = 100;
    const int MAP_CAM_TEX_HEIGHT = 70;
    // menu details
    const int TOP_MENU_TEX_LEFT = 770;
    const int TOP_MENU_TEX_TOP = 0;
    const int TOP_MENU_TEX_WIDTH = 100;
    const int TOP_MENU_TEX_HEIGHT = 100;
};