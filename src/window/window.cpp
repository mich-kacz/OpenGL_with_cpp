#include <GL/gl.h>
#include <iostream>
#include "window.hpp"


/*''''''''''''''Private methods''''''''''''''''''''''*/

void Window::resizeCallback(GLFWwindow* window, int width, int height)
{
    
}

Window::windowParameters_s* Window::createNewWindow(int width, int height, std::string name)
{
    windowParameters = new windowParameters_s;
    windowParameters->height = height;
    windowParameters->width = width;
    windowParameters->head = windowParameters;
    windowParameters->next = 0;
    windowParameters->tail = windowParameters;

    windowParameters->window = glfwCreateWindow(windowParameters->height, windowParameters->width, name.data(), NULL, NULL);

    return windowParameters;
}

/*''''''''''''''Exposed API''''''''''''''''''''''*/

Window::Window(int height, int width, std::string name)
{
    
    glfwInit();

    if (!windowParameters->window)
    {
        glfwTerminate();
    }else
    {
        glfwMakeContextCurrent(windowParameters->window);
        glfwSetWindowSizeCallback(windowParameters->window, resizeCallback);
    }

}

Window::~Window()
{
    glfwTerminate();
}

void Window::startLoop()
{
    while (!glfwWindowShouldClose(windowParameters->window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(windowParameters->window);

        /* Poll for and process events */
        glfwPollEvents();
    }
}