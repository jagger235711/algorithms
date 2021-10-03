/*
描述
定义一个含10个元素的整型数组，从键盘输入数组所有元素的值，并求该数组中的最小值和最小值的下标。如果最小值在数组中出现多次，输出最小的那个下标。

输入
10个整数
输出
最小值和最小值的下标。如果最小值在数组中出现多次，输出最小的那个下标。
样例输入
5 4 6 3 1 8 9 7 15 34
样例输出
The minimum number is 1.
It's subscript is 4.
创建数组储存输入数字
用循环查出最小值并储存最小下标
输出
*/
#include<iostream>
using namespace std;
int main() {
	int num[11], mark=0;//用num[0]存最小数字，mark标记下标
	//读入
	for (int i = 1; i <= 10; i++) {
		cin >> num[i];
	}
	//操作
	num[0] = num[1];//先赋个值
	for (int i = 1; i <= 10; i++) {
		if (num[i] < num[0]) {
			num[0] = num[i];
			mark = i-1;
		}
	}
	printf("The minimum number is %d. \nIt's subscript is %d. ", num[0], mark);
	return 0;
}