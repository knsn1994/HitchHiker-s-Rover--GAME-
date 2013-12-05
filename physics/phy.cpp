#include "vect.h"
#include "phy.h"
#include <iostream>
using namespace std; 
#define DOWN vect(0,-1,0)
#define DT 0.025
#define GRAV 30
#define ACC 100
#define EPS 0.1
#define ALPHA 0.07
ball::ball(int& _width ,int& _length,float** &_hs,vect** &_normals,vect _direct,vect _center,float _speed){
	width = _width; 
	length = _length; 
	hs = _hs; 
	normal = _normals; 
	center = _center; 
	direct = _direct; 
	speed = _speed; 
	vel = direct * speed; 
}
void ball::restrict(){
	
	if(center.x < EPS)vel.x = -vel.x , center.x = 2*EPS; 
	if(center.z < EPS)vel.z = - vel.z, center.z = 2*EPS; 
	if(center.x  + EPS > length)vel.x = -vel.x , center.x = length - 2*EPS; 
	if(center.z  + EPS > width)vel.z = - vel.z , center.z = width - 2*EPS; 
}
vect ball::getDirect(){
	return direct; 
}
float ball::x(){
	return center.x; 
}
float ball::y(){
	return center.y; 
}
float ball::z(){
	return center.z; 
}
vect ball::getNormal(){
	return normal[(int)center.x][(int)center.z].normalize(); 
}
float ball::getHeight(){
	return hs[(int)center.x][(int)center.z]; 
}
float ball::getHeight(int x,int z){
	return hs[x][z];
}
void ball::knockit(float mul){
	speed *= mul; 
}
void ball::swap(){
	center = vect(center.z,0,center.x);
}
void ball::simulate(bool isPressed[4]){
	vel = direct.normalize() * speed; 
	vect norm1 = getNormal();
	
	vect prevCenter(center.x,center.y,center.z); 
	vect newCenter = center + vel * DT; 
	
	 
	center = newCenter; 
	
	restrict(); 
	
	if(center.y < getHeight())center.y = getHeight() ; 
	
	if(center.y > getHeight() + EPS){  //IN AIR
		vel = (vel + DOWN * GRAV * DT);
		speed = vel.magnitude() * 0.999; 
		if(vel.magnitude() != 0 )direct = vel.normalize(); 
	}
	else{ //ON GROUND
		direct = direct - direct.dot(norm1)*norm1; 
		direct = direct.normalize(); 
		vel = vel + DOWN.project(direct) * GRAV * DT; 
		vel = vel.project(direct);
		if(isPressed[0]){
			vel = vel + direct*ACC*DT; 
		}
		if(isPressed[1]){
			vel = vel - vel.normalize()*ACC*DT; 
		}
		if(isPressed[3]){
			float x = direct.x;
			float z = direct.z; 
			direct.x = x * cos(ALPHA)-z*sin(ALPHA);
			direct.z = z * cos(ALPHA)+x*sin(ALPHA);
		}
		if(isPressed[2]){
			float x = direct.x;
			float z = direct.z; 
			direct.x = x * cos(ALPHA)+z*sin(ALPHA);
			direct.z = z * cos(ALPHA)-x*sin(ALPHA);
		}
		direct = direct - direct.dot(norm1)*norm1; 
		direct = direct.normalize();
		speed = vel.magnitude() * 0.96; 
		vel = direct * speed; 
	}
}