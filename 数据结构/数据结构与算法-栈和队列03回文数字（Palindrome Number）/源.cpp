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

void init(LinkStack& top);
bool isempty(LinkStack top);
void push(LinkStack& top, ElemType x);
int length(LinkStack top);
void output(LinkStack top);
void pop(LinkStack& top);
ElemType gettop(LinkStack top);
void destroy(LinkStack& top);
bool ispalindrome(char* s);
void myPop(LinkStack& top);
//ElemType myPop2(LinkStack& top);
void myPop2(LinkStack& top);
int main()
{
	char str[10];
	cin >> str;
	LinkStack ls;
	init(ls);
	for (int i = 0; str[i]; i++)
		push(ls, str[i]);
	/*for (int i = 0; str[i]; i++)
	{
		ElemType tmp = myPop2(ls);
		cout << "tmp is: " << tmp << endl;
	}*/
	/*for (int i = 0; i < 10; i++) {
		cout << "the num is: " << myPop2(ls) << endl;

		cout���ܳ���
		return������
	}*/
	while(!isempty(ls)) {
		//cout << "the num is: " << myPop2(ls) << endl;
		myPop2(ls);
	}

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
void myPop(LinkStack& top) {//Ϊ��̬���� Ҫ�����÷���
	LNode* p=top;
	if (top) {
		cout << top->data << " ";
		p = top;
		top = top->next;
		delete p;
	}
	cout << endl;
}

void myPop2(LinkStack& top) {//Ϊ��̬���� Ҫ�����÷���
	LNode* p = top;
	if (top) {
		cout << top->data<<endl;
	//	return top->data;
		p = top;
		top = top->next;
		delete p;
	}
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
bool ispalindrome(char* s)
{
	LinkStack ls;
	init(ls);
	for (int i = 0; s[i]; i++)
		push(ls, s[i]);
	for (int i = 0; s[i]; i++)
	{
		//ElemType tmp = myPop2(ls);
			//cout << "tmp is: " << tmp << endl;
	}
	/*for (int i = 0; s[i]; i++)
	{
		ElemType tmp = myPop2(ls);
		if (s[i] ==tmp ) {
			cout << "tmp is: " << tmp << endl;
		}
		else return false;
	}
	if (isempty(ls)) return true;
	return false;*/
	return true;
}