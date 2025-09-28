#include "MyMesh.h"
#include <GL/freeglut.h>

#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <sstream>
using namespace std;

MyMesh::MyMesh()
{
	vertNum = triNum = 0;
	vertices = NULL;
	indices = NULL;
	vertColors = NULL;
}

MyMesh::~MyMesh()
{
	if (vertices != NULL)
		delete[] vertices;
	if (indices != NULL)
		delete[] indices;

	if (vertColors != NULL)
		delete[] vertColors;
}

void MyMesh::load(char* fileName)
{
	vertNum = 0;
	triNum = 0;

	vertices = new float[100 * 2];
	indices = new unsigned int[100 * 3];
	vertColors = new float[100 * 3];

	ifstream file(fileName);

	//if there is an error opening the file
	if (!file.is_open())
	{
		//an error message is displayed if file can't be opened
		cout << "Error opening file: " << fileName << endl;
	}
	//line and counts created
	string line;

	//counts determine at which index on the vertices and indices array
	//to add data
	int vCount = 0;
	int iCount = 0; 

	//while the file is successfully opened and lines are being read
	while (getline(file, line)) {

		//line streamed and stored through istringstream so that
		//data can be extracted using >>
		istringstream iss(line);
		string type;
		//first section of each line will either be 'v' or 'f'
		//so type string is used to determine how to handle the data
		iss >> type;

		//if the line is a vertex
		if (type == "v") {
			//creates two new float variables, then
			//uses >> to extract the x and y values from
			//the data
			float x;
			float y; 
			iss >> x >> y; 

			//adds the x and y values to the vertices array
			vertices[vCount] = x;
			vertices[vCount + 1] = y;

			//increases vertex count by 1
			vertNum += 1; 
			//increases starting index for vertices array by 2
			vCount += 2;
		}
		//if the line is a face
		else if (type == "f") {

			//creates new int variables, then
			//uses >> to extract the faces from the data
			int v1;
			int v2;
			int v3; 
			iss >> v1 >> v2 >> v3; 
			
			//data is added to the indices, subtract 1
			//to account for .obj indices counted from 1
			indices[iCount] = v1 - 1;
			indices[iCount + 1] = v2 - 1;
			indices[iCount + 2] = v3 - 1;

			//increases tri count by 1
			triNum += 1; 
			//increases starting index for indices array by 3
			iCount += 3;
		}

	}

	// generate random vertex colors
	for (unsigned int i = 0; i < vertNum; i++)
	{
		vertColors[i * 3 + 0] = float(rand()) / (RAND_MAX + 1);
		vertColors[i * 3 + 1] = float(rand()) / (RAND_MAX + 1);
		vertColors[i * 3 + 2] = float(rand()) / (RAND_MAX + 1);
	}
}


void MyMesh::load(const unsigned int p_vertNum, const unsigned int p_triNum, const float* p_vertices, const unsigned int* p_indices)
{
	vertNum = p_vertNum;
	triNum = p_triNum;

	vertices = new float[vertNum * 2];
	indices = new unsigned int[triNum * 3];
	vertColors = new float[vertNum * 3];

	for (unsigned int i = 0; i < vertNum * 2; i++)
	{
		vertices[i] = p_vertices[i];
	}

	for (unsigned int i = 0; i < triNum * 3; i++)
	{
		indices[i] = p_indices[i];
	}

	// generate random vertex colors
	for (unsigned int i = 0; i < vertNum; i++)
	{
		vertColors[i * 3 + 0] = float(rand()) / (RAND_MAX + 1);
		vertColors[i * 3 + 1] = float(rand()) / (RAND_MAX + 1);
		vertColors[i * 3 + 2] = float(rand()) / (RAND_MAX + 1);
	}
}

void MyMesh::update()
{
	// we will use this for transformations later....
}

void MyMesh::draw()
{
	
	for (int i = 0; i < triNum; ++i)
	{
		glBegin(GL_TRIANGLES);
		glColor3fv(vertColors + indices[i * 3 + 0] * 3);
		glVertex2fv(vertices+ indices[i * 3 + 0] * 2);

		glColor3fv(vertColors + indices[i * 3 + 1] * 3);
		glVertex2fv(vertices+ indices[i * 3 + 1] * 2);

		glColor3fv(vertColors + indices[i * 3 + 2] * 3);
		glVertex2fv(vertices +indices[i * 3 + 2] * 2);
		glEnd();
	}
}