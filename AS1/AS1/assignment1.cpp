#ifdef __APPLE__
#include <GLUT/glut.h> // include glut for Mac
#else
#include <GL/freeglut.h> //include glut for Windows
#endif

#include <cstdlib>
#include <ctime>
#include <cmath>


//declare initiale variables
int screenWidth;
int screenHeight;


void init(void) {

    //set initial variables' values
    screenWidth = 400;
    screenHeight = 400;

}

void drawFilledCircle(float red, float green, float blue, float center_x, float center_y, float radius) {

    glColor3f(red, green, blue);
    glBegin(GL_POLYGON);

    float tris = 10;

    for (int i = 0; i <= tris; i++) {
        
        float angle = (float)i / tris * 2.0f * 3.14f;
        glVertex2f(center_x + radius * cos(angle),center_y + radius * sin(angle));
    }

}


void drawWireframeCircle(float red, float green, float blue, float center_x, float center_y, float radius, float lineWidth) {

    glColor3f(red, green, blue);
    glBegin(GL_LINE_LOOP);

    float tris = 10;

    for (int i = 0; i <= tris; i++) {

        float angle = (float)i / tris * 2.0f * 3.14f;
        glVertex2f(center_x + radius * cos(angle), center_y + radius * sin(angle));
        glLineWidth(lineWidth);
    }

}

void reshape(int width, int height) {

    //update screen dimensions
    screenWidth = width;
    screenHeight = height;


    // do an orthographic parallel projection, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //use the width and height of the screen to dynamically size objects
    //to fit the new screen sizes
    gluOrtho2D(0.0, width, 0.0, height);

    // tell OpenGL to use the whole window for drawing 
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);

    glutPostRedisplay();


}

// called when the GL context need to be rendered
void display(void)
{
    // clear the screen to white, which is the background color
    glClearColor(1.0, 1.0, 1.0, 0.0);
    // wipe the entire color buffer to the current clear color.
    glClear(GL_COLOR_BUFFER_BIT);

    /*
    glColor3f(1.0f, 0.0f, 0.0f); // red
    glBegin(GL_TRIANGLES);
    //left vertex - x slightly below the origin, y slightly above origin
    glVertex2f(screenWidth / 2 - screenWidth / 4, screenHeight / 2 + screenWidth / 4);
    //right vertex - x slightly above the origin, y slightly above origin
    glVertex2f(screenWidth / 2 + screenWidth / 4, screenHeight / 2 + screenWidth / 4);
    //middle vertex - x at the origin, y slightly below origin
    glVertex2f(screenWidth / 2, screenHeight / 2 - screenWidth / 4);
    */

    //drawFilledCircle(0.0f,0.0f,1.0f, screenWidth / 2, screenHeight / 2 - screenWidth / 4, 200.0f);
    drawWireframeCircle(0.0f, 0.0f, 1.0f, screenWidth / 2, screenHeight / 2 - screenWidth / 4, 100.0f, 50.0f);

    glEnd();

    glutSwapBuffers();

}




int main(int argc, char* argv[])
{
    //call the function to initialize screenWidth and screenHeight to
    //the correct starting proportions
    init();
    //initialize GLUT, let it extract command-line GLUT options that you may provide
    //NOTE that the '&' before argc
    glutInit(&argc, argv);

    // specify as double bufferred can make the display faster
    // Color is speicfied to RGBA, four color channels with Red, Green, Blue and Alpha(depth)
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    // set the initial window size 
    glutInitWindowSize((int)screenWidth, (int)screenHeight);

    //set the initial window size 

    // create the window with a title
    glutCreateWindow("My First Triange");

    //register the function to handle different
    //window sizes
    glutReshapeFunc(reshape);

    //call the display function to draw necessary shapes
    glutDisplayFunc(display);

    //start the glut main loop
    glutMainLoop();

    return 0;
}
