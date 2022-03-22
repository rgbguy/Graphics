#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "utility.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

GLFWwindow* CreateWindow(int w, int h, std::string title)
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(w, h, "YoutubeOpenGL", NULL, NULL);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return nullptr;
	}
    
	glfwMakeContextCurrent(window);

	gladLoadGL();

    return window;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	GlobalSettings::width = width;
	GlobalSettings::height = height;
	std::cout << width << " ," << height << "\n";
}
