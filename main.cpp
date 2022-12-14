#include "kvadrach.h"

int main() {
    #ifndef TEST
    while(1) {
        double  a = NAN,
                b = NAN,
                c = NAN,
                x1 = NAN,
                x2 = NAN;
        enum Roots nRoot = NO_ROOT;

        a = getCoeff('a');
        b = getCoeff('b');
        c = getCoeff('c');

        nRoot = (Roots) solveEq(a, b, c, &x1, &x2);

        printSolution(nRoot, x1, x2);
        printf("\n********************\n\n");
    }
    #endif

    #ifdef TEST
    testAll("Y:\\gthb\\SquareSolver\\test.txt");
    #endif

    return 0;
}
