#include<iostream>
using namespace std;

#define M 100//���������Ԫ�ص�������
typedef int elemType;

//ѭ�����еĽṹ
typedef struct {
	elemType data[M]; //�þ�̬�����Ŷ���Ԫ��
	int front, rear; //��ͷָ��Ͷ�βָ��
} SqQueue;
//��ʼ��
void InitQueue(SqQueue& Q)
{
	Q.front = Q.rear = 0;	//��ʼ��βָ����ͷָ��Ϊ0
}
//����г���
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + M) % M;
}
//���
int EnQueue(SqQueue& Q, elemType e)
{
	if ((Q.rear + 1) % M == Q.front) 
		return 0; //����
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % M;  //ѭ�����У���ֹ�����
	return 1;
}
//����
int DeQueue(SqQueue& Q)
{
	if (Q.rear == Q.front) 
		return 0;   //�ӿ�
	Q.front = (Q.front + 1) % M;  //ѭ�����У���ֹ�����
	return 1;
}
//ȡ��ͷԪ��
elemType getFront(SqQueue Q)
{
	if (Q.front != Q.rear)			//�ǿ�ʱ ȡֵ
		return Q.data[Q.front];
}
//�����������
void printQueue(SqQueue Q)
{
	printf("��ͷ��");
	elemType p = Q.front;
	while (p != Q.rear)
	{
		printf("%d ", Q.data[p]);
		p = (p + 1) % M;
	}
	printf("\n");
}
int main()
{
	SqQueue Q;
	int e;
	InitQueue(Q);
	do {
		printf("������һ��Ҫ��ӵ�Ԫ�أ�-1��ʾ��������");
		scanf_s("%d", &e);
		if (e == -1)
			break;
		EnQueue(Q, e);
	} while (e != -1);
	printQueue(Q);
	printf("��ǰ���г���Ϊ%d\n\n", QueueLength(Q));
	printf("���Ӳ��ԣ�");
	DeQueue(Q);
	printQueue(Q);
	printf("��ǰ���г���Ϊ%d\n\n", QueueLength(Q));

	printf("ȡ��ͷԪ�ز��ԣ�");
	e = getFront(Q);
	printf("ȡ���Ķ�ͷԪ��Ϊ��%d\n", e);
	printf("��ǰ���г���Ϊ%d\n", QueueLength(Q));
	return 0;
}
