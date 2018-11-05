﻿#include <windows.h>
#include<GL/GL.h> 
#include<GL/glut.h>
#include <math.h> 
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

void Display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();	
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);//绕x轴旋转  	
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);//绕y轴旋转  	

	//车下半部  
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex3f(-40.0f, 0.0f, 15.0f);
	glVertex3f(40.0f, 0.0f, 15.0f);

	glColor3f(1, 1, 0);
	glVertex3f(40.0f, -15.0f, 15.0f);
	glVertex3f(-40.0f, -15.0f, 15.0f);

	glEnd();
	glBegin(GL_POLYGON);

	glColor3f(0.3, 0.2, 0.5);
	glVertex3f(40.0f, 0.0f, -15.0f);
	glVertex3f(40.0f, 0.0f, 15.0f);
	glVertex3f(40.0f, -15.0f, 15.0f);
	glVertex3f(40.0f, -15.0f, -15.0f);
	glEnd();
	glBegin(GL_POLYGON);

	glColor3f(0.3, 0.1, 0.3);
	glVertex3f(-40.0f, 0.0f, -15.0f);
	glVertex3f(-40.0f, 0.0f, 15.0f);
	glVertex3f(-40.0f, -15.0f, 15.0f);
	glVertex3f(-40.0f, -15.0f, -15.0f);

	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.8);
	glVertex3f(-40.0f, 0.0f, -15.0f);
	glVertex3f(40.0f, 0.0f, -15.0f);

	glColor3f(1, 0.5, 0.8);
	glVertex3f(40.0f, -15.0f, -15.0f);
	glVertex3f(-40.0f, -15.0f, -15.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex3f(-40.0f, 0.0f, 15.0f);
	glVertex3f(-40.0f, 0.0f, -15.0f);
	glVertex3f(40.0f, 0.0f, -15.0f);
	glVertex3f(40.0f, 0.0f, 15.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.5, 0.2);
	glVertex3f(-40.0f, -15.0f, 15.0f);
	glVertex3f(-40.0f, -15.0f, -15.0f);
	glVertex3f(40.0f, -15.0f, -15.0f);
	glVertex3f(40.0f, -15.0f, 15.0f);
	glEnd();
	//车上半部  	
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex3f(-20.0f, 0.0f, 15.0f);
	glVertex3f(-10.0f, 10.0f, 15.0f);
	glVertex3f(20.0f, 10.0f, 15.0f);
	glVertex3f(25.0f, 0.0f, 15.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex3f(-20.0f, 0.0f, -15.0f);
	glVertex3f(-10.0f, 10.0f, -15.0f);
	glVertex3f(20.0f, 10.0f, -15.0f);
	glVertex3f(25.0f, 0.0f, -15.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);
	glVertex3f(-10.0f, 10.0f, 15.0f);
	glVertex3f(-10.0f, 10.0f, -15.0f);
	glVertex3f(20.0f, 10.0f, -15.0f);
	glVertex3f(20.0f, 10.0f, 15.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.8, 0.8);
	glVertex3f(-10.0f, 10.0f, 15.0f);
	glVertex3f(-20.0f, 0.0f, 15.0f);
	glVertex3f(-20.0f, 0.0f, -15.0f);
	glVertex3f(-10.0f, 10.0f, -15.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 0.5, 0.5);
	glVertex3f(20.0f, 10.0f, 15.0f);
	glVertex3f(20.0f, 10.0f, -15.0f);
	glVertex3f(25.0f, 0.0f, -15.0f);
	glVertex3f(25.0f, 0.0f, 15.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex3f(-30.0f, -15.0f, 15.0f);
	glVertex3f(-30.0f, -15.0f, -15.0f);
	glVertex3f(30.0f, -15.0f, -15.0f);
	glVertex3f(30.0f, -15.0f, 15.0f);
	glEnd();
	//车轮  	
	glColor3f(1, 0, 0);
	glTranslated(-20.0f, -15.0f, 15.0f);
	glutSolidTorus(2, 5, 5, 100);
	glTranslated(0.0f, 0.0f, -30.0f);
	glutSolidTorus(2, 5, 5, 100);
	glTranslated(45.0f, 0.0f, 0.0f);
	glutSolidTorus(2, 5, 5, 100);
	glTranslated(0.0f, 0.0f, 30.0f);
	glutSolidTorus(2, 5, 5, 100);
	glPopMatrix();
	glutSwapBuffers();
	//交换缓冲  

}
//定义键盘控制函数 
void SpecialKeys(int key, int x, int y){
	if (key == GLUT_KEY_UP)		xRot -= 5.0f;	
	if (key == GLUT_KEY_DOWN)	xRot += 5.0f;	
	if (key == GLUT_KEY_LEFT)	yRot -= 5.0f;
	if (key == GLUT_KEY_RIGHT)	yRot += 5.0f;
	glutPostRedisplay();
	// 刷新窗口 
}
int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("车");
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);	
	glEnable(GL_DEPTH_TEST);	
	glShadeModel(GL_SMOOTH);	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();	
	glOrtho(-100, 100, -100, 100, -100, 100);	
	glutSpecialFunc(SpecialKeys);
	//注册功能键回调函数  
	glutDisplayFunc(Display);	
	glutMainLoop();	
	return 0;
}