#pragma once
#include "raylib.h"

class Pipe {
public:
    Pipe(int x, int gapY);
    void update();
    void draw();
    Rectangle getUpperBounds() const;
    Rectangle getLowerBounds() const;
    int x, gapY;
};