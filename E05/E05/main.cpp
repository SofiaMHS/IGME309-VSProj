
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "MyMesh.h"

#include <iostream>
using namespace std;

float canvasSize[] = { 10.0f, 10.0,};
int rasterSize[] = { 600, 600 };

const float* p_vertices = new float[100]{ 1.0, 7.0,
1.0, 6.5
,2.0, 7.0
,2.0, 6.5
,1.2, 6.5
,1.8, 6.5
,1.2,3.5
,1.8, 3.5
,1.0, 3.5
,1.0, 3.0
,2.0, 3.5
,2.0, 3.0
,3.0 ,7.0
,3.0, 6.5
,5.0, 7.0
,5.0, 6.5
,3.5, 6.5
,3.0, 3.5
,3.5, 3.5
,3.0 ,3.0
,5.0, 3.5
,5.0, 3.0
,4.5, 3.5
,4.5, 4.5
,5.0, 4.5
,4.0 ,4.5
,5.2, 4.5
,4.0, 5.0
,5.2, 5.0
,6.0, 7.0
,6.5, 7.0
,6.0, 3.0
,6.5, 3.0
,6.5, 6.0
,7.5, 4.5
,7.25, 4.0
,8.5, 7.0
,9.0, 7.0
,8.5, 3.0
,9.0, 3.0
,8.5, 6.0
,7.75, 4.0
};

const unsigned int* p_indices = new unsigned int[200] { 1, 2, 5
,1, 5, 3
,3, 5, 6
,3, 6, 4
,5, 7, 6
,6, 7, 8
,7, 9, 10
,7, 10, 8
,8, 10, 12
,8, 12, 11
,13, 14, 17
,13, 17, 15
,15, 17, 16
,14, 18, 17
,18, 19, 17
,18, 20, 19
,20, 22, 19
,19, 22, 23
,23, 22, 21
,24, 23, 25
,23, 21, 25
,28, 26, 24
,28, 24, 29
,24, 25, 29
,25, 27, 29
,30, 32, 34
,30, 34, 31
,34, 32, 33
,31, 34, 35
,34, 36, 35
,36 ,42, 35
,35 ,41, 37
,35 ,42, 41
,37 ,41, 38
,38 ,41, 40
,41 ,39, 40 };

MyMesh g_mesh = MyMesh();


void init(void)
{
	// load the mesh data to g_mesh
	char fileName[19] = { "../Debug/data2.obj"};

	//g_mesh.load(42, 36, p_vertices, p_indices);  

	g_mesh.load(fileName);
}


void display(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// draw the mesh
	g_mesh.draw();

	glutSwapBuffers();
}

void reshape(int w, int h)
{
	rasterSize[0] = w;
	rasterSize[1] = h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0f, canvasSize[0], 0.0f, canvasSize[1]);
	glViewport(0, 0, rasterSize[0], rasterSize[1]);

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		exit(0);
		break;
	}
}

int main(int argc, char* argv[])
{
	init();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(rasterSize[0], rasterSize[1]);
	glutCreateWindow("MyMesh class example");

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;


}