#include <raylib.h>
#include <vector>

#include "RealVector.hpp"
using std::vector;

// SCREEN VARIABLES
#define WIDTH 800
#define HEIGHT 800
#define SCL 10
#define ROWS (HEIGHT/SCL)
#define COLS (WIDTH/SCL)

// PARTICLE VARIABLES
#define PARTICLE_RADIUS 2
#define PARTICLE_MAX_SPEED 2
#define PARTICLE_MIN_SPEED 1
#define NUM_PARTICLES 200

// BOARD
struct slot {
    RealVector vec;
    Vector2 start_point;
};

double map_to(double minimum, double maximum, double new_min, double new_max, double value);
double field_func(double x, double y);

extern vector<vector<slot>> BOARD;