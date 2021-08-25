//
// Created by Arnesh Nagavalli on 8/24/21.
//

#include "Film.h"

BYTE *Film::getBytes() {
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      BYTE avg[3] = {0};
      averagePixelColor(x, y, avg);
      memcpy(pixels + (y * width + x), avg, 3*sizeof(BYTE));
    }
  }

  return pixels;
}

void Film::averagePixelColor(int x, int y, BYTE* pixelCol) {
  for (int sampNo = 0; sampNo < numSamples; ++sampNo) {
    vec3& color = buckets.at(y).at(x).at(sampNo);
    int r = std::max(0, std::min(255, (int)floor(color.r * 256.0)));
    int g = std::max(0, std::min(255, (int)floor(color.g * 256.0)));
    int b = std::max(0, std::min(255, (int)floor(color.b * 256.0)));

    pixelCol[0] += r / numSamples;
    pixelCol[1] += g / numSamples;
    pixelCol[2] += b / numSamples;
  }
}

void Film::setBucketColor(int i, int j, int sampNo, vec3 color) {
  buckets.at(i).at(j).at(sampNo) = color;
}
