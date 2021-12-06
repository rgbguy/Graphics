#include "baseApp.h"

baseApp::baseApp()
{
}

void baseApp::CreateWindow(int w, int h, std::string title)
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

    GLFWwindow* window = glfwCreateWindow(w, h, (title + " " +std::to_string(FPScounter)).c_str(), NULL, NULL);
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
        auto start = std::chrono::system_clock::now();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        InputHandler(window);
        Update();

        glfwSwapBuffers(window);
        glfwPollEvents();

        auto end = std::chrono::system_clock::now();
        auto elapsed = end - start;
        FPScounter = 1/(elapsed.count()/1000000.0f);
        glfwSetWindowTitle(window, (title + " - FPS: " +std::to_string(FPScounter)).c_str());
    }    
    glfwTerminate();

}

void baseApp::InputHandler(GLFWwindow* window_)
{
	if (glfwGetKey(window_, GLFW_KEY_W) == GLFW_PRESS)
	{
        std::cout << "W pressed\n";
	}
}

void baseApp::Start()
{
    LOG("Base Start!\n", 1);
}

void baseApp::Update()
{
    LOG("Base Update loop\n", 1);
}