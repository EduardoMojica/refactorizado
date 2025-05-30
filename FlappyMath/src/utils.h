#ifndef UTILS_H
#define UTILS_H

#include "raylib.h"

const int SCREEN_WIDTH = 1525;
const int SCREEN_HEIGHT = 830;

const float GRAVITY = 0.5f;
const float JUMP_SPEED = -8.0f;
const int PIPE_SPEED = 5;
const int PIPE_GAP = 400;
const int PIPE_WIDTH = 100;
const int HALF_PIPE_HEIGHT = 150;
const int ANSWER_SPACE_HEIGHT = 200;
const int ANSWER_SPACE_WIDTH = 50;

void DrawCenteredText(const char* text, int y, int fontSize, Color color);
void DrawRectangleOutline(Rectangle rect, Color color);

#endif // UTILS_H