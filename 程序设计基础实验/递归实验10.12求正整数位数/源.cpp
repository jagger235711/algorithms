/*
描述
从键盘输入一个正整数，输出这个正整数的位数。
输入
一个不为0的正整数。
输出
这个正整数的位数。
样例输入
36798
样例输出
5
算法思想
边界条件 当数只有一位时
*/
#include<iostream>
using namespace std;
long long weishu(long long num)
{
	if (num < 10 && num >0)  return 1;
	else
	return weishu(num/10)+1;
}
int main()
{
	long long num,d=0;
	cin >> num;
	cout << weishu(num);
	return 0;
}
