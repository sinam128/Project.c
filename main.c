#include "raylib.h"
#include <math.h>

#define dimension 40
#define strong 16
int main() {
  int world_map[strong][strong] = {
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
      {1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
      {1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1},
      {1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1},
      {1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
      {1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
      {1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1},
      {1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}

  };
  struct Player {
    Vector2 pos;
    Vector2 dir;
    Vector2 plane;
  };
  struct Player gamer;
  Vector2 speed;
  float dspeed;
  gamer.pos.x = 1.5;
  gamer.pos.y = 1.5;
  gamer.dir.x = 1.0;
  gamer.dir.y = 0.0;
  speed.x = 3.5f;
  speed.y = 3.5f;
  dspeed = 1.5f;
  float angle = 0.0f;
  InitWindow(640, 640, "WorldMap");

  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    float dt = GetFrameTime();
    BeginDrawing();
    ClearBackground(RAYWHITE);
    if (IsKeyDown(KEY_RIGHT)) {
      angle += dt * dspeed;
      gamer.dir.x = cos(angle);
      gamer.dir.y = sin(angle);
    }
    if (IsKeyDown(KEY_LEFT)) {
      angle -= dt * dspeed;
      gamer.dir.x = cos(angle);
      gamer.dir.y = sin(angle);
    }
    if (IsKeyDown(KEY_W)) {
      gamer.pos.y += speed.y * dt * gamer.dir.y;
      gamer.pos.x += speed.x * dt * gamer.dir.x;
    }
    if (IsKeyDown(KEY_S)) {
      gamer.pos.y -= speed.y * dt * gamer.dir.y;
      gamer.pos.x -= speed.x * dt * gamer.dir.x;
    }
    if (IsKeyDown(KEY_A)) {
      gamer.pos.y -= speed.y * dt * gamer.dir.x;
      gamer.pos.x += speed.x * dt * gamer.dir.y;
    }
    if (IsKeyDown(KEY_D)) {
      gamer.pos.y += speed.y * dt * gamer.dir.x;
      gamer.pos.x -= speed.x * dt * gamer.dir.y;
    }
    for (int i = 0; i < strong; i++) {
      for (int j = 0; j < strong; j++) {
        if (world_map[i][j] == 1) {
          DrawRectangle(j * dimension, i * dimension, dimension, dimension,
                        DARKGRAY);
        } else {
          DrawRectangle(j * dimension, i * dimension, dimension, dimension,
                        LIGHTGRAY);
        }
        DrawRectangleLines(j * dimension, i * dimension, dimension, dimension,
                           BLACK);
      }
    }
    DrawCircle(gamer.pos.x * dimension, gamer.pos.y * dimension, 10, RED);
    DrawLine(gamer.pos.x * dimension, gamer.pos.y * dimension,
             (gamer.pos.x + gamer.dir.x) * dimension,
             (gamer.pos.y + gamer.dir.y) * dimension, DARKBLUE);
    EndDrawing();
  }
  CloseWindow();

  return 0;
}
// phase1 commit