#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "kvadrach.h"

double get(char k) {
    double res = NAN;
    char *inp = NULL;
    printf("Input %c:\n", k);
    //scanf("%s", inp);

    /* while(sscanf(inp, "%lg", &res) == 0) {
        printf("Input error\n");
        scanf("%s", inp);
    } */

    while(scanf("%lg", &res) == 0) {
        fflush(stdin);
        printf("Input error\n");
    }
    return res;
}

int compare(double a, double b) {
    if(isunordered(a, b))
        return 1;

    if(MODE == DEBUG) {
        assert(a != NAN);
        assert(b != NAN);
    }

    extern const double EPSILON;

    if(fabs(a - b) < EPSILON)
        return 1;

    return 0;
}

enum Roots linecase(double a, double b, double *x1) {
    if(MODE == DEBUG) {
        assert(a != NAN);
        assert(b != NAN);
        assert(x1 != NULL);
    }

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

enum Roots sqrcase(double a, double b, double c, double *x1, double *x2) {
    if(MODE == DEBUG) {
        assert(a != NAN);
        assert(!compare(a, 0));
        assert(b != NAN);
        assert(c != NAN);
        assert(x1 != NULL);
        assert(x2 != NULL);
        assert(x1 != x2);
    }

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

void solve(double a, double b, double c, enum Roots *nRoot, double *x1, double *x2) {
    if(MODE == DEBUG) {
        assert(a != NAN);
        assert(b != NAN);
        assert(c != NAN);
        assert(x1 != NULL);
        assert(x2 != NULL);
        assert(x1 != x2);
    }

    *nRoot = compare(a, 0) ? linecase(b, c, x1) : sqrcase(a, b, c, x1, x2);

    fixzero(x1);
    fixzero(x2);
}

