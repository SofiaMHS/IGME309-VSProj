
#include "audio_analyzer.h"
#include <iostream>
#include "sphere.h"
#include "cube.h"
#include "cone.h"
#include "torus.h"
#include "teapot.h"
#include "duck.h"
#include "pumpkin.h"
#include "candyCorn.h"
#include <vector>

// Global audio analyzer
AudioAnalyzer* g_analyzer = nullptr;
AudioFeatures g_currentFeatures;


// Window dimensions
const int WINDOW_WIDTH = 1400;
const int WINDOW_HEIGHT = 800;

// Collection of objects
std::vector<Object*> objects;

// Camera parameters
float cameraAngle = 0.0f;
float cameraDistance = 20.0f;
float cameraHeight = 10.0f;

float prevMag = 0.0f;
float currentMag = 0.0f;

float ambient = 0.0f;
float diffuse = 0.0f;
float specular = 0.0f; 

float rotateX = 0.5f;
float rotateY = 1.0f;
float rotateZ = 0.3f;

void init(){


    // Set background color to dark purple
    glClearColor(0.1f, 0.0f, 0.1f, 1.0f);

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);

    // Enable lighting with more prominent shading
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    // More noticeable lighting for better depth perception
    GLfloat lightPos[] = {5.0f, 5.0f, 5.0f, 1.0f};
    GLfloat lightAmbient[] = { 0.3f, 0.3f, 0.3f, 1.0f };  // Lower ambient for more contrast
    GLfloat lightDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };  // Higher diffuse for clear shading
    GLfloat lightSpecular[] = { 0.2f, 0.2f, 0.2f, 1.0f }; // Some specular for highlights

    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);

    // Enable color material
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    // Set material properties for specular highlights
    GLfloat matSpecular[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    GLfloat matShininess[] = { 32.0f };
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShininess);

    // Create objects in two rows
    float spacing = 4.0f;
    float startX = -14.0f;

    // Top row - GLUT-based shapes
    float topY = 2.0f;


    #pragma region Cones

    //Creation of cone background objects
    Cone* cone1 = new Cone(0.5f, 1.0f, 10, 10);
    cone1->setPosition(startX + spacing * 0.5, topY * 2.4f, 0.0f);
    cone1->setColor(0.0f, 1.0f, 1.0f); // Cyan
    objects.push_back(cone1);

    Cone* cone2 = new Cone(0.5f, 1.0f, 10, 10);
    cone2->setPosition(startX + spacing * 1.5, topY * 1.4f, 5.0f);
    cone2->setColor(0.0f, 0.9f, 0.0f); // Green
    objects.push_back(cone2);

    Cone* cone3 = new Cone(0.5f, 1.0f, 10, 10);
    cone3->setPosition(startX + spacing * 1.5, topY * 1.0f, -7.0f);
    cone3->setColor(1.0f, 0.0f, 1.0f); // Pink
    objects.push_back(cone3);

    Cone* cone4 = new Cone(0.5f, 1.0f, 10, 10);
    cone4->setPosition(startX + spacing * 1.5, topY * 0.4f, 9.0f);
    cone4->setColor(0.0f, 1.0f, 1.0f); // Cyan
    objects.push_back(cone4);

    Cone* cone5 = new Cone(0.5f, 1.0f, 10, 10);
    cone5->setPosition(startX + spacing * 1.5, topY * -2.4f, 4.0f);
    cone5->setColor(1.0f, 0.0f, 1.0f); // Pink
    objects.push_back(cone5);

    Cone* cone6 = new Cone(0.5f, 1.0f, 10, 10);
    cone6->setPosition(startX + spacing * 1.5, topY * 1.8f, -9.0f);
    cone6->setColor(0.0f, 0.9f, 0.0f); // Green
    objects.push_back(cone6);

    Cone* cone7 = new Cone(0.5f, 1.0f, 10, 10);
    cone7->setPosition(startX + spacing * 5.5, topY * 2.4f, 0.0f);
    cone7->setColor(0.0f, 1.0f, 1.0f); // Cyan
    objects.push_back(cone7);

    Cone* cone8 = new Cone(0.5f, 1.0f, 10, 10);
    cone8->setPosition(startX + spacing * 5.5, topY * 1.4f, 5.0f);
    cone8->setColor(0.0f, 1.0f, 1.0f); // Cyan
    objects.push_back(cone8);

    Cone* cone9 = new Cone(0.5f, 1.0f, 10, 10);
    cone9->setPosition(startX + spacing * 5.5, topY * 1.0f, -7.0f);
    cone9->setColor(0.0f, 0.9f, 0.0f); // Green
    objects.push_back(cone9);

    Cone* cone10 = new Cone(0.5f, 1.0f, 10, 10);
    cone10->setPosition(startX + spacing * 5.5, topY * 0.4f, 9.0f);
    cone10->setColor(1.0f, 0.0f, 1.0f); // Pink
    objects.push_back(cone10);

    Cone* cone11 = new Cone(0.5f, 1.0f, 10, 10);
    cone11->setPosition(startX + spacing * 5.5, topY * -2.4f, 4.0f);
    cone11->setColor(0.0f, 0.9f, 0.0f); // Green
    objects.push_back(cone11);

    Cone* cone12 = new Cone(0.5f, 1.0f, 10, 10);
    cone12->setPosition(startX + spacing * 5.5, topY * 1.8f, -9.0f);
    cone12->setColor(0.0f, 1.0f, 1.0f); // Cyan
    objects.push_back(cone12);
    #pragma endregion

    #pragma region Cubes

    //Creation of cube background objects
    Cube* cube1 = new Cube(0.5f);
    cube1->setPosition(startX + spacing * 0.5, topY * -2.0f, 0.0f);
    cube1->setColor(0.0f, 1.0f, 1.0f); // Cyan
    objects.push_back(cube1);

    Cube* cube2 = new Cube(0.5f);
    cube2->setPosition(startX + spacing * 1.2, topY * -2.0f, 5.0f);
    cube2->setColor(1.0f, 0.0f, 1.0f); // Pink
    objects.push_back(cube2);

    Cube* cube3 = new Cube(0.5f);
    cube3->setPosition(startX + spacing * 1.2, topY * -2.0f, -7.0f);
    cube3->setColor(0.0f, 0.9f, 0.0f); // Green
    objects.push_back(cube3);

    Cube* cube4 = new Cube(0.5f);
    cube4->setPosition(startX + spacing * 1.2, topY * 1.3f, -4.0f);
    cube4->setColor(0.0f, 1.0f, 1.0f); // Cyan
    objects.push_back(cube4);

    Cube* cube5 = new Cube(0.5f);
    cube5->setPosition(startX + spacing * 1.2, topY * -0.4f, 8.0f);
    cube5->setColor(1.0f, 0.0f, 1.0f); // Pink
    objects.push_back(cube5);

    Cube* cube6 = new Cube(0.5f);
    cube6->setPosition(startX + spacing * 1.2, topY * 2.4f, -9.0f);
    cube6->setColor(0.0f, 0.9f, 0.0f); // Green
    objects.push_back(cube6);

    Cube* cube7 = new Cube(0.5f);
    cube7->setPosition(startX + spacing * 5.5, topY * 1.7f, 7.0f);
    cube7->setColor(0.0f, 1.0f, 1.0f); // Cyan
    objects.push_back(cube7);

    Cube* cube8 = new Cube(0.5f);
    cube8->setPosition(startX + spacing * 5.5, topY * 1.0f, -8.0f);
    cube8->setColor(0.0f, 0.9f, 0.0f); // Green
    objects.push_back(cube8);

    Cube* cube9 = new Cube(0.5f);
    cube9->setPosition(startX + spacing * 5.5, topY * 1.5f, 6.0f);
    cube9->setColor(1.0f, 0.0f, 1.0f); // Pink
    objects.push_back(cube9);

    Cube* cube10 = new Cube(0.5f);
    cube10->setPosition(startX + spacing * 5.5, topY * 2.0f, 8.0f);
    cube10->setColor(0.0f, 0.9f, 0.0f); // Green
    objects.push_back(cube10);

    Cube* cube11 = new Cube(0.5f);
    cube11->setPosition(startX + spacing * 5.5, topY * -2.2f, -9.0f);
    cube11->setColor(0.0f, 1.0f, 1.0f); // Cyan
    objects.push_back(cube11);

    Cube* cube12 = new Cube(0.5f);
    cube12->setPosition(startX + spacing * 5.5, topY * -1.6f, 4.0f);
    cube12->setColor(1.0f, 0.0f, 1.0f); // Pink
    objects.push_back(cube12);


    #pragma endregion
   
    //Creation of candy corn objects to the left and right of the pumpk
    CandyCorn* candyCorn1 = new CandyCorn(1.5f);
    candyCorn1->setPosition(startX + spacing * 5, topY, 0.0f);
    objects.push_back(candyCorn1);

    CandyCorn* candyCorn2 = new CandyCorn(1.5f);
    candyCorn2->setPosition(startX + spacing * 2, topY, 0.0f);
    objects.push_back(candyCorn2);

    //Creation of pumpkin object in the center of the screen
    Pumpkin* pumpkin = new Pumpkin(1.5f);
    pumpkin->setPosition(startX + spacing * 3.5, topY, 0.0f);
    objects.push_back(pumpkin);

}


void onAudioFeaturesUpdated(const AudioFeatures& features)
{
    g_currentFeatures = features;

}

//called when audio is registered as active based on pitch
void onSpectrumChange(std::vector<float> spectrum) {
    //local variable for average energy 
    float avgEnergy = 0.0f;

    //loop through spectrum bins to get the average energy 
    for (int i = 0; i < spectrum.size(); i++) {

        //add the current frequency to the average
        avgEnergy += spectrum[i];

    }
    //divide the average by the size of the vector
    avgEnergy /= spectrum.size();

    //if the average energy is greater than 0.5, and has not reached the threshold 
    if (avgEnergy > 0.3f && rotateX < 3.0f && rotateY < 3.0f && rotateZ < 3.0f)
    {
        //increment the rotational values positively 
        rotateX += 0.2f;
        rotateY += 0.1f;
        rotateZ += 0.3f;


    }
    //if the average energy is less than 0.5, and has not reached the threshold 
    if (avgEnergy < 0.3f && rotateX > -3.0f && rotateY > -3.0f && rotateZ > -3.0f)
    {
        //increment the rotational values positively
        rotateX -= 0.2f;
        rotateY -= 0.1f;
        rotateZ -= 0.3f;
    }
}

//called when audio is registered as active based on pitch
void onWaveformChange(std::vector<float> waveform) {
    //creation position and increment local variables
    float posX;
    float posY;
    float posZ;
    float yIncrement;

    //loop through the waveform array
    for (int i = 0; i < waveform.size(); i++)
    {
        //nested loop of objects array
        for (size_t i = 0; i < objects.size(); i++) {

            //set y increment to the current waveform value multipled by 10
            yIncrement = waveform[i] * 10.0f;

            //get the position of the current object
            objects[i]->getPosition(posX, posY, posZ);

            //if the y increment is greater than 0
            if (yIncrement > 0.0f) {
                //set y increment to positive
                yIncrement = 0.2f;
            }
            //if the y increment is less than 0
            else if (yIncrement < 0.0f) {
                //set y increment to negative
                yIncrement = -0.2f;
            }

            //add y increment divided by 1000 to y position
            posY += yIncrement / 1000.0f;

            //check if the y value is within the boundaries of the world
            if (posY > -5.0f && posY < 5.0f) {
                //set the new position of the object
                objects[i]->setPosition(posX, posY, posZ);
            }
        }
    }
}

//Called when magnitude (volume) changes significantly
void onMagnitudeChange(float magnitude)
{
    //local values to store the scale
    float scaleX = 0.0f;
    float scaleY = 0.0f;
    float scaleZ = 0.0f;

    //local value to store the size increment
    float sizeIncrement = 0.0f;

    //get the current magnitude
    currentMag = magnitude;

    //if current magnitude is greater than the previous
    //magnitude, increase the size increment
    if (currentMag > prevMag) {
        sizeIncrement += 0.1f;
    }

    //if current magnitude is less than the previous
    //magnitude, decrease the size increment
    if (currentMag < prevMag) {
        sizeIncrement -= 0.1f;

    }

    //for each object in the list
    for (size_t i = 0; i < objects.size(); i++)
    {
        //get the current scale and set the values of 
        //local variables to that scale
        objects[i]->getScale(scaleX, scaleY, scaleZ);

        //add the size increment to each scale
        scaleX = scaleY = scaleZ += sizeIncrement;

        //if the scale has not reached either the 
        //positive or negative threshold
        if (scaleX > -1.0f && scaleX < 1.0f) {
            //the new scale is set uniformly to each object
            objects[i]->setUniformScale(scaleX);
        }

    }

    //store the current magnitude in the previous magnitude
    //variable for testing later
    prevMag = currentMag;

}



// ============================================================================
// OPENGL VISUALIZATION FUNCTIONS
// ============================================================================

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // ***********************************************************************

    // Position camera in a circular path
    float camX = cameraDistance * sin(cameraAngle * 3.14159f / 180.0f);
    float camZ = cameraDistance * cos(cameraAngle * 3.14159f / 180.0f);

    gluLookAt(camX, cameraHeight, camZ, // Eye position
        0.0, 0.0, 0.0,            // Look at point
        0.0, 1.0, 0.0);           // Up vector

    // Draw all objects
    for (size_t i = 0; i < objects.size(); i++)
    {
        objects[i]->render();
    }


    // ***********************************************************************

    glutSwapBuffers();
}

/**
 * Called continuously - use for animations
 */
void idle()
{


    #pragma region Audio Feature Processing DO NOT REMOVE
    // Update callbacks based on current features
    static float lastMagnitude = 0.0f;
    if (std::abs(g_currentFeatures.magnitude - lastMagnitude) > 0.05f)
    {
        onMagnitudeChange(g_currentFeatures.magnitude);

        lastMagnitude = g_currentFeatures.magnitude;
    }
    if (g_currentFeatures.pitch > 50.0f) {
        onWaveformChange(g_currentFeatures.waveform);

        onSpectrumChange(g_currentFeatures.spectrum);
    }
   

    #pragma endregion

    glutPostRedisplay();
}


void update(int value)
{
    // Rotate the camera around the scene
    cameraAngle += 0.3f;

    if (cameraAngle > 360.0f)
    {
        cameraAngle -= 360.0f;
    }

    // Rotate each object around its own axis
    for (size_t i = 0; i < objects.size(); i++)
    {
        //rotate using values altered by audio visualizer

        //Mode 1: rotate the objects using different values for 
        //each axis
        objects[i]->rotate(rotateX, rotateY, rotateZ);

        //Mode 2: rotate the objects using the same values for
        // each axis
       //objects[i]->rotate(rotateX, rotateX, rotateX);

    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // ~60 FPS
}


//Handle window resizing
void reshape(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0, (double)w / (double)h, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
}


//Handle keyboard input
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27: // ESC
    case 'q':
    case 'Q':
        if (g_analyzer)
        {
            g_analyzer->stop();
            delete g_analyzer;
        }
        exit(0);
        break;
    }
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================
int main(int argc, char** argv)
{
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("IGME 309 Final Project - Audio Visualizer");

    // OpenGL setup
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glLineWidth(2.0f);

    // Mode 2: file mode.
    // WAV file only.
    //audio file used in calculation 
    g_analyzer = new AudioAnalyzer("softFuzzyMan.wav");

    g_analyzer->setAudioCallback(onAudioFeaturesUpdated);

    if (!g_analyzer->start())
    {
        std::cerr << "Failed to start audio analyzer!" << std::endl;
        delete g_analyzer;
        return 1;
    }

    //initialize models and lighting effects
    init();

    // Register GLUT callbacks
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, update, 0);


    // Start main loop
    glutMainLoop();

    // Cleanup
    delete g_analyzer;
    return 0;
}
