#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include <glad/glad.h>
#include <stb_image.h>

#include "shader.h"

class Texture
{
public:
	GLuint ID;
	GLenum type;
    GLenum textureslot;
	Texture(const char* image, GLenum texType, unsigned int slot, GLenum format, GLenum pixelType);

	// Assigns a texture unit to a texture
	void SetUniform(unsigned int shaderProgram, const char* uniform);
	// Binds a texture
	void Bind();
	// Unbinds a texture
	void Unbind();
    // Activate and Bind (to use the texture)
    void Use();
	// Deletes a texture
	void Delete();
};
#endif