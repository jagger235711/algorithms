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
第一个密码确定了那么解的状态就确定了
*/
#include <iostream>
#include<math.h>
#include <string.h>
using namespace std;
void FlipLock(int u,int len,int *p)//引用传递
{
	if (u>0)
	{
		*(p - 1) = abs(*(p-1) - 1);
	}
	*(p) = abs(*p - 1);
	if (u <len-1)
	{
		*(p + 1) = abs(*(p + 1) - 1);
	}
}

int main()
{
	string lock, passPort;
	cin >> lock >> passPort;
	int len = lock.length();
	int Lock[30], Passport[30];
	//转化为数字
	for (int i = 0; i < len; i++)
	{
		Lock[i] = lock[i] - '0';
		Passport[i] = passPort[i] - '0';
	}

	int counter = 0;
	for (int i = 0; i < len; i++)
	{
		if (Lock[i] != Passport[i])
		{
			counter++;
			FlipLock(i+1, len, &Lock[i+1]);//如果不同，改后一个按钮
		}
		else continue;
	}

	int t;
	for ( t=0;t<len;t++)
	{
		if (!(Lock[t] == Passport[t])) break;
	}
	if (t == len ) cout << counter;
	else cout << "impossible";
	return 0;
}