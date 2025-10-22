IGME 309  
Sofia Murphy  
Assignment 03  
10/22/2025

	For this assignment, I mainly worked in the ParticleSystem class, in order to create methods which would spawn and continuously reset an array of particles, in order to create a fountain-like effect. In order to accomplish this, I first needed to initialize all the variables necessary for creating the needed particles. This included filling out multiple arrays which would be utilized in the particle configuration and display.   
The first of these arrays was the positions array. This array contains the x, y, and z coordinates of all the particles in the project. Initializing this array was simple, since each particle would start at (0,0,0).   
	The next array I would need to fill was the velocities array, which contains the x, y, and z velocities of each particle. For this array, the velocities would all be randomized, so I called the ParticleSystem’s getRandomValue to generate random values between the maximum and minimum x, y, and z values.   
	Finally, in order to fill out the colors array, which contains the rgba values of each color, I simply set the rgb values to the color I needed, and then set the a value to be one by default.   
	The next method I needed to establish was the update method. Here, I looped through each particle, checking if its lifetime had reached 0\. If it had, its position, velocity, and color would be reset to their initial values, and the particle’s lifespan would be reset as well. If the lifetime had not reached 0, then the lifespan would be decreased by the deltaTime, and its velocity would be incremented based on the gravitational acceleration multiplied by the deltaTime. The position would then add the new velocity multiplied by the deltaTime. Finally, the particle’s alpha value would be reduced by the deltaTime.   
	The final method I needed to complete was the draw method. Here, I set the point size, which would apply to each particle generated in the program. I would then call the method glBegin(), and use GL\_POINTS as the geometric primitive. Then, I would loop through each particle, utilizing its position as the vertex, and setting the color accordingly. With this, my particle system would spawn and reuse an arbitrary number of particles to produce a continuous water-fountain effect. 

**Performance Analysis**

500 Particles  
Approximate Average FPS: 4500

5000 Particles  
Approximate Average FPS: 3500

50000 Particles  
Approximate Average FPS: 995

500000 Particles  
Approximate Average FPS: 105

5000000 Particles  
Approximate Average FPS: 9

	