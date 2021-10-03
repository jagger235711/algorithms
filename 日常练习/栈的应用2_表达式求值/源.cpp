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
int priority(char c);  // 返回操作符c的优先级 
bool isop(char c);     // 判断字符c是否为操作符 
void topoststr(char* str, char* poststr);// 将中缀式str转换成后缀式poststr 
int postval(char* str);// 求后缀式str的值 
int main()
{// 20-(30+10/2-9-2^4)	
	char str[100], poststr[100];

	cin >> str;              // 输入中缀式 
	topoststr(str, poststr); // 求中缀式str对应的后缀式 
	cout << poststr << "=" << postval(poststr) << endl;// 输出后缀式=值 

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
		{// 操作数对应的数字依次送入后缀式poststr，最后加一个空格 
			while (str[i] && str[i] >= '0' && str[i] <= '9')
			{
				poststr[k++] = str[i];
				i++;
			}
			poststr[k++] = ' ';
			i--;
		}
		else if (str[i] == '(')	push(s, str[i]); // (入操作符栈 
		else if (str[i] == ')')
		{// 需要把()之间的栈中字符送入后缀式poststr 
			while (getTop(s) != '(')
			{
				poststr[k++] = getTop(s);
				pop(s);
			}
			pop(s); // ( 出栈 
		}
		else if (isop(str[i]))
		{// 操作符时:将高于当前所读操作符str[i]的栈顶字符送入后缀式poststr 
			while (!isEmpty(s) && priority(getTop(s)) >= priority(str[i]))
			{
				poststr[k++] = getTop(s);
				pop(s);
			}
			push(s, str[i]);// 当前所读操作符str[i]入栈 
		}
	}
	while (!isEmpty(s) && getTop(s) != '#')
	{// 栈内其他操作符送入后缀式poststr 
		poststr[k++] = getTop(s);
		pop(s);
	}
	poststr[k] = '\0';
}
void compute(int* sta, int& top, char c)
{// 将操作数栈sta的栈顶两个数出栈并进行c运算，并入栈 
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
	int dstack[100];// 操作数栈 
	int top = -1;

	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{// 将后缀式中的数字串转换成对应的整数并入栈 
			int d = 0;
			while (str[i] && str[i] >= '0' && str[i] <= '9')
			{
				d = d * 10 + str[i] - '0';
				i++;
			}
			dstack[++top] = d;
		}
		else
		{// 当前字符str[i]为操作符时，对操作数栈的栈顶两数据进行运算 
			compute(dstack, top, str[i]);
		}
	}
	return dstack[top]; // 返回表达式的值 
}




