#include "Game.h"
#include "Player.h"
#include "Pipe.h"
#include "Operation.h"
#include "ScoreManager.h"
#include "AudioManager.h"
#include "ResourceManager.h"
#include "raylib.h"
#include <vector>

class Game {
public:
    Game(int screenWidth, int screenHeight);
    void start();
    void update();
    void draw();
    void reset();

private:
    int screenWidth;
    int screenHeight;
    Player player;
    std::vector<Pipe> pipes;
    Operation operation;
    ScoreManager scoreManager;
    AudioManager audioManager;
    ResourceManager resourceManager;
    bool gameOver;
    void initialize();
    void handleInput();
    void updatePipes();
    void checkCollisions();
    void drawGameObjects();
};

Game::Game(int screenWidth, int screenHeight)
    : screenWidth(screenWidth), screenHeight(screenHeight), player(screenWidth / 2.0f, screenHeight / 2.0f), gameOver(false) {
    initialize();
}

void Game::initialize() {
    resourceManager.loadTextures();
    audioManager.loadSounds();
    operation.generate();
    scoreManager.loadHighScore();
}

void Game::start() {
    while (!WindowShouldClose()) {
        update();
        draw();
    }
}

void Game::update() {
    if (!gameOver) {
        handleInput();
        player.update();
        updatePipes();
        checkCollisions();
    }
}

void Game::draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    drawGameObjects();
    EndDrawing();
}

void Game::reset() {
    player.reset();
    pipes.clear();
    operation.generate();
    scoreManager.resetScore();
    gameOver = false;
}

void Game::handleInput() {
    if (IsKeyPressed(KEY_SPACE)) {
        player.jump();
        audioManager.playSound("wing");
    }
}

void Game::updatePipes() {
    for (auto& pipe : pipes) {
        pipe.update();
        if (pipe.isOffScreen()) {
            pipe.reset();
            scoreManager.increaseScore();
        }
    }
}

void Game::checkCollisions() {
    for (const auto& pipe : pipes) {
        if (CheckCollisionCircleRec(player.getPosition(), player.getRadius(), pipe.getRectangle())) {
            gameOver = true;
            audioManager.playSound("hit");
        }
    }
}

void Game::drawGameObjects() {
    player.draw();
    for (const auto& pipe : pipes) {
        pipe.draw();
    }
    DrawText(TextFormat("Score: %d", scoreManager.getScore()), 10, 10, 20, BLACK);
}