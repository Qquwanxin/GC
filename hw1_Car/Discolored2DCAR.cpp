#include "pch.h"
#include <windows.h>
#include<GL/GL.h> 
#include<GL/glut.h>
#include <math.h> 
static GLfloat x = 1.0f;
static GLfloat y = 0.0f;
static GLfloat car_color1 = 1.0f;
static GLfloat car_color2 = 1.0f;
static GLfloat car_color3 = 1.0f;

//F1小车上半部分bling
//F2小车下半部分bling
//F3小车轮子bling
//F4小车消失
//UP DOWN LEFT RIGHT控制小车上下左右平移

void Display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();	

	glTranslatef(x, 0.0f, 0.0f);
	glTranslatef(0.0, y, 0.0f);

	//车上半部  
	glBegin(GL_POLYGON);
	glColor3f(car_color1, 0, 0);
	glVertex2f(20.0f, 20.0f);
	glVertex2f(10.0f, 35.0f);
	glVertex2f(-10.0f, 35.0f);
	glVertex2f(-20.0f, 20.0f);
	glEnd();

	//车下半部  
	glBegin(GL_POLYGON);
	
	glColor3f(0, car_color2, 0);
	glVertex2f(30.0f, 5.0f);
	glVertex2f(30.0f, 20.0f);
	glVertex2f(-30.0f, 20.0f);
	glVertex2f(-30.0f, 5.0f);
	glEnd();
	
	

	//车轮  	
	glColor3f(0, 0, car_color3);
	float R = 5.0f;  //半径
	float PI = 3.1415926f;

	glBegin(GL_POLYGON);
	for (int i = 0; i < 3600; i++)
	{
		glVertex2f(20+R*cos(2 * PI*i / 3600), 5+R*sin(2 * PI*i / 3600));   
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (int i = 0; i < 3600; i++)
	{
		glVertex2f(-20 + R * cos(2 * PI*i / 3600), 5 + R * sin(2 * PI*i / 3600));
	}
	glEnd();

	glPopMatrix();


	glutSwapBuffers();
	//交换缓冲  

}
//定义键盘控制函数 
void SpecialKeys(int key, int xa, int ya){
	if (key == GLUT_KEY_UP)		y += 2.0f;	
	if (key == GLUT_KEY_DOWN)	y -= 2.0f;	
	if (key == GLUT_KEY_LEFT)	x -= 2.0f;
	if (key == GLUT_KEY_RIGHT)	x += 2.0f;

	if (key == GLUT_KEY_F1)	car_color1 += 0.2f;
	if (key == GLUT_KEY_F2)	car_color2 += 0.2f;
	if (key == GLUT_KEY_F3)	car_color3 += 0.2f;
	if (key == GLUT_KEY_F4)
	{
		car_color1 = 0.0f;
		car_color2 = 0.0f;
		car_color3 = 0.0f;
	}
	if (car_color1 > 1.0f)	car_color1 -= 1.0f;
	if (car_color2 > 1.0f)	car_color2 -= 1.0f;
	if (car_color3 > 1.0f)	car_color3 -= 1.0f;
	
	glutPostRedisplay();
	// 刷新窗口 
}

int main(int argc, char* argv[]){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("CAR");
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);	
	glEnable(GL_DEPTH_TEST);	
	glShadeModel(GL_SMOOTH);	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();	
	glOrtho(-100, 100, -100, 100, -100, 100);	

	glutSpecialFunc(SpecialKeys);//注册功能键回调函数  

	glutDisplayFunc(Display);	
	glutMainLoop();	
	return 0;
}