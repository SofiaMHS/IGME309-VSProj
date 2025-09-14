#ifdef __APPLE__
#include <GLUT/glut.h> // include glut for Mac
#else
#include <GL/freeglut.h> //include glut for Windows
#endif



int screenWidth;
int screenHeight;


void init(void) {

    screenWidth = 400;
    screenHeight = 400;

}



void reshape(int width, int height) {

    //update screen dimensions
    screenWidth = width;
    screenHeight = height;


    // do an orthographic parallel projection, limited by screen/window size
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0, 1.0, 0.0, 1.0);

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

    // Default coordinate bounds
    // x range: –1.0 (left) to +1.0 (right)
    // y range: –1.0 (bottom) to +1.0 (top)
    // z range: –1.0 (near) to +1.0 (far)

    glColor3f(1.0f, 0.0f, 0.0f); // red
    glBegin(GL_TRIANGLES);
    //left vertex
    glVertex2f(screenWidth / 2 -0.5f, screenHeight / 2 + 0.5f);

    //right vertex
    glVertex2f(screenWidth / 2 + 0.5f, screenHeight / 2 + 0.5f);

    //middle vertex
    glVertex2f(screenWidth/2, screenHeight / 2 -0.5f);


    glEnd();

    glutSwapBuffers();

}




int main(int argc, char* argv[])
{
    //initialize GLUT, let it extract command-line GLUT options that you may provide
    //NOTE that the '&' before argc
   // init(); 
    glutInit(&argc, argv);

    // specify as double bufferred can make the display faster
    // Color is speicfied to RGBA, four color channels with Red, Green, Blue and Alpha(depth)
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    // set the initial window size 


    glutInitWindowSize((int)screenWidth, (int)screenHeight);

    //set the initial window size 
    //glutInitWindowSize(400, 400);

    // create the window with a title
    glutCreateWindow("My First Triange");

   
    //glutReshapeFunc(reshape);

    glutDisplayFunc(display);
    // register function to handle window resizes

    //start the glut main loop
    glutMainLoop();

    return 0;
}
