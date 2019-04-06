// Compile: g++ transformation.cpp -o transformation -lglut -lGL -lGLU

#include "GL/glut.h"

GLfloat angle = 0;

void initGL()
{
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClearDepth(1.0f);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glShadeModel(GL_SMOOTH);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);

  // draw the white big square
  glLoadIdentity();
  glTranslatef(0, -4, -20);
  glColor3f(1, 1, 1);
  glBegin(GL_QUADS);
    glVertex3f(0, 10, 0);
    glVertex3f(10, 10, 0);
    glVertex3f(10, 0, 0);
    glVertex3f(0, 0, 0);
  glEnd();

  glLoadIdentity();
  glTranslatef(0, -4, -20);

  // X Rotation
  /*glRotatef(angle, 1, 0 , 0);*/

  // Y Rotation
  /*glRotatef(angle, 0, 1, 0);*/

  // Z Rotation
  /*glRotatef(angle, 0, 0, 1);*/

  // Rotation + Translation
  /*
  glTranslatef(-3, 0, 0);
  glRotatef(angle, 0, 1, 0);
  glTranslatef(3, 0, 0);
  */

  glColor3f(1, 0, 1);
  glBegin(GL_QUADS);
    glVertex3f(-3, 3, 0);
    glVertex3f(3, 3, 0);
    glVertex3f(3, -3, 0);
    glVertex3f(-3, -3, 0);
  glEnd();

  angle += 1;

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
