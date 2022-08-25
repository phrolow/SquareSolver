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
        a = b = c = testx1 = testx2 = NAN;
        testnRoot = 0;
        nRoot = NO_ROOT;

        sscanf(line, "%lg %lg %lg %d %lg %lg", &a, &b, &c, &testnRoot, &testx1, &testx2);

        printf("Test #%d. ", ++testnum);

        if(singletest(a, b, c, testnRoot, testx1, testx2)) {
            txSetConsoleAttr(FOREGROUND_GREEN);
            printf("SUCCESS");
        } else {
            err++;

            txSetConsoleAttr(FOREGROUND_RED);
            printf("FAIL");

            txSetConsoleAttr();
            printf(". Got %d %lg %lg instead of %d %lg %lg", (int) nRoot, x1, x2, testnRoot, testx1, testx2);
        }

        txSetConsoleAttr();
        printf("\n");
    }

    printf("Error in %d tests", err);
    fclose(tests);
}

int singletest(double a, double b, double c, int testnRoot, double testx1, double testx2) {
    assert(a != NAN);
    assert(b != NAN);
    assert(c != NAN);

    enum Roots nRoot = NO_ROOT;
    double x1 = NAN, x2 = NAN;

    solve(a, b, c, &nRoot, &x1, &x2);

    if(nRoot != testnRoot || !compare(x1, testx1) || !compare(x2, testx2))
        return 0;
    return 1;
}
