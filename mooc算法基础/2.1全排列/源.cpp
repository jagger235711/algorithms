/*
描述
给定一个由不同的小写字母组成的字符串，输出这个字符串的所有全排列。 我们假设对于小写字母有'a' < 'b' < ... < 'y' < 'z'，而且给定的字符串中的字母已经按照从小到大的顺序排列。

输入
输入只有一行，是一个由不同的小写字母组成的字符串，已知字符串的长度在1到6之间。
输出
输出这个字符串的所有排列方式，每行一个排列。要求字母序比较小的排列在前面。字母序如下定义：

已知S = s1s2...sk , T = t1t2...tk，则S < T 等价于，存在p (1 <= p <= k)，使得
s1 = t1, s2 = t2, ..., sp - 1 = tp - 1, sp < tp成立。
样例输入
abc
样例输出
abc
acb
bac
bca
cab
cba
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int M = 8;
char str[M];//存输入
char permutation[M];//存输出
bool used[M] = { 0 };//标记是否使用
int L = 0;
void Permutation(int n)
{
	if (n==L)
	{
		permutation[L] = 0;
		cout << permutation << endl;
	}
	else
	{
		for (int i=0;i<L;i++)
		{
			if (!used[i])
			{
				used[i] = true;
				permutation[n] = str[i];
				Permutation(n + 1);
				used[i] = false;
			}
		}
	}
}
int main()
{
	cin >> str;
	L = strlen(str);
	sort(str, str + L);
	Permutation(0);
	return 0;
}

