// Baseaso no código House3D.cpp
// Procurar função do mouse pra mexer a camêra "Passive"

#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
// Library for texture: #include <SFML/Graphics.hpp>

/*
 * Adaptado de:
 *   https://github.com/mdrkb/3D-House-using-OpenGL-and-C-/blob/master/main.cpp
*/

// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f;

// XZ position of the camera
float x=0.0f,z=7.0f;

float door_angle = 0.0f;

// angle for rotating
float angle = 0.0f;

void init(void) {
    // sky color
    //  seta a cor do fundo
    glClearColor(0.2, 0.2, 1.0, 1.0);

}

void drawHouse(){

    // Front side
    glPushMatrix();// 3 pilhas transformações, texturas e outra
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.65f);

        glBegin(GL_QUADS);  // Wall
            glVertex3f(0.3,0,1);
            glVertex3f(2,0,1);
            glVertex3f(2,-1.5,1);
            glVertex3f(0.3,-1.5,1);
        glEnd();

        glBegin(GL_QUADS);  // Wall
            glVertex3f(-2,0,1);
            glVertex3f(-0.3,0,1);
            glVertex3f(-0.3,-1.5,1);
            glVertex3f(-2,-1.5,1);
        glEnd();

        glBegin(GL_QUADS);  // Wall
        glVertex3f(0.3, 0, 1);
        glVertex3f(-0.3, 0, 1);
        glVertex3f(-0.3, -0.25, 1);
        glVertex3f(0.3,-0.25, 1);
    glEnd();

        glColor3f(0.4f, 0.0f, 0.0f);
        glBegin(GL_QUADS);  // Roof
            glVertex3f(-2.2,0.5,0);
            glVertex3f(2.2,0.5,0);
            glVertex3f(2.2,-0.1,1.25);
            glVertex3f(-2.2,-0.1,1.25);
        glEnd();
        glEnable(GL_BLEND);
            glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // transparência
      
        glColor4f(0.7f, 0.7f, 0.0f, 0.3); // quarto parâmetro é a transparência 1 opaco, 0 transparente
        glBegin(GL_QUADS);  // Window Left
            glVertex3f(-1.5,-0.3,1.0001);
            glVertex3f(-0.75,-0.3,1.0001);
            glVertex3f(-0.75,-0.8,1.0001);
            glVertex3f(-1.5,-0.8,1.0001);
        glEnd();
        glDisable(GL_BLEND); // desativa

        glBegin(GL_QUADS);  // Window Right
            glVertex3f(1.5,-0.3,1.0001);
            glVertex3f(0.75,-0.3,1.0001);
            glVertex3f(0.75,-0.8,1.0001);
            glVertex3f(1.5,-0.8,1.0001);
        glEnd();
    glPopMatrix();

    // Back side
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
        glColor3f(0.0f, 0.0f, 0.65f);
        glBegin(GL_QUADS);  // Wall
            glVertex3f(-2,0,-1);
            glVertex3f(2,0,-1);
            glVertex3f(2,-1.5,-1);
            glVertex3f(-2,-1.5,-1);
        glEnd();

        glColor3f(0.4f, 0.0f, 0.0f);
        glBegin(GL_QUADS);  // Roof
            glVertex3f(-2.2,0.5,0);
            glVertex3f(2.2,0.5,0);
            glVertex3f(2.2,-0.1,-1.25);
            glVertex3f(-2.2,-0.1,-1.25);
        glEnd();

        glBegin(GL_QUADS);  // Window Left
             glVertex3f(-1.5,-0.3,-1.0001);
             glVertex3f(-0.75,-0.3,-1.0001);
             glVertex3f(-0.75,-0.8,-1.0001);
             glVertex3f(-1.5,-0.8,-1.0001);
        glEnd();

        glBegin(GL_QUADS);  // Window Right
             glVertex3f(1.5,-0.3,-1.0001);
             glVertex3f(0.75,-0.3,-1.0001);
             glVertex3f(0.75,-0.8,-1.0001);
             glVertex3f(1.5,-0.8,-1.0001);
        glEnd();
    glPopMatrix();

    // Right side
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
        glColor3f(0.0f, 0.0f, 0.65f);
        glBegin(GL_QUADS);  // Wall
             glVertex3f(2,0,1);
             glVertex3f(2,0,-1);
            glVertex3f(2,-1.5,-1);
             glVertex3f(2,-1.5,1);
        glEnd();

        glBegin(GL_TRIANGLES);  // Wall Upper
             glVertex3f(2,0.5,0);
             glVertex3f(2,0,1);
             glVertex3f(2,0,-1);
        glEnd();
    glPopMatrix();

    // Left side
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
        glColor3f(0.0f, 0.0f, 0.65f);
        glBegin(GL_QUADS);  // Wall
                glVertex3f(-2,0,1);
                glVertex3f(-2,0,-1);
               glVertex3f(-2,-1.5,-1);
                glVertex3f(-2,-1.5,1);
        glEnd();

        glBegin(GL_TRIANGLES);  // Wall Upper
               glVertex3f(-2,0.5,0);
               glVertex3f(-2,0,1);
               glVertex3f(-2,0,-1);
        glEnd();
    glPopMatrix();
}

void drawDoor() {

    glPushMatrix();
        glTranslatef(-0.3f, 0.5f, 1);
        glRotatef (door_angle, 0,1,0);
        glTranslatef(0.3f, 0, 0);
        glColor3f(0.7f, 0.7f, 0.7f);
        glScalef(0.6, 1.1, 0.1f);
        glutSolidCube(1.0); // cria cubo. previews de 3d existem
    glPopMatrix();

}

void drawWalls() {
    glColor3f(0.5f, 0.5f, 0.5f);
    // Front Wall
    glBegin(GL_QUADS);
        glVertex3f(0, 0, 1);
        glVertex3f(0, 1, 1);
        glVertex3f(2, 1, 1);
        glVertex3f(2, 0, 1);
    glEnd();

    glColor3f(0.0f, 0.5f, 0.0f);
    // Right Wall
    glBegin(GL_QUADS);
        glVertex3f(2, 0, 1); 
        glVertex3f(2, 1, 1);
        glVertex3f(2, 1, 0);
        glVertex3f(2, 0, 0);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.5f);
    // Back Wall
    glBegin(GL_QUADS);
        glVertex3f(2, 0, 0);
        glVertex3f(2, 1, 0);
        glVertex3f(0, 1, 0);
        glVertex3f(0, 0, 0);
    glEnd();

    glColor3f(1.0f, 0.5f, 0.0f);
    // Left Wall
    glBegin(GL_QUADS);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 1, 0);
        glVertex3f(0, 1, 1);
        glVertex3f(0, 0, 1);
    glEnd();
}

void drawRoof() {
    glColor3f(0.5f, 0.5f, 0.5f);
    // Front Roof
    glBegin(GL_QUADS);
        glVertex3f(-0.2, 1, 1);
        glVertex3f(0, 1.2, 1);
        glVertex3f(2, 1.2, 1);
        glVertex3f(2.2, 1, 1);
    glEnd();

    glColor3f(0.0f, 0.5f, 0.0f);
    // Right Roof
    glBegin(GL_QUADS);
        glVertex3f(2.2, 1, 1); 
        glVertex3f(2, 1.2, 1);
        glVertex3f(2, 1.2, -0.2);
        glVertex3f(2, 1, -0.2);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.5f);
    // Back Wall
    glBegin(GL_QUADS);
        glVertex3f(2, 1, -0.2);
        glVertex3f(2, 1.2, 0);
        glVertex3f(-0.2, 1.2, -0.2);
        glVertex3f(-0.2, 1, -0.2);
    glEnd();

    glColor3f(1.0f, 0.5f, 0.0f);
    // Left Wall
    glBegin(GL_QUADS);
        glVertex3f(0,0,0);
        glVertex3f(0,1,0);
        glVertex3f(0,1,1);
        glVertex3f(0,0,1);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex3f(0,1.2,1);
        glVertex3f(0,1.2,0);
        glVertex3f(2,1.2,0);
        glVertex3f(2,1.2,1);
    glEnd();

}

void drawStructure() {

    drawWalls();
    drawRoof();

}

void drawRoom() {
    // Front side
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 0.5f, 0.5f);

    drawStructure();
}



void changeSize(int w, int h){

    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
    if (h == 0) h = 1;
    float ratio = w * 1.0 / h;

    // Use the Projection Matrix
    glMatrixMode(GL_PROJECTION);

    // Reset Matrix
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set the correct perspective.
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);

    // Get Back to the Modelview | Ortho para 2d. MOdel para 3d
    glMatrixMode(GL_MODELVIEW);
}

void renderScene(void){

    // Para ver os objetos em modo polígono (somente os traços) 
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Clear Color and Depth Buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity(); // reseta matriz identidade depois de ser modificada por translações ou rotações ou escalonamentos

    // Set the camera. Seta o vetor inicial da câmera
    gluLookAt(x, 1.0f, z, x+lx, 1.0f, z+lz, 0.0f, 1.0f, 0.0f);

    // Draw ground
    glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_QUADS);
        glVertex3f(-100.0f, 0.0f, -100.0f);
        glVertex3f(-100.0f, 0.0f, 100.0f);
        glVertex3f( 100.0f, 0.0f, 100.0f);
        glVertex3f( 100.0f, 0.0f, -100.0f);
    glEnd();

    //drawHouse();
    drawRoom();
    //drawDoor();

    glFlush(); // atualiza perspectiva. GLUT_SINGLE 
    glutSwapBuffers(); // atualiza perspectiva. GLUT_DOUBLE
}


void processNormalKeys(unsigned char key, int x, int y) {
    switch(key){
        case 'o':
            if(door_angle <= 118.0f) door_angle += 2.0f;
            glutPostRedisplay();
        break;

        case 'c':
            if(door_angle >= 2.0f) door_angle -= 2.0f;
            glutPostRedisplay();
        break;

        case 27:
            exit(0);
        break;
    }
}


void processSpecialKeys(int key, int xx, int yy){

float fraction = 0.5f;

    switch (key) {

        case GLUT_KEY_LEFT :
            angle -= 0.05f;
            lx = sin(angle);
            lz = -cos(angle);
        break;
        case GLUT_KEY_RIGHT :
            angle += 0.05f;
            lx = sin(angle);
            lz = -cos(angle);
        break;
        case GLUT_KEY_UP :
            x += lx * fraction;
            z += lz * fraction;
        break;
        case GLUT_KEY_DOWN :
            x -= lx * fraction;
            z -= lz * fraction;
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv){

    // init GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(800,600);
    glutCreateWindow("House 3D");

    init();

    // register callbacks
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);

    // OpenGL init
    glEnable(GL_DEPTH_TEST);

    // enter GLUT event processing cycle
    glutMainLoop();

    return 1;
}
