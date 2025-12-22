#include "raylib.h"

int main() {
  InitWindow(800, 600, "Hello Raylib");
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Hello, Raylib!", 190, 200, 20, RED);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
// phase1 commit
