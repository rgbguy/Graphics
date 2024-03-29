cmake_minimum_required(VERSION 2.8)
set (CMAKE_CXX_STANDARD 11)

project(Graphics)

include_directories(public)

add_executable(${PROJECT_NAME}
private/main.cpp
private/shader.cpp
private/vao.cpp
private/vbo.cpp
private/ebo.cpp
private/baseApp.cpp
private/texture.cpp
private/camera.cpp)

find_package(OpenGL REQUIRED)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../ext/glfw ${CMAKE_CURRENT_SOURCE_DIR}/../build/ext/glfw)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../ext/glad ${CMAKE_CURRENT_SOURCE_DIR}/../build/ext/glad)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../ext/glm ${CMAKE_CURRENT_SOURCE_DIR}/../build/ext/glm)

target_include_directories(${PROJECT_NAME}
PUBLIC ../ext/glfw/include
PUBLIC ../ext/glad/include
PUBLIC ../ext/glm/glm
PUBLIC public
PUBLIC shaders
PUBLIC experiments)

target_link_directories(${PROJECT_NAME}
PUBLIC ../ext/glfw/src
PUBLIC ../ext/glad/src
PUBLIC ../ext/glm/glm)

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} glfw glad glm)


