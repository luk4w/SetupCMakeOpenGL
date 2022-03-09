#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>

void processInput(GLFWwindow *);
void resizeCallback(GLFWwindow *, int, int);

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW window", NULL, NULL);
    
    if (window == NULL)
    {
        std::cout << "Nao foi possivel criar o objeto GLFW window!" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, resizeCallback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Nao foi possivel carregar o contexto OpenGL!" << std::endl;
        return -1;
    }    

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);
        glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void resizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}