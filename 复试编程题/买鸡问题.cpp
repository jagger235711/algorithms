//
// Created by jagger on 25-2-19.
//
/*
买鸡问题：某人用100元钱去买100只活鸡，公鸡5元1只，母鸡3元1只，小鸡1元3只，要求三种鸡都要买到，且钱不超不剩，求所有满足条件的买鸡方案。
 */

#include <iostream>

int main()
{
    int x, y, z;
    // x 是 4 的倍数，范围是 4 到 12
    for (x = 4; x < 15; x += 4)
    {
        y = 25 - (7 * x) / 4;
        z = 100 - x - y;
        printf("公鸡: %d 只, 母鸡: %d 只, 小鸡: %d 只\n", x, y, z);
    }
    return 0;
}
