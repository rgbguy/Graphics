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

    virtual void Start();
    virtual void Update();
};
#endif
