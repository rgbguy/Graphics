#ifndef UTILITY
#define UTILITY
#include <iostream>

#define DEBUG 0
#define LOG(x, level) if(DEBUG || !level) std::cout << x

class GlobalSettings
{
public:
    static int NumCows;
    static float FOV;
    static float width;
    static float height;
};
#endif
