#include <iostream>
#include "sqstack.h" 
#include <string>
using namespace std;

void init(SqStack& s)
{
	s.top = -1;
}
//bool empty(SqStack s)
//{
//	return s.top==-1; 
//} 
// 
void push(SqStack& s, ElemType x)
{
	if (s.top == M - 1)
	{
		cout << "overflow\n";
		return;
	}
	s.data[++s.top] = x;
}

void pop(SqStack& s)
{
	s.top--;
}

ElemType top(SqStack s)
{
	return s.data[s.top];
}

bool empty(SqStack p) {
	if (p.top == -1)
		return true;
	else
		return false;
}
//.cpp放具体实现