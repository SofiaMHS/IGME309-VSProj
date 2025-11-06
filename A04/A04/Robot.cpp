#include "Robot.h"



Robot::Robot()
{
	rotations = new float[MAX_NUM_LIMBS] {0.0f};
	translations = new float[2 * MAX_NUM_LIMBS] {0.0f};
	currentIndex = 3; 
	colors = new float[3 * MAX_NUM_LIMBS] {0.0f};
	centerPoint = new float[2];


	srand(time(NULL));
	for (int i = 0; i < 3 * MAX_NUM_LIMBS; i++) {
		colors[i + 0] = getRandFloat(0.0f, 1.0f); 
		colors[i + 1] = getRandFloat(0.0f, 1.0f);
		colors[i + 2] = getRandFloat(0.0f, 1.0f);

	}
	prevColor = new float[3] {colors[0], colors[1], colors[2]};

}

Robot::~Robot()
{

}

void Robot::draw()
{

	//if rotate is not called, the rest will rotate with the first
	//glRotatef(rotations[currentIndex], 0.0, 0.0f, 1.0f);
	//Lower Torso
	glColor3f(colors[3 * 3 + 0], colors[3 * 3 + 1], colors[3 * 3 + 2]);
	glRotatef(rotations[3], 0.0, 0.0f, 1.0f);
	glPushMatrix();
	glRectf(-0.5f, 0.0f, 2.5f, -2.0f);
	//push lower torso matrix

	glTranslatef(-0.5f, -2.0f, 0.0f);
	//Left Leg - 1
	glColor3f(colors[7 * 3 + 0], colors[7 * 3 + 1], colors[7 * 3 + 2]);
	glPushMatrix();
	glRotatef(rotations[7], 0.0, 0.0f, 1.0f);
	glRectf(0.0f, 0.0f, 1.0f, -1.5f);
	centerPoint = getCenterPoint(0.0f, -1.5f, 1.0f, -1.5f);
	glTranslatef(centerPoint[0], centerPoint[1], 0.0f);
	//Left Leg - 2
	glColor3f(colors[8 * 3 + 0], colors[8 * 3 + 1], colors[8 * 3 + 2]);
	glRotatef(rotations[8], 0.0, 0.0f, 1.0f);
	glRectf(-0.5f, 0.0f, 0.5f, -1.5f);
	centerPoint = getCenterPoint(-0.5f, -1.5f, 0.5f, -1.5f);
	glTranslatef(centerPoint[0], centerPoint[1], 0.0f);
	//Left Leg - 3
	glColor3f(colors[9 * 3 + 0], colors[9 * 3 + 1], colors[9 * 3 + 2]);
	glRotatef(rotations[9], 0.0, 0.0f, 1.0f);
	glRectf(0.5f, -1.0f, -1.5f, 0.0f);
	glPopMatrix();


	glTranslatef(2.0f, 0.0f, 0.0f);
	//Right Leg - 1
	glColor3f(colors[4 * 3 + 0], colors[4 * 3 + 1], colors[4 * 3 + 2]);
	glPushMatrix();
	glRotatef(rotations[4], 0.0, 0.0f, 1.0f);
	glRectf(0.0f, 0.0f, 1.0f, -1.5f);
	centerPoint = getCenterPoint(0.0f, -1.5f, 1.0f, -1.5f);
	glTranslatef(centerPoint[0], centerPoint[1], 0.0f);
	//Right Leg - 2
	glColor3f(colors[5 * 3 + 0], colors[5 * 3 + 1], colors[5 * 3 + 2]);
	glRotatef(rotations[5], 0.0, 0.0f, 1.0f);
	glRectf(-0.5f, 0.0f, 0.5f, -1.5f);
	centerPoint = getCenterPoint(-0.5f, -1.5f, 0.5f, -1.5f);
	glTranslatef(centerPoint[0], centerPoint[1], 0.0f);
	//Right Leg - 3
	glColor3f(colors[6 * 3 + 0], colors[6 * 3 + 1], colors[6 * 3 + 2]);
	glRotatef(rotations[6], 0.0, 0.0f, 1.0f);
	glRectf(1.5f, -1.0f, -0.5, 0.0f);
	glPopMatrix();


	glPopMatrix();
	//pop lower torso matrix

	//Upper Torso
	glColor3f(colors[2 * 3 + 0], colors[2 * 3 + 1], colors[2 * 3 + 2]);
	glPushMatrix();
	glRotatef(rotations[2], 0.0, 0.0f, 1.0f);
	glRectf(-1.0f, 2.0f, 3.0f, 0.0f);
	//push upper torso matrix


	glTranslatef(-1.0f, 2.0f, 0.0f);
	//Left Arm - 1
	glColor3f(colors[10 * 3 + 0], colors[10 * 3 + 1], colors[10 * 3 + 2]);
	glPushMatrix();
	glRotatef(rotations[10], 0.0, 0.0f, 1.0f);
	glRectf(0.0f, 0.0f, -2.0f, -1.0f);
	centerPoint = getCenterPoint(-2.0f, 0.0f, -2.0f, -1.0f);
	glTranslatef(centerPoint[0], centerPoint[1], 0.0f);
	//Left Arm - 2
	glColor3f(colors[11 * 3 + 0], colors[11 * 3 + 1], colors[11 * 3 + 2]);
	//glPushMatrix();
	glRotatef(rotations[11], 0.0, 0.0f, 1.0f);
	glRectf(0.0f, 0.5f, -2.0f, -0.5f);
	centerPoint = getCenterPoint(-2.0f, 0.5f, -2.0f, -0.5f);
	glTranslatef(centerPoint[0], centerPoint[1], 0.0f);
	//Left Arm - 3
	glColor3f(colors[12 * 3 + 0], colors[12 * 3 + 1], colors[12 * 3 + 2]);
	glRotatef(rotations[12], 0.0, 0.0f, 1.0f);
	glRectf(0.0f, 1.0f, -1.0f, -1.0f);
	//glPopMatrix();
	glPopMatrix();



	glTranslatef(4.0f, 0.0f, 0.0f);
	//Right Arm - 1
	glColor3f(colors[13 * 3 + 0], colors[13 * 3 + 1], colors[13 * 3 + 2]);
	glPushMatrix();
	glRotatef(rotations[13], 0.0, 0.0f, 1.0f);
	glRectf(0.0f, 0.0f, 2.0f, -1.0f);
	centerPoint = getCenterPoint(2.0f, 0.0f, 2.0f, -1.0f);
	glTranslatef(centerPoint[0], centerPoint[1], 0.0f);
	//Right Arm - 2
	glColor3f(colors[14 * 3 + 0], colors[14 * 3 + 1], colors[14 * 3 + 2]);
	glRotatef(rotations[14], 0.0, 0.0f, 1.0f);
	glRectf(0.0f, -0.5f, 2.0f, 0.5f);
	centerPoint = getCenterPoint(2.0f, -0.5f, 2.0f, 0.5f);
	glTranslatef(centerPoint[0], centerPoint[1], 0.0f);
	//Right Arm - 3
	glColor3f(colors[15 * 3 + 0], colors[15 * 3 + 1], colors[15 * 3 + 2]);
	glRotatef(rotations[15], 0.0, 0.0f, 1.0f);
	glRectf(0.0f, 1.0f, 1.0f, -1.0f);
	glPopMatrix();


	//Head - Neck
	glColor3f(colors[1 * 3 + 0], colors[1 * 3 + 1], colors[1 * 3 + 2]);
	glPushMatrix();
	glTranslatef(-2.5f, 0.5f, 0.0f);

	glRotatef(rotations[1], 0.0, 0.0f, 1.0f);
	glRectf(0.0f, 0.5f, 1.0f, -0.5f);
	centerPoint = getCenterPoint(1.0f, 0.5f, 1.0f, -0.5f);
	glTranslatef(centerPoint[0], centerPoint[1], 0.0f);
	//push neck matrix
	glColor3f(colors[0 * 3 + 0], colors[0 * 3 + 1], colors[0 * 3 + 2]);
	glRotatef(rotations[0], 0.0, 0.0f, 1.0f);
	glRectf(-2.0f, 2.5f, 1.0f, 0.5f);
	glPopMatrix();
	//pop neck matrix

	glPopMatrix();
	//pop upper torso matrix


}

void Robot::rotate(float rotateAngle)
{

	for (int i = 0; i < MAX_NUM_LIMBS; i++) {
		if (i == currentIndex) {
			rotations[i] += rotateAngle;
		}
	}

}

void Robot::keyboard(unsigned char key, int x, int y)
{
	int prevIndex = 0; 
	float* currentColor = new float[3] {1.0f, 0.0f, 0.0f};

	prevIndex = currentIndex;

	if (key == 'w') {
		if (currentIndex < MAX_NUM_LIMBS - 1) {
		
			currentIndex += 1;
		}
		else {

			currentIndex = 0; 
		}

	}
	else if (key == 's') {
		if (currentIndex > 0) {
			currentIndex -= 1;
		}
		else {
			currentIndex = MAX_NUM_LIMBS - 1; 
		}

	}



	colors[prevIndex * 3 + 0] = prevColor[0];
	colors[prevIndex * 3 + 1] = prevColor[1];
	colors[prevIndex * 3 + 2] = prevColor[2];

	prevColor[0] = colors[currentIndex * 3 + 0];
	prevColor[1] = colors[currentIndex * 3 + 1];
	prevColor[2] = colors[currentIndex * 3 + 2];

	colors[currentIndex * 3 + 0] = currentColor[0];
	colors[currentIndex * 3 + 1] = currentColor[1];
	colors[currentIndex * 3 + 2] = currentColor[2];

	if (key == 'd') {

		rotate(-15.0f);
	}
	else if (key == 'a') {
		rotate(15.0f);
	}

}

float Robot::getRandFloat(float min, float max)
{
	return min + (std::rand()) / (RAND_MAX / (max - min)); 
}

float* Robot::getCenterPoint(float x1, float y1, float x2, float y2)
{
	float* center = new float[2];

	center[0] = (x1 + x2) / 2; 
	center[1] = (y1 + y2) / 2;


	return center; 
}
