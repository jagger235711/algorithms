#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef char ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode, * LinkStack;
void initStack(LinkStack& s);
void clear(LinkStack& s);
bool isEmpty(LinkStack s);
bool isFull(LinkStack s);
void push(LinkStack& s);
void pop(LinkStack& s);
ElemType getTop(LinkStack s);
int priority(char c);  // ���ز�����c�����ȼ� 
bool isop(char c);     // �ж��ַ�c�Ƿ�Ϊ������ 
void topoststr(char* str, char* poststr);// ����׺ʽstrת���ɺ�׺ʽpoststr 
int postval(char* str);// ���׺ʽstr��ֵ 
int main()
{// 20-(30+10/2-9-2^4)	
	char str[100], poststr[100];

	cin >> str;              // ������׺ʽ 
	topoststr(str, poststr); // ����׺ʽstr��Ӧ�ĺ�׺ʽ 
	cout << poststr << "=" << postval(poststr) << endl;// �����׺ʽ=ֵ 

	return 0;
}
void initStack(LinkStack& s)
{
	s = NULL;  // s.top = M
}
void clear(LinkStack& s)
{
	LNode* p = s;
	s = NULL;
	while (p)
	{
		LNode* q = p;
		p = p->next;
		delete q;
	}
}
bool isEmpty(LinkStack s)
{
	return s == NULL;
}
bool isFull(LinkStack s)
{
	LNode* p = new LNode;
	if (!p) return true;
	delete p;
	return false;
}
void push(LinkStack& s, ElemType e)
{
	LNode* p = new LNode;
	p->data = e;
	p->next = s;
	s = p;
}
void pop(LinkStack& s)
{
	LNode* p = s;
	s = s->next;
}
ElemType getTop(LinkStack s)
{
	return s->data;
}
void output(LinkStack s)
{
	LNode* p = s;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
int priority(char c)
{
	int res;
	switch (c)
	{
	case '#': res = 0; break;
	case '(': res = 1; break;
	case '+':
	case '-': res = 2; break;
	case '*':
	case '/': res = 3; break;
	case '^': res = 4; break;
	}
	return res;
}
bool isop(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}
void topoststr(char* str, char* poststr)
{
	LinkStack s;
	initStack(s);
	push(s, '#');
	int k = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{// ��������Ӧ���������������׺ʽpoststr������һ���ո� 
			while (str[i] && str[i] >= '0' && str[i] <= '9')
			{
				poststr[k++] = str[i];
				i++;
			}
			poststr[k++] = ' ';
			i--;
		}
		else if (str[i] == '(')	push(s, str[i]); // (�������ջ 
		else if (str[i] == ')')
		{// ��Ҫ��()֮���ջ���ַ������׺ʽpoststr 
			while (getTop(s) != '(')
			{
				poststr[k++] = getTop(s);
				pop(s);
			}
			pop(s); // ( ��ջ 
		}
		else if (isop(str[i]))
		{// ������ʱ:�����ڵ�ǰ����������str[i]��ջ���ַ������׺ʽpoststr 
			while (!isEmpty(s) && priority(getTop(s)) >= priority(str[i]))
			{
				poststr[k++] = getTop(s);
				pop(s);
			}
			push(s, str[i]);// ��ǰ����������str[i]��ջ 
		}
	}
	while (!isEmpty(s) && getTop(s) != '#')
	{// ջ�����������������׺ʽpoststr 
		poststr[k++] = getTop(s);
		pop(s);
	}
	poststr[k] = '\0';
}
void compute(int* sta, int& top, char c)
{// ��������ջsta��ջ����������ջ������c���㣬����ջ 
	int a, b, res;
	b = sta[top--];
	a = sta[top--];
	switch (c)
	{
	case '+': res = a + b; break;
	case '-': res = a - b; break;
	case '*': res = a * b; break;
	case '/':
		if (b != 0) res = a / b;
		else
		{
			cout << "divided by 0" << endl;
			exit(1);
		}
		break;
	case '^': res = pow(a, b); break;
	}
	sta[++top] = res;
}
int postval(char* str)
{
	int dstack[100];// ������ջ 
	int top = -1;

	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{// ����׺ʽ�е����ִ�ת���ɶ�Ӧ����������ջ 
			int d = 0;
			while (str[i] && str[i] >= '0' && str[i] <= '9')
			{
				d = d * 10 + str[i] - '0';
				i++;
			}
			dstack[++top] = d;
		}
		else
		{// ��ǰ�ַ�str[i]Ϊ������ʱ���Բ�����ջ��ջ�������ݽ������� 
			compute(dstack, top, str[i]);
		}
	}
	return dstack[top]; // ���ر��ʽ��ֵ 
}




