#include <stdio.h>
#include <iostream>
#if __APPLE__ 
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif
#include "../read/glm.h"
/*! \drawaObj(GLMmodel *myModel)  show the object with the help of given model */
void drawObj(GLMmodel *myModel){
  glEnable(GL_TEXTURE_2D);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  glBegin(GL_TRIANGLES);
  for(int i = 0; i < myModel->numpolygons; i++)
  {
	GLMpolygon poly = myModel->polygons[i];

	int numver = poly.numvertices;
	for(int j = 0; j < numver; j++)
	{
	  int vi = poly.vindices[j];
	  int ti = poly.tindices[j];
	  glTexCoord2f(myModel->texcoords[2*ti],myModel->texcoords[2*ti + 1]);
	  glVertex3f(myModel->vertices[3*vi],myModel->vertices[3*vi+1],myModel->vertices[3*vi+2]);
	}
  }
  glDisable(GL_TEXTURE_2D); 
  glEnd();
}