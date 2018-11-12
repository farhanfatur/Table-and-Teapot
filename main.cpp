#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

using namespace std;

double rotAngle = 0;
double red = 0.5;
double blue = 0.5;
double green = 0.5;
double horizontal = 0.0;
double vertical = 0.0;
double xScale = 0.2;
double yScale = 0.2;
double zScale = 0.2;
double xAxis = 0.0;
double yAxis = 0.0;
double zAxis = 0.0;
void init(){
    glClearColor(1, 1, 1, 0);//Warna background
    glClearDepth(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
//glLoadIdentity(0.0, 0.0, 10.0,0.0, 0.0, 0.0,0.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    float lpos[] = {2,5,5,0};
    glLightfv(GL_LIGHT0, GL_POSITION, lpos);
    glShadeModel(GL_SMOOTH);//Tekstur objek
}

void kaki1() {
    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(0.39, 0.36, 0.12);
    glTranslatef(3.6, -2, 1.4);
    glScalef(0.3, 1, 0.4);
    glutSolidCube(2);
    glPopMatrix();
}

void kaki2() {
    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(0.39, 0.36, 0.12);
    glTranslatef(-3.6, -2, 1.4);
    glScalef(0.3, 1, 0.4);
    glutSolidCube(2);
    glPopMatrix();
}

void kaki3() {
    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(0.39, 0.36, 0.12);
    glTranslatef(-3.6, -2, -1.4);
    glScalef(0.3, 1, 0.4);
    glutSolidCube(2);
    glPopMatrix();
}

void kaki4() {
    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(0.39, 0.36, 0.12);
    glTranslatef(3.6, -2, -1.4);
    glScalef(0.3, 1, 0.4);
    glutSolidCube(2);
    glPopMatrix();
}

void meja(){
    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    //glRotated(rotAngle, 0, 1, 0);
    glColor3f(0.39, 0.36, 0.12);
    glTranslatef(0, -1, 0);
    glScalef(4, 0.4, 2);
    glutSolidCube(2);
    glPopMatrix();
}

void cangkir() {
    glPushMatrix();
    glRotated(rotAngle, 0, 1, 0);
    glTranslatef(0, 0.8, 0);
    glEnable(GL_COLOR_MATERIAL);
    glutSolidTeapot(2);//Membuat cangkir
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glColor3f(red, green, blue);
    glTranslatef(horizontal, vertical, 0);
    glScalef(xScale, yScale, zScale);
    glRotated(rotAngle, xAxis, yAxis, zAxis);

    cangkir();
    kaki1();
    kaki2();
    kaki3();
    kaki4();
    meja();

    glFlush();//untuk merender hasil kode
    glPopMatrix();
    glutSwapBuffers();
}

void keyboard(unsigned char a, int x, int y){
    switch(a){
        case 'r':
            red+=0.2;
        break;
        case 'g':
            green+=0.2;
        break;
        case 'b':
            blue+=0.2;
        break;
        case 'n':
            red-=0.2;
            green-=0.2;
            blue-=0.2;
        break;
        case 'a':
            horizontal-=0.2;
        break;
        case 'd':
            horizontal+=0.2;
        break;
        case 'w':
            vertical+=0.2;
        break;
        case 's':
            vertical-=0.2;
        break;
        case '-':
            xScale-=0.1;
            yScale-=0.1;
            zScale-=0.1;
        break;
        case '=':
            xScale+=0.1;
            yScale+=0.1;
            zScale+=0.1;
        break;
        case '1':
            rotAngle+=1.0;
            xAxis+=0.1;
            yAxis-=0.0;
            zAxis-=0.0;
        break;
        case '2':
            rotAngle+=1.0;
            xAxis-=0.0;
            yAxis+=0.1;
            zAxis-=0.0;
        break;
        case '3':
            rotAngle+=0.1;
            xAxis-=0.0;
            yAxis-=0.0;
            zAxis+=0.1;
        break;
    }
    glutPostRedisplay();
}

void doc() {
cout<<"Menu : \n\
1.  W : Up\n\
2.  S : Down\n\
3.  A : Left\n\
4.  D : Right\n\
5.  R : Change Point of Red Color a Teapot\n\
6.  G : Change Point of Green Color a Teapot\n\
7.  B : Change Point of Blue Color a Teapot\n\
8.  1 : Rotation(+)\n\
9.  2 : Rotation(-)\n\
10. - : Zoom In\n\
11. = : Zoom Out";
}

int main (int argc, char **argv) {
    doc();
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGB);
    glutCreateWindow("Cangkir");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();
    return 0;
}
