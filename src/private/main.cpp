#include "EX_modelLoading.h"
#include "windowCreator.h"

int main(int argc, char* argv[])
{
    GLFWwindow* window = CreateWindow(400, 400, "First Window");
    modelLoading Model = modelLoading(window);
    return 0;
}
