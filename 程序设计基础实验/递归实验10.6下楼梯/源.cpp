/*
����
����ʦ��¥�ݣ�������ÿ����1������2��������¥�ݵļ�������ͬ���߷���
���磺¥��һ����3����������ÿ�ζ���һ�������ߵ�һ����һ�����ڶ���������
Ҳ���Ե�һ�����������ڶ�����һ����һ��3�ַ�����
����
������������У�ÿ�а���һ��������N������¥�ݼ�����1 <= N <= 30
���
��ͬ���߷�����ÿһ�������Ӧһ�����
��������
5
8
10
�������
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