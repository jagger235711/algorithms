/*
����
�Ӽ�������һ������������������������λ����
����
һ����Ϊ0����������
���
�����������λ����
��������
36798
�������
5
�㷨˼��
�߽����� ����ֻ��һλʱ
*/
#include<iostream>
using namespace std;
long long weishu(long long num)
{
	if (num < 10 && num >0)  return 1;
	else
	return weishu(num/10)+1;
}
int main()
{
	long long num,d=0;
	cin >> num;
	cout << weishu(num);
	return 0;
}
