#include "MyMesh.h"

#include <iostream>
#include <time.h>
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

	// ********************************************************
	// Deletes all GPU buffers attached to the buffer ids
	glDeleteBuffers(1,&vboVerts); 
	glDeleteBuffers(1, &vboColors);
	glDeleteBuffers(1, &iboElems);
	// ********************************************************
}

void MyMesh::load(char* fileName)
{
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

	time_t t;
	srand((unsigned)time(&t));
	for (unsigned int i = 0; i < vertNum; i++)
	{
		vertColors[i * 3 + 0] = float(rand()) / (RAND_MAX + 1);
		vertColors[i * 3 + 1] = float(rand()) / (RAND_MAX + 1);
		vertColors[i * 3 + 2] = float(rand()) / (RAND_MAX + 1);
	}

	// Start creating GPU data.
	createOrUpdateGPU();
}

void MyMesh::createOrUpdateGPU()
{
	// Create buffers

	//1 buffer is generated with the vboVerts id
	glGenBuffers(1, &vboVerts); 
	//new buffer is binded
	glBindBuffer(GL_ARRAY_BUFFER, vboVerts); 
	//upload data to the buffer in the GPU
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertNum * 3, vertices, GL_STATIC_DRAW);
	//clean up the buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	//1 buffer is generated with the vboColors id
	glGenBuffers(1, &vboColors);
	//new buffer is binded
	glBindBuffer(GL_ARRAY_BUFFER, vboColors);
	//upload data to the buffer in the GPU
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertNum * 3, vertColors, GL_STATIC_DRAW);
	//clean up the buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//1 buffer is generated with the vboColors id
	glGenBuffers(1, &iboElems);
	//new buffer is binded
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboElems);
	//upload data to the buffer in the GPU
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * triNum * 3, indices, GL_STATIC_DRAW);
	//clean up the buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void MyMesh::update()
{
	// we will use this for transformations later....
}

void MyMesh::draw()
{
	// Enable fixed-function client states
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	// Draw shape with buffer data

	//vertex is drawn using the vboVerts data, which contains the data from vertices
	glBindBuffer(GL_ARRAY_BUFFER, vboVerts); 
	glVertexPointer(2, GL_FLOAT, 0, NULL);

	//colors are chosen based on the vboColors data, which contains data from vertColors
	glBindBuffer(GL_ARRAY_BUFFER, vboColors);
	glColorPointer(3,GL_FLOAT,0, NULL);

	//indices/elements are drawn using the iboElems buffer, which contains data from indicies
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboElems);
	glDrawElements(GL_TRIANGLES, triNum * 3, GL_UNSIGNED_INT, NULL);

	//clean up buffers used based on type
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}