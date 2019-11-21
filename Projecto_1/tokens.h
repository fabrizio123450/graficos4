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
float x = 0.0f, z = 1.5f;
