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
		float* colors; 
		float* prevColor;
		float* centerPoint;

    public:
		Robot(); 
		~Robot(); 
		void draw(); 
		void rotate(float rotateAngle);
		void keyboard(unsigned char key, int x, int y);
		float getRandFloat(float min, float max);
		float* getCenterPoint(float x1, float y1, float x2, float y2);
};

