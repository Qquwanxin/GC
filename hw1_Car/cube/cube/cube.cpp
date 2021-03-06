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
	glRotatef(x, 1.0f, 0.0f, 0.0f);
	glRotatef(y, 0.0f, 1.0f, 0.0f);

	glBegin(GL_POLYGON);
	glColor3f(0.9, 0, 0);
	glVertex3f(20.0f, 20.0f, 20.0f);
	glVertex3f(20.0f, 20.0f, -20.0f);
	glVertex3f(20.0f, -20.0f, -20.0f);
	glVertex3f(20.0f, -20.0f, 20.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.9, 0, 0);
	glVertex3f(-20.0f, 20.0f, 20.0f);
	glVertex3f(-20.0f, 20.0f, -20.0f);
	glVertex3f(-20.0f, -20.0f, -20.0f);
	glVertex3f(-20.0f, -20.0f, 20.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.8, 0, 0);
	glVertex3f(20.0f, 20.0f, 20.0f);
	glVertex3f(20.0f, 20.0f, -20.0f);
	glVertex3f(-20.0f, 20.0f, -20.0f);
	glVertex3f(-20.0f, 20.0f, 20.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.8, 0, 0);
	glVertex3f(20.0f, -20.0f, 20.0f);
	glVertex3f(20.0f, -20.0f, -20.0f);
	glVertex3f(-20.0f, -20.0f, -20.0f);
	glVertex3f(-20.0f, -20.0f, 20.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3f(20.0f, 20.0f, 20.0f);
	glVertex3f(20.0f, -20.0f, 20.0f);
	glVertex3f(-20.0f, -20.0f, 20.0f);
	glVertex3f(-20.0f, 20.0f, 20.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3f(20.0f, 20.0f, -20.0f);
	glVertex3f(20.0f, -20.0f, -20.0f);
	glVertex3f(-20.0f, -20.0f, -20.0f);
	glVertex3f(-20.0f, 20.0f, -20.0f);
	glEnd();

	glPopMatrix();
	glutSwapBuffers();
}

void control(int key, int xa, int ya) {
	if (key == GLUT_KEY_UP)		x -= 6.0f;
	if (key == GLUT_KEY_DOWN)	x += 6.0f;
	if (key == GLUT_KEY_LEFT)	y -= 6.0f;
	if (key == GLUT_KEY_RIGHT)	y += 6.0f;
	glutPostRedisplay();
}
int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("cube");
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100, 100, -100, 100, -100, 100);
	glutSpecialFunc(control);
	glutDisplayFunc(Display);
	glutMainLoop();
	return 0;
}