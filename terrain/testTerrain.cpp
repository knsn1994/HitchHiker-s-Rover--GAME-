#if __APPLE__ 
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif
#include<iostream>
#include<cstdio>
#include<math.h>
#include "renderTerrain.h"
#include "../read/load.h"
#define PI 3.14159265
using namespace std; 
//next function is to exit 
void handleKeypress(unsigned char key, int x,int y){
	cout << (int)key <<endl;
	switch (key) {
		case 65:
		case 27:
		case 97:
			exit(0); 
	}
}
	GLuint _textureId; 

//just to initialize
void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
	loadTexture("../bmpFiles/2texture.bmp",_textureId);
}

//resize the window 
void handleResize(int w,int h){
	glViewport(0,0,w,h); //cooridinates of the new window 
	glMatrixMode(GL_PROJECTION); //***********************NOT UNDERSTOOD **********// 
	glLoadIdentity(); //gets to the original viewing direction 
	gluPerspective(45.0,(double)w/(double)h,1.0,200.0); //***********************NOT UNDERSTOOD **********// 
}
float _angle = 0.,angle = 0; 
Terrain* _terrain; 
void drawCoin(){
	glPushMatrix();
	glColor3f(255,0,0);
	glRotatef(angle,0,1,0);
	gluCylinder(gluNewQuadric(),.1,.1,3,32,32);
	glColor3f(255,255,255);
	glPopMatrix(); 
	
}
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(30-80*cos(_angle*PI/180),30,30-80*sin(_angle*PI/180),30,10,30,0,1,0	);

	GLfloat ambientColor[] = {0.4f, 0.4f, 0.4f, 1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	GLfloat lightColor0[] = {0.6f, 0.6f, 0.6f, 1.0f};
	GLfloat lightPos0[] = {-0.5f, 0.8f, 0.1f, 0.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	
	//float scale = 5.0f / max(_terrain->width - 1, _terrain->length - 1);
	//glScalef(scale, scale, scale);
	//glTranslatef(-(float)(_terrain->width - 1) / 2,0.0f,-(float)(_terrain->length - 1) / 2);

	//glColor3f(0.3f, 0.9f, 0.0f);
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	for(int z = 0; z < _terrain->width - 1; z++) {
		//Makes OpenGL draw a triangle at every three consecutive vertices
		glBegin(GL_TRIANGLE_STRIP);
		for(int x = 0; x < _terrain->length; x++) {
			vect normal = _terrain->normals[x][z];
			glNormal3f(normal.x, normal.y, normal.z);
			glTexCoord2f(x/256.0,z/256.0);
			glVertex3f(x, _terrain->hs[x][z], z);
			normal = _terrain->normals[x][z + 1];
			glNormal3f(normal.x, normal.y, normal.z);
			glTexCoord2f(x/256.0,(z+1)/256.0);
			glVertex3f(x, _terrain->hs[x][z + 1], z + 1);
		}
		glEnd();
	}
	drawCoin();
	glutSwapBuffers();
}

void update(int value) {
	_angle += 1.0f;
	if (_angle > 3256) {
		_angle -= 3256;
	}

	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);

	glutCreateWindow("Test Terrain");
	initRendering();
	_terrain = new Terrain("../bmpFiles/img.bmp", 20);
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0);

	glutMainLoop();
	return 0;
}
