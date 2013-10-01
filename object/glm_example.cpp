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
GLuint _textureId;
#include "../read/load.h"
#include "../read/glm.h"
#include "obj.h"
using namespace std; 

void initRendering() {
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_COLOR_MATERIAL);

	loadTexture("../objFiles/QuadTex.bmp",_textureId);
	glBindTexture(GL_TEXTURE_2D, _textureId);
}
float _angle = 0.0; 
GLMmodel *myModel;
void drawScene() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(-4,4,-4,0,0,0,10,10,10);
  glRotatef(_angle,0,1,0);
  //Bottom
  drawObj(myModel); 
  glutSwapBuffers();
}
void update(int){
  _angle ++; 
  if(_angle>360)_angle-=360; 
  drawScene();
  glutTimerFunc(25,update,0);
}
void handleResize(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

int main(int argc, char **argv)
{
  myModel = glmReadOBJ("../objFiles/Quad.obj");
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800, 800);

  glutCreateWindow("Object Rendering");
  initRendering();
  glutDisplayFunc(drawScene);
  glutReshapeFunc(handleResize);
  glutTimerFunc(25,update,0);
  glutMainLoop();
  return 0;             /* ANSI C requires main to return int. */
}
