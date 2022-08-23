#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const double EPSILON = 0.0001;
const int ALL = 3;

//на фацлы разбить : ъедер, мейн и функции

double get(char k);
int compare(double a, double b);
int linecase(double a, double b, double *x1);
int sqrcase(double a, double b, double c, double *x1, double *x2);

main() {
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    int nRoot = 0;

    a = get('a');
    b = get('b');
    c = get('c');

    nRoot = compare(a, 0) ? linecase(b, c, &x1) : sqrcase(a, b, c, &x1, &x2);
    switch(nRoot) {
        case 0:
            printf("No solutions\n");
            break;
        case 1:
            printf("%lg is only solution\n", x1);
            break;
        case 2:
            printf("Both %lg and %lg are solutions\n", x1, x2);
            break;
        case ALL:
            printf("All numbers are solutions\n");
            break;
    }
}

double get(char k) {
    double res = NAN;
    printf("Input %c:\n", k);
    while(scanf("%lg", &res) == 0)
        printf("Input error\n");
    return res;
}

int compare(double a, double b) {
    extern const double EPSILON;

    if(abs(a - b) < EPSILON)
        return 1;

    return 0;
}



int linecase(double a, double b, double *x1) {
    if(compare(a, 0)) {
        if(compare(b, 0))
            return ALL;
        else
            return 0;
    } else {
        *x1 = (-b / a);
        return 1;
    }
}

int sqrcase(double a, double b, double c, double *x1, double *x2) {
    double d = b*b - 4*a*c;

    if(d < 0)
        return 0;
    else if(compare(d, 0)) {
        *x1 = (-b) / (2 * a);
        return 1;
    } else {
        double sqrtd = sqrt(d);
        *x1 = (-b - sqrtd) / (2 * a);
        *x2 = (-b + sqrtd) / (2 * a);
        return 2;
    }
}
