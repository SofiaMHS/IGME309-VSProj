
#include <iostream>
#include "PolygonObject.h"
#include <vector>
using namespace std;

float canvasSize[] = { 10.0f, 10.0f };
int rasterSize[] = { 800, 600 };

// structure for storing 3 2D vertices of a triangle
int numOfVertices = 0;
float v[2 * 3];
float color[3];

float mousePos[2];


PolyObject* myObj = new PolyObject();
vector<PolyObject*> completePolygons; 

void init(void)
{
    for (int i = 0; i < 6; i++)
        v[i] = 0.0f;
    mousePos[0] = mousePos[1] = 0.0f;
    color[0] = 1.0f;
    color[1] = color[2] = 0.0f;
}

void drawCursor()
{
    glColor3f(1.0f, 0.0f, 1.0f);
    glPointSize(10.0f);
    glBegin(GL_POINTS);
    glVertex2fv(mousePos);
    glEnd();
    glPointSize(1.0f);
}

void display(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    //glColor3fv(color);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    if (myObj->getVertNum() == 1) {
        glBegin(GL_LINES);
        myObj->draw();
        glEnd();
    }
    else if (myObj->getVertNum() >= 2) {
        glBegin(GL_POLYGON);
        myObj->draw();
        glEnd();
    }

    for (int i = 0; i < completePolygons.size(); i++) {

        PolyObject* obj = completePolygons[i]; 

        if (obj->getVertNum() == 1) {
            glBegin(GL_POINTS);
            obj->draw();
            glEnd();
        }
        else if (obj->getVertNum() == 2) {
            glBegin(GL_LINES);
            obj->draw();
            glEnd();

        }
        else if (obj->getVertNum() >= 3) {
            glBegin(GL_POLYGON);
            obj->draw();
            glEnd();

        }
        glutPostRedisplay();

    }

    drawCursor();
    glutSwapBuffers();

}

void reshape(int w, int h)
{
    rasterSize[0] = w;
    rasterSize[1] = h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, canvasSize[0], 0.0, canvasSize[1]);
    glViewport(0, 0, rasterSize[0], rasterSize[1]);

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mousePos[0] = (float)x / rasterSize[0] * canvasSize[0];
        mousePos[1] = (float)(rasterSize[1] - y) / rasterSize[1] * canvasSize[1];
        myObj->addVertex(mousePos[0], mousePos[1]); 
     
    }
}

void motion(int x, int y)
{
    // mouse events are handled by OS, eventually. When using mouse in the raster window, it assumes top-left is the origin.
    // Note: the raster window created by GLUT assumes bottom-left is the origin.
    mousePos[0] = (float)x / rasterSize[0] * canvasSize[0];
    mousePos[1] = (float)(rasterSize[1] - y) / rasterSize[1] * canvasSize[1];

    myObj->updateMousePos(mousePos[0], mousePos[1]); 

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        exit(0);
        break;

    case 13:
        completePolygons.push_back(myObj); 
        myObj = new PolyObject(); 
        break; 
    }

}

void menu(int value)
{
    switch (value) {
    case 0: // clear
        //somehow clear vertices
        myObj = new PolyObject(); 
        completePolygons.clear(); 
        glutPostRedisplay();
        break;
    case 1: //exit
        exit(0);
    case 2: // red
        //
        myObj->setColor(1.0f, 0.0f, 0.0f); 
        glutPostRedisplay();
        break;
    case 3: // green
        myObj->setColor(0.0f, 1.0f, 0.0f);
        glutPostRedisplay();
        break;
    case 4: // blue
        myObj->setColor(0.0f, 0.0f, 1.0f);
        glutPostRedisplay();
        break;
    default:
        break;
    }
}
void createMenu()
{
    int colorMenu = glutCreateMenu(menu);
    glutAddMenuEntry("Red", 2);
    glutAddMenuEntry("Green", 3);
    glutAddMenuEntry("Blue", 4);

    glutCreateMenu(menu);
    glutAddMenuEntry("Clear", 0);
    glutAddSubMenu("Colors", colorMenu);
    glutAddMenuEntry("Exit", 1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char* argv[])
{
    init();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(rasterSize[0], rasterSize[1]);
    glutCreateWindow("Mouse Event - draw a triangle");


    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutPassiveMotionFunc(motion);
    createMenu();
    glutMainLoop();
    return 0;
}