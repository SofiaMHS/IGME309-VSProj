#include <GL/glew.h>
#include <GL/freeglut.h>
#include "ParticleSystem.h"
#include <iostream>
#include <sstream>

void ParticleSystem::updateGPU()
{
	glGenBuffers(1, &vboPoints);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboPoints);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * numParticles * 3, positions, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &vboColors);
	glBindBuffer(GL_ARRAY_BUFFER, vboColors);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * numParticles * 4, colors, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glVertexAttribPointer(0, numParticles * 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glVertexAttribPointer(1, numParticles * 4, GL_FLOAT, GL_FALSE, 0, NULL);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	
}

ParticleSystem::ParticleSystem(int _numParticles)
{
	numParticles = _numParticles;	// Set the number of particles
	
	// Allocate memory for positions, velocities, colors, and lifetimes.
	positions = new float[numParticles * 3];
	velocities = new float[numParticles * 3];
	colors = new float[numParticles * 4];	
	lifeTimes = new float[numParticles];

	for (int i = 0; i < numParticles; i++) {
		// Initialize the life times
		lifeTimes[i] = maxLifeTime - maxLifeTime * i / numParticles;
 		velocities[i*3] = getRandomValue(minSpeedX, maxSpeedX);
		velocities[i* 3 + 1] = getRandomValue(minSpeedY, maxSpeedY);
		velocities[i *3 + 2] = getRandomValue(minSpeedZ, maxSpeedZ);
		colors[i * 4] = 1.0f;
		colors[i * 4 +1] = 0.0f;
		colors[i * 4 +2] = 0.0f;
		colors[i * 4 +3] = 1.0f;
		positions[i * 3] = 0.0f; 
		positions[i * 3 + 1] = 0.0f;
		positions[i * 3 + 2] = 0.0f;

		/***************************/
		// Write your code below
		// Please add initializations for other arrays as you see appropriate.
		//look at particles system fields
		//set colors base
		//set positions base
		//set velocities base
		/***************************/
	}
}

ParticleSystem::~ParticleSystem()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vboPoints); 
	glDeleteBuffers(1, &vboColors);
	
}

void ParticleSystem::update(float deltaTime)
{
	
		/***************************/
		// Write your code below
		// Update lifetime, velocity, position, and color.
		// Reset particle states (positions, velocities, colors, and lifetimes) when the lifetime reaches the maxLifeTime
		
		for (int i = 0; i < numParticles; i++) {
			// Initialize the life times
			//if lifeTimes[i] > 5, set to 0 
			if (lifeTimes[i] <= 0) {
				lifeTimes[i] = maxLifeTime - maxLifeTime * i / numParticles;
				positions[i * 3] = 0.0f;
				positions[i * 3 + 1] = 0.0f;
				positions[i * 3 + 2] = 0.0f;
				colors[i * 4 + 3] = 1.0f;				
				velocities[i * 3] = getRandomValue(minSpeedX, maxSpeedX);
				velocities[i * 3 + 1] = getRandomValue(minSpeedY, maxSpeedY);
				velocities[i * 3 + 2] = getRandomValue(minSpeedZ, maxSpeedZ);
			}
			else {
				lifeTimes[i] -= deltaTime;
				velocities[i * 3] +=  (acceleration[0] * deltaTime);
				velocities[i * 3 + 1] +=  (acceleration[1] * deltaTime);
				velocities[i * 3 + 2] +=  (acceleration[2] * deltaTime);
				positions[i * 3] += velocities[i*3]*deltaTime ;
				positions[i * 3 + 1] += velocities[i * 3 + 1] * deltaTime;
				positions[i * 3 + 2] += velocities[i * 3 + 2] * deltaTime;
				colors[i * 4 + 3] = lifeTimes[i] / maxLifeTime;
			}
		}

		//+ (0.5 * acceleration[0] * pow(deltaTime, 2))
		// += acceleration[1] * deltaTime
		// Write your code above
		/***************************/
	
	//updateGPU();
}



void ParticleSystem::draw()
{
	/***************************/
	// Write your code below
	// Use GL_POINTS for rendering
	glPointSize(3.0f); 
	//for loop with numParticles
	//for each, draw particle at position
	//with color
	glBegin(GL_POINTS);
	for (int i = 0; i < numParticles; i++) {

		glColor4f(colors[i * 4], colors[i * 4 + 1], colors[i * 4 + 2], colors[i * 4 + 3]);
	
		glVertex3fv(positions + i * 3); 

		glutPostRedisplay();
	}
	glEnd(); 

  //glBindVertexArray(vao);
  //glDrawArrays(GL_POINTS, 0, numParticles); 
  //glBindVertexArray(vao); 

	/*
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	// Draw shape with buffer data

	//vertex is drawn using the vboVerts data, which contains the data from vertices
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboPoints);
	glVertexPointer(3, GL_FLOAT, 0, NULL);

	//colors are chosen based on the vboColors data, which contains data from vertColors
	glBindBuffer(GL_ARRAY_BUFFER, vboColors);
	glColorPointer(4, GL_FLOAT, 0, NULL);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(vao);
    glDrawArrays(GL_POINTS, 0, numParticles); 
    glBindVertexArray(vao); 


	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	
	// Write your code above
	/***************************/
}

float ParticleSystem::getRandomValue(float min_value, float max_value)
{
	return min_value + (std::rand()) / (RAND_MAX / (max_value - min_value));;
}
