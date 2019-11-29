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

void mouseButton(int button, int state, int x, int y) {

	// only start motion if the left button is pressed
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			//xOrigin = -1;
			std::cout << "estoy en click x " << x << "e y " << y << std::endl;
			/*algo += 0.1f;
			GLdouble modelMatrix[16];
			GLdouble projMatrix[16];
			GLint viewport[4];

			glGetIntegerv(GL_VIEWPORT, viewport);
			glGetDoublev(GL_MODELVIEW_MATRIX, modelMatrix);
			glGetDoublev(GL_PROJECTION_MATRIX, projMatrix);

			GLdouble x, y, z;
			gluUnProject((double)x, viewport[1] + viewport[3] - (double) y, 0.0, modelMatrix, projMatrix, viewport, &x, &y, &z);
			std::cout << "estoy en click x " << x << " y " << y << " z " << z << std::endl;
			gluUnProject((double)x, viewport[1] + viewport[3] - (double)y, 1.0, modelMatrix, projMatrix, viewport, &x, &y, &z);

			std::cout << "estoy en click x " << x << " y " << y << " z "<< z<< std::endl;*/
//			cube(0.0,0.0,0.8);
			/*glPushMatrix();
			glColor3f(0.1, 1.0, 0.3);
			glShadeModel(GL_SMOOTH);
			glTranslatef(0.0, 0.0, 0.4);
			//glScalef(0.25, 0.4, 0.25);
			glutSolidCube(0.7f);
			glPopMatrix();
			glutSwapBuffers();*/
			//glutPostRedisplay();
		//	check = false
			if (state != GLUT_DOWN)
				return;

		//	window_width = glutGet(GLUT_WINDOW_WIDTH);
		//	window_height = glutGet(GLUT_WINDOW_HEIGHT);

			GLbyte color[4];
			GLfloat depth;
			GLuint index;

			glReadPixels(x, glutGet(GLUT_WINDOW_HEIGHT) - y - 1, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, color);
			glReadPixels(x, glutGet(GLUT_WINDOW_HEIGHT) - y - 1, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth);
			glReadPixels(x, glutGet(GLUT_WINDOW_HEIGHT) - y - 1, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);

			printf("Clicked on pixel %d, %d, color %02hhx%02hhx%02hhx%02hhx, depth %f, stencil index %u\n",
				x, y, color[0], color[1], color[2], color[3], depth, index);
			

	}
	glutPostRedisplay();
}
