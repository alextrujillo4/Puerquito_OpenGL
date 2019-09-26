#include <GL/glew.h>
#include <glfw3.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


   GLfloat vertices_body[] = {
        300, -300, 0,
        300, 225, 0,
        -300, 225, 0,
        -300, -300, 0,
        300, -300, 0,
        300, 225, 300,
        -300, -300, 300,
        -300, 225,300 ,
    };




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
    
    if ( !window )
    {
        glfwTerminate( );
        return -1;
    }
    
    // Make the window's context current
    glfwMakeContextCurrent( window );
    
    glViewport( 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT ); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
    glMatrixMode( GL_PROJECTION ); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
    glLoadIdentity( ); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
    glOrtho( -900, SCREEN_WIDTH, -900, SCREEN_HEIGHT, 0, 1 ); // essentially set coordinate system
    glMatrixMode( GL_MODELVIEW ); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
    glLoadIdentity( ); // same as above comment
    

    
    // Loop until the user closes the window
    while ( !glfwWindowShouldClose( window ) )
    {
          glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
              glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
            
        // Render OpenGL here
        glEnable( GL_LINE_SMOOTH );
        glEnable( GL_LINE_STIPPLE );
        glPushAttrib( GL_LINE_BIT );
        glLineWidth( 10 );
        glLineStipple( 1, 0x00FF );
        glEnableClientState( GL_VERTEX_ARRAY );
        glVertexPointer( 3, GL_FLOAT, 0, vertices_body );
        glDrawArrays( GL_LINES, 0, 8 );
        glDisableClientState( GL_VERTEX_ARRAY );
        glPopAttrib( );
        glDisable( GL_LINE_STIPPLE );
 
        
         
      
        
        // Swap front and back buffers
        glfwSwapBuffers( window );
        
        // Poll for and process events
        glfwPollEvents( );
    }
    
    glfwTerminate( );
    
    return 0;
}
