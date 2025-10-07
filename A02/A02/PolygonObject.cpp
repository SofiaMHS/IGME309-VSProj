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
	vertices[vertNum * 2] = x; //mousePos[0]
	vertices[vertNum * 2 + 1] = y;//mousePos[1] 
	vertNum++;


	glutPostRedisplay();
}

void PolyObject::setColor(float cr, float cg, float cb)
{
	//check menu function
	//check display function
	color[0] = cr;
	color[1] = cg;
	color[2] = cb; 
}

unsigned int PolyObject::getVertNum()
{
	//could clear vertNum here
	//ex. vertNum = 0
	return vertNum;
}

void PolyObject::draw()
{
	//check display function

	glColor3fv(color);

	if (vertNum == 0) {
		glBegin(GL_POINTS);
		for (int i = 0; i < vertNum; i++) {
			glVertex2fv(vertices + 1 * 2);
		}
		glVertex2fv(mousePos); //can't update mouse position - problem
		glEnd(); 
	}
	else if (vertNum == 1) {
		glBegin(GL_LINES);
		for (int i = 0; i < vertNum; i++)
		{
			glVertex2fv(vertices + i * 2);
		}
		glVertex2fv(mousePos);//can't update mouse position - problem
		glEnd();
	}
	else if (vertNum >= 2) {
		glBegin(GL_POLYGON);
		for (int i = 0; i < vertNum; i++) {//adding in odd positions
			glVertex2fv(vertices + i * 2);
		}
		glVertex2fv(mousePos);//can't update mouse position - problem
		glEnd();
	}

}

void PolyObject::updateMousePos(float x, float y)
{
	mousePos[0] = x;
	mousePos[1] = y; //updates mouse pos, only for +3 vertices? 
}

void PolyObject::polyMenu(int value)
{
	switch (value) {
	case 0: // clear
		vertNum = 0; 
		glutPostRedisplay();
		break;
	case 1: //exit
		exit(0);
	case 2: // red
		//
		setColor(1.0f, 0.0f, 0.0f); 
		glutPostRedisplay();
		break;
	case 3: // green
		setColor(0.0f, 1.0f, 0.0f);
		glutPostRedisplay();
		break;
	case 4: // blue
		setColor(0.0f, 0.0f, 1.0f);
		glutPostRedisplay();
		break;
	default:
		break;
	}
}
