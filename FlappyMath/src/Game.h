#pragma once
#include <vector>
#include "Player.h"
#include "Pipe.h"
#include "Operation.h"
#include "ScoreManager.h"
#include "AudioManager.h"
#include "ResourceManager.h"

class Game {
public:
    Game(int screenWidth, int screenHeight);
    ~Game();

    void start();
    void update();
    void draw();
    void reset();

private:
    void initialize();
    void handleInput();
    void updateGameObjects();
    void checkCollisions();
    void drawGameObjects();
    void drawUI();
    void spawnPipe();
    void spawnOperation();
    void onScore();

    int screenWidth;
    int screenHeight;
    Player player;
    std::vector<Pipe> pipes;
    std::vector<Operation> operations;
    ScoreManager scoreManager;
    AudioManager audioManager;
    ResourceManager resourceManager;

    int score;
    bool isGameOver;
    bool running;
};