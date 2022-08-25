#include "kvadrach.h"

double get(char k) {
    double res = NAN;

    printf("Input %c:\n", k);

    while(scanf("%lg", &res) == 0) {
        fflush(stdin);

        printf("Input error\n");
    }
    return res;
}

int compare(double a, double b) {
    if(isunordered(a, b))
        return 1;

    assert(a != NAN);
    assert(b != NAN);

    if(fabs(a - b) < EPSILON)
        return 1;

    return 0;
}

int linecase(double a, double b, double *x1) {
    assert(a != NAN);
    assert(b != NAN);
    assert(x1 != NULL);


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

int sqrcase(double a, double b, double c, double *x1, double *x2) {
    assert(a != NAN);
    assert(!compare(a, 0));
    assert(b != NAN);
    assert(c != NAN);
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    double discr = b*b - 4*a*c;

    if(discr < 0)
        return NO_ROOT;
    else if(compare(discr, 0)) {
        *x1 = (-b) / (2 * a);
        return ONE_ROOT;
    } else {
        double sqrtDiscr = sqrt(discr);

        *x1 = (-b - sqrtDiscr) / (2 * a);
        *x2 = (-b + sqrtDiscr) / (2 * a);

        return TWO_ROOTS;
    }
}

void fixzero(double *a) {
    assert(a != NULL);

    if(compare(*a, 0))
        *a = 0;
}

void solve(double a, double b, double c, enum Roots *nRoot, double *x1, double *x2) {
    assert(a != NAN);
    assert(b != NAN);
    assert(c != NAN);
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    *nRoot = (Roots) (compare(a, 0) ? linecase(b, c, x1) : sqrcase(a, b, c, x1, x2));

    if(!isnan(*x1)) {
        fixzero(x1);
    }
    if(!isnan(*x2)) {
        fixzero(x2);
    }
}

void test(char *path) {
    assert(path != NULL);

    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN, testx1 = NAN, testx2 = NAN;
    enum Roots nRoot = NO_ROOT;
    FILE *tests = NULL;
    char line[MAXLINE] = {};
    int err = 0, testnum = 0, testnRoot = 0;

    tests = fopen(path, "r");

    while(fgets(line, MAXLINE, tests) != NULL) {
        a = b = c = x1 = x2 = testx1 = testx2 = NAN;
        testnRoot = 0;
        nRoot = NO_ROOT;

        sscanf(line, "%lg %lg %lg %d %lg %lg", &a, &b, &c, &testnRoot, &testx1, &testx2);

        solve(a, b, c, &nRoot, &x1, &x2);

        printf("Test #%d. ", ++testnum);

        if(((int) nRoot) != testnRoot || !compare(x1, testx1) || !compare(x1, testx1)) {
            err++;
            printf("FAIL. Got %d %lg %lg instead of %d %lg %lg", (int) nRoot, x1, x2, testnRoot, testx1, testx2);
        }

        printf("\n");
    }

    printf("Error in %d tests", err);
    fclose(tests);
}
