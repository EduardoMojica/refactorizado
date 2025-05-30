#include "Player.h"
#include "ResourceManager.h"
#include "AudioManager.h"
#include "utils.h"

Player::Player() : x(200), y(SCREEN_HEIGHT / 2), velocity(0) {}

void Player::update() {
    velocity += GRAVITY;
    y += velocity;
    if (y < 0) y = 0;
    if (y > SCREEN_HEIGHT - 50) y = SCREEN_HEIGHT - 50;
}

void Player::draw() {
    Texture2D playerTexture = ResourceManager::getInstance().getTexture("player");
    DrawTexture(playerTexture, x, y, WHITE);
}

void Player::jump() {
    velocity = JUMP_SPEED;
    AudioManager::getInstance().playSound("jump");
}

Rectangle Player::getBounds() const {
    return { x, y, 50, 50 };
}