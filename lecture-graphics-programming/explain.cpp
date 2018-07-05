// Compile: g++ explain.cpp -o explain -lglut -lGL -lGLU

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

void kotak() {
  glBegin(GL_QUADS);
  glVertex3d(-1, 1, 0);
  glVertex3d(1, 1, 0);
  glVertex3d(1, -1, 0);
  glVertex3d(-1, -1, 0);
  glEnd();
}

int sudut = 90;
void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glTranslatef(0, -1, -10); // jauhkan bidang koordinat dari mata 10 langkah ke depan, 1 langkah ke bawah
  kotak(); // gambar kotak

  glPushMatrix(); // simpan bidang koordinat saat ini
  glTranslatef(4, 0, 0); // geser bidang koordinat 4 langkah ke kanan
  glRotatef(sudut, 0, 1, 0); // putar bidang koordinat 90 derajat dengan pusat sumbu y
  kotak(); // gambar kotak
  glPopMatrix(); // kembalikan bidang koordinat ke sebelum pushMatrix

  glPushMatrix(); // simpan bidang koordinat saat ini
  glTranslatef(-4, 0, 0); // geser bidang koordinat 4 langkah ke kiri
  glRotatef(sudut, 0, 1, 0); // putar bidang koordinat 90 derajat dengan pusat sumbu y
  kotak(); // gambar kotak
  glPopMatrix(); // kembalikan bidang koordinat ke sebelum pushMatrix

  sudut = sudut + 1;

  /*
  glTranslatef(0, 0, -8); // geser bidang koordinat searah sumbu z negatif 8 langkah
  kotak(); // gambar kotak
  */
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
