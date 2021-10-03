//枚举
/*
	人有体力、情商、智商的高峰日子，它们分别每隔
23天、28天和33天出现一次。对于每个人，我们想知道何时三个高峰落在同一天。给定三个高峰出
现的日子p,e和i（不一定是第一次高峰出现的日子）, 再给定另一个指定的日子d，你的任务是输出日子d 
之后，下一次三个高峰落在同一天的日子（用距离d 的天数表示）。例如：给定日子为10，下次出现三个高峰
同一天的日子是12，则输出2。

	输入
输入四个整数：p, e, i和d。 p, e, i分别表示体力、情感和智力高峰出现的日子。d是给定的日子，可能
小于p, e或 i。所有给定日子是非负的并且小于或等于365，所求的日子小于或等于
21252。
	输出从给定日子起，下一次三个高峰同一天的日子（距离给定日子的天数）。
	输入样例
0 0 0 0
0 0 0 100
5 20 34 325
4 5 6 7
283 102 23 320 
203 301 203 40
-1 -1 -1 -1
	输出样例
Case 1: the next triple peak occurs in 21252 days. 
Case 2: the next triple peak occurs in 21152 days.
Case 3: the next triple peak occurs in 19575 days.
Case 4: the next triple peak occurs in 16994 days. 
Case 5: the next triple peak occurs in 8910 days.
Case 6: the next triple peak occurs in 10789 days.
*/
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int p, e, i, d;
	int counter = 0;
	while (cin>>p>>e>>i>>d&&p!=-1)
	{
		int k ;
		for (k=p+1; k <= 21252; k += 23)//若从p+1开始就要注意对k-d进行限制
		{
			if ((k-e)%28==0)
			{
				for (; k <= 21252;k+=23*28)
				{
					if ((k-i)%33==0&&k-d>0)
					{
						counter++;
						printf("Case %d: the next triple peak occurs in %d days.\n", counter, k - d);
					}
				}
			}
		}
	}
	return 0;
}