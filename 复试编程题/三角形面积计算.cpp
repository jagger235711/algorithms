//
// Created by jagger on 25-2-21.
//
/*
三角形面积计算：编程实现输入三角形的边长a, b, c，根据海伦公式$area = \sqrt{s(s - a)(s - b)(s - c)}$（其中$s = \frac{a + b + c}{2}$）求三角形的面积area。
 */

#include <cmath>
#include<cstdio>
#include <math.h>

int main()
{
    float a, b, c, s;
    scanf("%f %f %f", &a, &b, &c);
    // 考虑输入的三条边是否能构成三角形
    if (a + b > c && a + c > b && b + c > a)
    {
        s = (a + b + c) / 2;
        printf("%f\n", sqrt(s * (s - a) * (s - b) * (s - c)));
    }else
    {
        printf("No solution\n");
    }
}
