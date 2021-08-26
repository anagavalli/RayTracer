//
// Created by Arnesh Nagavalli on 8/25/21.
//

#ifndef RAYTRACER_SURFACE_H
#define RAYTRACER_SURFACE_H


#include "Intersection.h"
#include "Ray.h"

class Surface {
  public:
    vec3 ambient, emission, diffuse, specular;
    int shininess;

    Surface(vec3 ambient, vec3 emission, vec3 diffuse, vec3 specular, int shininess)
      : ambient(ambient), emission(emission), diffuse(diffuse), specular(specular), shininess(shininess) { };
    virtual bool intersect(Intersection& out, const Ray& ray) = 0;
};


#endif //RAYTRACER_SURFACE_H
