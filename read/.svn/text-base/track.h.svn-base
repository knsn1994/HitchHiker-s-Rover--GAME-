#ifndef INCLUDED_TRACK_H
#define INCLUDED_TRACK_H
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
using namespace std;
/**< getTrackInfo takes the image files of texture and terrain as input 
   < and gives us the id of track to display*/ 
int getTrackInfo(char* terrain,char* texture,char* info,char* hs,int &d){
	ifstream f;
	f.open("../link/trackID.txt"); 
	int x;
	f >> x; 
	f >> d;
	strcpy(terrain,"../tracks/xh.bmp");
	strcpy(texture,"../tracks/xt.bmp");
	strcpy(info,"../tracks/x.txt");
	strcpy(hs,"../link/x.txt");
	texture[10]= x + '0';
	info[10]=x+'0';
	hs[8]=x+'0';
	terrain[10] = x+'0'; 
	f.close();
	return x; 
}
#endif