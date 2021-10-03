/*
描述
在一个长度为n(n < 1000)的整数序列中，判断是否存在某两个元素之和为k。

输入
第一行输入序列的长度n和k，用空格分开。
第二行输入序列中的n个整数，用空格分开。
输出
如果存在某两个元素的和为k，则输出yes，否则输出no。
样例输入
9 10
1 2 3 4 5 6 7 8 9
样例输出
yes
双重循环
*/
#include<iostream>
using namespace std;
int main() {
	int n, k,num[1000];
	bool res = false;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if ((num[i] + num[j]) == k) {
				cout << "yes";
				res = true;
				break;
			}
		}
		if (res) {
			break;
		}
	}
	if (res == false) {
		cout << "no";
	}
	return 0;
}