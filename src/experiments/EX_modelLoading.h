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
int possize;
class modelLoading : public baseApp
{
public:
    glm::mat4 modelMat;
    unsigned int shaderProgram;
    modelLoading()
    {
        baseApp::CreateWindow(400, 400, "model loading");
    }
    void Start() override
    {
    std::string Path = "../res/meshes/cow.obj";
    MeshLoader CowMesh = MeshLoader(Path);
    std::vector<float> Positions = CowMesh.ObjVertexPos;
    std::vector<float> Normals = CowMesh.ObjVertexNormal;
    std::vector<float> TexCoord = CowMesh.ObjTextureCoord;

    std::cout << "Pos size: " << Positions.size() << "\n";
        LOG("First Tri Start\n", 1);
    possize = Positions.size();
        std::string vspath = "shaders/modelLoading.vert";
        std::string fspath = "shaders/modelLoading.frag";

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
	    VBO VBO_vert(&Positions[0], Positions.size() * sizeof(float));
        VBO VBO_texC(&TexCoord[0], TexCoord.size() * sizeof(float));

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
        glDrawArrays(GL_TRIANGLES, 0, possize/3); 
    }

    void Input(GLFWwindow* window_) override
    {
        if (glfwGetKey(window_, GLFW_KEY_W) == GLFW_PRESS)
	    {
            LOG("W pressed\n",1);
            cam.position =  cam.position + glm::vec3(0,0,-0.1f);
	    }
        if (glfwGetKey(window_, GLFW_KEY_A) == GLFW_PRESS)
	    {
            LOG("A pressed\n",1);
            cam.position =  cam.position + glm::vec3(-0.1f,0,0);
	    }
        if (glfwGetKey(window_, GLFW_KEY_S) == GLFW_PRESS)
	    {
            LOG("S pressed\n",1);
            cam.position =  cam.position + glm::vec3(0,0,0.1f);
	    }
        if (glfwGetKey(window_, GLFW_KEY_D) == GLFW_PRESS)
	    {
            LOG("D pressed\n",1);
            cam.position =  cam.position + glm::vec3(0.1f,0,0);
	    }
    }
};