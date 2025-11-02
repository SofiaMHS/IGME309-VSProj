#include "Robot.h"



Robot::Robot()
{
	rotations = new float[MAX_NUM_LIMBS] {0.0f};
	translations = new float[2 * MAX_NUM_LIMBS] {0.0f};
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
	//glRotatef(rotations[currentIndex], 0.0, 0.0f, 1.0f);
	glRectf(-1.0f, 2.0f, 3.0f, 0.0f);

	//if rotate is not called, the rest will rotate with the first
	currentIndex = 4; 
	//glRotatef(rotations[currentIndex], 0.0, 0.0f, 1.0f);
	glColor3f(0.0f, 0.6f, 0.3f);
	glRectf(0.0f, 0.0f, 2.0f, -2.0f);

}

void Robot::drawHead()
{

}


void Robot::draw()
{


	
	//Upper Torso
	glColor3f(0.0f, 0.5f, 0.6f);
	//glRotatef(rotations[currentIndex], 0.0, 0.0f, 1.0f);
	glRectf(-1.0f, 2.0f, 3.0f, 0.0f);
	//push upper torso matrix

	//Head - Neck
	glColor3f(0.4f, 0.5f, 0.6f);
	glRectf(0.5f, 3.0f, 1.5f, 2.0f);

	//push neck matrix
	glColor3f(0.6f, 0.5f, 0.6f);
	glRectf(-0.5f, 5.0f, 2.5f, 3.0f);
	//pop neck matrix

	//Left Arm - 1
	glColor3f(1.0f, 0.0f, 0.6f);
	glRectf(-1.0f, 2.0f, -3.0f, 1.0f);
	//Left Arm - 2
	glColor3f(0.0f, 1.0f, 0.6f);
	glRectf(-3.0f, 2.0f, -5.0f, 1.0f);
	//Left Arm - 3
	glColor3f(0.3f, 0.5f, 1.0f);
	glRectf(-5.0f, 2.5f, -6.0f, 0.5f);

	//Right Arm - 1
	glColor3f(0.4f, 0.0f, 0.6f);
	glRectf(3.0f, 2.0f, 5.0f, 1.0f);
	//Right Arm - 2
	glColor3f(0.9f, 0.3f, 0.0f);
	glRectf(5.0f, 2.0f, 7.0f, 1.0f);
	//Right Arm - 3
	glColor3f(0.7f, 0.0f, 0.8f);
	glRectf(7.0f, 2.5f, 8.0f, 0.5f);

	//pop upper torso matrix

	//if rotate is not called, the rest will rotate with the first
	//glRotatef(rotations[currentIndex], 0.0, 0.0f, 1.0f);
	//Lower Torso
	glColor3f(0.0f, 0.6f, 0.3f);
	glRectf(-0.5f, 0.0f, 2.5f, -2.0f);
	//push lower torso matrix

	//Left Leg - 1
	glColor3f(0.5f, 0.3f, 0.0f);
	glRectf(-0.5f, -2.0f,0.5f,-3.5f);
	//Left Leg - 2
	glColor3f(0.5f, 0.3f, 0.7f);
	glRectf(-0.5f, -3.5f, 0.5f, -5.0f);
	//Left Leg - 3
	glColor3f(0.9f, 0.0f, 0.2f);
	glRectf(-1.5f, -6.0f, 0.5f, -5.0f);

	//Right Leg - 1
	glColor3f(0.3f, 0.3f, 0.3f);
	glRectf(1.5f, -2.0f, 2.5f, -3.5f);
	//Right Leg - 2
	glColor3f(0.0f, 0.3f, 0.9f);
	glRectf(1.5f, -3.5f, 2.5f, -5.0f);
	//Right Leg - 3
	glColor3f(0.9f, 0.7f, 0.2f);
	glRectf(1.5f, -5.0f, 3.5f, -6.0f);
	//pop lower torso matrix


}

void Robot::rotate()
{

	for (int i = 0; i < MAX_NUM_LIMBS; i++) {
		if (i == currentIndex) {
			rotations[i] += 15.0f;
		}
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
