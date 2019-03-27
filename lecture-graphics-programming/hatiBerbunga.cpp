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

void segiBeraturan(float xPusat, float yPusat, float r, int segi, float sudutAwal, float sudutAkhir) {
  float besarSudutRad = degreeToRadian(360.0/segi);
  float sudutAwalRad = degreeToRadian(sudutAwal);
  float sudutAkhirRad = degreeToRadian(sudutAkhir);
  glBegin(GL_LINES);
  for (int titikKe = 0; titikKe < segi; titikKe ++) {
    float sudut1 = besarSudutRad * titikKe + sudutAwalRad;
    float sudut2 = besarSudutRad * (titikKe + 1) + sudutAwalRad;
    float x1 = cos(sudut1) * r + xPusat;
    float x2 = cos(sudut2) * r + xPusat;
    float y1 = sin(sudut1) * r + yPusat;
    float y2 = sin(sudut2) * r + yPusat;
    glVertex3f(x1, y1, 0);
    glVertex3f(x2, y2, 0);
    if (sudut2 >= sudutAkhirRad) {
      break;
    }
  }
  glEnd();
}

void gambarHati() {
  /*
  glBegin(GL_LINES);
    glVertex3f(-1.414, 0, 0);
    glVertex3f(0, -1.414, 0);
    glVertex3f(0, -1.414, 0);
    glVertex3f(1.414, 0, 0);
  glEnd();
  */
  segiBeraturan( 0.707, 0.707, 1, 16, -45, 135);
  segiBeraturan(-0.707, 0.707, 1, 16, 45, 225);
}

void gambarSumbu() {
  glBegin(GL_LINES);
    glVertex3f(0,0,0); // x
    glVertex3f(3,0,0);
    glVertex3f(0,0,0); // y
    glVertex3f(0,3,0);
    glVertex3f(0,0,0); // z
    glVertex3f(0,0,3);
  glEnd();
}

void bunga() {
  glTranslatef(1, 1, 0);
  glRotatef(-45, 0, 0, 1);
  gambarHati();
  glRotatef(45, 0, 0, 1);

  glTranslatef(-2, 0, 0);
  glRotatef(45, 0, 0, 1);
  gambarHati();
  glRotatef(-45, 0, 0, 1);

  glTranslatef(0, -2, 0);
  glRotatef(135, 0, 0, 1);
  gambarHati();
  glRotatef(-135, 0, 0, 1);

  glTranslatef(2, 0, 0);
  glRotatef(-135, 0, 0, 1);
  gambarHati();
  glRotatef(135, 0, 0, 1);
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glTranslatef(0.0, 0.5, -10.0);

  // gambar sumbu koordinat
  glColor3f(0,0,0);

  gambarSumbu();
  bunga();

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
