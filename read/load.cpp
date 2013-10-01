#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
void loadBMP(char *fileName,int &width, int &length, unsigned char* &data){
	FILE* f = fopen(fileName, "rb");
	unsigned char *info = new unsigned char[54]; //this is the file information part
	fread(info,sizeof(unsigned char),54,f); // read the first 54 bytes in the info arr
	width = *(int*)(info + 18);
	length = *(int*)(info + 22);
	int size = 3*width*length; 
	data = new unsigned char[size]; 
	//Now we need to read the rest of the file
	int r,b,g;
	fread(data,sizeof(unsigned char),size,f); 
	for(int i=0;i < size;i+=3){r = data[i]; g = data[i+1]; b = data[i+2]; data[i] = b; data[i+1] = g; data[i+2] = r; }//swapping rgb to bgr
	fclose(f); 
	delete[] info; 
}
void loadTexture(char* fileName,GLuint &textureId) {
	int width,length;
	unsigned char *data; 
	loadBMP(fileName,width,length,data); 
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width, length, 0,GL_RGB, GL_UNSIGNED_BYTE,data);
	delete[] data;
}
