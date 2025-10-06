#include "PolygonObject.h"

PolyObject::PolyObject()
{
	//will need to establish vertices 
	// float v[2 * 3];
	//float color[3];
	//will need to establish colors
	//will need to set vertNum

	vertices = new float[2 * 3] {}; 
	color = new float[3] {1.0f,0.0f,0.0f}; 
	vertNum = 0; 
}

PolyObject::~PolyObject()
{
	//will need to dispose vertices
	//will need to dispose colors
	if (vertices != NULL) {
		delete[] vertices;
	}
	if (vertices != NULL) {
		delete[] color;
	}
}

void PolyObject::addVertex(float x, float y)
{
	//look at mouse function
	mousePos[0] = x;
	mousePos[1] = y;
	vertices[vertNum * 2 + vertNum] = x; //mousePos[0]
	vertices[vertNum * 2 + vertNum + 1] = y;//mousePos[1] 
	vertNum++;


	glutPostRedisplay();
}

void PolyObject::setColor(float cr, float cg, float cb)
{
	//check menu function
	//check display function
}

unsigned int PolyObject::getVertNum()
{
	return vertNum;
}

void PolyObject::draw()
{
	//check display function

	glColor3fv(color);

	if (vertNum == 1) {
		glBegin(GL_POINTS);
		for (int i = 0; i < vertNum; i++) {
			glVertex2fv(vertices + 1 * 2);
		}
		glVertex2fv(mousePos); 
		glEnd(); 
	}
	else if (vertNum == 2) {
		glBegin(GL_LINES);
		for (int i = 0; i < vertNum; i++)
		{
			glVertex2fv(vertices + i * 2);
		}
		glVertex2fv(mousePos);
		glEnd();
	}
	else if (vertNum >= 3) {
		glBegin(GL_POLYGON);
		for (int i = 0; i < vertNum; i++) {
			glVertex2fv(vertices + i * 2);
		}
		glVertex2fv(mousePos);
		glEnd();
	}

}
