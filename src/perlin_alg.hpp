#pragma once

struct vec2 {
    float x, y;
};

class perlin_alg {
    vec2 randomGradient(int ix, int iy);
    float dotGridGradient(int ix, int iy, float x, float y);
    float interpolate(float a0, float a1, float w);
    public:
        perlin_alg() {}
        float perlin(float x, float y);
};