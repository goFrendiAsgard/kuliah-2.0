// Compile: g++ filename.cpp -o filename -lglut -lGL -lGLU

#include "GL/glut.h"
#include "math.h"
#define PI 3.14159265

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
  //   1 degree = 2 pi / 360 radian
  //   1 degree = pi / 180 radian
  return (degree * PI) / 180.0;
}

void segiBeraturan(float r, int segi, float sudutAwal) {
  float besarSudutRad = degreeToRadian(360.0/segi);
  float sudutAwalRad = degreeToRadian(sudutAwal);
  glBegin(GL_LINES);
  for (int titikKe = 0; titikKe < segi; titikKe ++) {
    float sudut1 = besarSudutRad * titikKe + sudutAwalRad;
    float sudut2 = besarSudutRad * (titikKe + 1) + sudutAwalRad;
    float x1 = cos(sudut1) * r;
    float x2 = cos(sudut2) * r;
    float y1 = sin(sudut1) * r;
    float y2 = sin(sudut2) * r;
    glVertex3f(x1, y1, 0);
    glVertex3f(x2, y2, 0);
  }
  glEnd();
}

float sudut = 0;
void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glTranslatef(0.0, 0.0, -8.0);
  // glRotatef(sudut, 0,1,0);

  glColor3f(0,0,0);
  segiBeraturan(3, 5, 90);

  // sudut++;

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
