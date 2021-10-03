/*
����
��һ���ǽ������У����������ֵ��ӽ���Ԫ�ء�
����
��һ�а���һ������n��Ϊ�ǽ����г��ȡ�1 <= n <= 100000��
�ڶ��а���n��������Ϊ�ǽ����и�Ԫ�ء�����Ԫ�صĴ�С����0-1,000,000,000֮�䡣
�����а���һ������m��ΪҪѯ�ʵĸ���ֵ������1 <= m <= 10000��
������m�У�ÿ��һ��������ΪҪѯ����ӽ�Ԫ�صĸ���ֵ�����и���ֵ�Ĵ�С����0-1,000,000,000֮�䡣
���
m�У�ÿ��һ��������Ϊ��ӽ���Ӧ����ֵ��Ԫ��ֵ����������˳�����ж��ֵ���������������С��һ����
��������
3
2 5 8
2
10
5
�������
8
5
*/
#include<iostream>
#include<algorithm>
using namespace std;
int LowerBound(int a[], int size, int p)
{
	int l = 0;
	int r = size - 1;
	int lastPos = -1;
	while (l<=r)
	{
		int mid = l + (r - l) / 2;
		if (a[mid]>=p)
		{
			if (a[mid]=p)
			{
				return a[mid];
			}
			r = mid - 1;
		} 
		else
		{
			lastPos = mid;
			l = mid + 1;
		}
	}
	return a[lastPos];
}
int main()
{
	int n, Num[1000], m;
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> Num[i];
	
	//sort(Num, Num + n);//Ĭ����������

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int Question;
		cin >> Question;
		cout<<LowerBound(Num, n, Question)<<endl;//�Լ�дһ�����ֲ��Һ���
	}
	return 0;
}