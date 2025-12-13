#include <GL/freeglut.h>
#include "audio_analyzer.h"
#include <iostream>
#include "sphere.h"
#include "cube.h"
#include "cone.h"
#include "torus.h"
#include "teapot.h"
#include "duck.h"
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
float cameraHeight = 5.0f;

void init(){


    // Set background color to dark gray
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);

    // Enable lighting with more prominent shading
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    // More noticeable lighting for better depth perception
    GLfloat lightPos[] = { 5.0f, 5.0f, 5.0f, 1.0f };
    GLfloat lightAmbient[] = { 0.3f, 0.3f, 0.3f, 1.0f };  // Lower ambient for more contrast
    GLfloat lightDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };  // Higher diffuse for clear shading
    GLfloat lightSpecular[] = { 0.5f, 0.5f, 0.5f, 1.0f }; // Some specular for highlights

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

    // Sphere
    Sphere* sphere = new Sphere(1.2f, 30, 30);
    sphere->setPosition(startX, topY, 0.0f);
    sphere->setColor(1.0f, 0.3f, 0.3f); // Red
    objects.push_back(sphere);

    // Cube
    Cube* cube = new Cube(2.0f);
    cube->setPosition(startX + spacing, topY, 0.0f);
    cube->setColor(0.3f, 1.0f, 0.3f); // Green
    objects.push_back(cube);

    // Cone
    Cone* cone = new Cone(1.2f, 2.5f, 30, 30);
    cone->setPosition(startX + spacing * 2, topY, 0.0f);
    cone->setColor(0.3f, 0.3f, 1.0f); // Blue
    objects.push_back(cone);

    // Torus
    Torus* torus = new Torus(0.4f, 1.2f, 30, 30);
    torus->setPosition(startX + spacing * 3, topY, 0.0f);
    torus->setColor(1.0f, 1.0f, 0.3f); // Yellow
    objects.push_back(torus);

    // Teapot
    Teapot* teapot = new Teapot(1.2f);
    teapot->setPosition(startX + spacing * 4, topY, 0.0f);
    teapot->setColor(1.0f, 0.3f, 1.0f); // Magenta
    objects.push_back(teapot);

    // Duck (complex shape) - positioned in center
    Duck* duck = new Duck(1.5f);
    duck->setPosition(0.0f, -2.0f, 0.0f);
    duck->setColor(1.0f, 0.9f, 0.3f); // Yellow
    objects.push_back(duck);

}

void onAudioFeaturesUpdated(const AudioFeatures& features)
{
    g_currentFeatures = features;

    // TODO: Add your own audio-reactive logic here

    // Example: Print when loud sound detected
    if (features.magnitude > 0.5f)
    {
        // std::cout << "Loud sound detected! Magnitude: " << features.magnitude << std::endl;
    }
}

/**
 * Called when magnitude (volume) changes significantly
 */
void onMagnitudeChange(float magnitude)
{
    // TODO: Implement volume-reactive visualizations
}

/**
 * Called when pitch is detected
 */
void onPitchDetected(float pitch)
{
    // TODO: Map pitch to visual properties
}

/**
 * Called when spectral centroid changes (brightness of sound)
 */
void onSpectralCentroidChange(float centroid)
{
    // TODO: Use spectral centroid for brightness effects
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
    // ---- EXAMPLE VISUALIZATION (Replace with your own!) ----

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

    glutSwapBuffers();

    // ***********************************************************************

    glutSwapBuffers();
}

/**
 * Called continuously - use for animations
 */
void idle()
{
    // ***********************************************************************
    // You might want to do animation here.
    // 
    // ***********************************************************************

    #pragma region Audio Feature Processing DO NOT REMOVE
    // Update callbacks based on current features
    static float lastMagnitude = 0.0f;
    if (std::abs(g_currentFeatures.magnitude - lastMagnitude) > 0.05f)
    {
        onMagnitudeChange(g_currentFeatures.magnitude);
        lastMagnitude = g_currentFeatures.magnitude;
    }

    if (g_currentFeatures.pitch > 50.0f)
    { // Valid pitch range
        onPitchDetected(g_currentFeatures.pitch);
    }

    if (g_currentFeatures.spectralCentroid > 0.0f)
    {
        onSpectralCentroidChange(g_currentFeatures.spectralCentroid);
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
        objects[i]->rotate(0.5f, 1.0f, 0.3f);
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // ~60 FPS
}

/**
 * Handle window resizing
 */
void reshape(int w, int h)
{
    /*
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);*/
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0, (double)w / (double)h, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

/**
 * Handle keyboard input
 */
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

        // Optional: Add more keyboard controls
        // Example: Different visualization modes, color schemes, etc.
    case '1':
        std::cout << "Mode 1 selected" << std::endl;
        break;
    case '2':
        std::cout << "Mode 2 selected" << std::endl;
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

    // Initialize audio analyzer
    // Mode 1: microphone mode (recommended)
    //g_analyzer = new AudioAnalyzer(44100, 1024);
    //
    // Mode 2: file mode.
    // WAV file only.
    g_analyzer = new AudioAnalyzer("jingle_bells.wav");

    g_analyzer->setAudioCallback(onAudioFeaturesUpdated);

    if (!g_analyzer->start())
    {
        std::cerr << "Failed to start audio analyzer!" << std::endl;
        delete g_analyzer;
        return 1;
    }

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
