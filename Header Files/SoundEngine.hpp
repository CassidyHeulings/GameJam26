//
// Created by Cassidy Heulings on 1/29/26.
//

#pragma once
#include <SFML/Audio.hpp>

class SoundEngine {
public:
    SoundEngine();
    // sound engine object variables
    static SoundEngine* m_s_Instance;
    static bool m_MusicIsPlaying;
    // music control functions
    static void startMusic();
    static void pauseMusic();
    static void resumeMusic();
    static void stopMusic();
    // sound control functions
    static void playClick();
private:
    // music
    static sf::Music music;
    // sounds for clicking
    static sf::SoundBuffer m_ClickBuffer;
    static sf::Sound m_ClickSound;
};