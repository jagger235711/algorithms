//
// Created by jagger on 25-2-19.
//
/*
一元二次方程求根：编程求一元二次方程$ax^2 + bx + c = 0$的根$x_1$和$x_2$。(a!=0)
 */
#include <iostream>
#include <cmath>
#include <valarray>

int main()
{
    float a, b, c, x1, x2;
    scanf("%f %f %f", &a, &b, &c);
    // 先用判别式确定有几个实根b^2-4a*c
    // b*b-4*a*c
    float tmp = b * b - 4 * a * c;
    if (a == 0)
    {
        printf("非一元二次方程");
        return 0;
    }
    if (tmp < 0) //共轭复根 a+-bi
    {
        printf("No solution");
        return 0;
    }
    if (tmp == 0)
    {
        x1 = (-b + sqrt(tmp)) / (2 * a);
        x2 = x1;
        printf("x1:%f x2:%f\n", x1, x2);
        return 0;
    }
    x1 = (-b + sqrt(tmp)) / (2 * a);
    x2 = (-b - sqrt(tmp)) / (2 * a);
    printf("x1:%f x2:%f\n", x1, x2);
    // return 0;
}
