#pragma once
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include <iostream>
#include <math.h>
class Robot
{
	private: 
		const int MAX_NUM_LIMBS = 16;  
		int currentIndex; 
		float* rotations; 

    public:
		Robot(); 
		~Robot(); 
		void drawFoot();
		void drawTorso(); 
		void drawHead(); 
		void draw(); 
};

