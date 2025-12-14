#ifndef PUMPKIN_H
#define PUMPKIN_H 

#include "object.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Pumpkin : public Object
{
private:
    float size;

public:
    // Constructor
    Pumpkin(float s = 1.0f) : Object(), size(s) {}

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

        //Pumpkin Body
        glPushMatrix();
        glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
        glTranslatef(0.0f, -0.3f * size, 0.0f);
        glScalef(1.3f, 1.3f, 1.3f); 
        glutSolidSphere(size, 30, 30);
        glPopMatrix();

        //Pumpkin Stem
        glPushMatrix();
        glColor4f(0.5f, 0.5f, 0.0f, 1.0f);
        glTranslatef(0.0f, 1.2f * size, 0.0f);
        glutSolidCube(size * 0.5f);
        glPopMatrix();

        //Pumpkin Eye 1
        glPushMatrix();
        glColor4f(0.1f, 0.0f, 0.0f, 1.0f);
        glTranslatef(0.45f * size, 0.3f * size, 1.0f*size);
        glRotatef(-90, 1.0f, 0.0f, 0.0f); // Point forward along X-axis
        glScalef(1.0f, 0.6f, 0.6f);      // Flatten it a bit
        glutSolidCone(0.2f * size, 0.5f * size, 10, 10);
        glPopMatrix();

        //Pumpkin Eye 1
        glPushMatrix();
        glTranslatef(-0.2f * size, 0.3f * size, 1.2f * size);
        glRotatef(-90, 1.0f, 0.0f, 0.0f); // Point forward along X-axis
        glScalef(1.0f, 0.6f, 0.6f);      // Flatten it a bit
        glutSolidCone(0.2f * size, 0.5f * size, 10, 10);
        glPopMatrix();

        //Pumpkin Mouth 
        glPushMatrix();
        glTranslatef(0.2f * size, -0.3f * size, 1.1f * size);
        glRotatef(90, 1.0f, 0.0f, 0.0f); // Point forward along X-axis
        glScalef(1.5f, 0.6f, 0.6f);      // Flatten it a bit
        glutSolidCone(0.6f * size, 0.8f * size, 30, 30);
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

#endif // PUMPKIN_H
