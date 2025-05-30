#include "Game.h"
#include "PipeFactory.h"
#include "OperationFactory.h"
#include "ResourceManager.h"
#include "AudioManager.h"
#include "utils.h"

Game::Game() : score(0), running(true) {}

void Game::init() {
    ResourceManager::getInstance().loadTextures();
    AudioManager::getInstance().loadSounds();
    pipes.clear();
    operations.clear();
    score = 0;
    running = true;
    player = Player();
    spawnPipe();
    spawnOperation();
}

void Game::update() {
    if (!running) return;
    player.update();
    for (auto& pipe : pipes) pipe.update();
    // Lógica de colisiones, puntaje, etc.
}

void Game::draw() {
    DrawTexture(ResourceManager::getInstance().getTexture("background"), 0, 0, WHITE);
    player.draw();
    for (auto& pipe : pipes) pipe.draw();
    // Dibuja operaciones, puntaje, etc.
}

void Game::cleanup() {
    ResourceManager::getInstance().unloadTextures();
    AudioManager::getInstance().unloadSounds();
}

void Game::spawnPipe() {
    int x = SCREEN_WIDTH;
    Pipe newPipe = PipeFactory::createPipe(x);
    pipes.push_back(newPipe);
}

void Game::spawnOperation() {
    Operation op = OperationFactory::createRandomOperation();
    operations.push_back(op);
}

void Game::onScore() {
    AudioManager::getInstance().playSound("score");
    score++;
}