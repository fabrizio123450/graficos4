#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "GL/freeglut.h"
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctype.h>
using namespace std;
//tikes que uso
string tokens[10] = { "cubo", "color", "tran", "sca", "tam", "}", "tea" };

float angle = 0.0f;
// representa la direccion de la camara
float lx = 0.0f, lz = -1.0f;
// posicion de la camara
float x = 0.0f, z = 2.5f;

void cube(float x, float y, float z) {
	glPushMatrix();
	glColor3f(0.1, 0.0, 0.3);
	glShadeModel(GL_SMOOTH);
	glTranslatef(x, y, z);
	glScalef(0.25, 0.4, 0.25);
	glutSolidCube(0.5f);
	glPopMatrix();
}

void sphere(float x, float y, float z) {
	glPushMatrix();
	glShadeModel(GL_SMOOTH);
	glTranslatef(x, y, z);
	glScalef(0.15, 0.25, 0.15);
	glutSolidSphere(0.5f, 25, 25);
	glPopMatrix();
}