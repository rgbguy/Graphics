#include "baseApp.h"
#include "vbo.h"
#include "vao.h"
#include "shader.h"

class firstTriangle : public baseApp
{
public:
    glm::mat4 modelMat;
    unsigned int shaderProgram;
    firstTriangle()
    {
        baseApp::CreateWindow(400, 400, "red triangle");
    }
    void Start() override
    {
        LOG("First Tri Start\n", 1);

        std::string vspath = "shaders/default.vert";
        std::string fspath = "shaders/default.frag";

        shaderProgram = CreateShaderProgram(vspath.c_str(), fspath.c_str());
        glUseProgram(shaderProgram);

        float vertices[] = {
            0.0f,  0.5f, 0.0f,  // top
            0.5f, -0.5f, 0.0f,  // bottom right
           -0.5f, -0.5f, 0.0f,  // bottom left
        };

	    VAO VAO1;
	    VAO1.Bind();
	    VBO VBO1(vertices, sizeof(vertices));
	    VAO1.LinkVBO(VBO1, 0);
        modelMat = glm::mat4(1.0f);
    }

    void Update() override
    {
        modelMat = glm::rotate(modelMat, glm::radians(1.0f), glm::vec3(0.0f,0,1.0f));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "modelMat"), 1, GL_FALSE, &modelMat[0][0]);
        LOG("First Tri Update\n", 1);
        glDrawArrays(GL_TRIANGLES, 0, 3); 
    }
};