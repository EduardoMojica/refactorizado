#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

class Player {
public:
    Player(Vector2 position, float radius, Texture2D texture);
    void jump();
    void update();
    void draw() const;
    Rectangle getCollisionRectangle() const;

    Vector2 getPosition() const;
    float getRadius() const;

private:
    Vector2 position;
    float radius;
    float velocityY;
    Texture2D texture;
    static constexpr float GRAVITY = 0.5f;
    static constexpr float JUMP_SPEED = -8.0f;
};

#endif // PLAYER_H