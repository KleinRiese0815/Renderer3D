#include "Window.h"
#include "GLFW/glfw3.h"

Window::Window(int width, int height, std::string name) :
    m_clear_color(Color(0, 0, 0))
{
    m_glfw_window_ptr = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);

    if(!m_glfw_window_ptr)
    {
        glfwTerminate();
        std::cout << "ERROR : WINDOW CREATION" << std::endl;
    }

    glfwMakeContextCurrent(m_glfw_window_ptr);


    GLADloadproc glad_proc = (GLADloadproc)glfwGetProcAddress;
    gladLoadGLLoader(glad_proc);
}

void Window::SetClearColor(char r, char g, char b)
{
    glClearColor(r, g, b, 1);
    m_clear_color = Color(r, g, b);
}

void Window::SetClearColor(Color color)
{
    //color components can reach from 0 to 255, but gl Clear Color wants them normalized(0 - 1)
    const int max_color_component_val = sizeof(unsigned int);
    glClearColor(color.r / max_color_component_val, color.g / max_color_component_val, color.b / max_color_component_val, 1);
    m_clear_color = color;
}

GLFWwindow* Window::GetGLFWPointer()
{
    return m_glfw_window_ptr;
}

void Window::make_this_context_current(){
    glfwMakeContextCurrent(m_glfw_window_ptr);
}