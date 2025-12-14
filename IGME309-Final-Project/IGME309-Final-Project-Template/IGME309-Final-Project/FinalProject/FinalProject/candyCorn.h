#ifndef CANDYCORN_H
#define CANDYCORN_H 

#include "object.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class CandyCorn : public Object
{
private:
    float size;

public:
    // Constructor
    CandyCorn(float s = 1.0f) : Object(), size(s) {}

    // Set duck size
    void setSize(float s)
    {
        size = s;
    }

    float getSize() const // Const member function.
    {
        return size;
    }

    // Implement the draw method using GLUT primitives
    // This function overrides a virtual function from the base class.
    void draw() override
    {

        //Bottom of Candy Corn
        glPushMatrix();
        glColor4f(1.0f, 0.8f, 0.0f, 1.0f);//set the color to yellow
        glTranslatef(0.0f, -0.3f * size, 0.0f);
        glRotatef(-90, 1.0f, 0.0f, 0.0f); // Point forward along X-axis
        glScalef(0.8f, 0.8f, 1.3f);//scale the cone up
        glutSolidCone(1.4f * size, 1.5f * size, 30, 30);//set the base to be larger than the middle and top
        glPopMatrix();

        //Middle of Candy Corn
        glPushMatrix();
        glColor4f(1.0f, 0.2f, 0.0f, 1.0f);//set the color to orange
        glTranslatef(0.0f, 0.3f * size, 0.0f);
        glRotatef(-90, 1.0f, 0.0f, 0.0f); // Point forward along X-axis
        glScalef(1.0f, 1.0f, 1.3f);//scale the cone up 
        glutSolidCone(0.8f * size, 1.0f * size, 30, 30);//set the base to be the same as the top
        glPopMatrix();

        //Top of Candy Corn
        glPushMatrix();
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);//set the color to white
        glTranslatef(0.0f, 0.5f * size, 0.0f);
        glRotatef(-90, 1.0f, 0.0f, 0.0f); // Point forward along X-axis
        glScalef(0.8f, 0.8f, 1.3f);//scale the cone up 
        glutSolidCone(0.8f * size, 1.0f * size, 30, 30);//set the base to be the same as the middle
        glPopMatrix();

    }

    // Optional: wireframe version
    void drawWireframe()
    {
        applyTransformations();
        glutWireSphere(size, 12, 12);
        unapplyTransformations();
    }
};

#endif // CANDYCORN_H
