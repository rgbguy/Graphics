#include "texture.h"

Texture::Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType)
{
    textureslot = slot;
    glActiveTexture(slot); //tell opengl which texture slot to use!
    glGenTextures(1, &ID);
    glBindTexture(texType, ID);
    type = texType;
    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load and generate the texture
    int width, height, nrChannels;
    unsigned char *data = stbi_load(image, &width, &height, &nrChannels, 0);
    if (data)
    {
        std::cout << "Texture Loaded" << std::endl;   
        glTexImage2D(texType, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(texType);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
	// Unbinds the OpenGL Texture object so that it can't accidentally be modified
	glBindTexture(texType, 0);
}

void Texture::SetUniform(unsigned int shader, const char* uniform)
{
	// Shader needs to be activated before changing the value of a uniform
	glUseProgram(shader);
	// Set the texture uniform value to currently bound texture slot, in this case = 0
	glUniform1i(glGetUniformLocation(shader, uniform), textureslot- GL_TEXTURE0);
}

void Texture::Bind()
{
	glBindTexture(type, ID);
}

void Texture::Unbind()
{
	glBindTexture(type, 0);
}

void Texture::Use()
{
    glActiveTexture(ID);
	glBindTexture(type, ID);
}

void Texture::Delete()
{
	glDeleteTextures(1, &ID);
}