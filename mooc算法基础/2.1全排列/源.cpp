/*
����
����һ���ɲ�ͬ��Сд��ĸ��ɵ��ַ������������ַ���������ȫ���С� ���Ǽ������Сд��ĸ��'a' < 'b' < ... < 'y' < 'z'�����Ҹ������ַ����е���ĸ�Ѿ����մ�С�����˳�����С�

����
����ֻ��һ�У���һ���ɲ�ͬ��Сд��ĸ��ɵ��ַ�������֪�ַ����ĳ�����1��6֮�䡣
���
�������ַ������������з�ʽ��ÿ��һ�����С�Ҫ����ĸ��Ƚ�С��������ǰ�档��ĸ�����¶��壺

��֪S = s1s2...sk , T = t1t2...tk����S < T �ȼ��ڣ�����p (1 <= p <= k)��ʹ��
s1 = t1, s2 = t2, ..., sp - 1 = tp - 1, sp < tp������
��������
abc
�������
abc
acb
bac
bca
cab
cba
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int M = 8;
char str[M];//������
char permutation[M];//�����
bool used[M] = { 0 };//����Ƿ�ʹ��
int L = 0;
void Permutation(int n)
{
	if (n==L)
	{
		permutation[L] = 0;
		cout << permutation << endl;
	}
	else
	{
		for (int i=0;i<L;i++)
		{
			if (!used[i])
			{
				used[i] = true;
				permutation[n] = str[i];
				Permutation(n + 1);
				used[i] = false;
			}
		}
	}
}
int main()
{
	cin >> str;
	L = strlen(str);
	sort(str, str + L);
	Permutation(0);
	return 0;
}

