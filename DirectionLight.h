//
// Created by Arnesh Nagavalli on 8/25/21.
//

#ifndef RAYTRACER_DIRECTIONLIGHT_H
#define RAYTRACER_DIRECTIONLIGHT_H

#include "raytracer.h"
#include "Light.h"

class DirectionLight : public Light{
  public:
    DirectionLight(vec3 position, vec3 intensity) : Light(position, intensity) { }

    vec3 getDirFromPoint(const vec3 &point) override;
};


#endif //RAYTRACER_DIRECTIONLIGHT_H
