#ifndef KVADRACH
#define KVADRACH
//#define DEBUG

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <TXLib.h>

enum Roots
{   NO_ROOT = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    ALL_ROOTS = 3 };

const double EPSILON = 0.0001;
const int MAXLINE = 1000;

double get(char k);
int compare(double a, double b);
int linecase(double a, double b, double *x1);
int sqrcase(double a, double b, double c, double *x1, double *x2);
void fixzero(double *a);
void solve(double a, double b, double c, enum Roots *nRoot, double *x1, double *x2);
void test(char *path);
int singletest(double a, double b, double c, int testnRoots, double testx1, double testx2);

#endif
