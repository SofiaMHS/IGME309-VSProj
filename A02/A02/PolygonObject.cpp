#include "PolygonObject.h"

PolyObject::PolyObject()
{

	//create an empty array of vertices
	vertices = new float[2 * 3] {}; 
	//create an array for the rgb values of the color
	color = new float[3] {0.0f,0.0f,0.0f}; 
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
	//new x and y values for the new vertex added to vertices
	vertices[vertNum * 2] = x; //mousePos[0]
	vertices[vertNum * 2 + 1] = y;//mousePos[1] 
	//adds one to vertex count
	vertNum++;
}

void PolyObject::setColor(float cr, float cg, float cb)
{
	//sets the color values to the inputs for red, green, and blue
	color[0] = cr;
	color[1] = cg;
	color[2] = cb; 
}

unsigned int PolyObject::getVertNum()
{
	//returns the current number of vertices
	return vertNum;
}

void PolyObject::draw()
{
	//sets the color of the shape to the set color
	glColor3fv(color);

	//loops through the vertices list based on the number of vertices
	for (int i = 0; i < vertNum; i++) {
		//adds the vertex to the shape being drawn 
		glVertex2fv(vertices + i * 2);
	}
}

