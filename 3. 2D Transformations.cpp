#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

//funcao callback chamada para fazer o desenho

void desenha(void)
{   glClearColor(0.0, 0.0, 0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-200.0, 200.0, -200.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();                   
    glClear(GL_COLOR_BUFFER_BIT);
     
    
    
    //glPushMatrix();
    //glTranslatef(-0.0f, 0.0f, 0.0f);

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
      glVertex2i(-100,-100);
      glVertex2i(100,-100);
      glVertex2i(100,100);
      glVertex2i(-100,100);               
    glEnd();

    //glPopMatrix();

    //glPushMatrix();
      //glScalef(1.0,1.0, 1);
      //glRotatef(45, 0, 0, 1);
      //glTranslatef(-100,0, 0);
      glColor3f(0.0f, 0.0f, 1.0f);
      glBegin(GL_QUADS);
        glVertex2i(-50,-50);
        glVertex2i(50,-50);
        glVertex2i(50,50);
        glVertex2i(-50,50);               
      glEnd();
    //glPopMatrix();

    glFlush();
}

//inicializa paramentros de rendering
void inicializa(void){
  //define a cor de fundo da janela de visualizacao
  glClearColor(0.0, 0.0, 0.0,1.0);
}

int main(int argc, char **argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutCreateWindow("2D transformations !!!");
  glutDisplayFunc(desenha);
  inicializa();
  glutMainLoop();
}
