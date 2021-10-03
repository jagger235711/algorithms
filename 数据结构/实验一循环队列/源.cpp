#include<iostream>
using namespace std;

#define M 100//定义队列中元素的最大个数
typedef int elemType;

//循环队列的结构
typedef struct {
	elemType data[M]; //用静态数组存放队列元素
	int front, rear; //队头指针和队尾指针
} SqQueue;
//初始化
void InitQueue(SqQueue& Q)
{
	Q.front = Q.rear = 0;	//初始化尾指针与头指针为0
}
//求队列长度
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + M) % M;
}
//入队
int EnQueue(SqQueue& Q, elemType e)
{
	if ((Q.rear + 1) % M == Q.front) 
		return 0; //队满
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % M;  //循环队列，防止假溢出
	return 1;
}
//出队
int DeQueue(SqQueue& Q)
{
	if (Q.rear == Q.front) 
		return 0;   //队空
	Q.front = (Q.front + 1) % M;  //循环队列，防止假溢出
	return 1;
}
//取队头元素
elemType getFront(SqQueue Q)
{
	if (Q.front != Q.rear)			//非空时 取值
		return Q.data[Q.front];
}
//遍历输出队列
void printQueue(SqQueue Q)
{
	printf("队头：");
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
		printf("请输入一个要入队的元素（-1表示结束）：");
		scanf_s("%d", &e);
		if (e == -1)
			break;
		EnQueue(Q, e);
	} while (e != -1);
	printQueue(Q);
	printf("当前队列长度为%d\n\n", QueueLength(Q));
	printf("出队测试：");
	DeQueue(Q);
	printQueue(Q);
	printf("当前队列长度为%d\n\n", QueueLength(Q));

	printf("取队头元素测试：");
	e = getFront(Q);
	printf("取出的队头元素为：%d\n", e);
	printf("当前队列长度为%d\n", QueueLength(Q));
	return 0;
}
