/*
����
����һϵ�зǸ��������ж��Ƿ���һ����������������ָ��������д�͵���д��ȵ�����

����
�����У�ÿ����һ���Ǹ�������������99999999��
���
��ÿ�����룬�������һ�������������YES���������NO��
��������
11
123
0
14277241
67945497
�������
YES
NO
YES
YES
NO

1 �����ַ�����
2 ���ַ�����ѹ��ջ
3 һһ�Ա�

cout���ܳ���
return������

ע����return��ʽ�������ݣ��Һ�����������ָ��/���ô��ݵġ�
�����ĺ���û���ı���ָ��/���ô��ݵĲ�����ֵ��
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
