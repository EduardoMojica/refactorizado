#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include "raylib.h"
#include <string>

class AudioManager {
public:
    AudioManager();
    ~AudioManager();

    void loadSounds();
    void playSound(const std::string& soundName);
    void stopMusic();
    void playMusic(const std::string& musicName);
    void updateMusicStream();

private:
    Sound wingSound;
    Sound hitSound;
    Sound dieSound;
    Sound pointSound;
    Music backgroundMusic;

    void unloadSounds();
};

#endif // AUDIOMANAGER_H