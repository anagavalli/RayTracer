//
// Created by Arnesh Nagavalli on 8/24/21.
//

#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H


#include "raytracer.h"

class Ray {
  public:
    vec3 origin;
    vec3 direction;

    Ray() = default;

    Ray(vec3 origin, vec3 direction) : origin(origin), direction(direction) { }
};


#endif //RAYTRACER_RAY_H
