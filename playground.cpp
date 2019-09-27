#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>
using namespace glm;


#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
GLfloat vertices[] ={
    // front face
    200,300,-600 , // top left &1
    400,300,-600 , // top right &2
    400,100,-600 , // bottom right &4
    200,100,-600, // bottom left &3
    
    // back face
    200, 300, -300 , // top left &5
    400, 300, -300 , // top right &6
    400, 100, -300 , // bottom right &8
    200, 100, -300 , // bottom left &7
    
    // left face
    200,300,-600 , // top left &1
    200, 300, -300 , // top right &5
    200, 100, -300 , // bottom right &7
    200,100,-600, // bottom left &3
    
    // right face
    400, 300, -300 ,// top left &6
    400,300,-600 ,  // top right &2
    400,100,-600 , // bottom right &4
    400, 100, -300 , // bottom left &8
    
    // top face
    200,300,-600 , // top left &1
    400,300,-600 ,  // top right &2
    400, 300, -300 , // bottom right &6
    200, 300, -300 ,// bottom left &5
    
    // top face
    200, 100, -300 , // top left & 7
    200,100,-600, // top right &3
    400,100,-600 ,// bottom right &4
    400, 100, -300 , // bottom left &8
};

void keyCallback( GLFWwindow *window, int key, int scancode, int action, int mods );
void DrawPolygon(GLfloat vertices[] );

GLfloat rotationX = 0.0f;
GLfloat rotationY = 0.0f;

int main( void )
{
    GLFWwindow *window;
    
    // Initialize the library
    if ( !glfwInit( ) )
    {
        return -1;
    }
    
    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow( SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World", NULL, NULL );
    
    glfwSetKeyCallback( window, keyCallback );
    glfwSetInputMode( window, GLFW_STICKY_KEYS, 1 );
    
    
    int screenWidth, screenHeight;
    glfwGetFramebufferSize( window, &screenWidth, &screenHeight );

    if ( !window )
    {
        glfwTerminate( );
        return -1;
    }
    
    // Make the window's context current
    glfwMakeContextCurrent( window );
    
    glViewport( 0.0f, 0.0f, screenWidth, screenHeight ); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
    glMatrixMode( GL_PROJECTION ); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
    glLoadIdentity( ); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
    glOrtho( 0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1000 ); // essentially set coordinate system
    glMatrixMode( GL_MODELVIEW ); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
    glLoadIdentity( ); // same as above comment
    
    GLfloat halfScreenWidth = SCREEN_WIDTH / 2;
    GLfloat halfScreenHeight = SCREEN_HEIGHT / 2;
    
    
    // Loop until the user closes the window
    while ( !glfwWindowShouldClose( window ) )
    {
        glClear( GL_COLOR_BUFFER_BIT );
        
        // Render OpenGL here
        
        glPushMatrix( );
        glTranslatef( halfScreenWidth, halfScreenHeight, -500 );
        glRotatef( rotationX, 1, 0, 0 );
        glRotatef( rotationY, 0, 1, 0 );
        glTranslatef( -halfScreenWidth, -halfScreenHeight, 500 );
        DrawPolygon(vertices);
        glPopMatrix();

        
        // Swap front and back buffers
        glfwSwapBuffers( window );
        
        // Poll for and process events
        glfwPollEvents( );
    }
        
    glfwTerminate( );
    
    return 0;
}



void keyCallback( GLFWwindow *window, int key, int scancode, int action, int mods )
{
    //std::cout << key << std::endl;
    
    const GLfloat rotationSpeed = 10;
    
    // actions are GLFW_PRESS, GLFW_RELEASE or GLFW_REPEAT
    if ( action == GLFW_PRESS || action == GLFW_REPEAT )
    {
        switch ( key )
        {
            case GLFW_KEY_UP:
                rotationX -= rotationSpeed;
                break;
            case GLFW_KEY_DOWN:
                rotationX += rotationSpeed;
                break;
            case GLFW_KEY_RIGHT:
                rotationY += rotationSpeed;
                break;
            case GLFW_KEY_LEFT:
                rotationY -= rotationSpeed;
                break;
        }
        
        
    }
}

void DrawPolygon( GLfloat vertices[] ){
    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    //glColor3f( colour[0], colour[1], colour[2] );
    glEnableClientState( GL_VERTEX_ARRAY );
    glVertexPointer( 3, GL_FLOAT, 0, vertices );
    

    glDrawArrays( GL_QUADS, 0, 24 );
    
    glDisableClientState( GL_VERTEX_ARRAY );
}

