//#include "cubo.h"
#include "tokens.h"
void init(void){
	glClearColor(0.623529f, 0.623529f, 0.372549f, 0.0);//inicializamos glut limpiando el color
	glShadeModel(GL_SMOOTH);//para rellenar de color los polígonos. Si el parámetro es GL_FLAT, ogl rellenará los polígonos con el color activo
}
/*piso
pared
ventana y puerta*/
void unico() {
	glPushMatrix();
	glColor3f(0.1, 0.0, 0.3);
	glShadeModel(GL_SMOOTH);
	glTranslatef(0.0, 0.5, -0.4);
	glScalef(0.25, 0.4, 0.25);
	glutSolidCube(0.5f);

	//glutSolidCube(0.5f);
	glPopMatrix();

	//esfera hace 11
	glPushMatrix();
	glColor3f(0.1, 0.0, 0.3);
	glShadeModel(GL_SMOOTH);
	glTranslatef(0.0, 0.0, -0.4);
	glScalef(0.25, 0.4, 0.25);
	glutSolidCube(0.5f);
	glPopMatrix();



	glPushMatrix();
	glColor3f(0.1, 0.0, 0.3);
	glShadeModel(GL_SMOOTH);
	glTranslatef(0.0f, -0.5, -0.4f);
	glScalef(0.25, 0.4, 0.25);
	glutSolidCube(0.5f);
	glPopMatrix();
}
void center() {
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glTranslatef(0.0, 0.6, 0.0);
	glScalef(0.15, 0.25, 0.15);
	glutSolidSphere(0.5f, 25, 25);

	//glutSolidCube(0.5f);
	glPopMatrix();

	//esfera hace 11
	glPushMatrix();
	glColor3f(0.1, 0.0, 0.3);
	glShadeModel(GL_SMOOTH);
	glTranslatef(0.0, 0.0, 0.0);
	glScalef(0.25, 0.4, 0.25);
	glutSolidCube(0.5f);
	glPopMatrix();



	glPushMatrix();
	glColor3f(1.0, 0.0, 1.0);
	glShadeModel(GL_SMOOTH);
	glTranslatef(0.0f, -0.5, 0.0f);
	glScalef(0.15, 0.25, 0.15);
	glutSolidSphere(0.5f, 25, 25);
	glPopMatrix();


}
void floor_more() {	
	
	//cubo hace 7
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glTranslatef(-0.3, 0.6, 0.0);
	glScalef(0.15, 0.25, 0.15);
	glutSolidSphere(0.5f, 25, 25);

	//glutSolidCube(0.5f);
	glPopMatrix();

	//esfera hace 11
	glPushMatrix();
	glColor3f(-0.3, 0.0, 1.0);
	glShadeModel(GL_SMOOTH);
	glTranslatef(-0.3, 0.0, 0.0);
	glScalef(0.15, 0.25, 0.15);
	glutSolidSphere(0.5f, 25, 25);
	glPopMatrix();

	

	glPushMatrix();
	glColor3f(1.0, 0.0, 1.0);
	glShadeModel(GL_SMOOTH);
	glTranslatef(-0.3f, -0.5, 0.0f);
	glScalef(0.15, 0.25, 0.15);
	glutSolidSphere(0.5f, 25, 25);
	glPopMatrix();

}

void room(void){
	floor_more();
	
	
}
void reshape(int w, int h) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45.0f, w/h, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}
void repite(){
	room();


	glPushMatrix();
	glTranslatef(-0.3f, -0.0, -0.4f);
	center();
	glPopMatrix();



	glPushMatrix();
	glTranslatef(-0.0f, 0.0, -0.7f);
	room();
	glPopMatrix();
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
	//seccion izquierda
	repite();

	//seccion del centro
	unico();
	center();
	glPushMatrix();
	glTranslatef(0.3f, 0.0, -0.7f);
	room();
	glPopMatrix();


	
	//seccion derecha
	glPushMatrix();
	glTranslatef(0.6f, 0.0, 0.0f);
	repite();
	glPopMatrix();
	
	
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
