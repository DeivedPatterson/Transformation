// gcc -o Transformation Transformation.c -lGL -lGLU -lglu

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>


#define SCREEN_WIDTH 	480UL
#define SCREEN_HEIGHT	270UL

static void Keyboard(unsigned char key, int x, int y);
static void SpecialKeys(int key, int x, int y);
static void DrawLine(void);
static void Display(void);


static float dx;
static float dy;

static float angle = 0;
static float scale = 1.0;



static void DrawLine(void)
{
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
		glVertex2f(0.0, 0.0);
      	glVertex2f(30.0, 100.0);
      	glVertex2f(-100.0, 0.0);
      	glVertex2f(100.0, 0.0);
    glEnd();
}


static void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	//DrawLine();

	glColor3f (1.0, 0.0, 0.0);

   	glPushMatrix();
    	glTranslatef(dx, dy, 0.0);
 		glRotatef(angle, 0.0, 0.0, 1.0);
      	glScalef(scale, scale, scale);
    	glutWireCube(10);
    glPopMatrix();
	glutSwapBuffers();
	glutPostRedisplay();
}

static void SpecialKeys(int key, int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_LEFT:

			if(dx > 0)
			{
				dx -= 1;
			}	
			
		break;

		case GLUT_KEY_RIGHT:

			if(dx < 200)
			{
				dx += 1;
			}	

		break;

		case GLUT_KEY_UP:

			if(dy > 0)
			{
				dy -= 1;
			}	

		break;


		case GLUT_KEY_DOWN:

			if(dy < 200)
			{
				dy += 1;
			}	

		break;
	}
}

static void Keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case '+':

			if(scale < 200)
			{
				scale += 0.5;
			}

		break;

		case '-':

			if(scale > 0)
			{
				scale -= 0.5;
			}

		break;

		case 'r':

			angle += 0.5;

		break;

		case 'R':

			angle -= 0.5;

		break;

		case 27:
			exit(0);
		break;

		default:
			break;
	}
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
   	glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGB);
   	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
   	glutInitWindowPosition(100, 100);
   	glutCreateWindow("Transformation");

   	glClearColor (0.0, 0.0, 0.0, 0.0);

   	glMatrixMode(GL_PROJECTION);
   	glLoadIdentity();
   	glOrtho(0, 200.0, 200.0, 0.0, 0, 200.0);
   	glMatrixMode(GL_MODELVIEW);
   	glLoadIdentity();
	glutDisplayFunc(Display);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(SpecialKeys);
	glutMainLoop();
	
	return 0;
}