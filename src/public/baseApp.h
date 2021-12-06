#ifndef BASEAPP
#define BASEAPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "utility.h"
#include <chrono>
#include <string>

class baseApp
{
private:
    GLFWwindow* window;
    int FPScounter;
public:
    baseApp();

    void CreateWindow(int w, int h, std::string title);

    virtual void Start();
    virtual void Update();

    void InputHandler(GLFWwindow* window_);
};
#endif
