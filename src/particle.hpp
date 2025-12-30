#pragma once
#include <raylib.h>
#include <vector>
#include "RealVector.hpp"
using std::vector;

class particle {
    public:
        RealVector pos;
        RealVector vel;
        float mns, mas;

        particle();
        particle(RealVector p, RealVector v, float min_speed, float max_speed);

        void applyForce(RealVector force);
        void update();
        void show();
};