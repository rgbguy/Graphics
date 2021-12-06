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
    MeshLoader testModel = MeshLoader("../res/meshes/cow.obj");

    modelLoading()
    {
        baseApp::CreateWindow(400, 400, "model loading");
    }
    void Start() override
    {
        std::string vspath = "shaders/modelLoading.vert";
        std::string fspath = "shaders/modelLoading.frag";

        shaderProgram = CreateShaderProgram(vspath.c_str(), fspath.c_str());
        glUseProgram(shaderProgram);

	    VAO VAO1;
	    VAO1.Bind();
	    VBO VBO_vert(&testModel.position[0], testModel.position.size() * sizeof(float));
        VBO VBO_texC(&testModel.texcoord[0], testModel.texcoord.size() * sizeof(float));
        VBO VBO_norm(&testModel.normal[0],   testModel.normal.size()   * sizeof(float));

        VAO1.LinkAttrib(VBO_vert, 0, 3, GL_FLOAT, 0, (void*)0);
        VAO1.LinkAttrib(VBO_texC, 1, 2, GL_FLOAT, 0, (void*)0);
        VAO1.LinkAttrib(VBO_norm, 2, 3, GL_FLOAT, 0, (void*)0);

        //VAO1.Unbind();

	    Texture GridTexture("../res/textures/grid.jpeg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	    GridTexture.SetUniform(shaderProgram, "tex0");
        GridTexture.Use();

	    Texture WallTexture("../res/textures/wall.jpeg", GL_TEXTURE_2D, GL_TEXTURE1, GL_RGBA, GL_UNSIGNED_BYTE);
	    WallTexture.SetUniform(shaderProgram, "tex1");
        WallTexture.Use();

        //Activates the scene camera. Camera handled in base app.
        SceneCam.Activate(shaderProgram);
    }

    void Update() override
    {
        modelMat = glm::rotate(modelMat, glm::radians(1.0f), glm::vec3(0, 1.0f, 0));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "modelMat"), 1, GL_FALSE, &modelMat[0][0]);
        glDrawArrays(GL_TRIANGLES, 0, testModel.position.size()/3); 
    }
};