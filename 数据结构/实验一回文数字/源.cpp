/*
描述
给出一系列非负整数，判断是否是一个回文数。回文数指的是正着写和倒着写相等的数。

输入
若干行，每行是一个非负整数（不超过99999999）
输出
对每行输入，如果其是一个回文数，输出YES。否则输出NO。
样例输入
11
123
0
14277241
67945497
样例输出
YES
NO
YES
YES
NO

1 存入字符数组
2 以字符类型压入栈
3 一一对比

cout就能出来
return出不来

注意以return形式返回数据，且函数参数是以指针/引用传递的。
这样的函数没法改变以指针/引用传递的参数的值。
*/
#include <iostream>
using namespace std;
typedef char ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode, * LinkStack;
void init(LinkStack& top)
{
	top = NULL;
}
bool isempty(LinkStack top)
{
	return top == NULL;
}
void push(LinkStack& top, ElemType x)
{
	LNode* s = new LNode;
	s->data = x;
	s->next = top;
	top = s;
}

int length(LinkStack top)
{
	int n = 0;
	LNode* p = top;
	while (p)
	{
		n++;
		p = p->next;
	}
	return n;
}
void output(LinkStack top)
{
	LNode* p = top;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
void pop(LinkStack& top)
{
	LNode* q = top;
	top = top->next;
	delete q;
}
ElemType gettop(LinkStack top)
{
	return top->data;
}
void destroy(LinkStack& top)
{
	LNode* p = top;
	while (p)
	{
		LNode* q = p;
		p = p->next;
		delete q;
	}
}
bool huiwen(char* s)
{
	LinkStack l;
	init(l);
	for (int i = 0; s[i]; i++)
		push(l, s[i]);
	for (int i = 0; s[i]; i++)
	{
		if (s[i] == gettop(l))
			pop(l);
		else return false;
	}
	if (isempty(l)) return true;
	return false;
}
int main(void)
{
	char str[10];

	while (cin >> str)
	{
		if (huiwen(str))
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}
