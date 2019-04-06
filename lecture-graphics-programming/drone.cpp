// Compile: g++ 3d.cpp -o 3d -lglut -lGL -lGLU

#include "GL/glut.h"
#include "math.h"

void initGL()
{
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClearDepth(1.0f);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glShadeModel(GL_SMOOTH);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

float deg2Rad (float sudut) {
	return sudut * (22/7) / 180;
}

void busur(float sudutAwal, float sudutAkhir, float deltaSudut, float jariJari)
{
	sudutAwal = deg2Rad(sudutAwal);
	sudutAkhir = deg2Rad(sudutAkhir);
	deltaSudut = deg2Rad(deltaSudut);
	float sudut = sudutAwal;
	glBegin(GL_TRIANGLES);
	while (sudut + deltaSudut <= sudutAkhir) {
		float sudutBerikutnya = sudut + deltaSudut;
		float x1 = cos(sudut) * jariJari;
		float y1 = sin(sudut) * jariJari;
		float x2 = cos(sudutBerikutnya) * jariJari;
		float y2 = sin(sudutBerikutnya) * jariJari;
		sudut += deltaSudut;
		glVertex3f(x1, y1, 0);
		glVertex3f(x2, y2, 0);
		glVertex3f(0, 0, 0);
	}
	glEnd();
}

void badan()
{
  glBegin(GL_QUADS);
  glVertex3f(2, 0, -2);
  glVertex3f(2, 0, 2);
  glVertex3f(-2, 0, 2);
  glVertex3f(-2, 0, -2);
  glEnd();
}

void balingBaling()
{
  glBegin(GL_TRIANGLES);
  glVertex3f(0, 0, 0);
  glVertex3f(1, 0, 0.5);
  glVertex3f(1, 0, -0.5);
  glVertex3f(0, 0, 0);
  glVertex3f(-1, 0, 0.5);
  glVertex3f(-1, 0, -0.5);
  glEnd();
}

GLfloat angle = 0.0f;
void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glTranslatef(0, -2, -10);
  // glRotatef(-0.5 * angle, 0, 1, 0);
  glColor3f(1,1,1);
  badan();

  glColor3f(0,0,1);
  busur(0,360,30,1);
  glPushMatrix();
  glRotatef(90,0,1,0);
  glColor3f(0,1,0);
  busur(0,360,30,1);
  glPopMatrix();

  for (int i=0; i<4; i++) {
    glPushMatrix();
  }

  glColor3f(1,0,0);
  for (int x=-2; x<=2; x+=4) {
    for (int z=-2; z<=2; z+=4) {
      glPopMatrix();
      glTranslatef(x, 0.2, z);
      glRotatef(angle, 0, 1, 0);
      balingBaling();
    }
  }

  angle += 3;

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
