/*
描述
编写一个程序实现顺序栈（假设栈中元素类型为char）的各种基本运算，并在此基础上设计一个主程序完成如下功能：

（1）初始化顺序栈S;

（2）判断顺序栈S是否为空；

（3）依次进栈元素a，b，c，d，e;

（4）判断顺序栈S是否为空；

（5）输出顺序栈长度；

（6）输出从栈顶到栈底的元素；

（7）输出出栈序列；

（8）判断顺序栈S是否为空；

（9）释放顺序栈。

输入
两行数据，第一行是入栈字符数据的个数，第二行是具体入栈的字符数据。
输出
按照程序要求输出。
样例输入
5
a b c d e
样例输出
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
