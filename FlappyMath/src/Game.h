#ifndef GAME_H
#define GAME_H

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

    int screenWidth;
    int screenHeight;
    Player player;
    Pipe pipes[2]; // Assuming two pipes for the game
    Operation operation;
    ScoreManager scoreManager;
    AudioManager audioManager;
    ResourceManager resourceManager;

    bool isGameOver;
};

#endif // GAME_H