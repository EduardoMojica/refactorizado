#include "Player.h"
#include "raylib.h"

Player::Player(Vector2 position, float radius, Texture2D texture)
    : position(position), radius(radius), velocityY(0), texture(texture) {}

void Player::jump() {
    velocityY = JUMP_SPEED;
}

void Player::update() {
    velocityY += GRAVITY;
    position.y += velocityY;

    if (position.y + radius > GetScreenHeight() || position.y - radius < 0) {
        // Handle collision with screen boundaries
        position.y = Clamp(position.y, radius, GetScreenHeight() - radius);
    }
}

void Player::draw() {
    DrawTexture(texture, position.x - radius, position.y - radius, WHITE);
}

Vector2 Player::getPosition() const {
    return position;
}

float Player::getRadius() const {
    return radius;
}