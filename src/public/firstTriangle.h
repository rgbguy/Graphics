#include "baseApp.h"
#include "vbo.h"
#include "vao.h"
#include "shader.h"

class firstTriangle : public baseApp
{
public:
    firstTriangle()
    {
        baseApp::CreateWindow();
    }
    void Start() override
    {
        LOG("First Tri Start\n", 1);

        std::string vspath = "shaders/default.vert";
        std::string fspath = "shaders/default.frag";

        unsigned int shaderProgram = CreateShaderProgram(vspath.c_str(), fspath.c_str());
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
    }

    void Update() override
    {
        LOG("First Tri Update\n", 1);
        glDrawArrays(GL_TRIANGLES, 0, 3); 
    }
};