//
// Created by Arnesh Nagavalli on 8/24/21.
//

#include "Sampler.h"

vec2 Sampler::getSample(int i, int j) {
  return {(float) i + 0.5f / (float) width, (float) j + 0.5f / (float) height};
}
