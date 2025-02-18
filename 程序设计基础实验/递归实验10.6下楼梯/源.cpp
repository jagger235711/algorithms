/*
描述
树老师爬楼梯，他可以每次走1级或者2级，输入楼梯的级数，求不同的走法数
例如：楼梯一共有3级，他可以每次都走一级，或者第一次走一级，第二次走两级
也可以第一次走两级，第二次走一级，一共3种方法。
输入
输入包含若干行，每行包含一个正整数N，代表楼梯级数，1 <= N <= 30
输出
不同的走法数，每一行输入对应一行输出
样例输入
5
8
10
样例输出
8
34
89
*/
#include<iostream>
using namespace std;
int downstairs(int n)
{
	if (n < 0)return 0;
	if (n == 0 || n == 1)return 1;
	else return downstairs(n - 1) + downstairs(n - 2);
}
int main()
{
	int n;
	while (cin >> n)
	{
		cout << downstairs(n) << endl;
	}
	return 0;
}