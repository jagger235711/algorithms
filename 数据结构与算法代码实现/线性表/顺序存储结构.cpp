#include<iostream>
using namespace std;

#define MaxSize 50
typedef int ElemType;

struct {
	ElemType data[MaxSize];//������Ա��е�Ԫ��
	int length;//���Ա�ĳ���
}SqList;//����һ���ṹ�����

//����˳���
void CreateList(SqList*& L, ElemType a[], int n) { //ͨ��ָ�����ṩ˳���
	int i = 0, k = 0;//kΪL��Ԫ�ظ���
	L = (SqList*)malloc(sizeof(SqList));//���������Ա�Ŀռ� ��ǿ������ת����  malloc������̬����ռ�
	while (i < n) {
		L->data[k] = a[i];
		k++, i++;
	}
	L->length = k;
}
