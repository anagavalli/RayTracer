//
// Created by Arnesh Nagavalli on 8/24/21.
//

#ifndef RAYTRACER_FILM_H
#define RAYTRACER_FILM_H

#include <FreeImage.h>
#include "raytracer.h"

class Film {
    int width, height, numSamples;
    std::vector<std::vector<std::vector<vec3>>> buckets;
    BYTE *pixels;

    void averagePixelColor(int i, int j, BYTE* pixelCol);
  public:
    Film(int width, int height, int numSamples) : width(width), height(height), numSamples(numSamples) {
      pixels = new BYTE[width * height * 3];
      for (int y = 0; y < height; ++y) {
        std::vector<std::vector<vec3>> rowBuckets;
        for (int x = 0; x < width; ++x) {
          std::vector<vec3> colBuckets;
          for (int sampNo = 0; sampNo < numSamples; ++sampNo) {
            vec3 sampleBucket{0};
            colBuckets.push_back(sampleBucket);
          }
          rowBuckets.push_back(colBuckets);
        }
        buckets.push_back(rowBuckets);
      }
    }
    ~Film() { delete[] pixels; }

    void setBucketColor(int i, int j, int sampNo, vec3& color);

    BYTE* getBytes();
};


#endif //RAYTRACER_FILM_H
