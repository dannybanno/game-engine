cmake_minimum_required(VERSION 3.25)

project(ECSProj)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)


# GLFW
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4
)

FetchContent_MakeAvailable(glfw)


# GLAD
add_library(glad STATIC
    ext/glad/src/gl.c
)

target_include_directories(glad PUBLIC
    ext/glad/include
)


# OpenGL
find_package(OpenGL REQUIRED)


# Engine
add_executable(ECSProj
    main.cpp

    entity/entity.cpp
    application/application.cpp
    scene/scene.cpp
    transform/transform.cpp
    input/input.cpp
    movement_system/movement_system.cpp
    render_system/render_system.cpp
    window/window.cpp
)


# Libraries
target_link_libraries(ECSProj
    PRIVATE
        glfw
        glad
        OpenGL::GL
)