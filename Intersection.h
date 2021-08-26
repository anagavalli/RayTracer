//
// Created by Arnesh Nagavalli on 8/25/21.
//

#ifndef RAYTRACER_INTERSECTION_H
#define RAYTRACER_INTERSECTION_H


#include "raytracer.h"
#include "Ray.h"

class Intersection {
  public:
    vec3 location, normal, directionToViewer;
    double t;

    Intersection() = default;
    Intersection(vec3 location, vec3 normal, vec3 directionToViewer, double t) : location(location), normal(normal), directionToViewer(directionToViewer), t(t) { }
};


#endif //RAYTRACER_INTERSECTION_H
