#version 330 core
out vec4 FragColor;

in vec2 texCoord;

// Gets the Texture Unit from the main function
uniform sampler2D tex0;
uniform sampler2D tex1;

void main()
{
    FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);
    FragColor = mix(texture(tex0, texCoord), texture(tex1, texCoord), 0.5);
}