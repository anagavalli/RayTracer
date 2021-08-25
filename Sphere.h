//
// Created by Arnesh Nagavalli on 8/25/21.
//

#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H


#include "raytracer.h"
#include "Surface.h"
#include "Intersection.h"
#include "Ray.h"

class Sphere : public Surface {
    vec3 center;
    int radius;
  public:
    Sphere(vec3 center, int radius) : center(center), radius(radius) { }
    bool intersect(Intersection& out, Ray& ray);
};


#endif //RAYTRACER_SPHERE_H
