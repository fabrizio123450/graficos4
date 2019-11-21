//#include "cubo.h"
#include "tokens.h"
void init(void){
	glClearColor(0.623529f, 0.623529f, 0.372549f, 0.0);//inicializamos glut limpiando el color
	glShadeModel(GL_SMOOTH);//para rellenar de color los polígonos. Si el parámetro es GL_FLAT, ogl rellenará los polígonos con el color activo
}
/*piso
pared
ventana y puerta*/
void floor_more() {	
	/*glBegin(GL_QUADS);
	//suelo
	glColor3f(0.91f, 0.76f, 0.65f);
	glVertex3f(-1.0f, 0.0f, -1.0f);//arriba izquierda
	glVertex3f(-1.0f, 0.0f, 1.0f);//abajo izquierda
	glVertex3f(1.0f, 0.0f,1.0f);//abajo derecha
	glVertex3f(1.0f, 0.0f, -1.0f);//arriba derecha

	//pared izquierda
	glColor3f(0.81f, 0.76f, 0.65f);     
	glVertex3f(-1.0f, 2.0f, 1.0f);//arriba izquierda
	glVertex3f(-1.0f, 2.0f, -1.0f);//arriba derecha
	glVertex3f(-1.0f, 0.0f, -1.0f);//abajo derecha
	glVertex3f(-1.0f, 0.0f, 1.0f);//abajo izquierda

	//puerta
	glColor3f(0.55f, 0.55f, 0.55f);
	glVertex3f(-0.99f, 1.0f, 0.2f);//arriba izquierda
	glVertex3f(-0.99f, 1.0f, -0.2f);//arriba derecha
	glVertex3f(-0.99f, 0.0f, -0.2f);//abajo derecha
	glVertex3f(-0.99f, 0.0f, 0.2f);//abajo izquierda

	glColor3f(0.55f, 0.55f, 0.55f);
	glVertex3f(-1.01f, 1.0f, 0.2f);//arriba izquierda
	glVertex3f(-1.01f, 1.0f, -0.2f);//arriba derecha
	glVertex3f(-1.01f, 0.0f, -0.2f);//abajo derecha
	glVertex3f(-1.01f, 0.0f, 0.2f);//abajo izquierda

	//pared trasera
	glColor3f(0.71f, 0.76f, 0.65f);
	glVertex3f(1.0f, 0.0f, -1.0f);//derecha abajo
	glVertex3f(-1.0f, 0.0f, -1.0f);//izquierda abajo
	glVertex3f(-1.0f, 2.0f, -1.0f);//izquierda arriba
	glVertex3f(1.0f, 2.0f, -1.0f);//derecha arriba
	//ventana
	glColor3f(0.41f, 0.46f, 0.75f);
	glVertex3f(0.2f, 1.5f, -0.99f);//derecha abajo
	glVertex3f(-0.2f, 1.5f, -0.99f);//izquierda abajo
	glVertex3f(-0.2f, 0.7f, -0.99f);//izquierda arriba
	glVertex3f(0.2f, 0.7f, -0.99f);//derecha arriba

	glColor3f(0.41f, 0.46f, 0.75f);
	glVertex3f(0.2f, 1.5f, -1.01f);//derecha abajo
	glVertex3f(-0.2f, 1.5f, -1.01f);//izquierda abajo
	glVertex3f(-0.2f, 0.7f, -1.01f);//izquierda arriba
	glVertex3f(0.2f, 0.7f, -1.01f);//derecha arriba
	glEnd();*/

	//cubo hace 7
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glTranslatef(0.0, 0.0, 0.0);
	glScalef(0.25, 0.4, 0.25);
	glutSolidCube(0.5f);
	glPopMatrix();

	//esfera hace 11
	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glShadeModel(GL_SMOOTH);
	glTranslatef(0.0, 0.0, 0.0);
	glScalef(0.15, 0.25, 0.15);
	glutSolidSphere(0.5f, 25, 25);
	glPopMatrix();
}
/*
dibujo mis elementos
*/
/*void draw() {
	cubo a;
	a.parseread("cubo.txt");
	a.parseread("teapot.txt");
	
}*/
/*esceba completa*/
void room(void){
	floor_more();
	//draw();
}
void reshape(int w, int h) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45.0f, w/h, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}
/*
renderisa con la posicion de la camara
*/
void render_room() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(x, 0.0f, z, //ojo
		x + lx, 0.0f, z + lz,//mirar //arriba
		0.0f, 1.0f, 0.0f);//inclinacion //centro
	room();
	glutSwapBuffers();
}
/*uso del teclado*/
void keyboard(unsigned char key, int xx, int yy) {
	switch (key) {
	case 'a'://izquierda
	case 'A':
		angle -= 0.01f;
		lx = sin(angle);
		lz = -cos(angle);
		break;
	case 'd'://derecha
	case 'D':
		angle += 0.01f;
		lx = sin(angle);
		lz = -cos(angle);
		break;
	case 'w'://adelante
	case 'W':
		x += lx * 0.1f;
		z += lz * 0.1f;
		break;
	case 's'://atras
	case 'S':
		x -= lx * 0.1f;
		z -= lz * 0.1f;
		break;
	}
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB| GLUT_DEPTH);
	glutInitWindowSize(1280, 720);
	glutInitWindowPosition(50, 0);
	glutCreateWindow("ROOM");
	init();
	glutDisplayFunc(render_room);
	glutReshapeFunc(reshape);
	glutIdleFunc(render_room);
	glutKeyboardFunc(keyboard);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}
