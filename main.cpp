#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "kvadrach.h"

#define DEBUG

const int MAXLINE = 1000;

int main() {
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    enum roots nRoot = NO_ROOT;

    #ifdef DEBUG
    FILE *tests = NULL;

    char test[MAXLINE] = {};
    int err = 0, testnum = 0;
    double testx1 = NAN, testx2 = NAN;
    int testnRoot = 0;

    tests = fopen("Y:\\gthb\\SquareSolver\\test.txt", "r");

    while(fgets(test, MAXLINE, tests) != NULL) {
        a = b = c = x1 = x2 = testx1 = testx2 = NAN;
        testnRoot = 0;
        nRoot = NO_ROOT;

        sscanf(test, "%lg %lg %lg %d %lg %lg", &a, &b, &c, &testnRoot, &testx1, &testx2);

        printf("Test #%d. ", ++testnum);
    #endif

    #ifndef DEBUG
    a = get('a');
    b = get('b');
    c = get('c');
    #endif

    #ifdef DEBUG
    #endif

    nRoot = compare(a, 0) ? linecase(b, c, &x1) : sqrcase(a, b, c, &x1, &x2);

    fixzero(&x1);
    fixzero(&x2);

    #ifndef DEBUG
    switch(nRoot) {
        case NO_ROOT:
            printf("No solutions\n");
            break;
        case ONE_ROOT:
            printf("%lg is only solution\n", x1);
            break;
        case TWO_ROOTS:
            printf("Both %lg and %lg are solutions\n", x1, x2);
            break;
        case ALL_ROOTS:
            printf("All numbers are solutions\n");
            break;
    }
    #endif

    #ifdef DEBUG

        if(((int) nRoot) != testnRoot || !compare(x1, testx1) || !compare(x1, testx1)) {
            err++;
            printf("FAIL. Got %d %lg %lg, must be %d, %lg, %lg", (int) nRoot, x1, x2, testnRoot, testx1, testx2);
        }

        printf("\n");
    }
    printf("Error in %d tests", err);
    fclose(tests);
    #endif

    return 0;
}
//debug mode
//когда он есть открыть текстовки сравнить ответы с x1 x2 из файла вывести колво пройденных тестов
