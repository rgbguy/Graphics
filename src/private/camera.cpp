#include "camera.h"

Camera::Camera()
{
    viewMat = glm::lookAt(position, forward, up);
    projMat = glm::perspective(glm::radians(fov), 1.0f, 0.0f, 100.0f);    
}

Camera::Camera(glm::vec3 position_, glm::vec3 forward_, glm::vec3 up_)
{
    position = position_;
    forward = forward_;
    up = up_;

    viewMat = glm::lookAt(position, forward, up);
    projMat = glm::perspective(glm::radians(fov), 1.0f, 0.0f, 100.0f);
}

void Camera::Activate(unsigned int shader)
{
	glUseProgram(shader);
    glUniformMatrix4fv(glGetUniformLocation(shader, "viewMat"), 1, GL_FALSE, &viewMat[0][0]);
    glUniformMatrix4fv(glGetUniformLocation(shader, "projMat"), 1, GL_FALSE, &projMat[0][0]);
}

Camera::~Camera()
{
}
