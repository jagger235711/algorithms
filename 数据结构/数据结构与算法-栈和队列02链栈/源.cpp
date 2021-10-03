/*
����
��дһ������ʵ����ջ������ջ��Ԫ������Ϊchar���ĸ��ֻ������㣬���ڴ˻��������һ��������������¹��ܣ�

��1����ʼ����ջS;

��2���ж���ջS�Ƿ�Ϊ�գ�

��3�����ν�ջԪ��a��b��c��d��e;

��4���ж���ջS�Ƿ�Ϊ�գ�

��5�������ջ���ȣ�

��6�������ջ����ջ�׵�Ԫ�أ�

��7�������ջ���У�

��8���ж���ջS�Ƿ�Ϊ�գ�

��9���ͷ���ջ��



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
