#ifndef BASEAPP
#define BASEAPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "utility.h"

class baseApp
{
private:
    GLFWwindow* window;
public:
    baseApp();
    void CreateWindow();

    void Start();
    void Update();
};
#endif
