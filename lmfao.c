#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001

main() {
    float a, b, c, d, t;
    printf("Введите через пробел коэффициенты a, b и c:\n");
    scanf("%f %f %f", &a, &b, &c);

    if(a > (-EPSILON) && a < EPSILON) {
        printf("Ошибка ввода либо коэффициент a слишком мал по модулю");
        return 0;
    }

    d = b*b - 4*a*c;

    if(d < 0)
        printf("Вещественных корней нет");
    else if(d == 0)
        printf("%f - единственный корень", (-b) / (2 * a));
    else {
        t = sqrt(d);
        printf("Корни: %f и %f", (-b + t) / (2 * a), (-b - t) / (2 * a));
    }
}
