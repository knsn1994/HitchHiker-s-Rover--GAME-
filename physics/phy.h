#ifndef PHY_H_INCLUDED
#define PHY_H_INCLUDED
#include "vect.h"
#include <cmath>
/** class ball contain position,velocity vector,normal and speed  of object*/
class ball{
private:
	int width,length;
	float **hs; 
	vect **normal; 
	vect center, direct, vel;
	float speed; 
	
public:	
	ball(){}
	ball(int& _width ,int& _length,float** &_hs,vect** &_normals,vect _direct,vect _center,float speed);
/**returns speed of ball object*/	
	float getSpeed(){return speed;}
/** this method prevent ball object to cross over terrain by moving it back from opposite direction  */	
	void restrict();
	float x();
	float y(); 
	float z(); 
/**gives direction where object if going to move*/	
	vect getDirect();
/** gives height of ball object*/	
	float getHeight();
/**gives normal of ball object */	
	vect getNormal();
	void simulate(bool []);
/** sets ball object comes in freefall*/	
	void freeFall(); 
	void moveIt(bool []); 
/**return height at given point */	
	float getHeight(int,int);
/** changes speed instantaneously	*/
	void knockit(float);
/**changes position of ball object instantaneously*/	
	void swap();
};
#endif
