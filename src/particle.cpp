#include "particle.hpp"
#include "RealVector.hpp"
#include "config.hpp"
#include "raylib.h"
// #include <iostream>

particle::particle() {};
particle::particle(RealVector p, RealVector v, float min_speed, float max_speed) {
    pos = p;
    vel = v;
    mns = min_speed;
    mas = max_speed;
}

void particle::update(){
    pos = pos.add(vel);

    if (pos.x > GetScreenWidth()) pos.x = 0;
    if (pos.x < 0) pos.x = GetScreenWidth();
    if (pos.y > GetScreenHeight()) pos.y = 0;
    if (pos.y < 0) pos.y = GetScreenHeight();
}

void particle::applyForce(RealVector force){
    vel = vel.add(force);
    vel = vel.limit(mns, mas);
}

void particle::show() {
    DrawCircle(pos.x, pos.y, PARTICLE_RADIUS, {255, 0, 0, 20});
}