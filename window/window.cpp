#include "window.h"

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

window::window() {

}

window::~window() {
    if (m_window)
        glfwDestroyWindow(m_window);

	glfwTerminate();
}

bool window::shouldClose() const {
    return glfwWindowShouldClose(m_window);
}

bool window::create() {

	if (!glfwInit()) {
		std::cerr << "Failed to initialise GLFW\n";
		return false;
	}

    m_window = glfwCreateWindow(
        1280,
        720,
        "My Engine",
        nullptr,
        nullptr
    );

    if (!m_window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(m_window);

    if (!gladLoadGL(glfwGetProcAddress))
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
        return false;
    }

    return true;

}

void window::update()
{
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}