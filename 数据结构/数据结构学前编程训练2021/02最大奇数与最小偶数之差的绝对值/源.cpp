/*
描述
输入6个正整数，且这6个正整数中至少存在一个奇数和一个偶数。
设这6个正整数中最大的奇数为a，最小的偶数为b，求出|a-b|的值

输入
输入为一行，6个正整数,且6个正整数都小于100
输入保证这6个数中至少存在一个奇数和一个偶数
输出
输出为一行，输出最大的奇数与最小的偶数之差的绝对值
样例输入
1 2 3 4 5 6
样例输出
3
使用数组把输入数据存好
用循环查出最大奇数和最小偶数
*/
#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int num[8] = {0}, value;//num[0]放奇数，num[1]放偶数，value为差值
	//存入数据
	for (int i = 2; i <= 7; i++)
	{
		cin >> num[i];
	}
	//查找最大奇数和最小偶数
	num[1] = 999999999;
	for (int i = 2; i <= 7; i++)
	{
		if (num[i] % 2 == 0) {//说明是偶数
			if (num[i] < num[1]) {
				num[1] = num[i];
			}
		}
		else {//说明是奇数
			if (num[i] > num[0]) {
				num[0] = num[i];
			}
		}
	}
	value = abs(num[0] - num[1]);
	cout << value;
	return 0;
}