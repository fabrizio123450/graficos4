//#include "cubo.h"
#include "tokens.h"
#include "mouse.h"
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
//Camera camera;
void init(void) {
	ratio = (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT;
	glClearColor(0.623529f, 0.623529f, 0.372549f, 0.0);//inicializamos glut limpiando el color
	glShadeModel(GL_SMOOTH);//para rellenar de color los polígonos. Si el parámetro es GL_FLAT, ogl rellenará los polígonos con el color activo
	PlaySound("GB.wav",NULL, SND_ASYNC| SND_LOOP);
}
/*Prueba de textura

NO FUNCIONA*/
//fin de prueba texturag//



void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
}
/*
renderisa con la posicion de la camara
*/
/*uso del teclado*/
void ArrowKey(int key, int x, int y) {
	switch (key) {
	//rotacion abajo
	case GLUT_KEY_DOWN:
		anglex = (anglex + 3) % 360;
		break;
	//rotacion derecha
	case GLUT_KEY_RIGHT:
		angley = (angley + 3) % 360;
		break;
	//rotacion arriba
	case GLUT_KEY_UP:
		anglex = (anglex - 3) % 360;
		break;
	//rotacion izquierda
	case GLUT_KEY_LEFT:
		angley = (angley - 3) % 360;
		break;
	}
	glutPostRedisplay();

}
void keyboard(unsigned char key, int xx, int yy) {
	switch (key) {
	case 'a'://izquierda
	case 'A':
		angle -= 0.01f;
		lx = sin(angle);
		lz = -cos(angle);
		cout << "es en lx " << lx << " y en lz " << lz << endl;
		break;
	case 'd'://derecha
	case 'D':
		angle += 0.01f;
		lx = sin(angle);
		lz = -cos(angle);
		cout << "es en lx " << lx << " y en lz " << lz << endl;
		break;
	case 'w'://adelante
	case 'W':
		x += lx * 0.1f;
		z += lz * 0.1f;
		cout << "es en x " << x << " y en z " << z << endl;
		break;
	case 's'://atras
	case 'S':
		x -= lx * 0.1f;
		z -= lz * 0.1f;
		cout << "es en x " << x << " y en z " << z << endl;
		break;
	//Reseteo mi tateti a la posicion original
	case 'r':
	case 'R':
		anglex = angley = 0;
		break;
	case 27: /* escape */
		exit(0);
	}
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(500, 100);
	glutCreateWindow("Proyecto 4");
	init();
	texture = LoadTexture("b.bmp");
	glBindTexture(GL_TEXTURE_2D, texture);
	d = LoadTexture("c.bmp");
	glBindTexture(GL_TEXTURE_2D, d);
	glutDisplayFunc(draw);
	glutReshapeFunc(reshape);
	glutIdleFunc(draw);
	glutSpecialFunc(ArrowKey);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}
