#include<iostream>
#include<cstdio>
using namespace std;
const int N = 5;
void output_array(int a[][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
int circle(int x, int n, int k, int a[][N])
{
	for (int i = 0; i < n - 1; i++)
	{
		a[0 + x][i + x] = k++;
	}
	//�ϳ�
	for (int i = 0; i < n - 1; i++)
	{
		a[i + x][n - 1 + x] = k++;
	}
	//�Ҹ�
	for (int i = n - 1 + x; i > x; i--)
	{
		a[n - 1 + x][i] = k++;
	}
	//�³�
	for (int i = n - 1 + x; i > x; i--)
	{
		a[i][x] = k++;
	}
	//���
	return k;
}
int main()
{
	int a[N][N];
	int k = 1;
	//�ڼ���ѭ�� �߳� ������ ��ά����
	for (int i = 0; N - 2 * i > 1; i++)
		k = circle(i, N - 2 * i, k, a);
	//������ ���м�λ�ø�ֵ
	if (N % 2 == 1)
		a[N / 2][N / 2] = k;
	output_array(a);
	return 0;
}