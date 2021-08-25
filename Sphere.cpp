//
// Created by Arnesh Nagavalli on 8/25/21.
//

#include "Sphere.h"

float discriminant(float a, float b, float c) { return pow(b, 2) - 4.0f * a * c; }

bool Sphere::intersect(Intersection& out, Ray& ray) {
  float a = glm::dot(ray.direction, ray.direction);
  float b = 2 * glm::dot(ray.direction, ray.origin - center);
  float c = glm::dot(ray.origin - center, ray.origin - center) - pow(radius, 2);

  float discrim = discriminant(a, b, c);

  if (discrim <= 0) return false;

  double t = std::min((-1.0 * b + sqrt(discrim)) / (2.0 * a), (-1.0 * b - sqrt(discrim)) / (2.0 * a));
  vec3 point = ray.origin + (float) t * ray.direction;
  out.location = point;
  out.normal = glm::normalize(point - center);
  out.t = t;
  return true;
}