#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include <ctime>
#include <cmath>

using namespace std;

float canvasSize[] = { 20.0f, 20.0f };
int rasterSize[] = { 600, 600 };

// tracking the game time - millisecond 
unsigned int curTime = 0;
unsigned int preTime = 0;
float deltaTime = 0;

float rotationAngle = 0.0f;
float rotateSpeed = 90.0f;
int vertNum = 30; 
float circRadius = 1.0f; 

//initializations for necessary coordinates
float anchorX = canvasSize[0] / 2;
float anchorY = canvasSize[1] / 2 + canvasSize[1] / 4;
float radius = canvasSize[0] / 2;
float penX = -canvasSize[0] / 2;
float penY = -canvasSize[1] / 2;

//function to draw a circle based on input x,y coords
void drawCircle(float x, float y) {


	glBegin(GL_POLYGON);
	//loops based on the number of verticies
	
	for (int i = 0; i < vertNum; i++) {
		//each polygon is drawn in the correct displacement based on the angle dervided from the current
		//index divided by the total vertices times 2pi
		float t = (float)i / vertNum * 2.0f * 3.14f;
		glVertex2f(x + circRadius * cos(t), y + circRadius * sin(t));
	}
	glEnd(); 

}

void display(void)
{
	glClearColor(0.9f, 0.9f, 0.7f, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	/*****************************/
	//Draw anchor point
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(8.0f);
	glBegin(GL_POINTS);
	glVertex2f(anchorX, anchorY);
	glEnd();


	//setup for the anchor points
	//pushes the current matrix to the stack
	glPushMatrix();
	//translates the world so anchor becomes the local origin of this matrix
	glTranslatef(anchorX, anchorY, 0.0f);
	//Apply rotation around anchor point based on the current rotation angle
	glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
	//translates the world along the x-axis the appropriate distance from the anchor point
	glTranslatef(radius, 0.0f, 0.0f);



	// Draw rotating ball
	//sets the color for the ball
	glColor3f(0.7, 0.3f, 0.8f);
	//calls the draw circle function with the pendulum x and y coords.
	drawCircle(penX, penY);

	//sets color for the string
	glColor3f(0.0f, 0.0f, 0.0f);
	//sets line width of the string
	glLineWidth(2.0f);
	//drawing for the line begins
	glBegin(GL_LINES);
	//line origin rests at the pendulum x coord. and 0 for the y coord
	glVertex2f(penX, 0.0f);
	//line end point is at the pendulum x and y coords.
	glVertex2f(penX, penY);
	glEnd();

	//curent matrix is popped so it can later be updated according to the rotation angle
	glPopMatrix();

	glutPostRedisplay(); 
	/*****************************/

	glutSwapBuffers();
}

void reshape(int w, int h)
{
	rasterSize[0] = w;
	rasterSize[1] = h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, canvasSize[0], 0, canvasSize[1]);
	glViewport(0, 0, rasterSize[0], rasterSize[1]);

	glutPostRedisplay();
}


void update() {
	curTime = glutGet(GLUT_ELAPSED_TIME);
	deltaTime = (float)(curTime - preTime) / 1000.0f;


	if (rotationAngle > 45.0f) {
		rotateSpeed = -abs(rotateSpeed);
	}
	else if (rotationAngle < -45.0f) {
		rotateSpeed = abs(rotateSpeed);
	}
	rotationAngle += deltaTime * rotateSpeed;

	preTime = curTime;
	glutPostRedisplay();
}


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(rasterSize[0], rasterSize[1]);
	glutCreateWindow("Simple Pendulum");

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutIdleFunc(update);

	preTime = glutGet(GLUT_ELAPSED_TIME);
	glutMainLoop();
	return 0;
}