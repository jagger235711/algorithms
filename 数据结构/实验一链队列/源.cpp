#include<iostream>
using namespace std;
typedef int elemType;
typedef struct node {
	elemType data;
	node* next;
}Node;
typedef struct {
	Node* front;
	Node* rear;
}queue;
void init(queue &queue) {
	queue.front = queue.rear = new Node();
	queue.front->next = NULL;
}
void getLength(queue queue) {
	int count = 0;
	Node* p;
	p = queue.front->next;
	while (p != NULL) {
		count++;
		p = p->next;
	}
	cout<<count<<endl;
}
void enqueue(queue &queue, elemType x) {
	Node* p = new Node();
	p->data = x;
	p->next = queue.rear->next;
	queue.rear->next = p;
	queue.rear = p;
}
void dequeue(queue& queue) {
	Node* p;
	p = queue.front->next;
	if (p!=NULL) {
	queue.front->next = p->next;
	free(p);
	}
}
elemType GetHead(queue queue) {
	Node* p;
	p = queue.front->next;
	if (p != NULL) {
		return p->data;
	}
	else
		return -1;
}
int main() {
	queue q;
	init(q);
	while (1){
		elemType x;
		cin >> x;
		if (x != -1)
			enqueue(q, x);
		else
			break;
	}
	getLength(q);
	cout << GetHead(q) << endl;
	dequeue(q);
	cout << GetHead(q) << endl;
	return 0;
}