//
// Created by Arnesh Nagavalli on 8/24/21.
//

#include "Scene.h"

Film &Scene::renderImage() {
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      for (int sampNo = 0; sampNo < numSamples; ++sampNo) {
        vec2 sample = sampler.getSample(x, y);
        // TODO cast ray based on sample
        vec3 color{ (float) x / (float) width, (float) y / (float) height, 0};
        film.setBucketColor(x, y, sampNo, color);
      }
    }
  }

  return film;
}
