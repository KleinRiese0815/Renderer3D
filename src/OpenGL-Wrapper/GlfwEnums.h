#pragma once 
#include "GLFW/glfw3.h"


enum class window_parameter
{
    resizable, visible, decorated, focused, maximized
};

int bool_to_glfwbool(bool value);