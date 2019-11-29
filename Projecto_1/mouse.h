#pragma once
#include "tokens.h"
#include <math.h>
int xOrigin = -1;
float algo = 0.0f;
void mouseMove(int x, int y) {

	// this will only be true when the left button is down
	if (xOrigin >= 0) {

		// update deltaAngle
		//deltaAngle = (x - xOrigin) * 0.001f;

		// update camera's direction
		//lx = sin(angle + deltaAngle);
		//lz = -cos(angle + deltaAngle);
		std::cout << "estoy en moviemiento en x " << x << "e y "<<  y<< std::endl;
	}
}
void tic() {
	//las posiciones se dan entre -0.4 0 y 0.4
	/*Dibujo el cubo*/
	for (float i = 0.0f; i < 1.2f; i += 0.4f) {
		if (i == 0.4f) {
			//
			//cubo centro abajo y = -0.4
			cube(0.0, -i, 0.0, 2);
			//cubo centro arriba y = 0.4
			cube(0.0, i, 0.0, 3);
			//cubo centro derecha x = 0.4
			cube(i, 0.0, 0.0, 4);
			//cubo centro izquierda x = -0.4
			cube(-i, 0.0, 0.0, 5);
			//cubo centro adelante z = 0.4
			cube(0.0, 0.0, i, 6);
			//cubo centro atras z = -0.4
			cube(0.0, 0.0, -i, 7);
		}
		else if (i == 0.0f) {
			cube(0.0, i, 0.0, 1);
		}

	}
	/*
	dibujo las esferas
	*/
	for (float x = -0.4f,   i =8; x < 0.8f; x += 0.4f,i++) {
		for (float y = -0.4f,   j =0; y < 0.8f; y += 0.4f, j++) {
			for (float z = -0.4f,   k = 0; z < 0.8f; z += 0.4f,k++) {
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
					sphere(x, y, z,i+j+k);
				}
				else if (y == 0.0f) {
					glColor3f(0.0, 0.0, 1.0);
					sphere(x, y, z, i + j + k);
				}
				else if (y == -0.4f) {
					glColor3f(1.0, 0.0, 1.0);
					sphere(x, y, z, i + j + k+ algo);
				}


			}
		}
	}
	//glutMouseFunc(mouseButton);



}
//metodo que rota en x e y los angulos
void rotate(){
	glRotatef(anglex, 1.0, 0.0, 0.0);			
	glRotatef(angley, 0.0, 1.0, 0.0);
}
/*
renderisa con la posicion de la camara
*/
void draw() {
	glEnable(GL_TEXTURE_2D);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(x, 0.0f, z, //ojo
		x + lx, 0.0f, z + lz,//mirar //arriba
		0.0f, 1.0f, 0.0f);//inclinacion //centro
	//roto mi juego
	rotate();
	tic();
	glutSwapBuffers();
}
void processHits(GLint hits, GLuint buffer[]){
	unsigned int i, j, k;
	GLuint ii, jj, names, *ptr;

	//   printf ("hits = %d\n", hits);
	ptr = (GLuint *)buffer;
	for (i = 0; i < hits; i++) {	/*  for each hit  */
		names = *ptr;
		//      printf (" number of names for this hit = %d\n", names);
		ptr++;
		//      printf("  z1 is %g;", (float) *ptr/0x7fffffff);
		ptr++;
		//      printf(" z2 is %g\n", (float) *ptr/0x7fffffff);
		ptr++;
		printf("\n objeto n° ");
		for (j = 0; j < names; j++) { /*  for each name */
			printf("%d ", *ptr);
			k = *ptr - 1;
			ptr++;
		}
		printf("\n");
	}
}

//funcion click para mi mouse
void mouseButton(int button, int state, int x, int y) {
	GLuint selectBuf[BUFSIZE];
	GLint hits;
	GLint viewport[16];

	if (button != GLUT_LEFT_BUTTON || state != GLUT_DOWN)
		return;
	//PlaySound("GTAS.wav", NULL, SND_ASYNC);
	glGetIntegerv(GL_VIEWPORT, viewport);

	glSelectBuffer(BUFSIZE, selectBuf);
	glRenderMode(GL_SELECT);

	glInitNames();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	gluPickMatrix((GLdouble)x, (GLdouble)(viewport[3] - y),
		5.0, 5.0, viewport);
	// gluOrtho2D (0.0, 3.0, 0.0, 3.0);
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	draw();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glutSwapBuffers();


	hits = glRenderMode(GL_RENDER);
	processHits(hits, selectBuf);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glTranslatef(0.0, 0.0, -50);

	glutPostRedisplay();
}
