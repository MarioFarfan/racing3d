// Texturas.cpp: define el punto de entrada de la aplicación de consola.
//
#include "stdafx.h"
#include <windows.h>
#include <glut.h>
#include <GL/glu.h>
#include "ImageLoader.h"
#include <time.h>
#include <math.h>
#include <iostream>
#include <thread>
#include <chrono>


using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

static int lados = 0;
static double x = 0.7, y = 0.0, z = -0.1;
static double tras = 0.1;
static double zz = 0, xx = 0;
int masx = 0;
int masz = 0;
int bandera1 = 0;
static int teclaA = 0;
static int teclaD = 0;

int refreshMills = 15;
int bandera3 = 0;
int bandera4 = 0;
int bandera5 = 0;
int bandera6 = 0;
int bandera7 = 0;
int bandera8 = 0;
int bandera9 = 0;
int bandera10 = 0;
int bandera11 = 0;
int bandera12 = 0;
int flag = 0;
static int r = 0;
bool salir = false;
static char* texto = "Dispara a todos los objetivos";
static int angulo = 0;
static int direccion[] = { 0,30,60,90,120,150,180,210,240,270,300,330 };
static int matriz[144][27] = {{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,3,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,3,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,3,3,3,3,3,3,3,3,3,0,0,0,3,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,3,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,3,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,3,0,0,0,0,0,3,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,3,0,0,0,0,0,0,0,0,3,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,3,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,3,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,3,0,0,0,0,3,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,3,3,0,0,0,0,0,0,0,0,3,0,0,3,0,3,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,1,1,1,1 },
{ 1,1,1,1,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };
	static int cuadros[36][9] = {
		{ 1,1,1,1,1,1,1,1,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,1,1,1,1,1,1,1,1 } };

	static int pista[36][9] = {
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1 },
		{ 1,1,1,1,1,1,1,1,1 } };
static int posz = 34, posx = 41;
static int esferas[5][2];
using namespace std;
static int piezas[5] = { 0,0,0,0,0 };
static int contador = 0;

GLuint _pared,_cubito,_suelo,_cielo,_concreto,_borde; 


GLuint loadTexture(Image* image) {
	GLuint idtextura;
	glGenTextures(1, &idtextura);
	glBindTexture(GL_TEXTURE_2D, idtextura);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	return idtextura;
}


void initRendering() {
	Image* lado1 = loadBMP("3.bmp");
	Image* cbt = loadBMP("1.bmp");
	Image* suelo = loadBMP("suelo5.bmp");
	Image* concreto = loadBMP("suelo52.bmp");
	Image* borde = loadBMP("borde.bmp");
	Image* sky = loadBMP("skya.bmp");

	_pared = loadTexture(lado1);
	_cubito = loadTexture(cbt);
	_suelo = loadTexture(suelo);
	_cielo = loadTexture(sky);
	_concreto = loadTexture(concreto);
	_borde = loadTexture(borde);

	delete lado1;
	delete cbt;
	delete suelo;
	delete sky;
	delete concreto;
	delete borde;
	}

void cargarTextura(GLuint _textura) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textura);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void inline drawString(char *s)
{
	unsigned int i;
	for (i = 0; i<strlen(s); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
}

void generarCubo(int xmet, int zmet)
{
	glPushMatrix();
	cargarTextura(_pared);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, 1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, 1.5, 1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, -1.5, 1.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_pared);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, 1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, -1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, 1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, 1.5, 1.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_pared);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(1.5, 1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(1.5, 1.5, -1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, -1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, -1.5, 1.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_pared);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, 1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(-1.5, 1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(-1.5, -1.5, -1.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_pared);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, -1.5, -1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, -1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, -1.5, 1.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_pared);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, -1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, -1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, 1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, -1.5, -1.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_pared);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, -1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, -1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, 1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, -1.5, -1.5);
	glEnd();
	glPopMatrix();

}

void mostrarArma() {
	//Frente
	glPushMatrix();
	glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
	glTranslatef(-0.5f, -2.025f, -1.1f);
	glScalef(1.0f, 1.5f, 0.0f);
	glRectd(0.0f, 0.0f, 1.0f, 1.0f);
	glEnd();
	glPopMatrix();

	//Volante
	glPushMatrix();
	glColor3f(0.1f, 0.1f, 0.1f);
	glTranslatef(-0.2f, -0.9f, -0.85f);
	glScalef(0.1f, 0.1f, 0.1f);
	gluSphere(gluNewQuadric(), 2, 500, 500);
	glEnd();
	glPopMatrix();

	//Lateral derecho
	glPushMatrix();
	glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
	glTranslatef(0.38f, -1.0f, -.8);
	glRotatef(90.0f, .0f, .0f, 1.0f);
	glScalef(.30, -0.05, .1);
	gluSphere(gluNewQuadric(), 3, 100, 100);
	glEnd();
	glPopMatrix();

	//Lateral Izquierdo
	glPushMatrix();
	glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
	glTranslatef(-0.38f, -1.0f, -.8);
	glRotatef(270.0f, .0f, 0.0f, 2.0f);
	glScalef(.30, -0.05f, .1);
	gluSphere(gluNewQuadric(), 3, 100, 100);
	glEnd();
	glPopMatrix();
}

void generarCubito(int x, int z)
{
	glPushMatrix();
	cargarTextura(_cubito);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + x, -0.5, zz + z);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, 0.5, 0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, 0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_cubito);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + x, -0.5, zz + z);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, 0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, 0.5, -0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, 0.5, 0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_cubito);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + x, -0.5, zz + z);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.5, 0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, -0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_cubito);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + x, -0.5, zz + z);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, 0.5, 0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.5, 0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_cubito);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + x, -0.5, zz + z);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, -0.5, -0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, -0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_cubito);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + x, -0.5, zz + z);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, -0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, 0.5, -0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, -0.5, -0.5);
	glEnd();
	glPopMatrix();
}

void mostrarcuadros()
{
	int x = -6, z =-42, i, j;

	for (i = 0; i<36; i++)
	{
		for (j = 0; j<9; j++)
		{
			if (cuadros[i][j] == 1)
			{
				if (i == 36 && j == 1)
				{

				}
				else {
					generarCubo(x, z);
				}
			}
			x = x + 3;
		}
		z = z + 4;
		x = -6;
	}
}

static void key(unsigned char key, int x, int y) {

	int esferasx = 0;
	int esferasz = 0;
	int bandera = 0;
	int bandera2 = 0;
	int banderaYO = 0;
	int comprobar = 0;
	int aux1 = 0;
	int aux2 = 0;

	switch (key)
	{
	case '.':
		if (teclaD == 3) {
			teclaD = 2;
			teclaA = -2;
			angulo = 2;
			r = direccion[angulo];
			break;
		}
		_asm {
			CMP key, '.'
			JNE sa
			MOV EAX, angulo

			CMP EAX, 0
			JE igual

			DEC EAX
			MOV angulo, EAX
			JMP sa

			prueba : MOV EAX, 11
					 MOV angulo, EAX
					 sb :
		}
		r = direccion[angulo];
		break;

	case 'a':
		if (teclaD == 3) {
			teclaD = 2;
			teclaA = -2;
			angulo = 2;
			r = direccion[angulo];
			break;
		}
		else if (teclaA > -3 && teclaA < 3) {
			teclaD--;
			teclaA++;
			_asm {
				CMP key, 'a'
				JNE sa
				MOV EAX, angulo

				CMP EAX, 0
				JE igual

				DEC EAX
				MOV angulo, EAX
				JMP sa

				igual : MOV EAX, 11
						MOV angulo, EAX
						sa :
			}
			r = direccion[angulo];
		}

		break;
	case 'd':
		if (teclaA == 3) {
			teclaA = 2;
			teclaD = -2;
			angulo = 10;
			r = direccion[angulo];
			cout << angulo << endl;
			break;
		}
		else if (teclaD > -3 && teclaD < 3) {
			teclaA--;
			teclaD++;
			_asm {
				CMP key, 'd'
				JNE sa2
				MOV EAX, angulo

				CMP EAX, 0
				JE cero
				CMP EAX, 11
				JE once

				INC EAX
				MOV angulo, EAX
				JMP sa2
				cero : MOV EAX, 1
					   MOV angulo, EAX
					   JMP sa2

					   once : MOV EAX, 0
							  MOV angulo, EAX
							  sa2 :
			}
		}

		r = direccion[angulo];
		break;
	case 'w':

		texto = " ";
		_asm { CMP key, 'w'
		JNE fin

			sa3 : MOV EAX, r
			CMP EAX, 0
			JAE validar
			JMP nada
			validar : CMP EAX, 30
			JBE accion
			CMP EAX, 330
			JE accion
			JMP nada
			accion : MOV EDX, posx
			DEC EDX
			MOV masx, EDX
			MOV EDX, posz
			MOV masz, EDX
			MOV flag, 1
			fuera : MOV bandera1, 1
			JMP fin
			nada :
	fin:
		}
		if (flag == 1)
		{

			if (bandera1 == 1)
			{
				aux1 = matriz[masx][masz];
				if(aux1==3){
				texto="CHOCASTE, HAS PERDIDO";
				}
				if (aux1 == 1) {
					texto = "HAS GANADO";
				}
				
			}

			_asm {
				MOV EAX, aux1
				CMP EAX, 1
				JE sa4
				CMP EAX, 3
				JE sa4

				sig : MOV bandera2, 1
					  JMP sa4
					  sa4 :
			}

			if (bandera2 == 1)
			{
				zz = zz + 1;
				posx = posx - 1;
			}

			_asm {
				MOV EAX, masx
				CMP EAX, 71
				JE two
				JMP nada2
				two : MOV EDX, masz
					  CMP EDX, 3
					  JE exito

					  CMP EDX, 4
					  JE exito

					  CMP EDX, 5
					  JE exito
					  JMP nada2
					  exito : MOV bandera3, 1
							  nada2 :
			}
		}
		_asm {
			MOV EAX, r
			CMP EAX, 60
			JAE validar2
			JMP nada3
			validar2 : CMP EAX, 120
					   JBE accion2
					   JMP nada3
					   accion2 : MOV EAX, posx
								 MOV masx, EAX
								 MOV EAX, posz
								 INC EAX
								 MOV masz, EAX
								 MOV flag, 2
								 MOV bandera4, 1
								 nada3 :
		}
		if (flag == 2) {

			if (bandera4 == 1)
			{
				aux1 = matriz[masx][masz];
				aux2 = matriz[masx][masz];
			}

			if (matriz[masx][masz] != 1 && matriz[masx][masz] != 3)
			{
				xx = xx - 1;
				posz = posz + 1;
			}
		}
		_asm {
			MOV EAX, r
			CMP EAX, 150
			JAE validar6
			JMP nada6
			validar6 : CMP EAX, 210
					   JBE accion6
					   JMP nada6
					   accion6 : MOV EAX, posx
								 INC EAX
								 MOV masx, EAX
								 MOV EAX, posz
								 MOV masz, EAX
								 MOV flag, 3
								 MOV bandera7, 1
								 nada6 :
		}
		if (flag == 3) {
			
			if (bandera7 == 1)
			{
				aux1 = matriz[masx][masz];
				aux2 = matriz[masx][masz];
			}

			if (matriz[masx][masz] != 1 && matriz[masx][masz] != 3)
			{
				zz = zz - 1;
				posx = posx + 1;
			}

			_asm {
				MOV EAX, masx
				CMP EAX, 71
				JE two8

				JMP nada8
				two8 : MOV EAX, masz
					   CMP EAX, 3
					   JE exito8

					   CMP EAX, 4
					   JE exito8

					   CMP EAX, 5
					   JE exito8
					   JMP nada8
					   exito8 : MOV bandera9, 1
								nada8 :
			}
		}

		_asm {

			MOV EAX, r
			CMP EAX, 240
			JAE validar9
			JMP nada9
			validar9 : CMP EAX, 300
					   JBE accion9
					   JMP nada9
					   accion9 : MOV EAX, posx
								 MOV masx, EAX
								 MOV EAX, posz
								 DEC EAX
								 MOV masz, EAX
								 MOV flag, 4
								 MOV bandera10, 1
								 nada9 :
		}
		if (flag == 4) {

			if (bandera10 == 1)
			{
				aux1 = matriz[masx][masz];
				aux2 = matriz[masx][masz];
			}

			if (matriz[masx][masz] != 1 && matriz[masx][masz] != 3)
			{
				xx = xx + 1;
				posz = posz - 1;
			}

			_asm {
				MOV EAX, masx
				CMP EAX, 71
				JE two11

				JMP nada11
				two11 : MOV EAX, masz
						CMP EAX, 3
						JE exito11

						CMP EAX, 4
						JE exito11

						CMP EAX, 5
						JE exito11
						JMP nada11
						exito11 : MOV bandera12, 1
								  nada11 :
			}
		}

		break;
	}

	glutPostRedisplay();
}

void avanzar() {
	key('w', 0, 0);
	sleep_for(milliseconds(150));
}

void colocar() {
	
	for (int j = 0; j<6; j++) {
		key('.', 0, 0);
	}
	for (int j = 0; j<95; j++) {
		key('w', 0, 0);
	}
	for (int j = 0; j<3; j++) {
		key('.', 0, 0);
	}
	for (int j = 0; j<5; j++) {
		key('w', 0, 0);
	}
	for (int j = 0; j<3; j++) {
		key('.', 0, 0);
	}
}

void generarPiso(int x, int z) {
	glColor3d(0.5, 0.5, 0.5);
	glPushMatrix();
	cargarTextura(_concreto);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + x, 0.4, zz + z);

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-3, -1.5, 3);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-3, -1.5, -3);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(3, -1.5, -3);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(3, -1.5, 3);
	glEnd();
	glPopMatrix();

}

void generarBorde(int x, int z) {
	glColor3d(0.5, 0.5, 0.5);
	glPushMatrix();
	cargarTextura(_borde);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + x, 0.5, zz + z);

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-3, -1.5, 3);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-3, -1.5, -3);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(3, -1.5, -3);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(3, -1.5, 3);
	glEnd();
	glPopMatrix();

}

void mostrarPiso()
{
	int x = -6, z = -38, i, j;

	for (i = 0; i<36; i++)
	{
		for (j = 0; j<9; j++)
		{
			if (pista[i][j] == 0 ) {
				generarPiso(x, z);
			}
			else if (pista[i][j] == 1) {
				generarBorde(x,z);
			}
			x = x + 3;
		}
		z = z + 6;
		x = -6;
	}

}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3d(0.5, 0.5, 0.5);
	
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);

	mostrarcuadros();
	mostrarArma();
	mostrarPiso();

	/*glColor3d(0.5, 0.5, 0.5);
	glPushMatrix();
	cargarTextura(_suelo);
	glRotated(r, 0, 1, 0);
	glTranslated(xx, 0.4, zz);

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-33, -1.6, -42);
	glTexCoord2f(100.0f, 0.0f);
	glVertex3f(48, -1.6, -42);
	glTexCoord2f(100.0f, 100.0f);
	glVertex3f(48, -1.6, 30);
	glTexCoord2f(0.0f, 100.0f);
	glVertex3f(-33, -1.6, 30);
	glEnd();
	glPopMatrix();
	*/
	glColor3d(0.5, 0.5, 0.5);
	glPushMatrix();
	cargarTextura(_cielo);
	glRotated(r, 0, 1, 0);
	glTranslated(xx, 15, zz);



	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-100, -11.6, -100);
	glTexCoord2f(100.0f, 0.0f);
	glVertex3f(100, -11.6, -100);
	glTexCoord2f(100.0f, 100.0f);
	glVertex3f(100, -11.6, 100);
	glTexCoord2f(0.0f, 100.0f);
	glVertex3f(-100, -11.6, 100);
	glEnd();
	glPopMatrix();

	int x = -7, z = -43, i, j;

	for (i = 0; i<144; i++)
	{
		for (j = 0; j<27; j++)
		{
			if (matriz[i][j] == 3)
			{	
				glColor3d(0.6, 0.6, 0.6);
				generarCubito(x, z);
				glColor4f(2.0, 1.0, 1.0,0);
			}
			x = x + 1;
		}
		z = z + 1;
		x = -7;
	}

	glRasterPos3f(-0.4, 0, -1);
	
	glPushMatrix();
	drawString(texto);

	glutSwapBuffers();
	 avanzar();
}

void reshape(int width, int height){
	const float ar = (float)width / (float)height;
	double aspect = height / width;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

static void idle(void)
{
	glutPostRedisplay();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(1000, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutCreateWindow("Graficacion 3ra Unidad");
	glutSetCursor(GLUT_CURSOR_NONE);
	initRendering();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(key);
	glutIdleFunc(idle);
	glClearColor(0, 0.5, 0.7, 1);
	colocar();
	glutMainLoop();
	return 0;
}