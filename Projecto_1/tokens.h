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
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
//#include "mouse.h"
using namespace std;
//tikes que uso
string tokens[10] = { "cubo", "color", "tran", "sca", "tam", "}", "tea" };
int anglex = 0, angley = 0;
#define WINDOW_WIDTH	480
#define WINDOW_HEIGHT	480
#define BUFSIZE 512
float ratio = 0.0f;
float angle = 0.0f;
// representa la direccion de la camara
float lx = 0.0f, lz = -1.0f;
// posicion de la camara
float x = 0.0f, z = 2.5f;
GLuint d;
GLuint texture;
GLuint LoadTexture(const char * filename)
{

	GLuint texture;
	

	int width, height;

	unsigned char * data;

	FILE * file;

	file = fopen(filename, "rb");

	if (file == NULL) return 0;
	width = 512;
	height = 256;
	data = (unsigned char *)malloc(width * height * 3);
	//int size = fseek(file,);
	fread(data, width * height * 3, 1, file);
	fclose(file);

	for (int i = 0; i < width * height; ++i)
	{
		int index = i * 3;
		unsigned char B, R;
		B = data[index];
		R = data[index + 2];

		data[index] = R;
		data[index + 2] = B;

	}


	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);


	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
	free(data);

	return texture;
}


void cube(float x, float y, float z, GLuint name) {
	glPushName(name);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glBindTexture(GL_TEXTURE_2D, d);
	glPushMatrix();
	glColor3f(0.1, 0.0, 0.3);
	glShadeModel(GL_SMOOTH);
	glTranslatef(x, y, z);
	glScalef(0.25, 0.4, 0.25);
	glutSolidCube(0.5f);
	glPopName();
	glPopMatrix();
}

void sphere(float x, float y, float z, GLuint name) {
	glPushName(name);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glBindTexture(GL_TEXTURE_2D, texture);
	glPushMatrix();
	glShadeModel(GL_SMOOTH);
	glTranslatef(x, y, z);
	glScalef(0.15, 0.25, 0.15);
	glutSolidSphere(0.5f, 25, 25);
	glPopName();
	glPopMatrix();
}