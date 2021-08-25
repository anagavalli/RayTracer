#include <iostream>
#include <FreeImage.h>

#include "raytracer.h"

#include "Film.h"
#include "Scene.h"

void saveScreenshot(const std::string& fname, Film& film, int width, int height) {
  FIBITMAP *img = FreeImage_ConvertFromRawBits(film.getBytes(), width, height, width * 3, 24, 0xFF0000, 0x00FF00, 0x0000FF, true);

  std::cout << "Saving image: " << fname << "\n";

  FreeImage_Save(FIF_PNG, img, fname.c_str(), 0);
}

int main() {
  FreeImage_Initialise();

  int width = 100, height = 100, numSamples = 1;
  float fovy = 80.0f;
  vec3 eye{0};
  vec3 up{0, 1, 0};
  vec3 target{0, 0, -1};
  vec3 backgroundColor{0};
  Scene scene = Scene(eye, target, up, backgroundColor, width, height, fovy, numSamples);

  saveScreenshot("test.png", scene.renderImage(), width, height);

  FreeImage_DeInitialise();
  return 0;
}
