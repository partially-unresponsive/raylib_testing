#include "config.hpp"
// #include <cmath>
#include <algorithm>
#include "perlin_alg.hpp"
using std::clamp;

vector<vector<slot>> BOARD(ROWS+1, vector<slot>(COLS+1));

double map_to(double minimum, double maximum, double new_min, double new_max, double value){
    value = clamp(value, minimum, maximum);
    return (value - minimum) * (new_max - new_min) / (maximum - minimum) + new_min;
}

double field_func(double x, double y){
    // return RealVector(cos(y), sin(x)).angleOf();

    perlin_alg p;
    float val = 0;
    float freq = 2;
    float amp = 3;

    for (int i = 0; i < 4; i++){
        val += p.perlin(x*freq, y*freq) * amp;
        freq *= 2;
        amp /= 2;
    }
    val = clamp(val, -1.0f, 1.0f);
    return map_to(-1, 1, 0, 2*PI, val);
}