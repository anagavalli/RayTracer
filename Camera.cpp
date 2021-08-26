//
// Created by Arnesh Nagavalli on 8/25/21.
//

#include "Camera.h"

void Camera::getRay(Ray& out, vec2 pos) {
  double halfWidth = (float) width / 2.0f;
  double halfHeight = (float) height / 2.0f;
  double fovYRad = fovy * M_PI / 180;
  float alpha = tan(fovYRad / 2) * aspect * ((pos.x - halfWidth) / halfWidth);
  float beta = tan(fovYRad / 2.0f) * ((halfHeight - pos.y) / halfHeight);
  out.origin = eye;
  out.direction = glm::normalize((alpha * u) + (beta * v) - w);
}
