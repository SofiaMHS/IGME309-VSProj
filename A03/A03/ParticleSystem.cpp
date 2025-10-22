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

	//loops through the set of particles
	for (int i = 0; i < numParticles; i++) {
		// Initialize the life times
		lifeTimes[i] = maxLifeTime - maxLifeTime * i / numParticles;
		//initialize the velocities of particles to random numbers between the 
		//max and min x,y,z values
 		velocities[i*3] = getRandomValue(minSpeedX, maxSpeedX);
		velocities[i* 3 + 1] = getRandomValue(minSpeedY, maxSpeedY);
		velocities[i *3 + 2] = getRandomValue(minSpeedZ, maxSpeedZ);

		//initialize the colors of each particle to be blue with full
		//opacity 
		colors[i * 4] = 0.0f;
		colors[i * 4 +1] = 0.0f;
		colors[i * 4 +2] = 1.0f;
		colors[i * 4 +3] = 1.0f;
		//each particle starts at (0,0,0)
		positions[i * 3] = 0.0f; 
		positions[i * 3 + 1] = 0.0f;
		positions[i * 3 + 2] = 0.0f;
	}
}


void ParticleSystem::update(float deltaTime)
{
	
		/***************************/
		//loops through the set of particles
		for (int i = 0; i < numParticles; i++) {
			// Reset particle states (positions, velocities, colors, and lifetimes) when the lifetime reaches the maxLifeTime
			if (lifeTimes[i] < 0) {
				//lifetime is reset to its initial value
				lifeTimes[i] = maxLifeTime - maxLifeTime * i / numParticles;
				//position of the particle is reset to (0,0,0)
				positions[i * 3] = 0.0f;
				positions[i * 3 + 1] = 0.0f;
				positions[i * 3 + 2] = 0.0f;
				//opacity of the particle is reset to full, the rgb value remains the same
				colors[i * 4 + 3] = 1.0f;
				//velocities reset to random values between the max and min x, y, and z values
				velocities[i * 3] = getRandomValue(minSpeedX, maxSpeedX);
				velocities[i * 3 + 1] = getRandomValue(minSpeedY, maxSpeedY);
				velocities[i * 3 + 2] = getRandomValue(minSpeedZ, maxSpeedZ);
			}
			// Update lifetime, velocity, position, and color.
			else {
				//lifetime of the particle is decremented by deltaTime
				lifeTimes[i] -= deltaTime;
				//velocities incremented by the gravitational acceleration vector times deltaTime
				velocities[i * 3] +=  (acceleration[0] * deltaTime);
				velocities[i * 3 + 1] +=  (acceleration[1] * deltaTime);
				velocities[i * 3 + 2] +=  (acceleration[2] * deltaTime);
				//positions are incremented by the new velocity vector times deltaTime
				positions[i * 3] += velocities[i*3]*deltaTime ;
				positions[i * 3 + 1] += velocities[i * 3 + 1] * deltaTime;
				positions[i * 3 + 2] += velocities[i * 3 + 2] * deltaTime;
				//particle's opacity is set to the particle's current lifetime divided by the max lifetime
				colors[i * 4 + 3] = lifeTimes[i] / maxLifeTime;
			}
		}

		/***************************/
}



void ParticleSystem::draw()
{
	/***************************/
	//point size is set to 3
	glPointSize(3.0f); 

	//begins drawing with GL_POINTS
	glBegin(GL_POINTS);

	//loops through the set of particles
	for (int i = 0; i < numParticles; i++) {
		//color of the particle is set
		glColor4f(colors[i * 4], colors[i * 4 + 1], colors[i * 4 + 2], colors[i * 4 + 3]);
		//the particle is drawn at its corresponding position
		glVertex3fv(positions + i * 3); 

		glutPostRedisplay();
	}
	glEnd(); 

	/***************************/
}

float ParticleSystem::getRandomValue(float min_value, float max_value)
{
	return min_value + (std::rand()) / (RAND_MAX / (max_value - min_value));;
}
