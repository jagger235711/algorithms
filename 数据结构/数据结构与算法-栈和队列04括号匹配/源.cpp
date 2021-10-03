/*
����
������ʽ��ֻ�����������ţ�Բ���š������źͻ����ţ����ǿ��໥Ƕ�ף���([{}])��({[][()]})�Ⱦ�Ϊ��ȷ�ĸ�ʽ,��{[]})}��{[()]��([]}��Ϊ����ȷ�ĸ�ʽ.

����һ������
�������������Ŷ��࣬���:Extra right brackets
�������������Ŷ���, ���:Extra left brackets
�����������Ų�ƥ�䣬���:Brackets not match
������������ƥ�䣬���:Brackets match
����
{{{{)))
���
Brackets not match
��������
{([)]}
�������
Brackets not match
��ʾ
����ջ�ṹ
*/
#include <iostream>
using namespace std;
typedef char ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode, * LinkStack;

void init(LinkStack& top);
bool isempty(LinkStack top);
void push(LinkStack& top, ElemType x);
int length(LinkStack top);
void output(LinkStack top);
void pop(LinkStack& top);
ElemType gettop(LinkStack top);
void destroy(LinkStack& top);
int matchfun(char* s);
char error[4][50] = { "Extra right brackets",//�������������Ŷ��࣬���:Extra right brackets
					 "Extra left brackets",//�������������Ŷ���, ���:Extra left brackets
					 "Brackets not match",//�����������Ų�ƥ�䣬���:Brackets not match
					 "Brackets match" };//������������ƥ�䣬���:Brackets match
int main(void)
{
	char str[100];

	cin >> str;
	int res = matchfun(str);
	cout << error[res];

	return 0;
}
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

int matchfun(char* s)
{
	LinkStack ls;
	init(ls);
	for (int i = 0; s[i]; i++)
	{
		if (s[i] == '{' || s[i] == '(' || s[i] == '[')
			push(ls, s[i]);
		else if (s[i] == '}')
		{
			if (isempty(ls)) return 0;
			else if (gettop(ls) != '{')	return 2;
			else pop(ls);
		}
		else if (s[i] == ')')
		{
			if (isempty(ls)) return 0;
			else if (gettop(ls) != '(')	return 2;
			else pop(ls);
		}
		else if (s[i] == ']')
		{
			if (isempty(ls)) return 0;
			else if (gettop(ls) != '[')	return 2;
			else pop(ls);
		}
	}
	if (!isempty(ls)) return 1;
	return 3;
}

