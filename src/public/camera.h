#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.h"

class Camera
{
public:
    glm::vec3 position = glm::vec3(0,0,10.f);
    glm::vec3 forward = glm::vec3(0,0,-1.0f);
    glm::vec3 up = glm::vec3(0, 1.0f, 0.0f);

    float fov = 90.0f;
    glm::mat4 viewMat = glm::mat4(1.0f);
    glm::mat4 projMat = glm::mat4(1.0f);
public:
    Camera();
    Camera(glm::vec3 pos, glm::vec3 forw, glm::vec3 up);
    ~Camera();

    void Activate(unsigned int shader);
    void Update(unsigned int shader, glm::vec3 position_, glm::vec3 forward_, glm::vec3 up_);

};
