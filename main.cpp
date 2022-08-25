#include "kvadrach.h"

int main() {
    #ifndef TEST
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    enum Roots nRoot = NO_ROOT;

    a = getCoeff('a');
    b = getCoeff('b');
    c = getCoeff('c');

    solveEq(a, b, c, &nRoot, &x1, &x2);

    printSolution(nRoot, x1, x2);

    //функция printroot куда закинуть свитч
    //интерактивность
    #endif

    #ifdef TEST
    testAll("Y:\\gthb\\SquareSolver\\test.txt");
    #endif

    return 0;
}
