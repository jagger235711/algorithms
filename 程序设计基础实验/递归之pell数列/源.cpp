/*
����
��1���ǲ������ݵ�����n���������n�����롣ÿ���������ռ1�У�
����һ��������k (1 �� k < 1000000)��
���
n�У�ÿ�������Ӧһ�����롣���Ӧ��һ���Ǹ�������
��������
2
1
8
�������
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