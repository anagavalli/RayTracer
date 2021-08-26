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
    Sphere(vec3 center, int radius, vec3 ambient, vec3 emission, vec3 diffuse, vec3 specular, int shininess)
      : center(center), radius(radius), Surface(ambient, emission, diffuse, specular, shininess) { }
    bool intersect(Intersection& out, const Ray& ray) override;
};


#endif //RAYTRACER_SPHERE_H
