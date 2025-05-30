#include "AudioManager.h"
#include "raylib.h"

AudioManager::AudioManager() {}

AudioManager& AudioManager::getInstance() {
    static AudioManager instance;
    return instance;
}

void AudioManager::loadSounds() {
    // Load sound assets
    sounds["jump"] = LoadSound("assets/audio/wing.wav");
    sounds["score"] = LoadSound("assets/audio/point.wav");
    sounds["hit"] = LoadSound("assets/audio/hit.wav");
    soundDie = LoadSound("assets/audio/die.wav");
    musicBackground = LoadMusicStream("assets/audio/musicita.mp3");
}

void AudioManager::playSound(const std::string& name) {
    if (sounds.count(name)) PlaySound(sounds[name]);
}

void AudioManager::playMusic() {
    PlayMusicStream(musicBackground);
}

void AudioManager::stopMusic() {
    StopMusicStream(musicBackground);
}

void AudioManager::updateMusic() {
    UpdateMusicStream(musicBackground);
}

void AudioManager::unloadSounds() {
    for (auto& pair : sounds) {
        UnloadSound(pair.second);
    }
    sounds.clear();
}