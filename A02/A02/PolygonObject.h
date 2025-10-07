#pragma once
#include <vector>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif


using namespace std;

class PolyObject
{
private:
    float* vertices; // all vertices in C++ vector
    float* color;    // color of this polygon
    int vertNum; 
    float mousePos[2];
public:
    PolyObject();
    ~PolyObject();
    void addVertex(float x, float y);            // add vertex at the end of the vertex list
    void setColor(float cr, float cg, float cb); // set the color of this polygon
    unsigned int getVertNum();                   // return the number of vertices
    void draw();                                 // draw the polygon if it’s completed
    void updateMousePos(float x, float y); 
    void polyMenu(int value);
    //need a function to delete vertices - set vertices to nullptr?
};