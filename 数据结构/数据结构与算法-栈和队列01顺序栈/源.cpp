/*
����
��дһ������ʵ��˳��ջ������ջ��Ԫ������Ϊchar���ĸ��ֻ������㣬���ڴ˻��������һ��������������¹��ܣ�

��1����ʼ��˳��ջS;

��2���ж�˳��ջS�Ƿ�Ϊ�գ�

��3�����ν�ջԪ��a��b��c��d��e;

��4���ж�˳��ջS�Ƿ�Ϊ�գ�

��5�����˳��ջ���ȣ�

��6�������ջ����ջ�׵�Ԫ�أ�

��7�������ջ���У�

��8���ж�˳��ջS�Ƿ�Ϊ�գ�

��9���ͷ�˳��ջ��

����
�������ݣ���һ������ջ�ַ����ݵĸ������ڶ����Ǿ�����ջ���ַ����ݡ�
���
���ճ���Ҫ�������
��������
5
a b c d e
�������
yes
no
5
e d c b a
e d c b a
yes
*/

#include<iostream>
using namespace std;

typedef char ElemType;
//#define MSize 20;
constexpr auto MSize = 20;

typedef struct {
	ElemType data[MSize];
	int top;
}sqStack;

void InitStack(sqStack *&s) {
	s = new sqStack();
	s->top = -1;
}
bool isFull(sqStack *s) {
	if (s->top == MSize - 1)
		return true;
	else
		return false;
}
void Push(sqStack *&s,ElemType x) {
	sqStack* p = s;
	if (isFull(p))
		printf("stack is full.\n");
	else
		p->data[++p->top] = x;
}
bool isEmpty(sqStack *s) {
	if (s->top == -1)
		return true;
	else
		return false;
}
void getLength(sqStack* s) {
	cout << s->top +1<<endl;
}
void print(sqStack* s) {
	int top = s->top;
	while (top!=-1)
	{
		cout << s->data[top--] << " ";
	}
	cout << endl;
}
void Pop(sqStack*& s) {
	while (s->top != -1)
	{
		cout << s->data[s->top--] << " ";
	}
	cout << endl;
}
int main() {
	int n;
	ElemType a;
	cin >> n;

		sqStack* s;
		InitStack(s);
		if (isEmpty(s))
			cout << "yes" << endl;
		else cout << "no" << endl;
		for (int i = 0; i < n; i++) {
			cin >> a;
			Push(s, a);
		}
		if (isEmpty(s))
			cout << "yes" << endl;
		else cout << "no" << endl;
		getLength(s);
		print(s);
		Pop(s);
		if (isEmpty(s))
			cout << "yes" << endl;
		else cout << "no" << endl;
		free(s);
	return 0;
}
