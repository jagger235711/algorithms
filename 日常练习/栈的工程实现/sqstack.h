#pragma once
typedef int ElemType;
const int M = 5;
typedef struct
{
	ElemType data[M];
	int top;
} SqStack;

void init(SqStack& s);
bool empty(SqStack s);
void push(SqStack& s, ElemType x);
void pop(SqStack& s);
ElemType top(SqStack s);
void systemConvert(int number, int system, SqStack s);
bool empty(SqStack p);
//.h文件存放声明