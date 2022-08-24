#include "kvadrach.h"
//#define DEBUG

int main() {
    #ifdef DEBUG
    FILE *tests;;
    tests = fopen("Y:\\gthb\\SquareSolver\\SquareSolver\\tests.txt", "r");
    #endif

    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    enum roots nRoot = NO_ROOT;

    a = get('a');
    b = get('b');
    c = get('c');

    nRoot = compare(a, 0) ? linecase(b, c, &x1) : sqrcase(a, b, c, &x1, &x2);

    fixzero(&x1);
    fixzero(&x2);

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

    return 0;
}
//debug mode
//когда он есть открыть текстовки сравнить ответы с x1 x2 из файла вывести колво пройденных тестов
