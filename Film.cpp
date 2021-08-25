//
// Created by Arnesh Nagavalli on 8/24/21.
//

#include "Film.h"

BYTE *Film::getBytes() {
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      BYTE avg[3] = {0};
      averagePixelColor(x, y, avg);
      int index = (y * width + x) * 3;
      memcpy(pixels + index, avg, 3*sizeof(BYTE));
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

    // Reverse order because FreeImage can't use pixelmask on 24bit colors
    pixelCol[2] += r / numSamples;
    pixelCol[1] += g / numSamples;
    pixelCol[0] += b / numSamples;
  }
}

void Film::setBucketColor(int x, int y, int sampNo, vec3& color) {
  buckets.at(y).at(x).at(sampNo) = color;
}
