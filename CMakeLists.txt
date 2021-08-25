cmake_minimum_required(VERSION 3.20)
project(RayTracer)

set(CMAKE_CXX_STANDARD 17)

include_directories(glm)
include_directories(lib/FreeImage)

add_executable(RayTracer main.cpp Scene.cpp Scene.h Film.cpp Film.h Sampler.cpp Sampler.h raytracer.h Ray.cpp Ray.h Camera.cpp Camera.h)

target_link_libraries(RayTracer ${PROJECT_SOURCE_DIR}/lib/FreeImage/libfreeimage.a)