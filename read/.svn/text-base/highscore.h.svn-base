#ifndef INCLUDED_HIGHSCORE_H
#define INCLUDED_HIGHSCORE_H
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
/** < getHeighcore gives the highscore*/ 
int getHighScore(char* name){
	ifstream f;
	f.open(name); 
	int x;
	f >> x; 
	f.close();
	return x; 
}
/** putheighscore add new heighscore*/
void putHighScore(char* name,int score){
	ofstream f;
	f.open(name);
	cout <<score << endl;
	f << score ; 
	f.close();
}

#endif