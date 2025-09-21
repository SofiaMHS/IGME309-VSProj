#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include <cstdlib>
#include <ctime>
#include <cmath>

float canvasSize[] = { 10.0f, 10.0f };
int rasterSize[] = { 600, 600 };

// global parameters defining the ball
int vertNum = 30;				// total number of vertices for the circle
float ballPos[] = { 5.0f, 8.0f }; // center position of the circle
float radius = 0.3f;			// circle's radius

float velocity_x = 0.0f;
float velocity_y = 0.0f;

// bar
float barPos[] = { 5.0f, 2.0f }; // center position of the bar
float barSize = 3.0f;

// tracking the game time - millisecond
unsigned int curTime = 0;
unsigned int preTime = 0;
float deltaTime = 0;

int score = 0;
bool ballIsActive = false;
float prepareTime = 2.0f;

void throwBall()
{
	ballIsActive = true;

	ballPos[0] = 5.0f;
	ballPos[1] = 8.0f;

	velocity_x = -1.0f;
	velocity_y = 0.0f;
}

void init(void)
{
	std::srand(std::time(0));
}

void drawCircle(float x, float y)
{
	glColor3f(1.0f, 1.0f, 1.0f);
	// draw the cicle
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertNum; ++i)
	{
		float t = (float)i / vertNum * 2.0f * 3.14f;
		glVertex2f(x + radius * cos(t), y + radius * sin(t));
	}
	glEnd();
}

void drawBar(float x, float y, float w)
{
	glColor3f(0.5f, 0.25f, 0.25f);
	glLineWidth(10.0f);
	// draw the bar
	glBegin(GL_LINES);
	glVertex2f(x - w / 2.0f, y);
	glVertex2f(x + w / 2.0f, y);
	glEnd();
	glLineWidth(1.0f);
}

void display(void)
{
	glClearColor(0.3, 0.6, 0.3, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	drawCircle(ballPos[0], ballPos[1]);
	drawBar(barPos[0], barPos[1], barSize);

	glutSwapBuffers();
}

void reshape(int w, int h)
{
	rasterSize[0] = w;
	rasterSize[1] = h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, canvasSize[0], 0.0, canvasSize[1]);
	glViewport(0, 0, rasterSize[0], rasterSize[1]);

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		/***********************************************************/
		// Exit the game if the user presses esc
		exit(0);
		/***********************************************************/
		break;
	case 'a':
		/***********************************************************/
		// Move the bar one step left, make sure the bar does not move out of the screen.
		//if the bar's x value minus the length is less than 0, it has reached the left of the screen
		if (barPos[0] - barSize + 1 > 0) {
			//if the bar is not at the left of the screen, bar moves an 8th of the canvasSize to the left 
			barPos[0] -= canvasSize[0] / 8;
		}
		/***********************************************************/
		break;
	case 'd':
		/***********************************************************/
		// Move the bar one step right, make sure the bar does not move out of the screen.
		//if the bar's x value plus the length is less than 0, it has reached the right of the screen
		if (barPos[0] + barSize - 1 < canvasSize[0]) {
			//if the bar is not at the right of the screen, bar moves an 8th of the canvasSize to the right 
			barPos[0] += canvasSize[0] / 8;
		}
		break;
	}
}

void update()
{
	curTime = glutGet(GLUT_ELAPSED_TIME);			  // returns the number of milliseconds since glutInit() was called.
	deltaTime = (float)(curTime - preTime) / 1000.0f; // frame-different time in seconds

	/***********************************************************/
	// Calculate velocity_y with gravitational acceleration.
	//velocity w/ grav. accel. = (velocity + gravitational accel. * time) 
	velocity_y += -9.8f * deltaTime; 
	/***********************************************************/

	if (ballIsActive == false)
	{
		prepareTime -= deltaTime;
		if (prepareTime < 0.0f)
			throwBall();
	}
	else
	{
		/***********************************************************/
		// Incorporate collision detection to ascertain when the ball makes contact with the bar.
		// Upon collision, modify the ball's trajectory by adjusting its velocity, ensuring it bounces back.

		//if the ball's y value is less than or euqal to the bar's y value + .5f, and the ball's y is higher than the bar's y value minus .5f
		if (barPos[1] + 0.5f >= ballPos[1] && barPos[1] - 0.5f <= ballPos[1] 
			//and the bar's x value from the left is las than the ball's x value, 
			// and the bar's x value from the right is greater than the ball's y value
			&& barPos[0] - barSize /2  < ballPos[0] && barPos[0] + barSize /2 > ballPos[0]) {
			//on collision with the bar, the ball's velocity is reversed 
			velocity_y = -velocity_y; 
		}
		/***********************************************************/

		if (ballPos[0] - radius < 0.0f) // left boundary
			velocity_x = abs(velocity_x);
		else if (ballPos[0] + radius > canvasSize[0]) // right boundary
			velocity_x = -abs(velocity_x);

		if (ballPos[1] - radius < 0.0f)
		{ // hit the ground
			ballIsActive = false;
			prepareTime = 2.0f;
		}
		else if (ballPos[1] + radius > canvasSize[1]) // hit the ceiling
			velocity_y = -abs(velocity_y);

		ballPos[0] += velocity_x * deltaTime;
		ballPos[1] += velocity_y * deltaTime;
	}

	preTime = curTime; // the curTime become the preTime for the next frame
	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	init();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(rasterSize[0], rasterSize[1]);
	glutCreateWindow("Pong!");

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(update);

	preTime = glutGet(GLUT_ELAPSED_TIME);

	glutMainLoop();
	return 0;
}