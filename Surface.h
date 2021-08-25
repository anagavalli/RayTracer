//
// Created by Arnesh Nagavalli on 8/25/21.
//

#ifndef RAYTRACER_SURFACE_H
#define RAYTRACER_SURFACE_H


#include "Shader.h"
#include "Intersection.h"
#include "Ray.h"

class Surface {
  public:
    Surface() { }
    virtual bool intersect(Intersection& out, Ray& ray) = 0;
};


#endif //RAYTRACER_SURFACE_H
