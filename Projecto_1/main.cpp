//#include "cubo.h"
#include "tokens.h"
#include "mouse.h"
//Camera camera;
int anglex = 0, angley = 0, anglez = 0;
bool check = true;
void init(void) {
	glClearColor(0.623529f, 0.623529f, 0.372549f, 0.0);//inicializamos glut limpiando el color
	glShadeModel(GL_SMOOTH);//para rellenar de color los polígonos. Si el parámetro es GL_FLAT, ogl rellenará los polígonos con el color activo
}
/*Prueba de textura

NO FUNCIONA*/
//fin de prueba texturag//
void tic() {
	//las posiciones se dan entre -0.4 0 y 0.4
	/*Dibujo el cubo*/
	for (float i = 0.0f; i < 1.2f; i+=0.4f) {
		if (i == 0.4f) {
			//
			//cubo centro abajo y = -0.4
			cube(0.0, -i,0.0);
			//cubo centro arriba y = 0.4
			cube(0.0, i, 0.0);
			//cubo centro derecha x = 0.4
			cube(i, 0.0, 0.0);
			//cubo centro izquierda x = -0.4
			cube(-i, 0.0, 0.0);
			//cubo centro adelante z = 0.4
			cube(0.0, 0.0, i);
			//cubo centro atras z = -0.4
			cube(0.0, 0.0, -i);
		}
		else if (i == 0.0f) {
			cube(0.0, i, 0.0);
		}

	}
	/*
	dibujo las esferas
	*/
	for (float x = -0.4f; x < 0.8f; x += 0.4f) {
		for (float y = -0.4f; y < 0.8f; y += 0.4f) {
			for (float z = -0.4f; z < 0.8f; z += 0.4f) {
				//no pintar en posicion de los cuadrados en caso de que sea una posicion continua en el siguiente loop
				if (x == -0.4f && z == 0.0f && y == 0.0f || x == 0.4f && z == 0.0f && y == 0.0f) {
					continue;
				}
				else if (x == 0.0f && z == 0.4f && y == 0.0f || x == 0.0f && z == -0.4f && y == 0.0f) {
					continue;
				}
				else if (x == 0.0f && z == 0.0f && y == 0.4f || x == 0.0f && z == 0.0f && y == -0.4f) {
					continue;
				}
				else if (x == 0.0f && z == 0.0f && y == 0.0f) {
					continue;
				}
				//
				/*cambia el color segun el piso del tateti*/
				if (y == 0.4f) {
					glColor3f(1.0, 0.0, 0.0);
					sphere(x, y, z);
				}
				else if (y == 0.0f) {
					glColor3f(0.0, 0.0, 1.0);
					sphere(x, y, z);
				}
				else if (y == -0.4f) {
					glColor3f(1.0, 0.0, 1.0);
					sphere(x, y, z);
				}


			}
		}
	}
	//glutMouseFunc(mouseButton);



}

void rotate()
{
	glRotatef(anglex, 1.0, 0.0, 0.0);			//rotate along x-axis
	glRotatef(angley, 0.0, 1.0, 0.0);			//rotate along y-axis	
	glRotatef(anglez, 0.0, 0.0, 1.0);			//rotate along z-axis
}
void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, w / h, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
}
/*
renderisa con la posicion de la camara
*/
void render_room() {
	glEnable(GL_TEXTURE_2D);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(x, 0.0f, z, //ojo
		x + lx, 0.0f, z + lz,//mirar //arriba
		0.0f, 1.0f, 0.0f);//inclinacion //centro
	
	rotate();
	tic();
	//glutMouseFunc(mouseButton);
	glutSwapBuffers();
}
/*uso del teclado*/
void ArrowKey(int key, int x, int y) {
	switch (key) {
	//abajo
	case GLUT_KEY_DOWN:
		anglex = (anglex + 3) % 360;
		break;
		//derecha
	case GLUT_KEY_RIGHT:
		angley = (angley + 3) % 360;
		break;
	case 27: /* escape */
		exit(0);
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
	case GLUT_KEY_DOWN:
		anglex = (anglex + 3) % 360;
		break;
	case 'l':
		anglex = (anglex - 3) % 360;
		break;
	case 'y':
		angley = (angley + 3) % 360;
		break;
	case 'Y':
		angley = (angley - 3) % 360;
		break;
	case 'z':
		anglez = (anglez + 3) % 360;
		break;
	case 'Z':
		anglez = (anglez - 3) % 360;
		break;
	case 'r':
		anglex = angley = anglez = 0;
		break;
	case 27: /* escape */
		exit(0);
	}
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(480, 480);
	glutInitWindowPosition(500, 100);
	glutCreateWindow("Proyecto 4");
	init();
	texture = LoadTexture("b.bmp");
	glBindTexture(GL_TEXTURE_2D, texture);
	d = LoadTexture("c.bmp");
	glBindTexture(GL_TEXTURE_2D, d);
	glutDisplayFunc(render_room);
	glutReshapeFunc(reshape);
	glutIdleFunc(render_room);
	glutSpecialFunc(ArrowKey);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}
