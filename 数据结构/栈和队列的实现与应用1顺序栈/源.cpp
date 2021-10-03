#include<iostream>
using namespace std;

typedef int ElemType;
//#define MSize 20;
constexpr auto MSize = 20;

typedef struct {
	ElemType data[MSize];
	int top;
}sqStack;
void InitStack(sqStack*& p);
bool empty(sqStack* p);
int size(sqStack* p);
void pop(sqStack*& p);//动态操作，引用传递
void top(sqStack* p);
void push(sqStack*& p,ElemType x);
int main() {
	sqStack* sq;
	InitStack(sq);
	cout << empty(sq) << " " << endl;
	for (int i = 0; i < 5; i++) {
		push(sq, i);
	}
	cout << size(sq) << " " << endl;
	top(sq);
	pop(sq);
	top(sq);
	cout << size(sq) << " " << endl;
	return 0;
}
void InitStack(sqStack*& p) {
	p = new sqStack();
	p->top = -1;
}
bool empty(sqStack* p) {
	if (p->top == -1)
		return true;
	else
		return false;
}
int size(sqStack* p) {
	return p->top + 1;
}
void pop(sqStack*& p) {
	if (p->top != -1) {
		p->top--;
	}
}
void top(sqStack* p) {
	if (p->top != -1) {
		cout << p->data[p->top] << " " << endl;
	}
}

void push(sqStack*& p, ElemType x)
{
	if (p->top != MSize-1) {
		p->top++;
		p->data[p->top] = x;
	}
}
