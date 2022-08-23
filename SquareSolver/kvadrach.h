#include <stdio.h>
#include <math.h>
#include <stdlib.h>

enum roots { NO_ROOT, ONE_ROOT, TWO_ROOTS, ALL_ROOTS };

const double EPSILON = 0.0001;

double get(char k);
int compare(double a, double b);
enum roots linecase(double a, double b, double *x1);
enum roots sqrcase(double a, double b, double c, double *x1, double *x2);
void fixzero(double *a);
