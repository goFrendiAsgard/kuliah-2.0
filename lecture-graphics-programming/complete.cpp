// Compile: g++ 3d.cpp -o 3d -lglut -lGL -lGLU

#include "GL/glut.h"

#define checkImageWidth 64
#define checkImageHeight 64

GLUquadric *q = gluNewQuadric();
GLfloat camY = 0.0;
GLfloat camX = 0.0;
GLfloat angle = 1;
GLfloat direction = 1;


/*  Create checkerboard texture  */
static GLubyte checkImage[checkImageHeight][checkImageWidth][4];

static GLuint texName;

void makeCheckImage(void)
{
   int i, j, c;
    
   for (i = 0; i < checkImageHeight; i++) {
      for (j = 0; j < checkImageWidth; j++) {
         c = (((((i&0x8)==0)^((j&0x8)))==0))*255;
         checkImage[i][j][0] = (GLubyte) c;
         checkImage[i][j][1] = (GLubyte) c;
         checkImage[i][j][2] = (GLubyte) c;
         checkImage[i][j][3] = (GLubyte) 255;
      }
   }
}

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


  makeCheckImage();
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &texName);

  glBindTexture(GL_TEXTURE_2D, texName);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth, 
    checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, 
    checkImage);
}

void drawAxis()
{
  glBegin(GL_LINES);
  glColor3f(1,0,0); // red
  glVertex3f(0,0,0);
  glVertex3f(3,0,0); // x
  glColor3f(0,0,1); // blue
  glVertex3f(0,0,0);
  glVertex3f(0,3,0); // y
  glColor3f(0,1,0); // green
  glVertex3f(0,0,0);
  glVertex3f(0,0,3); // z
  glEnd();
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  gluLookAt(
    camX, camY, 0, 
    0, 0,-15,
    0,1,0);

  glTranslatef(0, 0, -15);
  glPushMatrix();
  glPushMatrix();

  // sphere
  glRotatef(angle, 0, 1, 0);
  drawAxis();
  glColor3f(1,0,0);
  glEnable(GL_TEXTURE_2D);
  gluQuadricTexture(q, true);
  gluSphere(q, 1.5, 8, 8);
  glDisable(GL_TEXTURE_2D);

  // cylinder
  glPopMatrix();
  glTranslatef(4, 0, 0);
  glRotatef(angle, 0, 1, 0);
  drawAxis();
  glColor3f(0,1,0);
  glEnable(GL_TEXTURE_2D);
  gluQuadricTexture(q, true);
  gluCylinder(q, 1, 1, 2, 8, 8);
  glDisable(GL_TEXTURE_2D);

  // triangle
  glPopMatrix();
  glTranslatef(-4, 0, 0);
  glRotatef(angle, 0, 1, 0);
  drawAxis();
  glColor3f(1, 0.5, 0.5);
  glEnable(GL_TEXTURE_2D);
  glBegin(GL_TRIANGLES);
    glTexCoord2f(0.5,0);
    glVertex3f(1.5,-1,0);
    glTexCoord2f(0,1);
    glVertex3f(-1.5,-1,0);
    glTexCoord2f(1,1);
    glVertex3f(0,2,0);
  glEnd();
  glDisable(GL_TEXTURE_2D);

  angle += direction;

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

void keyControl(int k, int x, int y)
{
  switch(k) {
    case GLUT_KEY_UP: camY ++; break;
    case GLUT_KEY_DOWN: camY --; break;
    case GLUT_KEY_LEFT: camX --; break;
    case GLUT_KEY_RIGHT: camX ++; break;
  }
}

void mouseControl(int button, int state, int x, int y)
{
  switch(button) {
    case GLUT_LEFT_BUTTON: direction = -direction; break;
  }
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(50, 50);
  glutCreateWindow("3d-control");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  initGL();
  glutTimerFunc(0, timer, 0);
  glutSpecialFunc(keyControl);
  glutMouseFunc(mouseControl);
  glutMainLoop();
  return 0;
}
