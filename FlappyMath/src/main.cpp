#include "raylib.h"
#include "Game.h"

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "FlappyMath");
    InitAudioDevice();

    Game game;
    game.init();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        game.update();
        game.draw();

        EndDrawing();
    }

    game.cleanup();
    CloseAudioDevice();
    CloseWindow();
    return 0;
}