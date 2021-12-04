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
        std::string exepath = "";
        std::string vspath = exepath + "shaders/default.vert";
        std::string fspath = exepath + "shaders/default.frag";

        unsigned int shaderProgram = CreateShaderProgram(vspath.c_str(), fspath.c_str());
        glUseProgram(shaderProgram);

        float vertices[] = {
         0.05f,  0.05f, 0.0f,  // top right
         0.05f, -0.05f, 0.0f,  // bottom right
        -0.05f, -0.05f, 0.0f,  // bottom left

        -0.05f, -0.05f, 0.0f,  // bottom left
        -0.05f,  0.05f, 0.0f,  // top left 
         0.05f,  0.05f, 0.0f   // top right
        };

	// Generates Vertex Array Object and binds it
	VAO VAO1;
	VAO1.Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO1(vertices, sizeof(vertices));

	// Links VBO to VAO
	VAO1.LinkVBO(VBO1, 0);
	// Unbind all to prevent accidentally modifying them
	//VAO1.Unbind();
	//VBO1.Unbind();
    }

    void Update() override
    {
        LOG("First Tri Update\n", 1);
        //glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawArrays(GL_TRIANGLES, 0, 6); 
    }
};