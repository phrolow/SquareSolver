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

    #ifdef DEBUG
    assert(a != NAN);
    assert(b != NAN);
    #endif

    extern const double EPSILON;

    if(fabs(a - b) < EPSILON)
        return 1;

    return 0;
}

int linecase(double a, double b, double *x1) {
    #ifdef DEBUG
    assert(a != NAN);
    assert(b != NAN);
    assert(x1 != NULL);
    #endif


    if(compare(a, 0)) {
        if(compare(b, 0))
            return 3;
        else
            return 0;
    } else {
        *x1 = (-b / a);
        return 1;
    }           //возвращать инты
}

int sqrcase(double a, double b, double c, double *x1, double *x2) {
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

void fixzero(double *a) {
    if(isnan(*a))
        return;

    if(compare(*a, 0))
        *a = 0;
}

void solve(double a, double b, double c, enum Roots *nRoot, double *x1, double *x2) {
    #ifdef DEBUG
    assert(a != NAN);
    assert(b != NAN);
    assert(c != NAN);
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);
    #endif

    *nRoot = (Roots) (compare(a, 0) ? linecase(b, c, x1) : sqrcase(a, b, c, x1, x2));

    fixzero(x1);
    fixzero(x2);
}

void test(char *path) {
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN, testx1 = NAN, testx2 = NAN;
    enum Roots nRoot = NO_ROOT;
    FILE *tests = NULL;
    char *test = NULL;
    int err = 0, testnum = 0, testnRoot = 0;

    tests = fopen(path, "r");

    while(fgets(test, 1000, tests) != NULL) {
        a = b = c = x1 = x2 = testx1 = testx2 = NAN;
        testnRoot = 0;
        nRoot = NO_ROOT;

        sscanf(test, "%lg %lg %lg %d %lg %lg", &a, &b, &c, &testnRoot, &testx1, &testx2);

        solve(a, b, c, &nRoot, &x1, &x2);

        printf("Test #%d. ", ++testnum);

        if(((int) nRoot) != testnRoot || !compare(x1, testx1) || !compare(x1, testx1)) {
            err++;
            printf("FAIL. Got %d %lg %lg, must be %d, %lg, %lg", (int) nRoot, x1, x2, testnRoot, testx1, testx2);
        }

        printf("\n");
    }

    printf("Error in %d tests", err);
    fclose(tests);
}
