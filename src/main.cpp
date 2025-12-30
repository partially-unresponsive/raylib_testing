// Following along with the flow fields tutorial from [MelonFruit](https://www.youtube.com/watch?v=UXO_jV3Nlnc)

#include <raylib.h>
#include <cmath>
#include <time.h>
// #include <iostream>
#include "RealVector.hpp"
#include "config.hpp"
#include "particle.hpp"

int main() {
    InitWindow(800, 800, "Flow Fields");
    srand(time(nullptr));
    SetTargetFPS(60);

    double MULT = 1.0f;
    double length = SCL * MULT;
    for (int y = 0; y < ROWS; y++){
        for (int x = 0; x < COLS; x++){
            slot s;
            s.start_point = {(float)SCL * x + SCL / 2, (float)SCL * y + SCL / 2};
            BOARD[y][x] = s;
        }
    }

    vector<particle> particles;
    for (int i = 0; i < NUM_PARTICLES; i++){
        particle p(RealVector((float)(rand() % WIDTH), (float)(rand() % HEIGHT)), RealVector(0, 0), PARTICLE_MIN_SPEED, PARTICLE_MAX_SPEED);
        particles.push_back(p);
    }

    double z = rand() % 10000;
    while (!WindowShouldClose()){
        BeginDrawing();
        // ClearBackground(WHITE);
        for (int y = 0; y < ROWS; y++){
            for (int x = 0; x < COLS; x++){
                double angle = field_func((double)x*0.03, (double)y*0.03 + z);

                BOARD[y][x].vec = RealVector(cos(angle)*length, sin(angle) * length);

                Vector2 end = {BOARD[y][x].start_point.x + BOARD[y][x].vec.x, BOARD[y][x].start_point.y + BOARD[y][x].vec.y};

                u_char c = map_to(0, 2*PI, 0, 255, angle);

                // DrawLineEx(BOARD[y][x].start_point, end, 1, (Color){0, c, c, 255});
            }
        }
        for (int i = 0; i < NUM_PARTICLES; i++){
            RealVector mv = BOARD[(int)particles[i].pos.y / SCL][(int)particles[i].pos.x / SCL].vec;
            particles[i].applyForce(mv);
            particles[i].update();
            particles[i].show();
        }
        // z += 0.003;
        EndDrawing();
    }
    CloseWindow();
}