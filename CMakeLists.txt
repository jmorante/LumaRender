cmake_minimum_required(VERSION 3.9)
project(LumaRender)

set(CMAKE_CXX_STANDARD 11)

add_executable(LumaRender main.cpp vec3.h ray.h camera.h material.h random.h raytracer.h color.h)