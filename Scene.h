
#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include "raytracer.h"
#include "Film.h"
#include "Sampler.h"
#include "Ray.h"
#include "Camera.h"
#include "Surface.h"
#include "Light.h"

class Scene {
    int width, height, numSamples;

    Camera camera;
    Sampler sampler;
    Film film;
    vec3 backgroundColor;
    std::vector<Light*> lights;
    std::vector<Surface*> surfaces;
    //std::vector<Shader> shaders; necessary??
  public:
    Scene(
            vec3 eye, vec3 target, vec3 up,
            vec3 backgroundColor,
            int width, int height, float fovy,
            int numSamples)
            : width(width), height(height), numSamples(numSamples), backgroundColor(backgroundColor),
            camera(eye, target, up, fovy, (float) width / (float) height, width, height),
            sampler(width, height),
            film(width, height, numSamples) { }
    ~Scene() = default;

    void addSurface(Surface* surface) { surfaces.push_back(surface); }

    void addLight(Light* light) { lights.push_back(light); }

    Surface* getFirstIntersection(Intersection& out, const Ray& ray);

    bool getAnyIntersection(Intersection& out, const Ray& ray);

    void shadeLocation(vec3& outColor, const Intersection& intersection, Surface* surface);

    Film& renderImage();
};

#endif //RAYTRACER_SCENE_H
