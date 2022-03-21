#include "baseApp.h"
#include "vbo.h"
#include "vao.h"
#include "shader.h"
#include "texture.h"
#include "camera.h"
#include "modelLoader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class modelLoading : public baseApp
{
public:
    glm::mat4 modelMat = glm::mat4(1.0f);
    ModelLoader testModel = ModelLoader("../res/meshes/cow.obj");
	VAO VAO1;

    modelLoading(GLFWwindow* window)
    {
        baseApp::AppMain(window);
    }
    void Start() override
    {
        std::string vspath = "shaders/modelLoading.vert";
        std::string fspath = "shaders/modelLoading.frag";

        shaderProgram = CreateShaderProgram(vspath.c_str(), fspath.c_str());
        glUseProgram(shaderProgram);

        //Activates the scene camera. Camera handled in base app.
        SceneCam.Activate(shaderProgram);
    }

    void Update() override
    {
        for (int i = 0; i < GlobalSettings::NumCows; i++)
        {
            modelMat = glm::mat4(1.0f);
            modelMat = glm::translate(modelMat, glm::vec3(i*10.0f, 0.0f, 0.0f));
            glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "modelMat"), 1, GL_FALSE, &modelMat[0][0]);
            testModel.Draw();
        }
    }
};