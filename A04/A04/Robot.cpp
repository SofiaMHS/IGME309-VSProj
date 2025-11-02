#include "Robot.h"



Robot::Robot()
{
	rotations = new float[MAX_NUM_LIMBS];
	translations = new float[2* MAX_NUM_LIMBS];
	currentIndex = 0; 
}

Robot::~Robot()
{

}

void Robot::drawFoot()
{

}

void Robot::drawTorso()
{
	currentIndex = 3; 
	glColor3f(0.0f, 0.5f, 0.6f);
	glRectf(-1.0f, 2.0f, 3.0f, 0.0f);
	glColor3f(0.0f, 0.6f, 0.3f);
	glRectf(0.0f, 0.0f, 2.0f, -2.0f);

}

void Robot::drawHead()
{

}


void Robot::draw()
{
	
}

void Robot::rotate()
{
	int asciiOffset = 49;
	for (unsigned char i = '1'; i < MAX_NUM_LIMBS; i++) {
			rotations[i - asciiOffset] += 15.0f;
	}
}

void Robot::keyboard(unsigned char key, int x, int y)
{
	if (key == 'd') {
		if (currentIndex < MAX_NUM_LIMBS) {
			currentIndex += 1;

		}
		else {
			currentIndex = 0; 
		}
	}

}
