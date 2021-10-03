/*
描述
编写一个程序实现链栈（假设栈中元素类型为char）的各种基本运算，并在此基础上设计一个主程序完成如下功能：

（1）初始化链栈S;

（2）判断链栈S是否为空；

（3）依次进栈元素a，b，c，d，e;

（4）判断链栈S是否为空；

（5）输出链栈长度；

（6）输出从栈顶到栈底的元素；

（7）输出出栈序列；

（8）判断链栈S是否为空；

（9）释放链栈。



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

typedef struct linkNode {
	ElemType data;
	linkNode* next;
}LinkStNode;
void InitStack(LinkStNode*& s) {
	s = new LinkStNode();
	s->next = NULL;
} 
void Push(LinkStNode*& s, ElemType x) {
	LinkStNode* p;
	p = new LinkStNode();
	p->data = x;
	p->next = s->next;
	s->next = p;
}
bool isEmpty(LinkStNode* s) {
	if (s->next == NULL)
		return true;
	else
		return false;
}
void getLength(LinkStNode* s) {
	LinkStNode* p;
	int count = 0;
	p = s->next;
	while (p) {
		count++;
		p = p->next;
	}
	cout << count << endl;
}
void print(LinkStNode* s) {
	LinkStNode* p;
	p = s->next;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
void Pop(LinkStNode* &s) {
	LinkStNode* p;
	while (s->next) {
		p = s->next;
		cout<< p->data<<" ";
		s->next = p->next;
		free(p);
	}
	cout << endl;
}

int main() {
	int n;
	ElemType a;
	cin >> n;

	LinkStNode* s;
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
	print(s);
	free(s);
	return 0;
}
