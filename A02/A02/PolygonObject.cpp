#include "PolygonObject.h"

PolyObject::PolyObject()
{

	//create an empty array of vertices
	vertices = new float[2 * 3] {}; 
	//create an array for the rgb values of the color
	color = new float[3] {1.0f,0.0f,0.0f}; 
	//number of vertices is set to 0 
	vertNum = 0; 
}

PolyObject::~PolyObject()
{
	// dispose vertices
	
	if (vertices != NULL) {
		delete[] vertices;
	}
	// dispose colors
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
	for (int i = 0; i < vertNum; i++) {//adding in odd positions
		glVertex2fv(vertices + i * 2);
	}
	glVertex2fv(mousePos);//can't update mouse position - problem
	
}

void PolyObject::updateMousePos(float x, float y)
{
	mousePos[0] = x;
	mousePos[1] = y; //updates mouse pos, only for +3 vertices? 
}

/*
void PolyObject::clearVertices()
{
	delete[] vertices;
	vertices = nullptr;

	vertices = new float[2 * 3] {};
	vertNum = 0; 
}
*/


