#include "baseApp.h"
#include "vbo.h"
#include "vao.h"
#include "shader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

class texturedTriangle : public baseApp
{
public:
    glm::mat4 modelMat;
    unsigned int shaderProgram;
    texturedTriangle()
    {
        baseApp::CreateWindow(400, 400, "textured triangle");
    }
    void Start() override
    {
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
	    VBO VBO1(vertices, sizeof(vertices));

        unsigned int texcBuff;
        glGenBuffers(1, &texcBuff);
	    glBindBuffer(GL_ARRAY_BUFFER, texcBuff);
	    glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords), texCoords, GL_STATIC_DRAW);
	    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
	    glEnableVertexAttribArray(1);

	    VAO1.LinkVBO(VBO1, 0);
        modelMat = glm::mat4(1.0f);

        unsigned int texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        // set the texture wrapping/filtering options (on the currently bound texture object)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        // load and generate the texture
        int width, height, nrChannels;
        unsigned char *data = stbi_load("/Users/rgbguy/Documents/Dev/Repositories/Graphics/src/public/wall.jpeg", &width, &height, &nrChannels, 0);
        if (data)
        {
            std::cout << "Texture Loaded" << std::endl;   
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            std::cout << "Failed to load texture" << std::endl;
        }
        stbi_image_free(data);

        glActiveTexture(GL_TEXTURE0);
        int locTex0 = glGetUniformLocation(shaderProgram, "tex0");
        glUniform1i(locTex0, 0);   //use texture bound to GL_TEXTURE0


    }

    void Update() override
    {
        glActiveTexture(GL_TEXTURE0);
        
        modelMat = glm::rotate(modelMat, glm::radians(1.0f), glm::vec3(0.0f,0,1.0f));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "modelMat"), 1, GL_FALSE, &modelMat[0][0]);
        LOG("First Tri Update\n", 1);
        glDrawArrays(GL_TRIANGLES, 0, 3); 
    }
};