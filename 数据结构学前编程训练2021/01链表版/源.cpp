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
������������������
��ѭ�������Сֵ��������С�±�
���
*/
#include<iostream>
using namespace std;
typedef int ElemType;

typedef struct LNode {
	ElemType data;//���Ԫ��ֵ
	struct LNode* next;//ָ���̽��
}LinkNode;//������������
void CreateListF(LinkNode*& L, ElemType a[], int n) {//linknode * &L,������������ṹ��ָ�����͵ı���L������L���ı�L
	LinkNode* s;
	//L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;//����ͷ��㣬��next����ΪNULL
	for (int i = 0; i < n; i++)//ѭ���������ݽ��s
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];//�������ݽ��s
		s->next = L->next;//�����s���뵽ԭ�׽��֮ǰ��ͷ���֮��
		L->next = s;
	}
}

int main() {

	return 0;
}