//
// Created by Arnesh Nagavalli on 8/24/21.
//

#include "Scene.h"

#define FLOAT_MAX 10000.0
#define FLOAT_MIN 0.0000000001
#define MAX_DEPTH 4

Film &Scene::renderImage() {
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      if ((y * width + x) % 100 == 0)
        std::cout << "Processing pixel " << y * width + x << " out of " << width * height << std::endl;
      for (int sampNo = 0; sampNo < numSamples; ++sampNo) {
        vec2 sample = sampler.getSample(x, y);
        Ray ray{};
        camera.getRay(ray, sample);

        Intersection intersection{};
        Surface *surface = nullptr;
        vec3 color(0);
        float curReflectivity = 0.2;

        for (int i = 0; i < MAX_DEPTH; i++) {
          surface = getFirstIntersection(intersection, ray);

          if (surface != nullptr) {
            vec3 curColor{0};
            shadeLocation(curColor, intersection, surface);
            color += (float) pow(curReflectivity, i) * curColor;

            ray = Ray(intersection.location, -2*glm::dot(ray.direction, intersection.normal)*intersection.normal);
          }
          else break;
        }

        film.setBucketColor(x, y, sampNo, color);
      }
    }
  }

  return film;
}

void Scene::shadeLocation(vec3 &outColor, const Intersection &intersection, Surface* surface) {
  outColor += surface->ambient + surface->emission;
  for (auto light : lights) {
    Ray rayToLight(intersection.location, light->getDirFromPoint(intersection.location));

    Intersection checkIntersection{};
    if (!getAnyIntersection(checkIntersection, rayToLight)) {
      float LdotN = std::max(glm::dot(rayToLight.direction, intersection.normal), 0.0f);
      vec3 h = glm::normalize(rayToLight.direction + glm::normalize(intersection.directionToViewer));
      float HdotN = std::max(glm::dot(h, intersection.normal), 0.0f);
      outColor += light->intensity * (surface->diffuse * LdotN + surface->specular * (float) pow(HdotN, surface->shininess));
    }
  }
}

Surface* Scene::getFirstIntersection(Intersection& out, const Ray& ray) {
  double minT = FLOAT_MAX;
  Intersection curIntersection{};
  Surface* outSurface;
  for (auto surface : this->surfaces) {
    bool didHit = surface->intersect(curIntersection, ray);

    if (didHit) {
      double t = curIntersection.t;
      if (t < minT && t > FLOAT_MIN) {
        minT = t;
        out = curIntersection;
        outSurface = surface;
      }
    }
  }

  if (minT < FLOAT_MAX) return outSurface;
  return nullptr;
}

bool Scene::getAnyIntersection(Intersection& out, const Ray& ray) {
  for (auto surface : this->surfaces) {
    bool didHit = surface->intersect(out, ray);

    if (didHit && out.t > FLOAT_MIN) {
      return true;
    }
  }

  return false;
}
