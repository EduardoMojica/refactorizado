#include "ScoreManager.h"
#include <fstream>

ScoreManager::ScoreManager() : score(0), highScore(0) {
    LoadHighScore();
}

void ScoreManager::IncreaseScore() {
    score++;
}

void ScoreManager::ResetScore() {
    score = 0;
}

int ScoreManager::GetScore() const {
    return score;
}

int ScoreManager::GetHighScore() const {
    return highScore;
}

void ScoreManager::SaveHighScore() {
    if (score > highScore) {
        highScore = score;
        std::ofstream file("highscore.bin", std::ios::binary);
        if (file.is_open()) {
            file.write(reinterpret_cast<const char*>(&highScore), sizeof(highScore));
            file.close();
        }
    }
}

void ScoreManager::LoadHighScore() {
    std::ifstream file("highscore.bin", std::ios::binary);
    if (file.is_open()) {
        file.read(reinterpret_cast<char*>(&highScore), sizeof(highScore));
        file.close();
    }
}