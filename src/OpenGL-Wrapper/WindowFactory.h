#pragma once
#include "Window.h"
#include "GlfwEnums.h"
#include "GLFW/glfw3.h"

class window_factory
{
private:
    static bool window_hint_resizable;
    static bool window_hint_visible;
    static bool window_hint_decorated;
    static bool window_hint_focused;
    static bool window_hint_maximized;
    static bool glfw_is_initialzed;
public:
    static Window create_window(int widht, int height, std::string name);


    //prameters are used to set initial attributes of the window, eg. wheter it is resizable or not
    static void set_parameter(window_parameter parameter, bool value);
};