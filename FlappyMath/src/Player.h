#pragma once
#include "raylib.h"

class Player {
public:
    Player();
    void update();
    void draw();
    void jump();
    Rectangle getBounds() const;
    float x, y, velocity;
};