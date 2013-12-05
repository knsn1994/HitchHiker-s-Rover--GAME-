#ifndef RENDER_TERRAIN_H_INCLUDED
#define RENDER_TERRAIN_H_INCLUDED
#include "../physics/vect.h"
class Terrain{
public:
	float **hs;
	vect **normals;/**Normal vector in terrain*/
	bool computedNormals;/** computedNormals tells us whether normal had been computed*/   
	void computeNormals();/** computedNormals()  computes normal in terrain*/
	int width, length;
	Terrain();
	Terrain(char *fileName,float maxHeight);
	void setHeight(int x, int z, float y);/** it can be used to chan height at a given x,z*/
	~Terrain();
};
#endif
