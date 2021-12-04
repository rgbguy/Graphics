#include "baseApp.h"
#include "vbo.h"
#include "vao.h"
#include "shader.h"

class firstTriangle : public baseApp
{
public:
    void Start() override
    {
        LOG("First Tri Start\n", 1);
    }
    void Update() override
    {
        LOG("First Tri Update\n", 1);
    }
};