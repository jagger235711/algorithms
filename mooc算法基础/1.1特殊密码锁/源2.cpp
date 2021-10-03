//枚举
/*
描述
有一种特殊的二进制密码锁，由n个相连的按钮组成（n<30），按钮有凹/凸两种状态，用手按按钮会改变其状态。
然而让人头疼的是，当你按一个按钮时，跟它相邻的两个按钮状态也会反转。当然，如果你按的是最左或者最右边的按钮，该按钮只会影响到跟它相邻的一个按钮。
当前密码锁状态已知，需要解决的问题是，你至少需要按多少次按钮，才能将密码锁转变为所期望的目标状态。
输入
两行，给出两个由0、1组成的等长字符串，表示当前/目标密码锁状态，其中0代表凹，1代表凸。
输出
至少需要进行的按按钮操作次数，如果无法实现转变，则输出impossible。
样例输入
011
000
样例输出
1
*/
#include <iostream>
#include<math.h>
#include <string.h>
using namespace std;
void* change(char* p)
{
	if (*(p - 1) != NULL)*(p - 1) = abs(*(p - 1) - 1);
	*p = abs(*p - 1);
	if (*(p + 1) != NULL)*(p + 1) = abs(*(p + 1) - 1);
	return 0;
}
int main()
{
	string lock, passPort;
	cin >> lock >> passPort;
	int len = lock.length();
	int counter = 0;
	for (int i = 0; i < len; i++)
	{
		if (lock[i] != passPort[i])
		{
			counter++;
			if (i == 0) change(&lock[i]);
			else change(&lock[i + 1]);
		}
		else continue;
	}
	if (lock == passPort)
	{
		cout << counter;
	}
	else cout << "impossible";
	return 0;
}