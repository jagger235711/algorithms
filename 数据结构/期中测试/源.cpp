#include <iostream>
#include <cstdlib> 
using namespace std;
typedef struct Node
{
	char data;
	struct Node* next;
} Node, * LinkList;

LinkList head;
LinkList create_LinkList();
void display(LinkList L);
void sortlink(LinkList L);
void output(LinkList L)
{
	if (L == NULL) cout << "list is empty!";
	else
	{
		Node* p = L;
		while (p)
		{
			cout << p->data << " ";
			p = p->next;
		}

	}
	cout << endl;
}

int main()
{
	Node* L = create_LinkList();
	output(head->next);

	return 0;
}

LinkList create_LinkList()//头插法建立单链表 
{
	head = new Node;
	head->next = NULL;
	char c;
	while (1)
	{
		Node* s = new Node;
		cin >> c;
		if (c == '$') break;
		s->data = c;
		sortlink(s);
	}
	return head;
}
void sortlink(LinkList L) {
	Node* n = new Node;
	n = head;
	if (n->next == NULL) {
		L->next = head->next;
		head->next = L;
		return;
	}
	while (n->next != NULL && n->next->data < L->data) {
		n = n->next;
	}
	L->next = n->next;
	n->next = L;
	return;
}