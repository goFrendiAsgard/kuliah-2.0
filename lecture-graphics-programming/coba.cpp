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

float degreeToRadian(float degree) {
  // 360 degree = 2 pi radian
  // 1 degree   = 2 pi / 360 radian
  // 1 degree   = pi / 180 radian
  return (degree * 22.0 / 7.0) / 180;
}

void segiBanyak(int jumlahSudut, float jariJari, float sudutAwal) {
  float perubahanSudut = 360.0/jumlahSudut;
  glBegin(GL_LINES);
  for (int i=0; i<jumlahSudut; i++) {
    float sudut1 = degreeToRadian(i * perubahanSudut + sudutAwal);
    float sudut2 = degreeToRadian((i+1) * perubahanSudut + sudutAwal);
    float x1 = cos(sudut1) * jariJari;
    float y1 = sin(sudut1) * jariJari;
    float x2 = cos(sudut2) * jariJari;
    float y2 = sin(sudut2) * jariJari;
    glVertex3f(x1,y1,0);
    glVertex3f(x2,y2,0);
  }
  glEnd();
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glTranslatef(0.0, 0.0, -6.0);
  glColor3f(0,0,0);
  segiBanyak(5, 2, 90);
  segiBanyak(360, 2, 90);
  segiBanyak(3, 2, 90);
  segiBanyak(3, 2, 270);

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
