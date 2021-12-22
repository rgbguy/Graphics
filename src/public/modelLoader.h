#ifndef MODEL_LOADER
#define MODEL_LOADER

#include <objLoader.h>
#include <iostream>
#include <glad/glad.h>
#include "vao.h"

class ModelLoader
{
private:
    VAO VAO;
    objl::Loader Loader;

public:
    ModelLoader(std::string Path);
    void Draw();
};

ModelLoader::ModelLoader(std::string Path)
{
    if (Loader.LoadFile(Path))
    {
        std::cout << "Obj File Loaded\n";
    }
    else
    {
        std::cout << "Failed to load obj file\n";
    }
    VBO MainVBO(&Loader.LoadedVertices[0].Position.X, Loader.LoadedVertices.size() * sizeof(objl::Vertex));
    VAO.Bind();
    VAO.LinkAttrib(MainVBO, 0, 3, GL_FLOAT, sizeof(objl::Vertex), (void*)0);
    VAO.LinkAttrib(MainVBO, 1, 3, GL_FLOAT, sizeof(objl::Vertex), (void*)(3 * sizeof(float)));       
    VAO.LinkAttrib(MainVBO, 2, 2, GL_FLOAT, sizeof(objl::Vertex), (void*)(6 * sizeof(float)));
    VAO.Unbind();
}

void ModelLoader::Draw()
{
    VAO.Bind();
    glDrawArrays(GL_TRIANGLES, 0, Loader.LoadedVertices.size());
    VAO.Unbind();
}

#endif