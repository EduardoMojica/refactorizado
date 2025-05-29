#ifndef PIPE_H
#define PIPE_H

#include "raylib.h"

class Pipe {
public:
    Pipe(float x, float y, float width, float height);
    void update(float speed);
    void draw(Texture2D texture);
    void reset(float x, float y);
    Rectangle getCollisionRect() const;

private:
    Rectangle collisionRect;
};

#endif // PIPE_H