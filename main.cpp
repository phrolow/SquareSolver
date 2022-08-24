#include "kvadrach.h"

int main() {
    #ifndef DEBUG
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    enum Roots nRoot = NO_ROOT;

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
        default:
            break;
    }
    #endif

    #ifdef DEBUG
    test("Y:\\gthb\\SquareSolver\\test.txt");
    #endif

    return 0;
}
