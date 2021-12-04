#include "baseApp.h"

baseApp::baseApp()
{
}

void baseApp::CreateWindow()
{
    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    GLFWwindow* window = glfwCreateWindow(400, 400, "Graphics", NULL, NULL);
    if (window == NULL)
    {
        LOG("Failed to create GLFW window\n", 0);
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        LOG("Failed to initialize GLAD\n", 0);
    }

    Start();

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        Update();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();

}

void baseApp::Start()
{
    LOG("Base Start!\n", 1);
}

void baseApp::Update()
{
    LOG("Base Update loop\n", 1);
}