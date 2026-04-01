#include <iostream>
#include "raylib.h"
#include "player.h"

int main() {

    Player player;
    InitWindow(800, 600, "Test Window");
    SetTargetFPS(30);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        player.Update(dt);

        BeginDrawing();
        ClearBackground(BLACK);
        player.Draw();
        EndDrawing();
    }
    return 0;
}