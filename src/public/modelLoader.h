#pragma once
#include<objLoader.h>
#include<iostream>

class MeshLoader
{
public:
    std::vector<objl::Vertex> ObjVertices;
public:
    std::vector<float> position;
    std::vector<float> normal;
    std::vector<float> texcoord;

    MeshLoader(std::string Path)
    {
        objl::Loader Loader;
        if (Loader.LoadFile(Path))
        {
            std::cout << "Obj File Loaded\n";
        }
        else
        {
            std::cout << "Failed to load obj file\n";
        }

        ObjVertices = Loader.LoadedVertices;
        for (auto it : ObjVertices)
        {
            position.push_back(it.Position.X);
            position.push_back(it.Position.Y);
            position.push_back(it.Position.Z);

            normal.push_back(it.Normal.X);
            normal.push_back(it.Normal.Y);
            normal.push_back(it.Normal.Z);

            texcoord.push_back(it.TextureCoordinate.X);
            texcoord.push_back(it.TextureCoordinate.Y);
        }
    }
};