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


class car {
private:
	void translate(void)
	{
		glTranslatef(x, 0.0f, 0.0f);
		glTranslatef(0.0, y, 0.0f);
	}

	void draw_the_car(void)
	{
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
		GLfloat R = 5.0f;  //半径
		GLfloat PI = 3.1415926f;

		glBegin(GL_POLYGON);
		for (int i = 0; i < 3600; i++)
		{
			glVertex2f(20 + R * cos(2 * PI*i / 3600), 5 + R * sin(2 * PI*i / 3600));
		}
		glEnd();

		glBegin(GL_POLYGON);
		for (int i = 0; i < 3600; i++)
		{
			glVertex2f(-20 + R * cos(2 * PI*i / 3600), 5 + R * sin(2 * PI*i / 3600));
		}
		glEnd();
	}
public:
	void draw(void)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glPushMatrix();
		translate();

		draw_the_car();
		glPopMatrix();
		glutSwapBuffers();
		//交换缓冲
	}
};

car the2Dcar;

	//display
void Display(void) {
	the2Dcar.draw();
}

//键盘控制上下左右、变色、消失
void control(int key, int xa, int ya) {
	//move the car
	if (key == GLUT_KEY_UP)		y += 2.0f;
	if (key == GLUT_KEY_DOWN)	y -= 2.0f;
	if (key == GLUT_KEY_LEFT)	x -= 2.0f;
	if (key == GLUT_KEY_RIGHT)	x += 2.0f;

	//change the car's color
	if (key == GLUT_KEY_F1)	car_color1 += 0.2f;
	if (key == GLUT_KEY_F2)	car_color2 += 0.2f;
	if (key == GLUT_KEY_F3)	car_color3 += 0.2f;


	if (car_color1 > 1.0f)	car_color1 -= 1.0f;
	if (car_color2 > 1.0f)	car_color2 -= 1.0f;
	if (car_color3 > 1.0f)	car_color3 -= 1.0f;


	//the color reset when F4 pressed
	if (key == GLUT_KEY_F4)
	{
		car_color1 = 1.0f;
		car_color2 = 1.0f;
		car_color3 = 1.0f;
	}

	glutPostRedisplay();		//refresh
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

	glutSpecialFunc(control);
	
	glutDisplayFunc(Display);
	glutMainLoop();	
	return 0;
}
