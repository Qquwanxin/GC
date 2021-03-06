#include "pch.h"
#include <windows.h>
#include<GL/GL.h> 
#include<GL/glut.h>
#include <math.h> 
static GLfloat x = 0.0f;
static GLfloat y = 0.0f;

void Display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex2f(100.0f, -85.0f);
	glVertex2f(0.0f, 85.0f);
	glVertex2f(-100.0f, -85.0f);
	glEnd();

	glPopMatrix();
	glutSwapBuffers();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutCreateWindow("triangle");
	glOrtho(-100, 100, -100, 100, -100, 100);
	glutDisplayFunc(Display);
	glutMainLoop();
	return 0;
}