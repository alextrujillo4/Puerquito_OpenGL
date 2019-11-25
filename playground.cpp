/* Integrantes:
Esthephany Ayala
Valentin Trujillo
Alberto Bermea

Este codigo esta basado en el tutorial de
Sonar Systems
Link: https://www.youtube.com/watch?v=vcMox6i8f4Y
*/


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "SOIL2/SOIL2.h"



//Reading a PPM file
#include <iostream>
#include <iomanip>
#include <fstream>


#include <iostream>
#include <cstdlib>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480


GLenum fill_mode = GL_FILL;

GLfloat color[] = {
    
    1,0.5,0.8,
    1,0.5,0.8,
    1,0.5,0.8,
    1,0.5,0.8,
    
    1,0.5,0.8,
    1,0.5,0.8,
    1,0.5,0.8,
    1,0.5,0.8,
    
    1,0.5,0.8,
    1,0.5,0.8,
    1,0.5,0.8,
    1,0.5,0.8,
    
    1,0.5,0.8,
    1,0.5,0.8,
    1,0.5,0.8,
    1,0.5,0.8,
    
    1,0.5,0.8,
    1,0.5,0.8,
    1,0.5,0.8,
    1,0.5,0.8
    
};

GLfloat color_amarillo_tranqui[] = {
    
    0.9,0.9,0.5,
    0.9,0.9,0.5,
    0.9,0.9,0.5,
    0.9,0.9,0.5,
    
    0.9,0.9,0.5,
    0.9,0.9,0.5,
    0.9,0.9,0.5,
    0.9,0.9,0.5,
    
    0.9,0.9,0.5,
    0.9,0.9,0.5,
    0.9,0.9,0.5,
    0.9,0.9,0.5,
    
    0.9,0.9,0.5,
    0.9,0.9,0.5,
    0.9,0.9,0.5,
    0.9,0.9,0.5,
    
    0.9,0.9,0.5,
    0.9,0.9,0.5,
    0.9,0.9,0.5,
    0.9,0.9,0.5,
    
    0.9,0.9,0.5,
    0.9,0.9,0.5,
    0.9,0.9,0.5,
    0.9,0.9,0.5,
    
    
};

GLfloat color_rosaFuerte[] = {
    1,0,0.4,
    1,0,0.4,
    1,0,0.4,
    1,0,0.4,
    
    1,0,0.4,
    1,0,0.4,
    1,0,0.4,
    1,0,0.4,
    
    1,0,0.4,
    1,0,0.4,
    1,0,0.4,
    1,0,0.4,
    
    1,0,0.4,
    1,0,0.4,
    1,0,0.4,
    1,0,0.4,
    
    1,0,0.4,
    1,0,0.4,
    1,0,0.4,
    1,0,0.4,
    
    1,0,0.4,
    1,0,0.4,
    1,0,0.4,
    1,0,0.4
};

GLfloat color_negro[] = {
    
    0,0,0,
    0,0,0,
    0,0,0,
    0,0,0,
    
    0,0,0,
    0,0,0,
    0,0,0,
    0,0,0,
    
    0,0,0,
    0,0,0,
    0,0,0,
    0,0,0,
    
    0,0,0,
    0,0,0,
    0,0,0,
    0,0,0,
    
    0,0,0,
    0,0,0,
    0,0,0,
    0,0,0,
    
    0,0,0,
    0,0,0,
    0,0,0,
    0,0,0,
    
};

GLfloat color_blanco[] = {
    
    255,255,255,
    255,255,255,
    255,255,255,
    255,255,255,
    
    255,255,255,
    255,255,255,
    255,255,255,
    255,255,255,
    
    255,255,255,
    255,255,255,
    255,255,255,
    255,255,255,
    
    255,255,255,
    255,255,255,
    255,255,255,
    255,255,255,
    
    255,255,255,
    255,255,255,
    255,255,255,
    255,255,255,
    
    255,255,255,
    255,255,255,
    255,255,255,
    255,255,255,
    
};

GLfloat color_raro[] = {
    1,0.5,0.3,
    1,0.5,0.3,
    1,0.5,0.3,
    1,0.5,0.3,
    
    1,0.5,0.3,
    1,0.5,0.3,
    1,0.5,0.3,
    1,0.5,0.3,
    
    1,0.5,0.3,
    1,0.5,0.3,
    1,0.5,0.3,
    1,0.5,0.3,
    
    1,0.5,0.3,
    1,0.5,0.3,
    1,0.5,0.3,
    1,0.5,0.3,
    
    1,0.5,0.3,
    1,0.5,0.3,
    1,0.5,0.3,
    1,0.5,0.3,
    
    1,0.5,0.3,
    1,0.5,0.3,
    1,0.5,0.3,
    1,0.5,0.3

};

GLfloat textVertices [] = {
    
    // back face
    200, 300, -300 , // top left &5
    400, 300, -300 , // top right &6
    400, 100, -300 , // bottom right &8
    200, 100, -300 , // bottom left &7
};

GLuint indices [] = {
    0,1,3,
    1,2,3
};

unsigned char CHECKERS [4][4]={{000,255,000,255},
    {255,000,255,000},
    {000,255,000,255},
    {255,000,255,000}
};

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

GLfloat vertices_algo_blanco_1[] ={
    // top face
    200, 301,-600 , // top left &1
    225, 301,-600 ,  // top right &2
    225, 301, -575 , // bottom right &6
    200, 301, -575 ,// bottom left &5
    
    200,301,-525 , // top left &1
    225,301,-525 ,  // top right &2
    225, 301,-475 , // bottom right &6
    200, 301, -475 ,// bottom left &5
    
    200,301,-375, // top left &1
    225,301,-375 ,  // top right &2
    225, 301, -425 , // bottom right &6
    200, 301, -425 ,// bottom left &5
    
    
    //
    275,301,-525 , // top left &1
    225,301,-525 ,  // top right &2
    225, 301, -575 , // bottom right &6
    275, 301, -575 ,// bottom left &5
    
    275,301,-425 , // top left &1
    225,301,-425 ,  // top right &2
    225, 301, -475 , // bottom right &6
    275, 301, -475 ,// bottom left &5
    
    275,301,-375 , // top left &1
    225,301,-375 ,  // top right &2
    225, 301, -325 , // bottom right &6
    275, 301, -325 ,// bottom left &5
    
    
};

GLfloat vertices_algo_blanco_2[] ={
    //
    275,301,-600 , // top left &1
    325,301,-600 ,  // top right &2
    325, 301, -575 , // bottom right &6
    275, 301, -575 ,// bottom left &5
    
    275,301,-525 , // top left &1
    325,301,-525 ,  // top right &2
    325, 301, -475 , // bottom right &6
    275, 301, -475 ,// bottom left &5
    
    275,301,-375 , // top left &1
    325,301,-375 ,  // top right &2
    325, 301, -425 , // bottom right &6
    275, 301, -425 ,// bottom left &5
    
    //
    375,301,-525 , // top left &1
    325,301,-525 ,  // top right &2
    325, 301, -575 , // bottom right &6
    375, 301, -575 ,// bottom left &5
    
    375,301,-425 , // top left &1
    325,301,-425 ,  // top right &2
    325, 301, -475 , // bottom right &6
    375, 301, -475 ,// bottom left &5
    
    375,301,-375 , // top left &1
    325,301,-375 ,  // top right &2
    325, 301, -325, // bottom right &6
    375, 301, -325 ,// bottom left &5
};

GLfloat vertices_algo_blanco_3[] ={
    // top face
    200, 301,-325 , // top left &1
    225, 301,-325 ,  // top right &2
    225, 301, -300 , // bottom right &6
    200, 301, -300 ,// bottom left &5
    
    275,301,-325 , // top left &1
    325,301,-325 ,  // top right &2
    325, 301,-300 , // bottom right &6
    275, 301, -300 ,// bottom left &5
    
    375,301,-325 , // top left &1
    400,301,-325 ,  // top right &2
    400, 301,-300 , // bottom right &6
    375, 301, -300 ,// bottom left &5
    
    400, 301,-600 , // top left &1
    375, 301,-600 ,  // top right &2
    375, 301, -575 , // bottom right &6
    400, 301, -575 ,// bottom left &5
    
    400,301,-525 , // top left &1
    375,301,-525 ,  // top right &2
    375, 301,-475 , // bottom right &6
    400, 301, -475 ,// bottom left &5
    
    400,301,-375, // top left &1
    375,301,-375 ,  // top right &2
    375, 301, -425 , // bottom right &6
    400, 301, -425 ,// bottom left &5
    
    
};

GLfloat vertices_blanco_atras_1[] ={
    // top face
    200, 300,-601 , // top left &1
    225, 300, -601 , // bottom right &6
    225, 275, -601 ,
     200, 275,-601 , // bottom left &5
    
    200,125,-601, // top left &1
      // top right &2
    225, 125, -601 , // bottom right &6
    225, 100, -601 ,// bottom left &5
    200,100,-601 ,
    
    
    //
    225,275,-601 , // top left &1
     // top right &2
    275, 275, -601 , // bottom right &6
    275, 225, -601 ,// bottom left &5
     225,225,-601 ,
    
    225,175,-601 , // top left &1
     // top right &2
    275, 175,-601 , // bottom right &6
    275, 125,-601 ,// bottom left &5
     225,125,-601 ,
    
};

GLfloat vertices_atras_negro_1[] ={
    200,275,-601,
    225,275,-601,
    225,225,-601,
    200,225,-601,
    
    200,175,-601,
    225,175,-601,
    225,125,-601,
    200,125,-601,
    
    225,300,-601,
    275,300,-601,
    275,275,-601,
    225,275,-601,
    
    225,225,-601,
    275,225,-601,
    275,175,-601,
    225,175,-601,
    
    225,125,-601,
    275,125,-601,
    275,100,-601,
    225,100,-601,
};
GLfloat vertices_atras_negro_2[]={
    325,300,-601,
    375,300,-601,
    375,275,-601,
    325,275,-601,
    
    325,225,-601,
    375,225,-601,
    375,175,-601,
    325,175,-601,
    
    325,125,-601,
    375,125,-601,
    375,100,-601,
    325,100,-601,
    
    375,275,-601,
    400,275,-601,
    400,225,-601,
    375,225,-601,
    
    375,175,-601,
    400,175,-601,
    400,125,-601,
    375,125,-601,
    
    375,175,-601,
    400,175,-601,
    400,125,-601,
    375,125,-601,
};

GLfloat vertices_atras_negro_3[]={
    275,275,-601,
    325,275,-601,
    325,225,-601,
    275,225,-601,
    
    275,125,-601,
    325,125,-601,
    325,175,-601,
    275,175,-601,
    
    325,125,-601,
    375,125,-601,
    375,100,-601,
    325,100,-601,
    
    375,275,-601,
    400,275,-601,
    400,225,-601,
    375,225,-601,
    
    375,175,-601,
    400,175,-601,
    400,125,-601,
    375,125,-601,
    
    375,175,-601,
    400,175,-601,
    400,125,-601,
    375,125,-601,
};
GLfloat vertices_atras_negro_1_a[] ={
    200,275,-299,
    225,275,-299,
    225,225,-299,
    200,225,-299,
    
    200,175,-299,
    225,175,-299,
    225,125,-299,
    200,125,-299,
    
    225,300,-299,
    275,300,-299,
    275,275,-299,
    225,275,-299,
    
    225,225,-299,
    275,225,-299,
    275,175,-299,
    225,175,-299,
    
    225,125,-299,
    275,125,-299,
    275,100,-299,
    225,100,-299,
};
GLfloat vertices_atras_negro_2_a[]={
    325,300,-299,
    375,300,-299,
    375,275,-299,
    325,275,-299,
    
    325,225,-299,
    375,225,-299,
    375,175,-299,
    325,175,-299,
    
    325,125,-299,
    375,125,-299,
    375,100,-299,
    325,100,-299,
    
    375,275,-299,
    400,275,-299,
    400,225,-299,
    375,225,-299,
    
    375,175,-299,
    400,175,-299,
    400,125,-299,
    375,125,-299,
    
    375,175,-299,
    400,175,-299,
    400,125,-299,
    375,125,-299,
};

GLfloat vertices_atras_negro_3_a[]={
    275,275,-299,
    325,275,-299,
    325,225,-299,
    275,225,-299,
    
    275,125,-299,
    325,125,-299,
    325,175,-299,
    275,175,-299,
    
    325,125,-299,
    375,125,-299,
    375,100,-299,
    325,100,-299,
    
    375,275,-299,
    400,275,-299,
    400,225,-299,
    375,225,-299,
    
    375,175,-299,
    400,175,-299,
    400,125,-299,
    375,125,-299,
    
    375,175,-299,
    400,175,-299,
    400,125,-299,
    375,125,-299,
};

GLfloat vertices_atras_blanco_3[]={
    275,300,-601,
    325,300,-601,
    325,275,-601,
    275,275,-601,
    
    275,225,-601,
    325,225,-601,
    325,175,-601,
    275,175,-601,
    
    275,125,-601,
    325,125,-601,
    325,100,-601,
    275,100,-601
};

GLfloat vertices_atras_blanco_2[]={
    
    325,225,-601,
    375,225,-601,
    375,275,-601,
    325,275,-601,
    
    325,175,-601,
    375,175,-601,
    375,125,-601,
    325,125,-601,
    
    375,300,-601,
    400,300,-601,
    400,275,-601,
    375,275,-601,
    
    375,225,-601,
    400,225,-601,
    400,175,-601,
    375,175,-601,
    
    375,125,-601,
    375,125,-601,
    375,100,-601,
    375,100,-601,
};
GLfloat vertices_algo_negro_1[] ={
    
    //
    200,301,-525 , // top left &1
    225,301,-525 ,  // top right &2
    225, 301, -575 , // bottom right &6
    200, 301, -575 ,// bottom left &5
    
    200,301,-425 , // top left &1
    225,301,-425 ,  // top right &2
    225, 301, -475 , // bottom right &6
    200, 301, -475 ,// bottom left &5
    
    200,301,-375 , // top left &1
    225,301,-375 ,  // top right &2
    225, 301, -325 , // bottom right &6
    200, 301, -325 ,// bottom left &5
    
    //
    275,301,-600 , // top left &1
    225,301,-600 ,  // top right &2
    225, 301, -575 , // bottom right &6
    275, 301, -575 ,// bottom left &5
    
    275,301,-525 , // top left &1
    225,301,-525 ,  // top right &2
    225, 301, -475 , // bottom right &6
    275, 301, -475 ,// bottom left &5
    
    275,301,-375 , // top left &1
    225,301,-375 ,  // top right &2
    225, 301, -425 , // bottom right &6
    275, 301, -425 ,// bottom left &5
};

GLfloat vertices_algo_negro_2[] ={
    //
    400,301,-525 , // top left &1
    375,301,-525 ,  // top right &2
    375, 301, -575 , // bottom right &6
    400, 301, -575 ,// bottom left &5
    
    400,301,-425 , // top left &1
    375,301,-425 ,  // top right &2
    375, 301, -475 , // bottom right &6
    400, 301, -475 ,// bottom left &5
    
    400,301,-375 , // top left &1
    375,301,-375 ,  // top right &2
    375, 301, -325 , // bottom right &6
    400, 301, -325 ,// bottom left &5
    
    //
    375,301,-600 , // top left &1
    325,301,-600 ,  // top right &2
    325, 301, -575 , // bottom right &6
    375, 301, -575 ,// bottom left &5
    
    375,301,-525 , // top left &1
    325,301,-525 ,  // top right &2
    325, 301, -475 , // bottom right &6
    375, 301, -475 ,// bottom left &5
    
    375,301,-375 , // top left &1
    325,301,-375 ,  // top right &
    325, 301, -425 , // bottom right &6
    375, 301, -425 ,// bottom left &5
};

GLfloat vertices_algo_negro_3[] ={
    //
    275,301,-525 , // top left &1
    325,301,-525 ,  // top right &2
    325, 301, -575 , // bottom right &6
    275, 301, -575 ,// bottom left &5
    
    275,301,-425 , // top left &1
    325,301,-425 ,  // top right &2
    325, 301, -475 , // bottom right &6
    275, 301, -475 ,// bottom left &5
    
    275,301,-375 , // top left &1
    325,301,-375 ,  // top right &2
    325, 301, -325 , // bottom right &6
    275, 301, -325 ,// bottom left &5
    
    //
    225,301,-325 , // top left &1
    275,301,-325 ,  // top right &2
    275, 301, -300 , // bottom right &6
    225, 301, -300 ,// bottom left &5
    
    375,301,-325 , // top left &1
    325,301,-325 ,  // top right &2
    325, 301, -300 , // bottom right &6
    375, 301, -300 ,// bottom left &5
    
};


GLfloat vertices_algo_negro_1_a[] ={
    
    //
    200,99,-525 , // top left &1
    225,99,-525 ,  // top right &2
    225, 99, -575 , // bottom right &6
    200, 99, -575 ,// bottom left &5
    
    200,99,-425 , // top left &1
    225,99,-425 ,  // top right &2
    225, 99, -475 , // bottom right &6
    200, 99, -475 ,// bottom left &5
    
    200,99,-375 , // top left &1
    225,99,-375 ,  // top right &2
    225, 99, -325 , // bottom right &6
    200, 99, -325 ,// bottom left &5
    
    //
    275,99,-600 , // top left &1
    225,99,-600 ,  // top right &2
    225, 99, -575 , // bottom right &6
    275, 99, -575 ,// bottom left &5
    
    275,99,-525 , // top left &1
    225,99,-525 ,  // top right &2
    225, 99, -475 , // bottom right &6
    275, 99, -475 ,// bottom left &5
    
    275,99,-375 , // top left &1
    225,99,-375 ,  // top right &2
    225, 99, -425 , // bottom right &6
    275, 99, -425 ,// bottom left &5
};

GLfloat vertices_algo_negro_2_a[] ={
    //
    400,99,-525 , // top left &1
    375,99,-525 ,  // top right &2
    375, 99, -575 , // bottom right &6
    400, 99, -575 ,// bottom left &5
    
    400,99,-425 , // top left &1
    375,99,-425 ,  // top right &2
    375, 99, -475 , // bottom right &6
    400, 99, -475 ,// bottom left &5
    
    400,99,-375 , // top left &1
    375,99,-375 ,  // top right &2
    375, 99, -325 , // bottom right &6
    400, 99, -325 ,// bottom left &5
    
    //
    375,99,-600 , // top left &1
    325,99,-600 ,  // top right &2
    325, 99, -575 , // bottom right &6
    375, 99, -575 ,// bottom left &5
    
    375,99,-525 , // top left &1
    325,99,-525 ,  // top right &2
    325, 99, -475 , // bottom right &6
    375, 99, -475 ,// bottom left &5
    
    375,99,-375 , // top left &1
    325,99,-375 ,  // top right &
    325, 99, -425 , // bottom right &6
    375, 99, -425 ,// bottom left &5
};

GLfloat vertices_algo_negro_3_a[] ={
    //
    275,99,-525 , // top left &1
    325,99,-525 ,  // top right &2
    325, 99, -575 , // bottom right &6
    275, 99, -575 ,// bottom left &5
    
    275,99,-425 , // top left &1
    325,99,-425 ,  // top right &2
    325, 99, -475 , // bottom right &6
    275, 99, -475 ,// bottom left &5
    
    275,99,-375 , // top left &1
    325,99,-375 ,  // top right &2
    325, 99, -325 , // bottom right &6
    275, 99, -325 ,// bottom left &5
    
    //
    225,99,-325 , // top left &1
    275,99,-325 ,  // top right &2
    275, 99, -300 , // bottom right &6
    225, 99, -300 ,// bottom left &5
    
    375,99,-325 , // top left &1
    325,99,-325 ,  // top right &2
    325, 99, -300 , // bottom right &6
    375, 99, -300 ,// bottom left &5
    
};

GLfloat vertices_pata1[] ={
    // front face
    200,100,-600 , // top left &1
    250,100,-600 , // top right &2
    250,50,-600 , // bottom right &4
    200,50,-600, // bottom left &3
    
    // back face
    200, 100, -550 , // top left &5
    250, 100, -550 , // top right &6
    250, 50, -550 , // bottom right &8
    200, 50, -550 , // bottom left &7
    
    // left face
    200,100,-600 , // top left &1
    200, 100, -550 , // top right &5
    200, 50, -550  , // bottom right &7
    200, 50,-600, // bottom left &3
    
    // right face
    250, 100, -550 ,// top left &6
    250,100,-600 ,  // top right &2
    250,50,-600, // bottom right &4
    250, 50, -550 , // bottom left &8
    
    // top face
    200,100,-600  , // top left &1
    250,100,-600 ,  // top right &2
    250, 100, -550 , // bottom right &6
    200, 100, -550 ,// bottom left &5
    
    // top face
    200, 50, -550 , // top left & 7
    200,50,-600, // top right &3
    250,50,-600 ,// bottom right &4
    250, 50, -550 , // bottom left &8
};

GLfloat vertices_pata2[] ={
    // front face
    350,100,-600 , // top left &1
    400,100,-600 , // top right &2
    400,50,-600 , // bottom right &4
    350,50,-600, // bottom left &3
    
    // back face
    350, 100, -550 , // top left &5
    400, 100, -550 , // top right &6
    400, 50, -550 , // bottom right &8
    350, 50, -550 , // bottom left &7
    
    // left face
    350,100,-600 , // top left &1
    350, 100, -550 , // top right &5
    350, 50, -550  , // bottom right &7
    350, 50,-600, // bottom left &3
    
    // right face
    400, 100, -550 ,// top left &6
    400,100,-600 ,  // top right &2
    400,50,-600, // bottom right &4
    400, 50, -550 , // bottom left &8
    
    // top face
    350,100,-600  , // top left &1
    400,100,-600 ,  // top right &2
    400, 100, -550 , // bottom right &6
    350, 100, -550 ,// bottom left &5
    
    // top face
    350, 50, -550 , // top left & 7
    350,50,-600, // top right &3
    400,50,-600 ,// bottom right &4
    400, 50, -550 , // bottom left &8
};

GLfloat vertices_pata3[] ={
    // front face
    200,100,-300 , // top left &1
    250,100,-300 , // top right &2
    250,50,-300 , // bottom right &4
    200,50,-300, // bottom left &3
    
    // back face
    200, 100, -350 , // top left &5
    250, 100, -350 , // top right &6
    250, 50, -350 , // bottom right &8
    200, 50, -350 , // bottom left &7
    
    // left face
    200,100,-300 , // top left &1
    200, 100, -350 , // top right &5
    200, 50, -350  , // bottom right &7
    200, 50,-300, // bottom left &3
    
    // right face
    250, 100, -350 ,// top left &6
    250,100,-300 ,  // top right &2
    250,50,-300, // bottom right &4
    250, 50, -350 , // bottom left &8
    
    // top face
    200,100,-300  , // top left &1
    250,100,-300 ,  // top right &2
    250, 100, -350 , // bottom right &6
    200, 100, -350 ,// bottom left &5
    
    // top face
    200, 50, -350 , // top left & 7
    200,50,-300, // top right &3
    250,50,-300 ,// bottom right &4
    250, 50, -350 , // bottom left &8
};

GLfloat vertices_pata4[] ={
    // front face
    350,100,-300 , // top left &1
    400,100,-300 , // top right &2
    400,50,-300 , // bottom right &4
    350,50,-300, // bottom left &3
    
    // back face
    350, 100, -350 , // top left &5
    400, 100, -350 , // top right &6
    400, 50, -350 , // bottom right &8
    350, 50, -350 , // bottom left &7
    
    // left face
    350,100,-300 , // top left &1
    350, 100, -350 , // top right &5
    350, 50, -350  , // bottom right &7
    350, 50,-300, // bottom left &3
    
    // right face
    400, 100, -350 ,// top left &6
    400,100,-300 ,  // top right &2
    400,50,-300, // bottom right &4
    400, 50, -350 , // bottom left &8
    
    // top face
    350,100,-300  , // top left &1
    400,100,-300 ,  // top right &2
    400, 100, -350 , // bottom right &6
    350, 100, -350 ,// bottom left &5
    
    // top face
    350, 50, -350 , // top left & 7
    350,50,-300, // top right &3
    400,50,-300 ,// bottom right &4
    400, 50, -350 , // bottom left &8
};


GLfloat vertices_nariz[] ={
    // front face
    255,225,-275 , // top left &1
    350,225,-275 , // top right &2
    350,150,-275 , // bottom right &4
    255,150,-275, // bottom left &3
    
    // back face
    255, 225, -300 , // top left &5
    350, 225, -300 , // top right &6
    350, 150, -300 , // bottom right &8
    255, 150, -300 , // bottom left &7
    
    // left face
    255,225,-275 , // top left &1
    255, 225, -300 , // top right &5
    255, 150, -300 , // bottom right &7
    255,150,-275 , // bottom left &3
    
    // right face
    350, 225, -300 ,// top left &6
    350,225,-275 ,  // top right &2
    350,150,-275 , // bottom right &4
    350, 150, -300 , // bottom left &8
    
    // top face
    255,225,-275 , // top left &1
    350,225,-275 ,  // top right &2
    350, 225, -300 , // bottom right &6
    255, 225, -300 ,// bottom left &5
    
    // top face
    255, 150, -300 , // top left & 7
    255,150,-275, // top right &3
    350,150,-275 ,// bottom right &4
    350, 150, -300 , // bottom left &8
};

GLfloat vertices_oreja1[] ={
    // front face
    225,325,-350 , // top left &1
    290,325,-350 , // top right &2
    290,300,-350 , // bottom right &4
    225,300,-350, // bottom left &3
    
    // back face
    225, 325, -375 , // top left &5
    290, 325, -375 , // top right &6
    290, 300, -375 , // bottom right &8
    225, 300, -375 , // bottom left &7
    
    // left face
    225,325,-350 , // top left &1
    225, 325, -375 , // top right &5
    225, 300, -375 , // bottom right &7
    225,300,-350, // bottom left &3
    
    // right face
    290, 325, -375 ,// top left &6
    290,325,-350 ,  // top right &2
    290,300,-350 , // bottom right &4
    290, 300, -375 , // bottom left &8
    
    // top face
    225,325,-350 , // top left &1
    290,325,-350 ,  // top right &2
    290, 325, -375 , // bottom right &6
    225, 325, -375 ,// bottom left &5
    
    // top face
    225, 300, -375 , // top left & 7
    225,300,-350, // top right &3
    290,300,-350 ,// bottom right &4
    290, 300, -375 , // bottom left &8
};

GLfloat vertices_oreja2[] ={
    // front face
    375,325,-350 , // top left &1
    310,325,-350 , // top right &2
    310,300,-350 , // bottom right &4
    375,300,-350, // bottom left &3
    
    // back face
    375, 325, -375 , // top left &5
    310, 325, -375 , // top right &6
    310, 300, -375 , // bottom right &8
    375, 300, -375 , // bottom left &7
    
    // left face
    375,325,-350 , // top left &1
    375, 325, -375 , // top right &5
    375, 300, -375 , // bottom right &7
    375,300,-350, // bottom left &3
    
    // right face
    310, 325, -375 ,// top left &6
    310,325,-350 ,  // top right &2
    310,300,-350 , // bottom right &4
    310, 300, -375 , // bottom left &8
    
    // top face
    375,325,-350 , // top left &1
    310,325,-350 ,  // top right &2
    310, 325, -375 , // bottom right &6
    375, 325, -375 ,// bottom left &5
    
    // top face
    375, 300, -375 , // top left & 7
    375,300,-350, // top right &3
    310,300,-350 ,// bottom right &4
    310, 300, -375 , // bottom left &8
};

GLfloat vertices_ojoizq[] ={
    // front face
    230,225,-285 , // top left &1
    275,225,-285 , // top right &2
    275,270,-285 , // bottom right &4
    230,270,-285, // bottom left &3
    
    // back face
    230, 225, -300 , // top left &5
    275, 225, -300 , // top right &6
    275, 270, -300 , // bottom right &8
    230, 270, -300 , // bottom left &7
    
    // left face
    230,225,-285 , // top left &1
    230, 225, -300 , // top right &5
    230, 270, -300 , // bottom right &7
    230,270,-285 , // bottom left &3
    
    // right face
    275, 225, -300 ,// top left &6
    275,225,-285 ,  // top right &2
    275,270,-285 , // bottom right &4
    275, 270, -300 , // bottom left &8
    
    // top face
    230,225,-285 , // top left &1
    275,225,-285 ,  // top right &2
    275,225, -300 , // bottom right &6
    230,225, -300 ,// bottom left &5
    
    // top face
    230, 270, -300 , // top left & 7
    230,270,-285, // top right &3
    275,270,-285 ,// bottom right &4
    275, 270, -300 , // bottom left &8
};

GLfloat vertices_ojoder[] ={
    // front face
    370,225,-285 , // top left &1
    325,225,-285 , // top right &2
    325,270,-285 , // bottom right &4
    370,270,-285, // bottom left &3
    
    // back face
    370, 225, -300 , // top left &5
    325, 225, -300 , // top right &6
    325, 270, -300 , // bottom right &8
    370, 270, -300 , // bottom left &7
    
    // left face
    370,225,-285 , // top left &1
    370, 225, -300 , // top right &5
    370, 270, -300 , // bottom right &7
    370,270,-285 , // bottom left &3
    
    // right face
    325, 225, -300 ,// top left &6
    325,225,-285 ,  // top right &2
    325,270,-285 , // bottom right &4
    325, 270, -300 , // bottom left &8
    
    // top face
    370,225,-285 , // top left &1
    325,225,-285 ,  // top right &2
    325,225, -300 , // bottom right &6
    370,225, -300 ,// bottom left &5
    
    // top face
    370, 270, -300 , // top left & 7
    370,270,-285, // top right &3
    325,270,-285 ,// bottom right &4
    325, 270, -300 , // bottom left &8
};



GLfloat vertices_pupila_izq[] ={
    // front face
    245, 240, -284 , // top left &1
    260, 240, -284 , // top right &2
    260, 255, -284 , // bottom right &4
    245, 255, -284, // bottom left &3
    
    // back face
    245, 240, -300 , // top left &5
    260, 240, -300 , // top right &6
    260, 255, -300 , // bottom right &8
    245, 255, -300 , // bottom left &7
    
    // left face
    245, 240, -285 , // top left &1
    245, 240, -300 , // top right &5
    245, 255, -300 , // bottom right &7
    245, 255, -285 , // bottom left &3
    
    // right face
    260, 240, -300 ,// top left &6
    260, 240, -285 ,  // top right &2
    260, 255, -285 , // bottom right &4
    260, 255, -300 , // bottom left &8
    
    // top face
    245, 240, -285 , // top left &1
    260, 240, -285 ,  // top right &2
    260, 240, -300 , // bottom right &6
    245, 240, -300 ,// bottom left &5
    
    // top face
    245, 255, -300 , // top left & 7
    245, 255, -285, // top right &3
    260, 255, -285 ,// bottom right &4
    260, 255, -300 , // bottom left &8
};

GLfloat vertices_pupila_der[] ={
    // front face
    355,240, -284 , // top left &1
    340,240, -284 , // top right &2
    340,255, -284 , // bottom right &4
    355,255, -284, // bottom left &3
    
    // back face
    355, 240, -300 , // top left &5
    340, 240, -300 , // top right &6
    340, 255, -300 , // bottom right &8
    355, 255, -300 , // bottom left &7
    
    // left face
    355, 240, -285 , // top left &1
    355, 240, -300 , // top right &5
    355, 255, -300 , // bottom right &7
    355, 255, -285 , // bottom left &3
    
    // right face
    340, 240, -300 ,// top left &6
    340, 240, -285 ,  // top right &2
    340, 255, -285 , // bottom right &4
    340, 255, -300 , // bottom left &8
    
    // top face
    355,240,-285 , // top left &1
    340,240,-285 ,  // top right &2
    340,240, -300 , // bottom right &6
    355,240, -300 ,// bottom left &5
    
    // top face
    355, 255, -300 , // top left & 7
    355, 255,-285, // top right &3
    340, 255,-285 ,// bottom right &4
    340, 255, -300 , // bottom left &8
};



GLfloat vertices_orificio_izq[] ={
    // front face
    275, 180, -274 , // top left &1
    290, 180, -274 , // top right &2
    290, 195, -274 , // bottom right &4
    275, 195, -274, // bottom left &3
    
    // back face
    275, 180, -300 , // top left &5
    290, 180, -300 , // top right &6
    290, 195, -300 , // bottom right &8
    275, 195, -300 , // bottom left &7
    
    // left face
    275, 180, -275 , // top left &1
    275, 180, -300 , // top right &5
    275, 195, -300 , // bottom right &7
    275, 195, -275 , // bottom left &3
    
    // right face
    290, 180, -300 ,// top left &6
    290, 180, -275 ,  // top right &2
    290, 195, -275 , // bottom right &4
    290, 195, -300 , // bottom left &8
    
    // top face
    275, 180, -275 , // top left &1
    290, 180, -275 ,  // top right &2
    290, 180, -300 , // bottom right &6
    275, 180, -300 ,// bottom left &5
    
    // top face
    275, 195, -300 , // top left & 7
    275, 195, -275, // top right &3
    290, 195, -275 ,// bottom right &4
    290, 195, -300 , // bottom left &8
};

GLfloat vertices_orificio_der[] ={
    // front face
    315, 180, -274 , // top left &1
    330, 180, -274 , // top right &2
    330, 195, -274 , // bottom right &4
    315, 195, -274, // bottom left &3
    
    // back face
    315, 180, -300 , // top left &5
    330, 180, -300 , // top right &6
    330, 195, -300 , // bottom right &8
    315, 195, -300 , // bottom left &7
    
    // left face
    315, 180, -275 , // top left &1
    315, 180, -300 , // top right &5
    315, 195, -300 , // bottom right &7
    315, 195, -275 , // bottom left &3
    
    // right face
    330, 180, -300 ,// top left &6
    330, 180, -275 ,  // top right &2
    330, 195, -275 , // bottom right &4
    330, 195, -300 , // bottom left &8
    
    // top face
    315, 180, -275 , // top left &1
    330, 180, -275 ,  // top right &2
    330, 180, -300 , // bottom right &6
    315, 180, -300 ,// bottom left &5
    
    // top face
    315, 195, -300 , // top left & 7
    315, 195, -275, // top right &3
    330, 195, -275 ,// bottom right &4
    330, 195, -300 , // bottom left &8
};


GLfloat vertices_lengüita[] ={
    // front face
    320, 150, -285 , // top left &1
    285, 150, -285 , // top right &2
    285, 130, -285 , // bottom right &4
    320, 130, -285, // bottom left &3
    
    // back face
    320, 150, -300 , // top left &5
    285, 150, -300 , // top right &6
    285, 130, -300 , // bottom right &8
    320, 130, -300 , // bottom left &7
    
    // left face
    320, 150, -285 , // top left &1
    320, 150, -300 , // top right &5
    320, 150, -300 , // bottom right &7
    320, 150, -285 , // bottom left &3
    
    // right face
    285, 150, -300 ,// top left &6
    285, 150, -285 ,  // top right &2
    285, 130, -285 , // bottom right &4
    285, 130, -300 , // bottom left &8
    
    // top face
    320, 150, -285 , // top left &1
    285, 150, -285 ,  // top right &2
    285, 150, -300 , // bottom right &6
    320, 150, -300 ,// bottom left &5
    
    // top face
    320, 130, -300 , // top left & 7
    320, 130, -285, // top right &3
    285, 130, -285 ,// bottom right &4
    285, 130, -300 , // bottom left &8
};

GLfloat rotationX = 0.0f;
GLfloat rotationY = 0.0f;

GLfloat scalingX = 1.0f;
GLfloat scalingY = 1.0f;
GLfloat scalingZ = 1.0f;

GLfloat traslatingX = 1.0f;
GLfloat traslatingY = 1.0f;
GLfloat traslatingZ = 1.0f;

void keyCallback( GLFWwindow *window, int key, int scancode, int action, int mods ){
    //std::cout << key << std::endl;
    const GLfloat rotationSpeed = 10;
    // actions are GLFW_PRESS, GLFW_RELEASE or GLFW_REPEAT
    if ( action == GLFW_PRESS || action == GLFW_REPEAT ){
        switch ( key ){
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
                
            case GLFW_KEY_M : //For Expanding
                scalingX += 0.10;
                scalingY += 0.10;
                scalingZ += 0.10;
                break;
            case GLFW_KEY_N:
                scalingX -= 0.10;
                scalingY -= 0.10;
                scalingZ -= 0.10;
                break;
                
            case GLFW_KEY_A: //for X traslation
                traslatingX -= 5;
                break;
            case GLFW_KEY_D: //for
                traslatingX += 5;
                break;
                
            case GLFW_KEY_W: //for Y Traslation
                traslatingY += 5;
                break;
            case GLFW_KEY_S: //for
                traslatingY -= 5;
                break;
            case GLFW_KEY_Q: //for Z Traslation
                traslatingZ += 10;
                break;
            case GLFW_KEY_E: //for
                traslatingZ -= 10;
                break;
                
        
        }
    }
}

void initTexturas(){
    
    //Pegado sobre el polígono
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    //Filtros
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
    
    //Cargamos un fichero bmp en el array
   // imagen[0]=LoadBMP("Raul.bmp");
    
    //Activamos las texturas
    glEnable(GL_TEXTURE_2D);
}


void DrawPolygon( GLfloat vertices[] , GLfloat colorAux[] ){
    glPolygonMode( GL_FRONT_AND_BACK, fill_mode );
    
    //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    //glColor3f( colour[0], colour[1], colour[2] );
    glEnableClientState( GL_VERTEX_ARRAY );
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer( 3, GL_FLOAT, 0, vertices );
    glColorPointer(3, GL_FLOAT, 0, colorAux);
    
   
    //glDepthMask(GL_TRUE);
    glEnable(GL_DEPTH_TEST);
    
    
    glDrawArrays( GL_QUADS, 0, 24 );
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState( GL_VERTEX_ARRAY );
}

void DrawLine( GLfloat vertices[] ){
    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    //glColor3f( colour[0], colour[1], colour[2] );
    glEnableClientState( GL_VERTEX_ARRAY );
    glVertexPointer( 3, GL_FLOAT, 0, vertices );
    
    
    glDrawArrays( GL_QUADS, 0, 24 );
    
    glDisableClientState( GL_VERTEX_ARRAY );
}


int main(){
    GLFWwindow *window;
    
    // Initialize the library
    if ( !glfwInit( ) )
    {
        return -1;
    }
    
    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow( SCREEN_WIDTH, SCREEN_HEIGHT, "Puerquito MAMALON", NULL, NULL );
    
    glfwSetKeyCallback(window, keyCallback );
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
    
    //    colortext = texture( myTextureSampler, UV ).rgb;
    
    glClearColor(0.1f, 0.2f, 0.2f, 0.0f);
    glViewport( 0.0f, 0.0f, screenWidth, screenHeight ); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
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
        glClear (GL_DEPTH_BUFFER_BIT);
        
        // Render OpenGL here
        
        glPushMatrix( );
        //glEnableClientState(GL_VERTEX_ARRAY);
        
       glTranslatef( halfScreenWidth, halfScreenHeight, -500 );
        glRotatef( rotationX, 1, 0, 0 );
        glScalef(scalingX, scalingY, scalingZ);
        glTranslatef(traslatingX, traslatingY, traslatingZ);
        
        
        
        glTranslatef( -halfScreenWidth, -halfScreenHeight, 500 );
        
      
        
        DrawPolygon(vertices,color_blanco);
        
        DrawPolygon(vertices_pata1,color);
        DrawLine(vertices_pata1);
        
        DrawPolygon(vertices_pata2,color);
        DrawLine(vertices_pata2);
        
        DrawPolygon(vertices_pata3,color);
        DrawLine(vertices_pata3);
        
        DrawPolygon(vertices_pata4,color);
        DrawLine(vertices_pata4);
        
        DrawPolygon(vertices_nariz,color);
        DrawLine(vertices_nariz);
        
        DrawPolygon(vertices_oreja1,color_rosaFuerte);
        DrawLine(vertices_oreja1);
        
        DrawPolygon(vertices_oreja2,color_rosaFuerte);
        DrawLine(vertices_oreja2);
        
        DrawPolygon(vertices_ojoizq,color_amarillo_tranqui);
        DrawLine(vertices_ojoizq);
        
        DrawPolygon(vertices_ojoder,color_amarillo_tranqui);
        DrawLine(vertices_ojoder);
        
        DrawPolygon(vertices_pupila_izq,color_negro);
        DrawLine(vertices_pupila_izq);
        
        DrawPolygon(vertices_pupila_der,color_negro);
        DrawLine(vertices_pupila_der);
        
        DrawPolygon(vertices_orificio_izq,color_negro);
        DrawLine(vertices_orificio_izq);
        
        DrawPolygon(vertices_orificio_der,color_negro);
        DrawLine(vertices_orificio_der);
        
        DrawPolygon(vertices_lengüita,color_raro);
        DrawLine(vertices_lengüita);
        
        //DrawPolygon(vertices_algo_blanco_1,color_blanco);
        //DrawPolygon(vertices_algo_blanco_2,color_blanco);
        //DrawPolygon(vertices_algo_blanco_3,color_blanco);
        DrawPolygon(vertices_algo_negro_1,color_negro);
        DrawPolygon(vertices_algo_negro_2,color_negro);
        DrawPolygon(vertices_algo_negro_3,color_negro);
        DrawPolygon(vertices_algo_negro_1_a,color_negro);
        DrawPolygon(vertices_algo_negro_2_a,color_negro);
        DrawPolygon(vertices_algo_negro_3_a,color_negro);
        //DrawPolygon(vertices_blanco_atras_1 ,color_blanco);
        DrawPolygon(vertices_atras_negro_1 ,color_negro);
        DrawPolygon(vertices_atras_negro_2 ,color_negro);
        DrawPolygon(vertices_atras_negro_3 ,color_negro);
        DrawPolygon(vertices_atras_negro_1_a ,color_negro);
        DrawPolygon(vertices_atras_negro_2_a ,color_negro);
        DrawPolygon(vertices_atras_negro_3_a ,color_negro);
        //DrawPolygon(vertices_atras_blanco_3 ,color_blanco);
        //DrawPolygon(vertices_atras_blanco_2 ,color_blanco);
        
       
        
        
        glPopMatrix();
        // Swap front and back buffers
        glfwSwapBuffers( window );
        
        // Poll for and process events
        glfwPollEvents( );
    }
    
    glfwTerminate( );
    
    return 0;
}
