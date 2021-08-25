//
// Created by Arnesh Nagavalli on 8/25/21.
//

#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include "raytracer.h"

class Camera {
    vec3 eye;
    vec3 target;
    vec3 up;

    float fovy;
    float aspect;
  public:
    Camera(vec3 eye, vec3 target, vec3 up, float fovy, float aspect)
      : eye(eye), target(target), up(up), fovy(fovy), aspect(aspect) { }

    vec4 retrieveRay(int i, int j);
};


#endif //RAYTRACER_CAMERA_H
