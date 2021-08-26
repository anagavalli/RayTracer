//
// Created by Arnesh Nagavalli on 8/25/21.
//

#include "PointLight.h"

vec3 PointLight::getDirFromPoint(const vec3 &point) {
  return glm::normalize(position - point);
}
