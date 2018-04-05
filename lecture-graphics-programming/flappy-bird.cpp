// Source: https://www.ntu.edu.sg/home/ehchua/programming/opengl/CG_Examples.html
// Compile: g++ 3d.cpp -o 3d -lglut -lGL -lGLU

#include "GL/glut.h"


void initGL()
{
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClearDepth(1.0f);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glShadeModel(GL_SMOOTH);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void badan()
{
  glBegin(GL_QUADS);
  glVertex3f(1, -1, 0);
  glVertex3f(1, 1, 0);
  glVertex3f(-1, 1, 0);
  glVertex3f(-1, -1, 0);
  glEnd();
}

void sayapKanan()
{
  glBegin(GL_TRIANGLES);
  glVertex3f(0, 0, 0);
  glVertex3f(2, 0, 0);
  glVertex3f(2, 1, 0);
  glEnd();
}

void sayapKiri()
{
  glBegin(GL_TRIANGLES);
  glVertex3f(0, 0, 0);
  glVertex3f(-2, 0, 0);
  glVertex3f(-2, 1, 0);
  glEnd();
}

GLfloat angle = 0.0f;
GLfloat direction = 1.0f;
void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glTranslatef(0, 0, -15);
  glPushMatrix();
  badan();

  glTranslatef(1, 0, 0);
  glRotatef(angle, 0, 0, 1);
  sayapKanan();

  glPopMatrix();
  glTranslatef(-1, 0, 0);
  glRotatef(-angle, 0, 0, 1);
  sayapKiri();

  angle += direction;
  if (angle >= 45 || angle <= -45) {
    direction = -direction;
  }

  glutSwapBuffers();
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

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(50, 50);
  glutCreateWindow("3d-animation");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  initGL();
  glutTimerFunc(0, timer, 0);
  glutMainLoop();
  return 0;
}