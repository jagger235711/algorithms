/*
输入
第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，
包括一个正整数k (1 ≤ k < 1000000)。
输出
n行，每行输出对应一个输入。输出应是一个非负整数。
样例输入
2
1
8
样例输出
1
408
*/
#include<iostream>
using namespace std;
int Pell(int n);
int main()
{
	int n,m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
    cin >> n;
	cout << Pell(n)%32767<<endl;
	}
	return 0;
}
int Pell(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 2;
	else return 2*Pell(n - 1) + Pell(n - 2);
}