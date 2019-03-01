// Compile: g++ filename.cpp -o filename -lglut -lGL -lGLU

#include "GL/glut.h"
#include "math.h"


void initGL()
{
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glClearDepth(1.0f);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glShadeModel(GL_SMOOTH);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void timer(int value)
{
  glutPostRedisplay();
  glutTimerFunc(15, timer, 0);
}


void reshape(GLsizei width, GLsizei height)
{
  if (height == 0)
    height = 1;
  GLfloat aspect = (GLfloat)width / (GLfloat)height;
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}


float deg2Rad (float sudut) {
	return sudut * (22.0/7.0) / 180.0;
}

void lingkaran(float jariJari)
{
	float sudutAwal = deg2Rad(0);
	float sudutAkhir = deg2Rad(360);
	float deltaSudut = deg2Rad(1);
	float sudut = sudutAwal;
	glBegin(GL_TRIANGLES);
	while (sudut <= sudutAkhir) {
		float sudutBerikutnya = sudut + deltaSudut;
		float x1 = cos(sudut) * jariJari;
		float y1 = sin(sudut) * jariJari;
		float x2 = cos(sudutBerikutnya) * jariJari;
		float y2 = sin(sudutBerikutnya) * jariJari;
        sudut = sudutBerikutnya;
		glVertex3f(x1, y1, 0);
		glVertex3f(x2, y2, 0);
		glVertex3f(0, 0, 0);
	}
	glEnd();
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glTranslatef(0.0, 0.0, -6.0);
  glColor3f(1,0,0); // red
  lingkaran(2);

  glFlush();
  glutSwapBuffers();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(50, 50);
  glutCreateWindow("praktikum 1");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  initGL();
  glutTimerFunc(0, timer, 0);
  glutMainLoop();
  return 0;
}
