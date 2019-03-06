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

float sudut = 0;
void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glTranslatef(0.0, 0.0, -8.0);
  glRotatef(sudut, 0,1,0);
  glBegin(GL_LINES);
      glColor3f(1,0,0); // red

      glVertex3f(3,2,0);
      glVertex3f(3,1,0);

      glVertex3f(3,1,0);
      glVertex3f(0,1,0);

      glVertex3f(0,1,0);
      glVertex3f(0,-2,0);

      glVertex3f(0,-2,0);
      glVertex3f(2,-2,0);

      glVertex3f(2,-2,0);
      glVertex3f(2,-1,0);

      glVertex3f(2,-1,0);
      glVertex3f(1,-1,0);

      glVertex3f(1,-1,0);
      glVertex3f(1,0,0);

      glVertex3f(1,0,0);
      glVertex3f(3,0,0);

      glVertex3f(3,0,0);
      glVertex3f(3,-3,0);

      glVertex3f(3,-3,0);
      glVertex3f(-1,-3,0);

      glVertex3f(-1,-3,0);
      glVertex3f(-1,2,0);

      glVertex3f(-1,2,0);
      glVertex3f(3,2,0);

  glEnd();
  sudut++;

  glFlush();
  glutSwapBuffers();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(50, 50);
  glutCreateWindow("coba");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  initGL();
  glutTimerFunc(0, timer, 0);
  glutMainLoop();
  return 0;
}
