#include "GlfwEnums.h"

int bool_to_glfwbool(bool value)
{
    if(value)
        return GLFW_TRUE;
    else
        return GLFW_FALSE;
}
