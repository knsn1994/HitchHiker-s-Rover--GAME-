#if __APPLE__ 
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif
#include <iostream>
#include <cstdio>
#include <math.h>
#include <ctime>
#include <string>
#include <sstream>
#include "../terrain/renderTerrain.h"
#include "../read/load.h"
#include "../object/obj.h"
#include "../physics/vect.h"
#include "../physics/phy.h"
#include "../read/glm.h"
#include "../terrain/culling.h"
#include "../read/info.h"
#include "../read/highscore.h"
#include "../read/track.h"
#define MAXSPEED 70.0
#define PI 3.14159265
#define DT 0.025
using namespace std; 
//next function is to exit 
#define tp(x,y,z) vect(y,x,z)
float theta = 0.;  
Terrain* _terrain;
ball B; 
GLMmodel *myModel;
void update(int);
void skyBox(int);
//void moveIt(vect& center, vect& vel, vect getDirect() = vect(0,0,0), vect normal = vect(0,1,0), float acc = 0.0, float r = 0, float k = 0);
bool isPressed[] = {false,false,false,false}; 
void tree(float x1, float y1, float x2, float y2, float angle,int n, int branchCount);
char TERRAIN[20],TEXTURE[20],HSCORE[20],TRACKINFO[20];
int DIFFICULTY;
GLuint _textureId,_textureId2,_textureId1,_textureSelect,_sky; 
int TIRE = 0;
int TIMELEFT = 1000*300; //two and a half minutes
int CHECKLEFT = 4;
obj COINS; 
bool HIGHSCORE = false;
int camFlag = 0;
bool GAMEUP = false; 
/////////////////////////////////////////////////////////
void HUD(const int x, const int y,const int z,string text);
void drawHUD(float);
void drawCoin(int,int,int,int); 
void handleKeypress(unsigned char key, int x, int y) {
		switch (key) {
		case 27: //Escape key
				exit(0);
				break;
		case 'c':
		case 'C':
				camFlag ++;
				camFlag %= 3;
		}
}
void keySpecialDown(int key, int x, int y) {
		switch (key) {
		case GLUT_KEY_RIGHT:
				isPressed[3] = true;
				break;
		case GLUT_KEY_LEFT:
				isPressed[2] = true;
				break;
		case GLUT_KEY_UP:
				isPressed[0] = true;
				break;
		case GLUT_KEY_DOWN:
				isPressed[1] = true;
				break;
		}
}

void keySpecialUp(int key, int x, int y) {
		switch (key) {
		case GLUT_KEY_RIGHT:
				isPressed[3] = false;
				break;
		case GLUT_KEY_LEFT:
				isPressed[2] = false;
				break;
		case GLUT_KEY_UP:
				isPressed[0] = false;
				break;
		case GLUT_KEY_DOWN:
				isPressed[1] = false;
				break;
		}
}
/////////////////////////////////////////////////////////
//just to initialize
void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
	loadTexture(TEXTURE,_textureId);
	loadTexture("../objFiles/QuadTex.bmp",_textureId2);
	loadTexture("../objFiles/QuadTex2.bmp",_textureId1);
	loadTexture("../objFiles/skybox.bmp",_sky);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

//resize the window 
void handleResize(int w,int h){
	glViewport(0,0,w,h); //cooridinates of the new window 
	glMatrixMode(GL_PROJECTION); //***********************NOT UNDERSTOOD **********// 
	glLoadIdentity(); //gets to the original viewing getDirect()ion 
	gluPerspective(45.0,(double)w/(double)h,1.0,10000.0); //***********************NOT UNDERSTOOD **********// 
}
int angle = 1; 
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); //gets to the original viewing getDirect()ion 
	gluPerspective(45.0,1.6,2.0,10000.0); //camera frustum
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	skyBox(_sky);
	vect orient = B.getDirect();
	vect cam(orient.x,0,orient.z);
	cam.normalize(); 
	if(camFlag == 0)gluLookAt(B.x()-cam.x*20,B.y() + 5,B.z()- cam.z*20,B.x(),B.y(),B.z(),0,1,0);
	else if (camFlag == 1) gluLookAt(B.x()-orient.x*5,B.y()+5-orient.y*5,B.z()-orient.z*5,B.x()+orient.x*20,B.y()+5 +orient.y*20,B.z()+orient.z*20,0,1,0);
	else gluLookAt(B.x()-orient.x*5,B.y()+5-orient.y*5,B.z()-orient.z*5,B.x()+orient.x*20,B.y() +orient.y*20,B.z()+orient.z*20,0,1,0);
	GLfloat ambientColor[] = {0.4f, 0.4f, 0.4f, 1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	GLfloat lightColor0[] = {0.6f, 0.6f, 0.6f, 1.0f};
	GLfloat lightPos0[] = {-0.5f, 0.8f, 0.1f, 0.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	glBindTexture(GL_TEXTURE_2D, _textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glEnable(GL_TEXTURE_2D);
	//glColor3f(1,1,1);
	//DRAW TERRAIN
	//glColor3f(1,0,0);
	ExtractFrustum(); 
	vect normal; 		
	int counter = 0; 
	for(int z = 0; z < _terrain->width - 1; z++) {
		glBegin(GL_TRIANGLE_STRIP);
		for(int x = 0; x < _terrain->length; x++) {
			if(PointInFrustum(x, _terrain->hs[x][z], z)){
				counter ++; 
				normal = _terrain->normals[x][z];
				glNormal3f(normal.x, normal.y, normal.z);
				glTexCoord2f(x/512.0,z/512.0);
				glVertex3f(x, _terrain->hs[x][z], z);
			}
			if(PointInFrustum(x, _terrain->hs[x][z + 1], z + 1)){
				counter ++; 
				normal = _terrain->normals[x][z + 1];
				glNormal3f(normal.x, normal.y, normal.z);
				glTexCoord2f(x/512.0,(z+1)/512.0);
				glVertex3f(x, _terrain->hs[x][z + 1], z + 1);
			}
		}
		glEnd();
	}
	glDisable(GL_TEXTURE_2D);
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureSelect);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glPushMatrix();
	//	cout << B.x() << " " << B.y() << " " << B.z() << endl; 
	//	cout <<B.x()-cam.x*20 << " " << B.y() + 5 << " " << B.z()- cam.z*20 << endl; 
	//	cout << endl;
		glTranslatef(B.x(),B.y(),B.z());
		float phi = acos(orient.y/orient.magnitude()) * 180 / PI ; 
		float theta = atan(orient.x/orient.z) * 180 / PI; 
		if(orient.z < 0) theta += 180; 
		//glRotatef(phi-90,0,0,1); 
	
		glRotatef(theta,0,1,0); 
		glRotatef(phi - 90,1,0,0);
		drawObj(myModel); 
		//glutSolidSphere(2,10,10);
		
	glPopMatrix();
	glDisable(GL_TEXTURE_2D); 
	for(int i=0;i<COINS.n; i++){
			if(COINS.type[i] > -1)
				drawCoin(COINS.x[i],B.getHeight(COINS.x[i],COINS.z[i])+2,COINS.z[i],COINS.type[i]);	
	}
	drawHUD(B.getSpeed());
	glutSwapBuffers();
}
void checkCollision();
void update(int value) {
	if(DIFFICULTY == 2)TIMELEFT = 999; 
	if(CHECKLEFT == 0 && DIFFICULTY != 2){
		cout << "score is " << TIMELEFT/1000<< endl;
		int prev = getHighScore(HSCORE); 
		cout << prev << endl ;
		if(prev < TIMELEFT/1000)putHighScore(HSCORE,TIMELEFT/1000);
		HIGHSCORE = prev < TIMELEFT/1000;
		GAMEUP = true;
		drawScene();
		return;
	} 
	if((int)B.getSpeed() > 0)TIRE ^= 1; 
	_textureSelect = TIRE ? _textureId1 : _textureId2; 
	B.simulate(isPressed);
	TIMELEFT -= 25; 
	checkCollision();
	drawScene();
	angle = (angle+10)%360;
	if(TIMELEFT <= 0){
		return; 
	}
	glutTimerFunc(25, update, 1000*DT);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	myModel = glmReadOBJ("../objFiles/Quad.obj");
	getTrackInfo(TERRAIN,TEXTURE,TRACKINFO,HSCORE,DIFFICULTY);
	cout << TERRAIN << endl;
	cout << TEXTURE << endl;
	cout << TRACKINFO << endl;
	cout << HSCORE << endl;
	glutCreateWindow("GAME");
	initRendering();
	_terrain = new Terrain(TERRAIN, 20);
	COINS = 	returnInfo((char*)string(TRACKINFO).c_str());
	B = ball(_terrain->width,_terrain->length,_terrain->hs,_terrain->normals,vect(1,0,0),vect(COINS.sx,0,COINS.sz),0);
	glutDisplayFunc(drawScene);
	glutReshapeFunc(handleResize);
	glutKeyboardFunc(handleKeypress);
	glutSpecialFunc(keySpecialDown);
	glutSpecialUpFunc(keySpecialUp);
	glutFullScreen();
	update(0);
	glutMainLoop();
	return 0;
}
void HUD(const int x, const int y,const int z,int speed)
{
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glColor3f(255,0,0);
	glRasterPos3f(5,8,10);
	stringstream ss0; 
	ss0 << "CHECKPOINTS LEFT: " << CHECKLEFT ;
	string text = ss0.str(); 
	for(int i=0;i<text.length();i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text[i]);
	stringstream ss1,ss;
	ss1<<"SPEED: "<< speed;
	string abhi=ss1.str();
	glRasterPos3f(-9,8,10);
	for(int i=0;i<abhi.length();i++)
 		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, abhi[i]);
	if(HIGHSCORE){
			 ss<<"TIME LEFT: " << TIMELEFT/1000;
			string Time=ss.str();
			glRasterPos3f(-1,8,10);
			for(int j=0;j<Time.length();j++)
	 			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, Time[j]);
			string str = string("NEW HIGHSCORE");
			glRasterPos3f(-1,4,5);
			for(int j=0;j<str.length();j++)
	 			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[j]);
	}
	else if(GAMEUP){
			 ss<<"TIME LEFT: " << TIMELEFT/1000;
			string Time=ss.str();
			glRasterPos3f(-1,8,10);
			for(int j=0;j<Time.length();j++)
	 			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, Time[j]);
			string str = string("LEVEL CLEARED");
			glRasterPos3f(-1,4,5);
			for(int j=0;j<str.length();j++)
	 			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[j]);
	}
	else if (TIMELEFT){
		 
		 ss<<"TIME LEFT: " << TIMELEFT/1000;
		string Time=ss.str();
		glRasterPos3f(0,8,10);
		for(int j=0;j<Time.length();j++)
 			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, Time[j]);

	}
	else{
		 ss<<"TIME LEFT: " << TIMELEFT/1000;
		string Time=ss.str();
		glRasterPos3f(-1,8,10);
		for(int j=0;j<Time.length();j++)
 			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, Time[j]);
		string str = string("GAME OVER");
		glRasterPos3f(-1,4,5);
		for(int j=0;j<str.length();j++)
 			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[j]);
	}

	float rad=1,len=0.1,r=PI/180;
	glTranslatef(0,-8,0);

	glBegin(GL_LINE_STRIP);
	for(int i=0;i<=180;i+=5){
		glVertex3f(rad*cos(r*(i)),-1+rad*sin(r*(i)),0);
		if(i%10==0)
			len=0.2;
		if(i%40==0)
			len=0.3;
		if(i%10!=0 & i%40!=0)
			len=0.1;
		glVertex3f((rad-len)*cos(r*(i)),-1+(rad-len)*sin(r*(i)),0);
		glVertex3f(rad*cos(r*(i)),-1+rad*sin(r*(i)),0);
	}
	glVertex3f(rad,-1,0);
	glEnd();
	rad=0.9;
//	glColor3f(1,0,0);
	if(speed>MAXSPEED)speed = MAXSPEED;
	glBegin(GL_LINE_STRIP);
		glVertex3f(-0.05,-1,0);
		glVertex3f(rad*cos(r*(180-(180/MAXSPEED)*speed)),-1+rad*sin(r*(180-(180/MAXSPEED)*speed)),0);
		glVertex3f(0.05,-1,0);
	glEnd();
	glColor3f(1,1,1);
}
void drawHUD(float speed){
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-10,10,-10,10,-10,10);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   HUD(0,0,10,speed);
}
void drawCoin(int x,int y,int z,int type){
	if(type < 0)return ; 
	glPushMatrix();
	glTranslatef(x,y,z+(type==3)); 
	glRotatef(angle,0,1,0);
	#define QUAD gluNewQuadric()
	#define HEIGHT 0.2
	if(type == 3){
		tree(0,0,0,2,36,2,10);
	}
	else{
		if(type == 0 && DIFFICULTY != 0)glColor3f(255/256.0,140/256.0,0/256.0);
		else if(type == 1 ||(type == 0 && DIFFICULTY == 0)) glColor3f(255/256.,215/256.,0/256.);
		else if(type == 2)glColor3f(0,0,1); 
		int R = 1;
		gluCylinder(QUAD,R,R,HEIGHT,30,10);
		glRotatef(180, 1,0,0);
		gluDisk(QUAD, 0.0f, R, 30, 1);
		glRotatef(180, 1,0,0);
		glTranslatef(0.0f, 0.0f, HEIGHT); 
		gluDisk(QUAD, 0.0f, R, 30, 1); 
		glTranslatef(0.0f, 0.0f, -HEIGHT);
		glColor3f(1,1,1);
	}
	glPopMatrix();
}
#define treeRatio 2.0
void tree(float x1, float y1, float x2, float y2, float angle,int n, int branchCount) {
	glBegin(GL_LINE_STRIP);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glEnd();
	if(n<1)return ;
	int nn = n-1;      
   float x3=(x2-x1)*treeRatio+x1-x2, y3=(y2-y1)*treeRatio+y1-y2; 
	if(branchCount==2){
			 tree(x2, y2, x3 * cos(angle) + y3 * sin(angle) + x2, -x3 * sin(angle) + y3 * cos(angle) + y2, angle, nn, branchCount);
			 tree(x2, y2, x3 * cos(-angle) + y3 * sin(-angle) + x2, -x3 * sin(-angle) + y3 * cos(-angle) + y2, angle, nn, branchCount);
	}
 else { 
	   float nowAngle = -angle; float angleTone = angle/(branchCount-1)*2; 
	   for(int i=0;i<branchCount;i++,nowAngle+=angleTone){ 
		   tree(x2, y2, x3 * cos(nowAngle) + y3 * sin(nowAngle) + x2, -x3 * sin(nowAngle) + y3 * cos(nowAngle) + y2, angle,nn,branchCount); 
		}

}}
bool checkIn(float a,float b,float c,float x,float y,float z,int SPAN){
	return (a-x)*(a-x) + (b-y)*(b-y) + (c-z)*(c-z) <= SPAN; 
}
void checkCollision(){
	for(int i=0;i<COINS.n;i++){
		if(COINS.type[i] == -1)continue; 
		else if(COINS.type[i] < 2 && checkIn(COINS.x[i],B.getHeight(COINS.x[i],COINS.z[i]),COINS.z[i],B.x(),B.y(),B.z(),4)){
			if(COINS.type[i] == 0 && DIFFICULTY != 0){B.knockit(0.1);if(DIFFICULTY!=2)TIMELEFT -= 10*1000;}
			else {B.knockit(2); if(DIFFICULTY!=2)TIMELEFT += 5*1000;}
			COINS.type[i] = -1; 
		}
		else if(COINS.type[i] == 2 && checkIn(COINS.x[i],B.getHeight(COINS.x[i],COINS.z[i]),COINS.z[i],B.x(),B.y(),B.z(),9)){
			TIMELEFT += 1000*50; 
			COINS.type[i] = -1; 
			CHECKLEFT --; 
		}
		else if(COINS.type[i] == 3 && checkIn(COINS.x[i],B.getHeight(COINS.x[i],COINS.z[i]),COINS.z[i],B.x(),B.y(),B.z(),9)){
			B.swap();
		}
	}
}
void skyBox(int _pass){
	glPushMatrix();
	glScalef(1000,1000,1000);
	glBindTexture(GL_TEXTURE_2D, _pass);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glEnable(GL_TEXTURE_2D);
	 // Render the front quad
	//glBindTexture(GL_TEXTURE_2D, _skybox[0]);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0); glVertex3f(  .5, -.5, -.5 );
		glTexCoord2f(1, 0); glVertex3f( -.5, -.5, -.5 );
		glTexCoord2f(1, 1); glVertex3f( -.5,  .5, -.5 );
		glTexCoord2f(0, 1); glVertex3f(  .5,  .5, -.5 );
	glEnd();

	// Render the left quad
	//glBindTexture(GL_TEXTURE_2D, _skybox[1]);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0); glVertex3f(  .5, -.5,  .5 );
		glTexCoord2f(1, 0); glVertex3f(  .5, -.5, -.5 );
		glTexCoord2f(1, 1); glVertex3f(  .5,  .5, -.5 );
		glTexCoord2f(0, 1); glVertex3f(  .5,  .5,  .5 );
	glEnd();

	// Render the back quad
	//glBindTexture(GL_TEXTURE_2D, _skybox[2]);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0); glVertex3f( -.5, -.5,  .5 );
		glTexCoord2f(1, 0); glVertex3f(  .5, -.5,  .5 );
		glTexCoord2f(1, 1); glVertex3f(  .5,  .5,  .5 );
		glTexCoord2f(0, 1); glVertex3f( -.5,  .5,  .5 );

	glEnd();

	// Render the right quad
	//glBindTexture(GL_TEXTURE_2D, _skybox[3]);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0); glVertex3f( -.5, -.5, -.5 );
		glTexCoord2f(1, 0); glVertex3f( -.5, -.5,  .5 );
		glTexCoord2f(1, 1); glVertex3f( -.5,  .5,  .5 );
		glTexCoord2f(0, 1); glVertex3f( -.5,  .5, -.5 );
	glEnd();

	// Render the top quad
	//glBindTexture(GL_TEXTURE_2D, _skybox[4]);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 1); glVertex3f( -.5,  .5, -.5 );
		glTexCoord2f(0, 0); glVertex3f( -.5,  .5,  .5 );
		glTexCoord2f(1, 0); glVertex3f(  .5,  .5,  .5 );
		glTexCoord2f(1, 1); glVertex3f(  .5,  .5, -.5 );
	glEnd();

	// Render the bottom quad
	//glBindTexture(GL_TEXTURE_2D, _skybox[5]);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0); glVertex3f( -.5, -.5, -.5 );
		glTexCoord2f(0, 1); glVertex3f( -.5, -.5,  .5 );
		glTexCoord2f(1, 1); glVertex3f(  .5, -.5,  .5 );
		glTexCoord2f(1, 0); glVertex3f(  .5, -.5, -.5 );
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}