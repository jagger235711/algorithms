/*
����
����һ����10��Ԫ�ص��������飬�Ӽ���������������Ԫ�ص�ֵ������������е���Сֵ����Сֵ���±ꡣ�����Сֵ�������г��ֶ�Σ������С���Ǹ��±ꡣ

����
10������
���
��Сֵ����Сֵ���±ꡣ�����Сֵ�������г��ֶ�Σ������С���Ǹ��±ꡣ
��������
5 4 6 3 1 8 9 7 15 34
�������
The minimum number is 1.
It's subscript is 4.
�������鴢����������
��ѭ�������Сֵ��������С�±�
���
*/
#include<iostream>
using namespace std;
int main() {
	int num[11], mark=0;//��num[0]����С���֣�mark����±�
	//����
	for (int i = 1; i <= 10; i++) {
		cin >> num[i];
	}
	//����
	num[0] = num[1];//�ȸ���ֵ
	for (int i = 1; i <= 10; i++) {
		if (num[i] < num[0]) {
			num[0] = num[i];
			mark = i-1;
		}
	}
	printf("The minimum number is %d. \nIt's subscript is %d. ", num[0], mark);
	return 0;
}