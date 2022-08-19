#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define EPSILON 0.0001
#define MAXSIZE 40

int get(char k, float *);

main() {
    float a, b, c, d, t;

    if(get('a', &a) || get('b', &b) || get('c', &c)) {
        printf("Ошибка ввода");
        return 0;
    }


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

int get(char k, float *res) {
    char inp[MAXSIZE];
    int i = 0;

    printf("Введите коэффициент %c:\n", k);
    scanf("%s", inp);                                                       //собсно ввод

    while(i < MAXSIZE && inp[i] != '\0') {                                  //проверить, ввёл ли юзверь что-то кроме цифр
        if ((inp[i] < '0' || inp[i] > '9') && inp[i] != '.')
            return 1;                                                       //ошибка ввода
        i++;
    }

    *res = (float) atof(inp);

    return 0;
}
