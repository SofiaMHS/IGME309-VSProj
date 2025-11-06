#include "Robot.h"



Robot::Robot()
{
	//array pointer for rotations is set to a new float array
	//with a length the size of the maximum number of limbs 
	rotations = new float[MAX_NUM_LIMBS] {0.0f};
	//the current index is set to 3, starting the player at the lower torso
	currentIndex = 3; 
	//colors is set to a new float array with 
	// a length 3 times the maximum number of limbs
	colors = new float[3 * MAX_NUM_LIMBS] {0.0f};
	//centerPoint is set to a new float array
	centerPoint = new float[2];

	//generates a random seed 
	srand(time(NULL));
	for (int i = 0; i < 3 * MAX_NUM_LIMBS; i++) {
		//fills the color list with random color values
		colors[i + 0] = getRandFloat(0.0f, 1.0f); 
		colors[i + 1] = getRandFloat(0.0f, 1.0f);
		colors[i + 2] = getRandFloat(0.0f, 1.0f);

	}
	//previous color is set to the first rgb values of the colors array pointer
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
	//rotate lower torso before it is pushed, this will allow
	//the lower torso's rotation angle to affect the other limbs
	glRotatef(rotations[3], 0.0, 0.0f, 1.0f);
	//push the lower torso's coord. matrix
	glPushMatrix();
	//draws the torso rectabgle
	glRectf(-0.5f, 0.0f, 2.5f, -2.0f);
	

	//translate the local origin to pivot point for the 1st left leg
	glTranslatef(-0.5f, -2.0f, 0.0f);
	//Left Leg - 1
	glColor3f(colors[7 * 3 + 0], colors[7 * 3 + 1], colors[7 * 3 + 2]);
	//push the 1st left leg's matrix to control the rotation of 
	//the child legs
	glPushMatrix();
	//rotate and draw the 1st left leg 
	glRotatef(rotations[7], 0.0, 0.0f, 1.0f);
	glRectf(0.0f, 0.0f, 1.0f, -1.5f);
	//calculate the center point of the bottom of the leg
	centerPoint = getCenterPoint(0.0f, -1.5f, 1.0f, -1.5f);
	//translates the origin to the pivot point for 2nd left leg
	glTranslatef(centerPoint[0], centerPoint[1], 0.0f);

	//Left Leg - 2
	glColor3f(colors[8 * 3 + 0], colors[8 * 3 + 1], colors[8 * 3 + 2]);
	//rotate and draw the 2nd left leg 
	glRotatef(rotations[8], 0.0, 0.0f, 1.0f);
	glRectf(-0.5f, 0.0f, 0.5f, -1.5f);
	//calculate the center point of the bottom of the leg
	centerPoint = getCenterPoint(-0.5f, -1.5f, 0.5f, -1.5f);
	//translates the origin to the pivot point for 3rd left leg
	glTranslatef(centerPoint[0], centerPoint[1], 0.0f);

	//Left Leg - 3
	glColor3f(colors[9 * 3 + 0], colors[9 * 3 + 1], colors[9 * 3 + 2]);
	//rotate and draw the 3rd left leg 
	glRotatef(rotations[9], 0.0, 0.0f, 1.0f);
	glRectf(0.5f, -1.0f, -1.5f, 0.0f);
	//pop the left leg matrix
	glPopMatrix();


	//translate the local origin to pivot point for the 1st right leg
	glTranslatef(2.0f, 0.0f, 0.0f);
	//Right Leg - 1
	glColor3f(colors[4 * 3 + 0], colors[4 * 3 + 1], colors[4 * 3 + 2]);
	//push the 1st right leg's matrix to control the rotation of 
	//the child legs
	glPushMatrix();
	//rotate and draw the 1st right leg 
	glRotatef(rotations[4], 0.0, 0.0f, 1.0f);
	glRectf(0.0f, 0.0f, 1.0f, -1.5f);
	//calculate the center point of the bottom of the leg
	centerPoint = getCenterPoint(0.0f, -1.5f, 1.0f, -1.5f);
	//translates the origin to the pivot point for 2nd right leg
	glTranslatef(centerPoint[0], centerPoint[1], 0.0f);

	//Right Leg - 2
	glColor3f(colors[5 * 3 + 0], colors[5 * 3 + 1], colors[5 * 3 + 2]);
	//rotate and draw the 2nd right leg 
	glRotatef(rotations[5], 0.0, 0.0f, 1.0f);
	glRectf(-0.5f, 0.0f, 0.5f, -1.5f);
	//calculate the center point of the bottom of the leg
	centerPoint = getCenterPoint(-0.5f, -1.5f, 0.5f, -1.5f);
	//translates the origin to the pivot point for 3rd right leg
	glTranslatef(centerPoint[0], centerPoint[1], 0.0f);
	
	//Right Leg - 3
	glColor3f(colors[6 * 3 + 0], colors[6 * 3 + 1], colors[6 * 3 + 2]);
	//rotate and draw the 3rd right leg
	glRotatef(rotations[6], 0.0, 0.0f, 1.0f);
	glRectf(1.5f, -1.0f, -0.5, 0.0f);
	//pop the right leg matrix
	glPopMatrix();

	//pop lower torso matrix
	glPopMatrix();


	//Upper Torso
	glColor3f(colors[2 * 3 + 0], colors[2 * 3 + 1], colors[2 * 3 + 2]);
	//push the upper torso's matrix
	glPushMatrix();
	//rotate and draw the upper torso
	glRotatef(rotations[2], 0.0, 0.0f, 1.0f);
	glRectf(-1.0f, 2.0f, 3.0f, 0.0f);


	//translate the local origin to pivot point for the 1st left arm
	glTranslatef(-1.0f, 2.0f, 0.0f);
	//Left Arm - 1
	glColor3f(colors[10 * 3 + 0], colors[10 * 3 + 1], colors[10 * 3 + 2]);
	//push the 1st left arm's matrix to control the rotation of 
	//the child arms
	glPushMatrix();
	//rotate and draw the 1st left arm
	glRotatef(rotations[10], 0.0, 0.0f, 1.0f);
	glRectf(0.0f, 0.0f, -2.0f, -1.0f);
	//calculate the center point of the far side of the 1st left arm
	centerPoint = getCenterPoint(-2.0f, 0.0f, -2.0f, -1.0f);
	//translates the origin to the pivot point for 2nd left arm
	glTranslatef(centerPoint[0], centerPoint[1], 0.0f);

	//Left Arm - 2
	glColor3f(colors[11 * 3 + 0], colors[11 * 3 + 1], colors[11 * 3 + 2]);
	//draw and rotate the 2nd left arm
	glRotatef(rotations[11], 0.0, 0.0f, 1.0f);
	glRectf(0.0f, 0.5f, -2.0f, -0.5f);
	//calculate the center point of the far side of the 2nd left arm
	centerPoint = getCenterPoint(-2.0f, 0.5f, -2.0f, -0.5f);
	//translates the origin to the pivot point for the 3rd left arm
	glTranslatef(centerPoint[0], centerPoint[1], 0.0f);

	//Left Arm - 3
	glColor3f(colors[12 * 3 + 0], colors[12 * 3 + 1], colors[12 * 3 + 2]);
	//draw and rotate the 3rd left arm
	glRotatef(rotations[12], 0.0, 0.0f, 1.0f);
	glRectf(0.0f, 1.0f, -1.0f, -1.0f);
	//pop the left arm matrix
	glPopMatrix();


	//translate the local origin to pivot point for the 1st right arm
	glTranslatef(4.0f, 0.0f, 0.0f);
	//Right Arm - 1
	glColor3f(colors[13 * 3 + 0], colors[13 * 3 + 1], colors[13 * 3 + 2]);
	//push the 1st left arm's matrix to control the rotation of 
	//the child arms
	glPushMatrix();
	//draw and rotate the 1st right arm
	glRotatef(rotations[13], 0.0, 0.0f, 1.0f);
	glRectf(0.0f, 0.0f, 2.0f, -1.0f);
	//calculate the center point of the far side of the 1st right arm
	centerPoint = getCenterPoint(2.0f, 0.0f, 2.0f, -1.0f);
	//translates the origin to the pivot point for the 2nd right arm
	glTranslatef(centerPoint[0], centerPoint[1], 0.0f);

	//Right Arm - 2
	glColor3f(colors[14 * 3 + 0], colors[14 * 3 + 1], colors[14 * 3 + 2]);
	//draw and rotate the 2nd right arm
	glRotatef(rotations[14], 0.0, 0.0f, 1.0f);
	glRectf(0.0f, -0.5f, 2.0f, 0.5f);
	//calculate the center point of the far side of the 2nd right arm
	centerPoint = getCenterPoint(2.0f, -0.5f, 2.0f, 0.5f);
	//translates the origin to the pivot point for the 3rd right arm
	glTranslatef(centerPoint[0], centerPoint[1], 0.0f);

	//Right Arm - 3
	glColor3f(colors[15 * 3 + 0], colors[15 * 3 + 1], colors[15 * 3 + 2]);
	//draw and rotate the 3rd right arm
	glRotatef(rotations[15], 0.0, 0.0f, 1.0f);
	glRectf(0.0f, 1.0f, 1.0f, -1.0f);
	glPopMatrix();


	//Head - Neck
	//translate the local origin to pivot point for the neck
	glTranslatef(-2.5f, 0.5f, 0.0f);
	glColor3f(colors[1 * 3 + 0], colors[1 * 3 + 1], colors[1 * 3 + 2]);
	//push the neck's matrix to control the rotation of 
	//the head
	glPushMatrix();

	//draw and rotate the neck
	glRotatef(rotations[1], 0.0, 0.0f, 1.0f);
	glRectf(0.0f, 0.5f, 1.0f, -0.5f);
	//calculate the center point of the far side of the neck
	centerPoint = getCenterPoint(1.0f, 0.5f, 1.0f, -0.5f);
	//translates the origin to the picot point for the 3rd right arm
	glTranslatef(centerPoint[0], centerPoint[1], 0.0f);

	//push neck matrix
	glColor3f(colors[0 * 3 + 0], colors[0 * 3 + 1], colors[0 * 3 + 2]);
	//draw and rotate the head
	glRotatef(rotations[0], 0.0, 0.0f, 1.0f);
	glRectf(-2.0f, 2.5f, 1.0f, 0.5f);
	//pop neck matrix
	glPopMatrix();

	//pop upper torso matrix
	glPopMatrix();


}

void Robot::rotate(float rotateAngle)
{
	//loop through the rotations array
	for (int i = 0; i < MAX_NUM_LIMBS; i++) {
		//if the current index is equal to the current index
		//being rotated, the angle adds the input rotation angle
		//to itself
		if (i == currentIndex) {
			rotations[i] += rotateAngle;
		}
	}

}

void Robot::keyboard(unsigned char key, int x, int y)
{
	//int to track the previous index
	int prevIndex = 0; 
	//float array pointer to set the current selected limb to red
	float* currentColor = new float[3] {1.0f, 0.0f, 0.0f};

	//previous index equals the current index
	prevIndex = currentIndex;

	//if the user presses the 'w' key
	if (key == 'w') {
		//if the current index is not greater than the max. number of 
		//limbs minus 1
		if (currentIndex < MAX_NUM_LIMBS - 1) {
		
			//add one to current index
			currentIndex += 1;
		}
		else {

			//else revert to 0
			currentIndex = 0; 
		}

	}
	//if the user presses the 's' key
	else if (key == 's') {
		//if the current index is not less than 0
		if (currentIndex > 0) {
			//subtract one from current index
			currentIndex -= 1;
		}
		else {
			//else revert to the final index
			currentIndex = MAX_NUM_LIMBS - 1; 
		}

	}


	//reset the color of the previously selected index
	colors[prevIndex * 3 + 0] = prevColor[0];
	colors[prevIndex * 3 + 1] = prevColor[1];
	colors[prevIndex * 3 + 2] = prevColor[2];

	//store the color of the currently selected index
	prevColor[0] = colors[currentIndex * 3 + 0];
	prevColor[1] = colors[currentIndex * 3 + 1];
	prevColor[2] = colors[currentIndex * 3 + 2];


	//set the current index's color to red
	colors[currentIndex * 3 + 0] = currentColor[0];
	colors[currentIndex * 3 + 1] = currentColor[1];
	colors[currentIndex * 3 + 2] = currentColor[2];


	//if the user presses the 'd' key
	if (key == 'd') {
		//subtract 15 degrees from the selected limbs' rotational angle
		rotate(-15.0f);
	}
	//if the user presses the 'a' key
	else if (key == 'a') {
		//add 15 degrees to the selected limbs' rotational angle
		rotate(15.0f);
	}

}

float Robot::getRandFloat(float min, float max)
{
	//returns a float between the input min and max
	return min + (std::rand()) / (RAND_MAX / (max - min)); 
}

float* Robot::getCenterPoint(float x1, float y1, float x2, float y2)
{
	//creates a float array to contain the midpoint
	float* center = new float[2];

	//calculates the x an y center coords. between
	//the input variables
	center[0] = (x1 + x2) / 2; 
	center[1] = (y1 + y2) / 2;

	//returns the center
	return center; 
}
