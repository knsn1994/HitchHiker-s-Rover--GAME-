#ifndef INCLUDED_INFO_H
#define INCLUDED_INFO_H
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
class obj{
public:
/** this is container class for object,coin,teleportals and other obstacles etc*/ 
	int n; 
	float sx,sz;
	float *x,*z;
	int *type;
	obj(){} 
	obj(int num); 
}; 
obj::obj(int num){
	n = num;
	x = new float[num]; 
	z = new float[num];
	type = new int[num]; 
} 
obj returnInfo(char* name)/**return info of obj in this class by reading it from a file*/ 
{
	FILE* f = freopen(name,"r",stdin);
	int n;
	cin >> n;
	obj ret = obj(n); 
	cin >> ret.sx >> ret.sz ;
	for(int i=0;i<n;i++){
		cin >> ret.x[i] >> ret.z[i] >> ret.type[i] ; 
	}
	fclose(f);
	return ret; 
}
#endif