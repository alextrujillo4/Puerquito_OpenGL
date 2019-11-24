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

#include <iostream>
#include <cstdlib>




#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480


GLenum fill_mode = GL_FILL;

/*
GLuint loadBMP_custom (const char * imagepath){
    
    printf("Reading image", imagepath);
    
    
    // Lectura de información del encabezado del archivo
    unsigned char header[54]; // Each BMP file begins by a 54-bytes header
    unsigned int dataPos;     // Position in the file where the actual data begins
    unsigned int width, height;
    unsigned int imageSize;   // = width*height*3
    // Información RGB
    unsigned char * data;
    
    // Apertura del archivo
    FILE * file = fopen(imagepath,"rb");
    if (!file){
        printf("Image could not be opened\n", imagepath);
        getchar();
        return 0;
        
    }
    
    if ( fread(header, 1, 54, file)!=54 ){ // If not 54 bytes read : problem
        printf("Not a correct BMP file\n");
        fclose(file);
        return 0;
    }
    
    if ( header[0]!='B' || header[1]!='M' ){
        printf("Not a correct BMP file\n");
        fclose(file);
        return 0;
    }
    
    if ( (int)&(header[0x1E])!=0 ) {
        printf("not a correct bmpfile");
        fclose(file);
        return 0;
    }
    if ( (int)&(header[0x1C])!=24 ) {
        printf("not a correct bmpfile");
        fclose(file);
        return 0;
    }
    
    // Lectura de los enteros desde el arreglo de bytes
    dataPos    = (int)&(header[0x0A]);
    imageSize  = (int)&(header[0x22]);
    width      = (int)&(header[0x12]);
    height     = (int)&(header[0x16]);
    
    // Algunos archivos BMP tienen un mal formato, así que adivinamos la información faltante
    if (imageSize==0)    imageSize=width*height*3; // 3 : un byte por cada componente Rojo (Red), Verde (Green) y Azul(Blue)
    if (dataPos==0)      dataPos=54; // El encabezado del BMP está hecho de ésta manera
    
    // Se crea un buffer
    data = new unsigned char [imageSize];
    
    // Leemos la información del archivo y la ponemos en el buffer
    fread(data,1,imageSize,file);
    
    //Todo está en memoria ahora, así que podemos cerrar el archivo
    fclose(file);
    
    // Se Crea una textura OpenGL
    GLuint textureID;
    glGenTextures(1, &textureID);
    
    // Se "Ata" la nueva textura : Todas las futuras funciones de texturas van a modificar esta textura
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    // Se le pasa la imagen a OpenGL
    glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
    
    delete [] data;
    
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    
    //glTextParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
     //glTextParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
     //glTextParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glTextParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    return 0
}*/





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



int main( void ){
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
    
    GLuint VBO, VAO, EBO;
    
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
        DrawPolygon(vertices,color);
        DrawLine(vertices);
        
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
        
        DrawPolygon(vertices_ojoizq,color_blanco);
        DrawLine(vertices_ojoizq);
        
        DrawPolygon(vertices_ojoder,color_blanco);
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
        
        glPopMatrix();
        // Swap front and back buffers
        glfwSwapBuffers( window );
        
        // Poll for and process events
        glfwPollEvents( );
    }
    
    glfwTerminate( );
    
    return 0;
}
