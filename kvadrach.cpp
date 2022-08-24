#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "kvadrach.h"

#define DEBUG

double get(char k) {
    double res = NAN;
    char *inp;
    printf("Input %c:\n", k);
    scanf("%s", inp);

    while(sscanf(inp, "%lg", &res) == 0) {
        printf("Input error\n");
        scanf("%s", inp);
    }

    return res;
}

int compare(double a, double b) {
    if(isunordered(a, b))
        return 1;

    #ifdef DEBUG
    assert(a != NAN);
    assert(b != NAN);
    #endif

    extern const double EPSILON;

    if(fabs(a - b) < EPSILON)
        return 1;

    return 0;
}

enum roots linecase(double a, double b, double *x1) {
    #ifdef DEBUG
    assert(a != NAN);
    assert(b != NAN);
    assert(x1 != NULL);
    #endif

    if(compare(a, 0)) {
        if(compare(b, 0))
            return ALL_ROOTS;
        else
            return NO_ROOT;
    } else {
        *x1 = (-b / a);
        return ONE_ROOT;
    }
}

enum roots sqrcase(double a, double b, double c, double *x1, double *x2) {
    #ifdef DEBUG
    assert(a != NAN);
    assert(!compare(a, 0));
    assert(b != NAN);
    assert(c != NAN);
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);
    #endif

    double d = b*b - 4*a*c;

    if(d < 0)
        return NO_ROOT;
    else if(compare(d, 0)) {
        *x1 = (-b) / (2 * a);
        return ONE_ROOT;
    } else {
        double sqrtd = sqrt(d);

        *x1 = (-b - sqrtd) / (2 * a);
        *x2 = (-b + sqrtd) / (2 * a);

        return TWO_ROOTS;
    }
}

void fixzero(double *a) {
    if(isnan(*a))
        return;

    if(compare(*a, 0))
        *a = 0;
}
