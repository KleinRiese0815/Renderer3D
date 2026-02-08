#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include "Color.h"


class Window
{
    GLFWwindow* m_glfw_window_ptr;
    Color m_clear_color; 
    
public:
    Window(int width, int height, std::string name);
    GLFWwindow* GetGLFWPointer();
    
    void SetClearColor(char r, char g, char b);
    void SetClearColor(Color);
    void make_this_context_current();
};
