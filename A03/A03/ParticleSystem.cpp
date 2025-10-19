#include <GL/glew.h>
#include <GL/freeglut.h>
#include "ParticleSystem.h"
#include <iostream>
#include <sstream>

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

void ParticleSystem::update(float deltaTime)
{
	for (int i = 0; i < numParticles; i++) {
		/***************************/
		// Write your code below
		// Update lifetime, velocity, position, and color.
		// Reset particle states (positions, velocities, colors, and lifetimes) when the lifetime reaches the maxLifeTime
		
		for (int i = 0; i < numParticles; i++) {
			// Initialize the life times
			//if lifeTimes[i] > 5, set to 0 
			if (lifeTimes[i] <= 0) {
				lifeTimes[i] = 0; 
				positions[i*3] = 0; 
				colors[3] = 1; 
				velocities[i * 3] = 0; 
			}
			else {
				lifeTimes[i] -= deltaTime;
				velocities[i * 3] += acceleration[1] * deltaTime;
				velocities[i * 3 + 1] += acceleration[1] * deltaTime;
				velocities[i * 3 + 2] += acceleration[1] * deltaTime;
				positions[i * 3] += velocities[i*3]*deltaTime;
				positions[i * 3 + 1] += velocities[i * 3 + 1] * deltaTime;
				positions[i * 3 + 2] += velocities[i * 3 + 2] * deltaTime;
				colors[i * 4 + 3] -= 0.1; 
			}
		}

		//+ (0.5 * -9.8f * pow(deltaTime, 2))
		// Write your code above
		/***************************/
	}
}

void ParticleSystem::draw()
{
	/***************************/
	// Write your code below
	// Use GL_POINTS for rendering
	glPointSize(10.0f); 
	glBegin(GL_POINTS);

	//for loop with numParticles
	//for each, draw particle at position
	//with color
	for (int i = 0; i < numParticles; i++) {
		glVertex3fv(positions + i * 3); 
	}
	glEnd(); 

	glutPostRedisplay(); 
	
	// Write your code above
	/***************************/
}

float ParticleSystem::getRandomValue(float min_value, float max_value)
{
	return min_value + (std::rand()) / (RAND_MAX / (max_value - min_value));;
}
