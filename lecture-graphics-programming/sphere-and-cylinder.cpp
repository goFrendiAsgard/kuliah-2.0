// Compile: g++ filename.cpp -o filename -lglut -lGL -lGLU

#include "GL/glut.h"
#include "math.h"


void initGL()
{

  GLfloat sun_direction[] = { 0.0, 2.0, -1.0, 1.0 };
  GLfloat sun_intensity[] = {0.7, 0.7, 0.7, 1.0};
  GLfloat ambient_intensity[] = { 0.3, 0.3, 0.3, 1.0 };

  glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // set clear color to white
  glClearDepth(1.0f);
  glEnable(GL_DEPTH_TEST); // draw only closest surface
  glDepthFunc(GL_LEQUAL);
  glShadeModel(GL_SMOOTH);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

  glEnable(GL_LIGHTING);
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_intensity);

  glEnable(GL_LIGHT0);                // Set up sunlight.
  glLightfv(GL_LIGHT0, GL_POSITION, sun_direction);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, sun_intensity);

  glEnable(GL_COLOR_MATERIAL);        // Configure glColor().
  glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);


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

GLUquadric *q = gluNewQuadric();
float sudut = 0;

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glTranslatef(0.0, 0.0, -6.0);

  glPushMatrix();

  glTranslatef(2,0,0);
  glRotatef(sudut, 0,1,0);
  glColor3f(1,0,0);
  gluSphere(q, 1, 10, 10);

  glPopMatrix();

  glTranslatef(-2,0,0);
  glRotatef(sudut, 0,1,0);
  glColor3f(1,0,0);
  gluCylinder(q, 1, 1, 2, 10, 10);

  sudut++;
  if (sudut == 360) {
    sudut = 0;
  }

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
