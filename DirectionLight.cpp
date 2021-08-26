//
// Created by Arnesh Nagavalli on 8/25/21.
//

#include "DirectionLight.h"

vec3 DirectionLight::getDirFromPoint(const vec3 &point) {
  return -position;
}