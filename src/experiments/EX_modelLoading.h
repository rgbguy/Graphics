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

Camera cam;

class modelLoading : public baseApp
{
public:
    glm::mat4 modelMat;
    unsigned int shaderProgram;
    modelLoading()
    {
        baseApp::CreateWindow(400, 400, "multi textured triangle");
    }
    void Start() override
    {
    std::string Path = "../res/meshes/cube.obj";
    MeshLoader CowMesh = MeshLoader(Path);
    std::vector<float> Positions = CowMesh.ObjVertexPos;
    std::vector<float> Normals = CowMesh.ObjVertexNormal;
    std::vector<float> TexCoord = CowMesh.ObjTextureCoord;

    std::cout << "Pos size: " << Positions.size() << "\n";
        LOG("First Tri Start\n", 1);

        std::string vspath = "shaders/textured.vert";
        std::string fspath = "shaders/textured.frag";

        shaderProgram = CreateShaderProgram(vspath.c_str(), fspath.c_str());
        glUseProgram(shaderProgram);

        float vertices[] = {
            0.0f,  0.5f, 0.0f,  // top
            0.5f, -0.5f, 0.0f,  // bottom right
           -0.5f, -0.5f, 0.0f,  // bottom left
        };

        float texCoords[] = {
            0.0f, 0.0f,  // lower-left corner  
            1.0f, 0.0f,  // lower-right corner
            0.5f, 1.0f   // top-center corner
        };

	    VAO VAO1;
	    VAO1.Bind();
	    VBO VBO_vert(vertices, sizeof(vertices));
        VBO VBO_texC(texCoords, sizeof(texCoords));

        VAO1.LinkAttrib(VBO_vert, 0, 3, GL_FLOAT, 0, (void*)0);
        VAO1.LinkAttrib(VBO_texC, 1, 2, GL_FLOAT, 0, (void*)0);

        modelMat = glm::mat4(1.0f);

	    Texture GridTexture("../res/textures/grid.jpeg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	    GridTexture.SetUniform(shaderProgram, "tex0");
        GridTexture.Use();

	    Texture WallTexture("../res/textures/wall.jpeg", GL_TEXTURE_2D, GL_TEXTURE1, GL_RGBA, GL_UNSIGNED_BYTE);
	    WallTexture.SetUniform(shaderProgram, "tex1");
        WallTexture.Use();

        cam.Activate(shaderProgram);
    }

    void Update() override
    {
        cam.Update(shaderProgram, cam.position, cam.forward, cam.up);
        //modelMat = glm::rotate(modelMat, glm::radians(1.0f), glm::vec3(0.0f,0,1.0f));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "modelMat"), 1, GL_FALSE, &modelMat[0][0]);
        LOG("First Tri Update\n", 1);
        glDrawArrays(GL_TRIANGLES, 0, 3); 
    }

    void Input(GLFWwindow* window_) override
    {
        if (glfwGetKey(window_, GLFW_KEY_W) == GLFW_PRESS)
	    {
            std::cout << "W pressed\n";
            cam.position =  cam.position + glm::vec3(0,0,-0.1f);
	    }
        if (glfwGetKey(window_, GLFW_KEY_A) == GLFW_PRESS)
	    {
            std::cout << "A pressed\n";
            cam.position =  cam.position + glm::vec3(-0.1f,0,0);
	    }
        if (glfwGetKey(window_, GLFW_KEY_S) == GLFW_PRESS)
	    {
            std::cout << "S pressed\n";
            cam.position =  cam.position + glm::vec3(0,0,0.1f);
	    }
        if (glfwGetKey(window_, GLFW_KEY_D) == GLFW_PRESS)
	    {
            std::cout << "D pressed\n";
            cam.position =  cam.position + glm::vec3(0.1f,0,0);
	    }
    }
};