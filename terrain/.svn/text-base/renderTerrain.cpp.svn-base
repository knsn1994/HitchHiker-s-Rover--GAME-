#include<cstdio>
#include "renderTerrain.h"
#include "../read/load.h"

Terrain::Terrain(){}

Terrain::Terrain(char *fileName,float maxHeight){
	unsigned char* data;
	loadBMP(fileName,width,length,data); 
	hs = new float*[length];
	normals = new vect*[length];
	int i,j;
	for(i=0;i<length;i++){
		hs[i] = new float[width];
		normals[i] = new vect[width]; 
	}
	for(i=0;i<length;i++){
		for(j=0;j<width;j++){
			setHeight(i,j,data[3*(width*j+i)] * maxHeight /255); 
		}
	}
	computeNormals();
	delete[] data; 
}

Terrain::~Terrain(){
	for(int i=0;i<length;i++)delete[] hs[i];
	delete[] hs;
	for(int i=0;i<length;i++)delete[] normals[i];
	delete[] normals;
}
void Terrain::setHeight(int x,int z,float y){
	hs[x][z] = y; 
}

void Terrain::computeNormals() {
	//Compute the rough version of the normals
	vect** normals2 = new vect*[length];
	for(int i = 0; i < length; i++) {
		normals2[i] = new vect[width];
	}

	for(int z = 0; z < length; z++) {
		for(int x = 0; x < width; x++) {
			vect sum(0.0f, 0.0f, 0.0f);

			vect out;
			if (z > 0) {
				out = vect(0.0f, hs[z - 1][x] - hs[z][x], -1.0f);
			}
			vect in;
			if (z < length - 1) {
				in = vect(0.0f, hs[z + 1][x] - hs[z][x], 1.0f);
			}
			vect left;
			if (x > 0) {
				left = vect(-1.0f, hs[z][x - 1] - hs[z][x], 0.0f);
			}
			vect right;
			if (x < width - 1) {
				right = vect(1.0f, hs[z][x + 1] - hs[z][x], 0.0f);
			}

			if (x > 0 && z > 0) {
				sum = sum + out.cross(left).normalize();
			}
			if (x > 0 && z < length - 1) {
				sum = sum + left.cross(in).normalize();
			}
			if (x < width - 1 && z < length - 1) {
				sum = sum + in.cross(right).normalize();
			}
			if (x < width - 1 && z > 0) {
				sum = sum + right.cross(out).normalize();
			}

			normals2[z][x] = sum;
		}
	}

	//Smooth out the normals
	const float FALLOUT_RATIO = 0.5f;
	for(int z = 0; z < length; z++) {
		for(int x = 0; x < width; x++) {
			vect sum = normals2[z][x];

			if (x > 0) {
				sum = sum + normals2[z][x - 1] * FALLOUT_RATIO;
			}
			if (x < width - 1) {
				sum = sum + normals2[z][x + 1] * FALLOUT_RATIO;
			}
			if (z > 0) {
				sum = sum + normals2[z - 1][x] * FALLOUT_RATIO;
			}
			if (z < length - 1) {
				sum = sum + normals2[z + 1][x] * FALLOUT_RATIO;
			}

			if (sum.magnitude() == 0) {
				sum = vect(0.0f, 1.0f, 0.0f);
			}
			normals[z][x] = sum;
		}
	}

	for(int i = 0; i < length; i++) {
		delete[] normals2[i];
	}
	delete[] normals2;
}


