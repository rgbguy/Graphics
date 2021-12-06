#version 330 core
out vec4 FragColor;

in vec2 texCoord;
in vec3 normal;

// Gets the Texture Unit from the main function
uniform sampler2D tex0;
uniform sampler2D tex1;

void main()
{
    vec3 lightdir = normalize(vec3(1.0f, -1.0f, -1.0f));
    float intensity = dot(normal, lightdir);
    intensity = (intensity > 0) ? intensity : 0;
    FragColor = (intensity + 0.2f) * vec4(1.0f, 1.0f, 0.3f, 1.0f);
    //FragColor = mix(texture(tex0, texCoord), texture(tex1, texCoord), 0.5);
}