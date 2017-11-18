#include <iostream>
#include <string>
#include <GL/freeglut.h>

using namespace std;


int main (int argc, char **argv)
{
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,600);
	glutCreateWindow("Урок 1");
	gluOrtho2D(1, 80, 1, 60);

        double 


        return 0;
}