//
// Created by Arnesh Nagavalli on 8/25/21.
//

#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include "raytracer.h"
#include "Ray.h"

class Camera {
    vec3 eye, target, up;
    vec3 u, v, w;

    int width, height;

    mat4 transform;

    float fovy;
    float aspect;
  public:
    Camera(vec3 eye, vec3 target, vec3 up, float fovy, float aspect, int width, int height)
      : eye(eye), target(target), up(up), fovy(fovy), aspect(aspect), transform(1.0), width(width), height(height)
      {
        transform = glm::lookAt(eye, target, up);
        w = glm::normalize(eye - target);
        u = glm::normalize(glm::cross(up, w));
        v = glm::cross(w, u);
      }

    void getRay(Ray& out, vec2 pos);
};


#endif //RAYTRACER_CAMERA_H
