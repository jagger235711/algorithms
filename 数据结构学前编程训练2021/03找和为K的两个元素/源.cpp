/*
����
��һ������Ϊn(n < 1000)�����������У��ж��Ƿ����ĳ����Ԫ��֮��Ϊk��

����
��һ���������еĳ���n��k���ÿո�ֿ���
�ڶ������������е�n���������ÿո�ֿ���
���
�������ĳ����Ԫ�صĺ�Ϊk�������yes���������no��
��������
9 10
1 2 3 4 5 6 7 8 9
�������
yes
˫��ѭ��
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