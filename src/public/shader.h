#ifndef SHADER_CLASS
#define SHADER_CLASS

#include <glad/glad.h>
#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>

#define LOG(x, level) if(DEBUG || !level) std::cout << x

enum ShaderType{
    vertexShader,
    fragmentShader
};

unsigned int CompileShader(const char * source, GLenum shaderType);

unsigned int CreateShaderProgram(const char * vsPath, const char * fsPath);

#endif