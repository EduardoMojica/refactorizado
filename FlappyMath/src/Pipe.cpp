#include "Pipe.h"
#include "ResourceManager.h"
#include "utils.h"

Pipe::Pipe(int x_, int gapY_) : x(x_), gapY(gapY_) {}

void Pipe::update() {
    x -= PIPE_SPEED;
}

void Pipe::draw() {
    Texture2D pipeTexture = ResourceManager::getInstance().getTexture("pipe");
    DrawTexture(pipeTexture, x, gapY - PIPE_GAP / 2 - HALF_PIPE_HEIGHT, WHITE); // Superior
    DrawTexture(pipeTexture, x, gapY + PIPE_GAP / 2, WHITE); // Inferior
}

Rectangle Pipe::getUpperBounds() const {
    return { (float)x, 0, (float)PIPE_WIDTH, (float)(gapY - PIPE_GAP / 2) };
}

Rectangle Pipe::getLowerBounds() const {
    return { (float)x, (float)(gapY + PIPE_GAP / 2), (float)PIPE_WIDTH, (float)(SCREEN_HEIGHT - (gapY + PIPE_GAP / 2)) };
}