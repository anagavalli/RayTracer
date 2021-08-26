//
// Created by Arnesh Nagavalli on 8/25/21.
//

#ifndef RAYTRACER_POINTLIGHT_H
#define RAYTRACER_POINTLIGHT_H

#include "raytracer.h"
#include "Light.h"

class PointLight : public Light{
  public:
    PointLight(vec3 position, vec3 intensity) : Light(position, intensity) { }

    vec3 getDirFromPoint(const vec3 &point) override;
};


#endif //RAYTRACER_POINTLIGHT_H
