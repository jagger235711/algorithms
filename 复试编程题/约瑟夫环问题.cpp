//
// Created by jagger on 25-2-21.
//
/*
约瑟夫环问题：有n个人围成一圈，从1开始顺序排号。从第一个人开始报数（从1到3报数），凡报到3的人退出圈子，问最后留下的是原来第几号的那位。
 */
#include<cstdio>

int main()
{
    int n, num, index = 0, count = 1;
    scanf("%d", &n);
    num = n;
    bool man[n];

    for (int i = 0; i < n; i++)
    {
        man[i] = true;
    }

    while (num > 1)
    {
        if (man[index] == false)
            index++;
        else
        {
            // man[index] == true
            if (count != 3)
            {
                count++;
                index++;
            }
            else //count == 3
            {
                man[index] = false;
                count = 1;
                index++;
                num--;
            }
        }
        index = index % n;
    }


    for (int i = 0; i < n; i++)
    {
        if (man[i]) printf("%d ", i + 1);
    }
    return 0;
}
