#include "AudioManager.h"
#include "raylib.h"

AudioManager::AudioManager() {}

AudioManager::~AudioManager() {
    UnloadSounds();
}

void AudioManager::loadSounds() {
    // Load sound assets
    soundJump = LoadSound("assets/audio/wing.wav");
    soundHit = LoadSound("assets/audio/hit.wav");
    soundDie = LoadSound("assets/audio/die.wav");
    soundPoint = LoadSound("assets/audio/point.wav");
    musicBackground = LoadMusicStream("assets/audio/musicita.mp3");
}

void AudioManager::playSound(Sound sound) {
    PlaySound(sound);
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

void AudioManager::UnloadSounds() {
    UnloadSound(soundJump);
    UnloadSound(soundHit);
    UnloadSound(soundDie);
    UnloadSound(soundPoint);
    UnloadMusicStream(musicBackground);
}