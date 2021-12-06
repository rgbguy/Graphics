#pragma once
#include<objLoader.h>
#include<iostream>

class MeshLoader
{
    std::vector<objl::Vertex> ObjVertices;
public:
    std::vector<float> ObjVertexNormal;
    std::vector<float> ObjVertexPos;
    std::vector<float> ObjTextureCoord;

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
            ObjVertexPos.push_back(it.Position.X);
            ObjVertexPos.push_back(it.Position.Y);
            ObjVertexPos.push_back(it.Position.Z);

            ObjVertexNormal.push_back(it.Normal.X);
            ObjVertexNormal.push_back(it.Normal.Y);
            ObjVertexNormal.push_back(it.Normal.Z);

            ObjTextureCoord.push_back(it.TextureCoordinate.X);
            ObjTextureCoord.push_back(it.TextureCoordinate.Y);
        }
    }
};