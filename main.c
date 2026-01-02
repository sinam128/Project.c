#include "raylib.h"
#include <math.h>

#define dimension 40
#define strong 16
#define radius 0.25

float check(float rad) {
  if (rad > 0) {
    return radius;
  } else {
    return (-1) * radius;
  }
}
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
  gamer.plane.x = 0.0;
  gamer.plane.y = 1.0;
  speed.x = 3.5f;
  speed.y = 3.5f;
  dspeed = 1.8f;
  int mapflag = 1;
  float angle = 0.0f;
  InitWindow(640, 640, "WorldMap");

  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    float dt = GetFrameTime();
    BeginDrawing();
    ClearBackground(RAYWHITE);
    if (IsKeyDown(KEY_M)) {
      mapflag *= (-1);
    }
    if (IsKeyDown(KEY_RIGHT)) {
      angle += dt * dspeed;
      gamer.dir.x = cos(angle);
      gamer.dir.y = sin(angle);
      gamer.plane.x = -sin(angle);
      gamer.plane.y = cos(angle);
    }
    if (IsKeyDown(KEY_LEFT)) {
      angle -= dt * dspeed;
      gamer.dir.x = cos(angle);
      gamer.dir.y = sin(angle);
      gamer.plane.x = -sin(angle);
      gamer.plane.y = cos(angle);
    }
    if (IsKeyDown(KEY_W)) {

      if (world_map[(int)(gamer.pos.y + (speed.y * dt * gamer.dir.y) +
                          check(speed.y * dt * gamer.dir.y))]
                   [(int)gamer.pos.x] != 1) {
        gamer.pos.y += speed.y * dt * gamer.dir.y;
      }

      if (world_map[(int)gamer.pos.y]
                   [(int)(gamer.pos.x + (speed.x * dt * gamer.dir.x) +
                          check(speed.x * dt * gamer.dir.x))] != 1) {
        gamer.pos.x += speed.x * dt * gamer.dir.x;
      }
    }
    if (IsKeyDown(KEY_S)) {
      if (world_map[(int)(gamer.pos.y - (speed.y * dt * gamer.dir.y) +
                          check(-speed.y * dt * gamer.dir.y))]
                   [(int)gamer.pos.x] != 1) {
        gamer.pos.y -= speed.y * dt * gamer.dir.y;
      }
      if (world_map[(int)gamer.pos.y]
                   [(int)(gamer.pos.x - (speed.x * dt * gamer.dir.x) +
                          check(-speed.x * dt * gamer.dir.x))] != 1) {
        gamer.pos.x -= speed.x * dt * gamer.dir.x;
      }
    }
    if (IsKeyDown(KEY_A)) {
      if (world_map[(int)(gamer.pos.y - (speed.y * dt * gamer.dir.x) +
                          check(-speed.y * dt * gamer.dir.x))]
                   [(int)gamer.pos.x] != 1) {
        gamer.pos.y -= speed.y * dt * gamer.dir.x;
      }
      if (world_map[(int)gamer.pos.y]
                   [(int)(gamer.pos.x + (speed.x * dt * gamer.dir.y) +
                          check(speed.x * dt * gamer.dir.y))] != 1) {
        gamer.pos.x += speed.x * dt * gamer.dir.y;
      }
    }

    if (IsKeyDown(KEY_D)) {
      if (world_map[(int)(gamer.pos.y + (speed.y * dt * gamer.dir.x) +
                          check(speed.y * dt * gamer.dir.x))]
                   [(int)gamer.pos.x] != 1) {
        gamer.pos.y += speed.y * dt * gamer.dir.x;
      }
      if (world_map[(int)gamer.pos.y]
                   [(int)(gamer.pos.x - (speed.x * dt * gamer.dir.y) +
                          check(-speed.x * dt * gamer.dir.y))] != 1) {
        gamer.pos.x -= speed.x * dt * gamer.dir.y;
      }
    }
    for (int i = 0; i < 640; i++) {
      double cameraX = (double)(2 * i) / 640.0 - 1;
      double rayDirX = gamer.dir.x + gamer.plane.x * cameraX;
      double rayDirY = gamer.dir.y + gamer.plane.y * cameraX;

      int mapX = (int)gamer.pos.x;
      int mapY = (int)gamer.pos.y;
      double stepX;
      double sideDistX;

      double stepY;
      double sideDistY;

      double deltaDistX;
      double deltaDistY;
      if (rayDirX != 0) {
        deltaDistX = fabs(1 / rayDirX);
      } else {
        deltaDistX = 1e28;
      }
      if (rayDirY != 0) {
        deltaDistY = fabs(1 / rayDirY);
      } else {
        deltaDistY = 1e28;
      }

      if (rayDirX < 0) {
        stepX = -1;
        sideDistX = (gamer.pos.x - mapX) * deltaDistX;
      } else {
        stepX = 1;
        sideDistX = (mapX + 1.0 - gamer.pos.x) * deltaDistX;
      }
      if (rayDirY < 0) {
        stepY = -1;
        sideDistY = (gamer.pos.y - mapY) * deltaDistY;
      } else {
        stepY = 1;
        sideDistY = (mapY + 1.0 - gamer.pos.y) * deltaDistY;
      }

      int side;
      int flag = 0;

      int maxSteps = 100;
      int steps = 0;

      while (flag == 0 && maxSteps > steps) {
        steps++;
        if (sideDistX < sideDistY) {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        } else {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }

        if (world_map[mapY][mapX] > 0) {
          flag = 1;
        }
      }

      double perpWallDist;

      if (side == 0)
        perpWallDist = (sideDistX - deltaDistX);
      else
        perpWallDist = (sideDistY - deltaDistY);

      int lineHeight = (int)(640 / perpWallDist);

      int drawStart = -lineHeight / 2 + 320;
      if (drawStart < 0)
        drawStart = 0;
      int drawEnd = lineHeight / 2 + 320;
      if (drawEnd >= 640)
        drawEnd = 639;

      Color color = RED;
      if (side == 1) {
        color = MAROON;
      }

      if (mapflag == 1) {
        DrawLine(i, 0, i, drawStart - 1, SKYBLUE);

        DrawLine(i, drawStart, i, drawEnd, color);

        DrawLine(i, drawEnd + 1, i, 639, GREEN);
      }
    }
    if (mapflag == 1) {
      for (int i = 0; i < strong; i++) {
        for (int j = 0; j < strong; j++) {
          if (world_map[i][j] == 1) {

            DrawRectangle(640 - strong * 10 + j * 10, 10 + i * 10, 10, 10,
                          DARKGRAY);
          } else {
            DrawRectangle(640 - strong * 10 + j * 10, 10 + i * 10, 10, 10,
                          LIGHTGRAY);
          }
          DrawRectangleLines(640 - strong * 10 + j * 10, 10 + i * 10, 10, 10,
                             BLACK);
        }
      }
      DrawCircle(640 - strong * 10 + gamer.pos.x * 10, 10 + gamer.pos.y * 10, 3,
                 RED);

      DrawLine(640 - strong * 10 + gamer.pos.x * 10, 10 + gamer.pos.y * 10,
               640 - strong * 10 + (gamer.pos.x + gamer.dir.x * 0.5) * 10,
               10 + (gamer.pos.y + gamer.dir.y * 0.5) * 10, DARKBLUE);
    } else {
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
      DrawLine(gamer.pos.x * dimension, gamer.pos.y * dimension,
               (gamer.pos.x + gamer.plane.x * 0.9) * dimension,
               (gamer.pos.y + gamer.plane.y * 0.9) * dimension, PINK);
    }

    // DrawLine(640 - strong * 10 + gamer.pos.x * 10, 10 + gamer.pos.y * 10,
    //          640 - strong * 10 + (gamer.pos.x + gamer.plane.x * 0.45) * 10,
    //          10 + (gamer.pos.y + gamer.plane.y * 0.45) * 10, PINK);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
