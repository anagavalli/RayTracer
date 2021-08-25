//
// Created by Arnesh Nagavalli on 8/24/21.
//

#ifndef RAYTRACER_SAMPLER_H
#define RAYTRACER_SAMPLER_H

#include "raytracer.h"

class Sampler {
    int width, height;
  public:
    Sampler(int width, int height) : width(width), height(height) { }
    ~Sampler() = default;

    vec2 getSample(int i, int j);
};


#endif //RAYTRACER_SAMPLER_H
