#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "kvadrach.h"

int main() {
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    enum Roots nRoot = NO_ROOT;

    if(MODE == NORMAL) {
        a = get('a');
        b = get('b');
        c = get('c');

        solve(a, b, c, &nRoot, &x1, &x2);
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
    }

    if(MODE == DEBUG) {
        FILE *tests = NULL;
        char *test = NULL;
        int err = 0, testnum = 0, testnRoot = 0;
        double testx1 = NAN, testx2 = NAN;

        tests = fopen("Y:\\gthb\\SquareSolver\\test.txt", "r");

        while(fgets(test, MAXLINE, tests) != NULL) {
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

    return 0;
}
