cmake_minimum_required(VERSION 4.3)
project(ECSProj)

set(CMAKE_CXX_STANDARD 20)

add_executable(ECSProj main.cpp entity/entity.cpp application/application.cpp scene/scene.cpp
        transform/transform.cpp
        transform/transform.h)
