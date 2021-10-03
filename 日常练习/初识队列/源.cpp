#include<iostream>
using namespace std;
typedef int ElemType;
typedef struct LNode {
	ElemType data;
	LNode* next;
}LNode;
typedef struct {
	LNode* front;
	LNode* rear;
}LinkQueue;
void InitQueue(LinkQueue& q) {
	q.front = new LNode;
	q.rear = q.front;
	q.front->next = NULL;
}
void EnterQueue(LinkQueue& q, ElemType x) {
	//将数据元素x插入到队列q
	LNode* NewNode = new LNode;
	NewNode->data = x;
	NewNode->next = NULL;
	q.rear->next = NewNode;
	q.rear = NewNode;
}
bool DeQueue(LinkQueue& q, ElemType& x) {
	LNode* p;
	if (q.front == q.rear)
		return false;
	p = q.front->next;
	q.front->next = p->next;//队头元素p出队
	if (q.rear == p)
		q.rear = q.front;
	x = p->data;
	delete p;
	return false;
}