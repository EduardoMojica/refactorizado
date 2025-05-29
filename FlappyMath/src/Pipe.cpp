#include "Pipe.h"
#include "raylib.h"

Pipe::Pipe(int screenWidth, int screenHeight, float pipeGap, float pipeWidth, float halfPipeHeight)
    : screenWidth(screenWidth), screenHeight(screenHeight), pipeGap(pipeGap), pipeWidth(pipeWidth), halfPipeHeight(halfPipeHeight)
{
    reset();
}

void Pipe::reset()
{
    int randomY = GetRandomValue(-150, 150);
    float pipeCenterY = (float)(screenHeight / 2) + randomY;

    upperPipe = { (float)screenWidth, pipeCenterY - pipeGap / 2 - halfPipeHeight, pipeWidth, halfPipeHeight };
    lowerPipe = { (float)screenWidth, pipeCenterY + pipeGap / 2, pipeWidth, halfPipeHeight };
}

void Pipe::update(float speed)
{
    upperPipe.x -= speed;
    lowerPipe.x -= speed;
}

void Pipe::draw(Texture2D upperTexture, Texture2D lowerTexture)
{
    DrawTexturePro(upperTexture,
                   { 0, 0, (float)upperTexture.width, (float)upperTexture.height },
                   upperPipe,
                   { 0, 0 }, 0, WHITE);

    DrawTexturePro(lowerTexture,
                   { 0, 0, (float)lowerTexture.width, (float)lowerTexture.height },
                   lowerPipe,
                   { 0, 0 }, 0, WHITE);
}

Rectangle Pipe::getUpperPipe() const
{
    return upperPipe;
}

Rectangle Pipe::getLowerPipe() const
{
    return lowerPipe;
}