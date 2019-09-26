#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>
using namespace glm;

int main( void ){
    GLFWwindow* window;

    // Initialise GLFW library
    if( !glfwInit() ){
        return -1;
    }
    window = glfwCreateWindow( 720, 720, "Puerquito Project", NULL, NULL);
    if( window == NULL ){
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        //Render Open Gl Here
        
        //Swap front and back buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

