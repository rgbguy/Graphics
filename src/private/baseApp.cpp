#include "baseApp.h"

int GlobalSettings::NumCows = 1;

baseApp::baseApp()
{
}

void baseApp::AppMain(GLFWwindow* window_)
{
    if(!window_)
    {
        LOG("Failed to run. No window created. Please add this:\nGLFWwindow* window = CreateWindow(w, h, title); in main.cpp\n", 0);
        return;
    }
    window = window_;
    Start();

    // Initialize ImGUI
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    glEnable(GL_DEPTH_TEST);
    while (!glfwWindowShouldClose(window))
    {
        if(SceneCam.activated) SceneCam.Update(shaderProgram);
        auto start = std::chrono::system_clock::now();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  

        // Tell OpenGL a new frame is about to begin
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        InputHandler(window);
        Update();

        // ImGUI window creation
        ImGui::Begin("Cows");
        // Text that appears in the window
    
        ImGui::InputInt("How many cows?", &GlobalSettings::NumCows);
        // Ends the window
        ImGui::End();

        // Renders the ImGUI elements
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
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
    Input(window_);
}

void baseApp::Input(GLFWwindow* window_)
{
    LOG("Base Input!\n", 1);
    if (glfwGetKey(window_, GLFW_KEY_W) == GLFW_PRESS)
	{
        LOG("W pressed\n",1);
        SceneCam.position =  SceneCam.position + glm::vec3(0,0,-0.1f);
	}
    if (glfwGetKey(window_, GLFW_KEY_A) == GLFW_PRESS)
	{
        LOG("A pressed\n",1);
        SceneCam.position =  SceneCam.position + glm::vec3(-0.1f,0,0);
	}
    if (glfwGetKey(window_, GLFW_KEY_S) == GLFW_PRESS)
	{
        LOG("S pressed\n",1);
        SceneCam.position =  SceneCam.position + glm::vec3(0,0,0.1f);
	}
    if (glfwGetKey(window_, GLFW_KEY_D) == GLFW_PRESS)
	{
        LOG("D pressed\n",1);
        SceneCam.position =  SceneCam.position + glm::vec3(0.1f,0,0);
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