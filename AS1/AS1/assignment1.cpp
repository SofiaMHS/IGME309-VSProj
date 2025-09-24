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
float tris;


void init(void) {

    //set initial variables' values
    screenWidth = 800;
    screenHeight = 800;
    tris = 50;

}

void drawFilledCircle(float red, float green, float blue, float center_x, float center_y, float radius) {

    glColor3f(red, green, blue);
    glBegin(GL_POLYGON);

    for (int i = 0; i <= tris; i++) {
        
        float angle = (float)i / tris * 2.0f * 3.14f;
        glVertex2f(center_x + radius * cos(angle),center_y + radius * sin(angle));
    }
    glEnd();
}


void drawWireframeCircle(float red, float green, float blue, float center_x, float center_y, float radius, float lineWidth) {

    glColor3f(red, green, blue);
    glLineWidth(lineWidth);
    glBegin(GL_LINE_LOOP);

    for (int i = 0; i <= tris; i++) {

        float angle = (float)i / tris * 2.0f * 3.14f;
        glVertex2f(center_x + radius * cos(angle), center_y + radius * sin(angle));
    }
    glEnd();
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
    //drawWireframeCircle(0.33f, 0.23f, 0.09f, screenWidth / 2, screenHeight / 2 - screenWidth / 4, 100.0f, 5.0f);
    //400.0f, 500.0f
    //ears - left
    //drawWireframeCircle(0.24f, 0.13f, 0.06f, 230.0f, 450.0f, 40.0f, 5.0f);
    drawFilledCircle(0.33f, 0.23f, 0.09f, 230.0f, 450.0f, 40.0f);
    drawFilledCircle(0.33f, 0.23f, 0.09f, 190.0f, 450.0f, 40.0f);

    drawFilledCircle(0.33f, 0.23f, 0.09f, 250.0f, 500.0f, 60.0f);
    drawFilledCircle(0.33f, 0.23f, 0.09f, 210.0f, 500.0f, 60.0f);
    //drawWireframeCircle(0.24f, 0.13f, 0.06f, 250.0f, 500.0f, 60.0f, 5.0f);


    drawFilledCircle(0.33f, 0.23f, 0.09f, 270.0f, 550.0f, 80.0f);
    drawFilledCircle(0.33f, 0.23f, 0.09f, 230.0f, 550.0f, 80.0f);
   // drawWireframeCircle(0.24f, 0.13f, 0.06f, 270.0f, 550.0f, 80.0f, 5.0f);
   

    //ears - right
   // drawWireframeCircle(0.24f, 0.13f, 0.06f, 570.0f, 450.0f, 40.0f, 5.0f);
    drawFilledCircle(0.33f, 0.23f, 0.09f, 570.0f, 450.0f, 40.0f);
    drawFilledCircle(0.33f, 0.23f, 0.09f, 610.0f, 450.0f, 40.0f);


    drawFilledCircle(0.33f, 0.23f, 0.09f, 550.0f, 500.0f, 60.0f);
    drawFilledCircle(0.33f, 0.23f, 0.09f, 590.0f, 500.0f, 60.0f);
  //  drawWireframeCircle(0.24f, 0.13f, 0.06f, 550.0f, 500.0f, 60.0f, 5.0f);


    drawFilledCircle(0.33f, 0.23f, 0.09f, 530.0f, 550.0f, 80.0f);
    drawFilledCircle(0.33f, 0.23f, 0.09f, 570.0f, 550.0f, 80.0f);
   // drawWireframeCircle(0.24f, 0.13f, 0.06f, 530.0f, 550.0f, 80.0f, 5.0f);


    //body
    drawWireframeCircle(0.24f, 0.13f, 0.06f, 400.0f, 500.0f, 150.0f, 5.0f);

    drawFilledCircle(0.33f, 0.23f, 0.09f, 400.0f, 300.0f, 200.0f);
    drawWireframeCircle(0.24f, 0.13f, 0.06f, 400.0f, 300.0f, 200.0f, 5.0f);

    drawFilledCircle(0.33f, 0.23f, 0.09f, 400.0f, 500.0f, 150.0f);


    //face - left
    drawFilledCircle(0.0f, 0.0f, 0.0f, 320.0f, 550.0f, 25.0f);
    drawWireframeCircle(1.0f, 1.0f, 1.0f, 320.0f, 550.0f, 25.0f, 5.0f);
    drawFilledCircle(1.0f, 1.0f, 1.0f, 340.0f, 555.0f, 5.0f);

    //face - right
    drawFilledCircle(0.0f, 0.0f, 0.0f, 480.0f, 550.0f, 25.0f);
    drawWireframeCircle(1.0f, 1.0f, 1.0f, 480.0f, 550.0f, 25.0f, 5.0f);
    drawFilledCircle(1.0f, 1.0f, 1.0f, 500.0f, 555.0f, 5.0f);

    drawFilledCircle(0.0f, 0.0f, 0.0f, 400.0f, 500.0f, 25.0f);
    drawFilledCircle(0.0f, 0.0f, 0.0f, 400.0f, 470.0f, 10.0f);

    //left paw - bottom
    drawFilledCircle(0.24f, 0.13f, 0.06f, 220.0f, 180.0f, 80.0f);
    drawFilledCircle(0.0f, 0.0f, 0.0f, 220.0f, 160.0f, 50.0f);
    drawFilledCircle(0.0f, 0.0f, 0.0f, 220.0f, 230.0f, 15.0f);
    drawFilledCircle(0.0f, 0.0f, 0.0f, 190.0f, 220.0f, 15.0f);
    drawFilledCircle(0.0f, 0.0f, 0.0f, 250.0f, 220.0f, 15.0f);

    //left paw - top
    drawFilledCircle(0.24f, 0.13f, 0.06f, 300.0f, 380.0f, 50.0f); 
    drawFilledCircle(0.0f, 0.0f, 0.0f, 300.0f, 360.0f, 25.0f);//-20
    drawFilledCircle(0.0f, 0.0f, 0.0f, 300.0f, 410.0f, 10.0f); //+50
    drawFilledCircle(0.0f, 0.0f, 0.0f, 270.0f, 390.0f, 10.0f);//+40
    drawFilledCircle(0.0f, 0.0f, 0.0f, 330.0f, 390.0f, 10.0f);//+40

    //right paw - bottom
    drawFilledCircle(0.24f, 0.13f, 0.06f, 580.0f, 180.0f, 80.0f);
    drawFilledCircle(0.0f, 0.0f, 0.0f, 580.0f, 160.0f, 50.0f);
    drawFilledCircle(0.0f, 0.0f, 0.0f, 580.0f, 230.0f, 15.0f);
    drawFilledCircle(0.0f, 0.0f, 0.0f, 550.0f, 220.0f, 15.0f);
    drawFilledCircle(0.0f, 0.0f, 0.0f, 610.0f, 220.0f, 15.0f);


    //right paw - top
    drawFilledCircle(0.24f, 0.13f, 0.06f, 500.0f, 380.0f, 50.0f);
    drawFilledCircle(0.0f, 0.0f, 0.0f, 500.0f, 360.0f, 25.0f);//-20
    drawFilledCircle(0.0f, 0.0f, 0.0f, 500.0f, 410.0f, 10.0f); //+50
    drawFilledCircle(0.0f, 0.0f, 0.0f, 470.0f, 390.0f, 10.0f);//+40
    drawFilledCircle(0.0f, 0.0f, 0.0f, 530.0f, 390.0f, 10.0f);//+40

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
