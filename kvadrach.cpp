#include "kvadrach.h"

double getCoeff(char k) {
    double res = NAN;

    printf("Input %c:\n", k);

    while(scanf("%lg", &res) == 0) {
        fflush(stdin);

        printf("Input error\n");
    }

    fflush(stdin);

    return res;
}

int compare(double a, double b) {
    if(isunordered(a, b))
        return 1;

    assert(a != NAN);
    assert(b != NAN);

    return (fabs(a - b) < EPSILON);
}

int solveLinear(double a, double b, double *x1) {
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

void printSolution(enum Roots nRoot, double x1, double x2) {
    switch(nRoot) {
        case NO_ROOT:
            printf("No solutions\n");
            break;
        case ONE_ROOT:
            assert(!isnan(x1));

            printf("%lg is only solution\n", x1);
            break;
        case TWO_ROOTS:
            assert(!isnan(x1) || !isnan(x2));

            printf("Both %lg and %lg are solutions\n", x1, x2);
            break;
        case ALL_ROOTS:
            printf("All numbers are solutions\n");
            break;
        default:
            assert(0);
    }
}

void fixZero(double *a) {
    assert(a != NULL);

    if(compare(*a, 0))
        *a = 0;
}

int solveEq(double a, double b, double c, double *x1, double *x2) {
    assert(a != NAN);
    assert(b != NAN);
    assert(c != NAN);
    assert(x1 || x2);
    assert(x1 != x2);

    if(compare(a, 0))
        return solveLinear(b, c, x1);

    double discr = b*b - 4*a*c;

    if(discr < 0) {
        return NO_ROOT;
    } else if(compare(discr, 0)) {
        *x1 = (-b) / (2*a);
        fixZero(x1);

        return ONE_ROOT;
    }

    double sqrtDiscr = sqrt(discr);

    *x1 = (-b - sqrtDiscr) / (2*a);
    *x2 = (-b + sqrtDiscr) / (2*a);

    fixZero(x1);
    fixZero(x2);

    return TWO_ROOTS;
}

#ifdef TEST
void testAll(char *path) {
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

        if(test(a, b, c, testnRoot, testx1, testx2)) {
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

int test(double a, double b, double c, int testnRoot, double testx1, double testx2) {
    assert(a != NAN);
    assert(b != NAN);
    assert(c != NAN);

    enum Roots nRoot = NO_ROOT;
    double x1 = NAN, x2 = NAN;

    nRoot = (Roots) solveEq(a, b, c, &x1, &x2);

    return (nRoot == testnRoot && compare(x1, testx1) && compare(x2, testx2));
}
#endif

