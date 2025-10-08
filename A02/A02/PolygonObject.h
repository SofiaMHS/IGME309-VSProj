#pragma once
#include <vector>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include <vector>
using namespace std;

class PolyObject
{
private:
    float* vertices; // all vertices in the polygon
    float* color;    // color of this polygon
    int vertNum;     // number of vertices in the polygon
public:
    PolyObject();                                // object constructor
    ~PolyObject();                               // object destructor
    void addVertex(float x, float y);            // add a vertex to the end of vertices array pointer
    void setColor(float cr, float cg, float cb); // set the rgb color of the current shape
    unsigned int getVertNum();                   // returns the number of vertices
    void draw();                                 // draws the current polygon

};