#include <iostream>
#include "OpenGL-Wrapper/Window.h"
#include "OpenGL-Wrapper/WindowFactory.h"

int main()
{
    Window window = window_factory::create_window(200, 200, "Hello Window");
    Window window2 = window_factory::create_window(400, 400, "Hello World 2");
    window.SetClearColor(100, 100, 100);

    GLFWwindow* windowptr = window.GetGLFWPointer();
    GLFWwindow* windowptr2 = window2.GetGLFWPointer();

    while(!glfwWindowShouldClose(windowptr))
    {
        window.make_this_context_current();
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();

        window2.make_this_context_current();
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();

        glfwSwapBuffers(windowptr);
        glfwSwapBuffers(windowptr2);
    }

    glfwTerminate();
    return 0;
}
