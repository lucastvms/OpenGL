#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

//funcao callback chamada para fazer o desenho

void desenha(){
  //limpa a janela de visualiza'c~ao com a cor de fundo especificada
  glClearColor(0.0, 0.0, 0.0,1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(0, 0, 1); 
  glBegin(GL_TRIANGLES);
    
    glVertex3f(0, 0.5, 0);
    glVertex3f(0.6, -0.5, 0);
    glVertex3f(-0.5, -0.5, 0.0);
    
  glEnd();

  /*
  glColor3f(1, 0, 1); 
  glBegin(GL_QUADS);
    
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(0.5, 0.0, 0.0);
  glEnd();
  */


  //Executa os comandos OepnGl
  glFlush();
}

void teclado(unsigned char key, int x, int y){
  if(key == 27){
    exit(0);
  }

}

//inicializa paramentros de rendering
void inicializa(void){
  //define a cor de fundo da janela de visualizacao
  glClearColor(0.0, 0.0, 0.0,1.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);

}

int main(int argc, char **argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(400,400);
  glutCreateWindow("Hello world !!!");
  glutDisplayFunc(desenha);
  glutKeyboardFunc(teclado);
  inicializa();
  glutMainLoop();
}
