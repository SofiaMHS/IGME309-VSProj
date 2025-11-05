#include "Robot.h"



Robot::Robot()
{
	rotations = new float[MAX_NUM_LIMBS] {0.0f};
	translations = new float[2 * MAX_NUM_LIMBS] {0.0f};
	currentIndex = 0; 
	colors = new float[3 * MAX_NUM_LIMBS] {0.0f};



	srand(time(NULL));
	for (int i = 0; i < 3 * MAX_NUM_LIMBS; i++) {
		colors[i + 0] = getRandFloat(0.0f, 1.0f); 
		colors[i + 1] = getRandFloat(0.0f, 1.0f);
		colors[i + 2] = getRandFloat(0.0f, 1.0f);

	}
	prevColor = new float[3] {colors[0], colors[1], colors[2]};


	vertices = new float[4 * MAX_NUM_LIMBS] {
		-0.5f, 5.0f, 2.5f, 3.0f, //Head
			0.5f, 3.0f, 1.5f, 2.0f, //Neck
			-1.0f, 2.0f, 3.0f, 0.0f, //Upper Torso
			-0.5f, 0.0f, 2.5f, -2.0f,//Lower Torso
			1.5f, -2.0f, 2.5f, -3.5f,//Right Leg - 1
			1.5f, -3.5f, 2.5f, -5.0f,//Right Leg - 2
			1.5f, -5.0f, 3.5f, -6.0f,//Right Leg - 3
			-0.5f, -2.0f, 0.5f, -3.5f,//Left Leg - 1
			-0.5f, -3.5f, 0.5f, -5.0f,//Left Leg - 2
			-1.5f, -6.0f, 0.5f, -5.0f,//Left Leg - 3
			-1.0f, 2.0f, -3.0f, 1.0f,//Left Arm - 1
			-3.0f, 2.0f, -5.0f, 1.0f,//Left Arm - 2
			-5.0f, 2.5f, -6.0f, 0.5f,//Left Arm - 3
			3.0f, 2.0f, 5.0f, 1.0f,//Right Arm - 1
			5.0f, 2.0f, 7.0f, 1.0f,//Right Arm - 2
			7.0f, 2.5f, 8.0f, 0.5f,//Right Arm - 3
	};

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
	/*
	for (int i = 0; i < 4 * MAX_NUM_LIMBS; i++) {

		if (i = currentIndex) {
			glColor3f(1.0f, 0.0f, 0.0f);
		}
		else {
			glColor3f(colors[i * 3 + 0], colors[i * 3 + 1], colors[i * 3 + 2]);
		}
		glBegin(GL_LINE_LOOP); 
		glRotatef(rotations[i], 0.0, 0.0f, 1.0f);
		glVertex4f(vertices[i * 4 + 0],
			vertices[i * 4 + 1],
			vertices[i * 4 + 2],
			vertices[i * 4 + 3]);
	}*/

	


	//Upper Torso
	glColor3f(colors[2*3 + 0], colors[2 * 3 + 1], colors[2 * 3 + 2]);
	glRotatef(rotations[2], 0.0, 0.0f, 1.0f);
	glPushMatrix();
	glRectf(-1.0f, 2.0f, 3.0f, 0.0f);
	//push upper torso matrix



	//Left Arm - 1
	glColor3f(colors[10 * 3 + 0], colors[10 * 3 + 1], colors[10 * 3 + 2]);
	glPushMatrix();
	glRotatef(rotations[10], 0.0, 0.0f, 1.0f);
	glRectf(-1.0f, 2.0f, -3.0f, 1.0f);
	//Left Arm - 2
	glColor3f(colors[11 * 3 + 0], colors[11 * 3 + 1], colors[11 * 3 + 2]);
	glRotatef(rotations[11], 0.0, 0.0f, 1.0f);
	glRectf(-3.0f, 2.0f, -5.0f, 1.0f);
	//Left Arm - 3
	glColor3f(colors[12 * 3 + 0], colors[12 * 3 + 1], colors[12 * 3 + 2]);
	glRotatef(rotations[12], 0.0, 0.0f, 1.0f);
	glRectf(-5.0f, 2.5f, -6.0f, 0.5f);
	glPopMatrix();


	//Right Arm - 1
	glColor3f(colors[13 * 3 + 0], colors[13 * 3 + 1], colors[13 * 3 + 2]);
	glPushMatrix();
	glRotatef(rotations[13], 0.0, 0.0f, 1.0f);
	glRectf(3.0f, 2.0f, 5.0f, 1.0f);
	//Right Arm - 2
	glColor3f(colors[14 * 3 + 0], colors[14 * 3 + 1], colors[14 * 3 + 2]);
	glRotatef(rotations[14], 0.0, 0.0f, 1.0f);
	glRectf(5.0f, 2.0f, 7.0f, 1.0f);
	//Right Arm - 3
	glColor3f(colors[15 * 3 + 0], colors[15 * 3 + 1], colors[15 * 3 + 2]);
	glRotatef(rotations[15], 0.0, 0.0f, 1.0f);
	glRectf(7.0f, 2.5f, 8.0f, 0.5f);
	glPopMatrix();

	//Head - Neck
	glColor3f(colors[1 * 3 + 0], colors[1 * 3 + 1], colors[1 * 3 + 2]);
	glPushMatrix();
	glRotatef(rotations[1], 0.0, 0.0f, 1.0f);
	glRectf(0.5f, 3.0f, 1.5f, 2.0f);

	//push neck matrix
	glColor3f(colors[0 * 3 + 0], colors[0 * 3 + 1], colors[0 * 3 + 2]);
	glRotatef(rotations[0], 0.0, 0.0f, 1.0f);
	glRectf(-0.5f, 5.0f, 2.5f, 3.0f);
	glPopMatrix();
	//pop neck matrix

	glPopMatrix(); 
	//pop upper torso matrix

	//if rotate is not called, the rest will rotate with the first
	//glRotatef(rotations[currentIndex], 0.0, 0.0f, 1.0f);
	//Lower Torso
	glColor3f(colors[3 * 3 + 0], colors[3 * 3 + 1], colors[3 * 3 + 2]);
	glPushMatrix();
	glRotatef(rotations[3], 0.0, 0.0f, 1.0f);
	glRectf(-0.5f, 0.0f, 2.5f, -2.0f);
	//push lower torso matrix

	//Left Leg - 1
	glColor3f(colors[7 * 3 + 0], colors[7 * 3 + 1], colors[7 * 3 + 2]);
	glPushMatrix();
	glRotatef(rotations[7], 0.0, 0.0f, 1.0f);
	glRectf(-0.5f, -2.0f,0.5f,-3.5f);
	//Left Leg - 2
	glColor3f(colors[8 * 3 + 0], colors[8 * 3 + 1], colors[8 * 3 + 2]);
	glRotatef(rotations[8], 0.0, 0.0f, 1.0f);
	glRectf(-0.5f, -3.5f, 0.5f, -5.0f);
	//Left Leg - 3
	glColor3f(colors[9 * 3 + 0], colors[9 * 3 + 1], colors[9 * 3 + 2]);
	glRotatef(rotations[9], 0.0, 0.0f, 1.0f);
	glRectf(-1.5f, -6.0f, 0.5f, -5.0f);
	glPopMatrix();

	//Right Leg - 1
	glColor3f(colors[4 * 3 + 0], colors[4 * 3 + 1], colors[4 * 3 + 2]);
	glPushMatrix();
	glRotatef(rotations[4], 0.0, 0.0f, 1.0f);
	glRectf(1.5f, -2.0f, 2.5f, -3.5f);
	//Right Leg - 2
	glColor3f(colors[5 * 3 + 0], colors[5 * 3 + 1], colors[5 * 3 + 2]);
	glRotatef(rotations[5], 0.0, 0.0f, 1.0f);
	glRectf(1.5f, -3.5f, 2.5f, -5.0f);
	//Right Leg - 3
	glColor3f(colors[6 * 3 + 0], colors[6 * 3 + 1], colors[6 * 3 + 2]);
	glRotatef(rotations[6], 0.0, 0.0f, 1.0f);
	glRectf(1.5f, -5.0f, 3.5f, -6.0f);
	glPopMatrix();


	glPopMatrix(); 
	//pop lower torso matrix
	

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
		if (currentIndex < MAX_NUM_LIMBS) {
		
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
