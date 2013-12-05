#ifndef LOAD_H_INCLUDED
#define LOAD_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <string>
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
void loadBMP(char *fileName,int &width, int &length, unsigned char* &data); /**<loadBMP is used read image file*/
void loadTexture(char* fileName,GLuint &textureId);/**<loadtexture is used to load texture from an image file*/ 
#endif
