//
// Created by Arnesh Nagavalli on 8/25/21.
//

#include "Camera.h"

void Camera::getRay(Ray& out, vec2 pos) {
  float fovx = fovy * aspect;
  float halfWidth = (float) width / 2.0f;
  float halfHeight = (float) height / 2.0f;
  float alpha = tan(glm::radians(fovx) / 2.0f) * ((pos.x - halfWidth) / halfWidth);
  float beta = tan(glm::radians(fovy) / 2.0f) * ((halfHeight - pos.y) / halfHeight);
  out.origin = eye;
  out.direction = glm::normalize(-w + alpha * u + beta * v);
}
