//
// Created by Arnesh Nagavalli on 8/25/21.
//

#ifndef RAYTRACER_LIGHT_H
#define RAYTRACER_LIGHT_H


class Light {
  public:
    vec3 position, intensity;
    explicit Light(vec3 position, vec3 intensity) : position(position), intensity(intensity) { };
    virtual vec3 getDirFromPoint(const vec3& point) = 0;
};


#endif //RAYTRACER_LIGHT_H
