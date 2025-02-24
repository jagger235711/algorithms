//
// Created by jagger on 25-2-22.
//
/*
水仙花数查找：编程打印出所有的“水仙花数”，所谓“水仙花数”是指一个三位数，其各位数字立方和等于该数本身。例如：153是一个“水仙花数”，因为$153 = 1^3＋5^3＋3^3$。
 */
#include<iostream>
#include <cmath>
using namespace std;

int main()
{
    // int num;
    // scanf("%d",&num);
    for (int num = 100; num < 1000; num++)
    {
        if (pow(num / 100, 3) + pow(num % 100 / 10, 3) + pow(num % 10, 3) == num)
        {
            printf("%d是水仙花数\n", num);
        }
    }
}
