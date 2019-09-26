#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>
using namespace glm;

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main( void ){
    GLFWwindow* window;

    // Initialise GLFW library
    if( !glfwInit() ){
        return -1;
    }
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Puerquito Project", NULL, NULL);
    if( window == NULL ){
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    float vertices[] =
    {
        0, 300, 0.0, //Top LEFT Cornet
         300, 300 ,0.0, //Top RIGHT Cornet
         300 ,0 ,0.0, //Bottom LEFT corner
         0, 0,0.0 //Bottom RIGHT corner
    };
    /*Normalize square pixels with screen deep*/
    glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    /*END Normalize square pixels with screen deep*/
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        /*
          ====== RENDER OPEN GLE HERE==========
         */
        //TellOpenGLWeAreGonnaDrawVertices:
        glEnableClientState(GL_VERTEX_ARRAY);
        //glVertexPointer -> #OfDimension, Datatype, GAP, CreatedVariable
        glVertexPointer(3, GL_FLOAT, 0, vertices);
        //glDrawArrays -> FIGURE TYPE, VERTEX START, #ofTotalVertices
        glDrawArrays(GL_QUADS, 0, 4);
        glDisableClientState(GL_VERTEX_ARRAY);
        /*
        ====== END RENDER OPEN GLE HERE==========
        */
        //Swap front and back buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
        
    }
    glfwTerminate();
    return 0;
}

