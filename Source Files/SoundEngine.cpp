//
// Created by Cassidy Heulings on 1/29/26.
//

#include "../Header Files/SoundEngine.hpp"
#include <assert.h>
using namespace sf;

// TODO add sound

// initialize sound variables
SoundEngine* SoundEngine::m_s_Instance = nullptr;
bool SoundEngine::m_MusicIsPlaying = false;
Music SoundEngine::music;
SoundBuffer SoundEngine::m_ClickBuffer;
Sound SoundEngine::m_ClickSound;

SoundEngine::SoundEngine() {
    // make sure sound pointer does not already exist
    assert(m_s_Instance == nullptr);
    // declare current instance as this instance
    m_s_Instance = this;
    // load and set sounds
    m_ClickBuffer.loadFromFile("((INSERT HERE))");
    m_ClickSound.setBuffer(m_ClickBuffer);
}

void SoundEngine::startMusic() {
    // load and set music
    music.openFromFile("((INSERT HERE))");
    // play music on a loop
    m_s_Instance->music.play();
    m_s_Instance->music.setLoop(true);
    // music is now playing
    m_MusicIsPlaying = true;
}

void SoundEngine::pauseMusic() {
    // pause music where it is
    m_s_Instance->music.pause();
    // music is no longer playing
    m_MusicIsPlaying = false;
}

void SoundEngine::resumeMusic() {
    // play music from where it is
    m_s_Instance->music.play();
    // music is now playing
    m_MusicIsPlaying = true;
}

void SoundEngine::stopMusic() {
    // stop music completely
    m_s_Instance->music.stop();
    // music is not playing
    m_MusicIsPlaying = false;
}

void SoundEngine::playClick() {
    m_ClickSound.play();
}