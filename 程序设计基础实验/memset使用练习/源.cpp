//void* memset(void* dest, int ch, int n)memste的定义
//注意第一个变量是地址
#include<iostream>
using namespace std;
int main()
{
	char szName[200] = "";//默认初始化为结束符/0
	memset(szName, 'a', 10);
	for (int i = 0; i < 200; i++)
	{
		cout << szName[i] << " ";
	}
	return 0;
}
