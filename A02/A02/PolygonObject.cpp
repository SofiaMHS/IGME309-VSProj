#include "PolygonObject.h"

PolyObject::PolyObject()
{
	//will need to establish vertices 
	//will need to establish colors
	//will need to set vertNum
}

PolyObject::~PolyObject()
{
	//will need to dispose vertices
	//will need to dispose colors
}

void PolyObject::addVertex(float x, float y)
{
	//look at mouse function


	vertices[vertNum * 2 + vertNum - 1] = x; //mousePos[0]
	vertices[vertNum * 2 + vertNum] = y;//mousePos[1]
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
			glVertex2fv(vertices + i * 2);
		glVertex2fv(mousePos);
		glEnd();
	}
	else if (vertNum >= 3) {
		glBegin(GL_POLYGON);
		for (int i = 0; i < vertNum; i++)
			glVertex2fv(vertices + i * 2);
		glEnd();
	}
}
