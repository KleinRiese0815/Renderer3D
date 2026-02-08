#include "WindowFactory.h"

bool window_factory::window_hint_resizable = true;
bool window_factory::window_hint_visible = true;
bool window_factory::window_hint_decorated = true;
bool window_factory::window_hint_focused = true;
bool window_factory::window_hint_maximized = false;
bool window_factory::glfw_is_initialzed = false;

void window_factory::set_parameter(window_parameter parameter, bool value)
{
    //convert the enum parameter into a glfw enum
    int glfw_parameter = GLFW_DECORATED;
    
    switch(parameter)
    {
        case window_parameter::decorated:
            window_hint_decorated = value;
        break;

        case window_parameter::focused:
            window_hint_focused = value;
        break;

        case window_parameter::maximized:
            window_hint_maximized = value;
        break;

        case window_parameter::resizable:
            window_hint_resizable = value;
        break;

        case window_parameter::visible:
            window_hint_visible = value;
        break;
    }
}

Window window_factory::create_window(int width, int height, std::string name)
{
    
    if(!glfw_is_initialzed){
        if(!glfwInit()){
            std:: cout << "ERROR : GLFW INIT" << std::endl;
        }
        glfw_is_initialzed = true;
    }

    glfwWindowHint(GLFW_DECORATED, bool_to_glfwbool(window_hint_decorated));
    glfwWindowHint(GLFW_FOCUSED, bool_to_glfwbool(window_hint_focused));
    glfwWindowHint(GLFW_MAXIMIZED, bool_to_glfwbool(window_hint_maximized));
    glfwWindowHint(GLFW_RESIZABLE, bool_to_glfwbool(window_hint_resizable));
    glfwWindowHint(GLFW_VISIBLE, bool_to_glfwbool(window_hint_visible));
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    
    return Window(width, height, name);
}

