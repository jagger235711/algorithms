#include<iostream>
using namespace std;
//创建单链表
typedef int ElemType;

typedef struct LNode {
	ElemType data;//存放元素值
	struct LNode* next;//指向后继结点
}LinkNode;//单链表结点类型
void CreateListF(LinkNode*& L, ElemType a[], int n) {//linknode * &L,即引用了这个结构体指针类型的变量L，引用L则会改变L
	LinkNode* s;
	//L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;//创建头结点，其next域置为NULL
	for (int i = 0; i < n; i++)//循环建立数据结点s
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];//创建数据结点s
		s->next = L->next;//将结点s插入到原首结点之前，头结点之后
		L->next = s;
	}
}
void CreateListR(LinkNode*& L, ElemType a[], int n) {
	LinkNode* s, * r;
	//L = (LinkNode*)malloc(sizeof(LinkNode));//创建头结点
	s = new LinkNode();
	r = L;//r始终指向尾结点，初始时指向头结点
	
	for (int i = 1; i < n; i++)//循环建立数据结点
	{
		//s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];//创建数据结点s
		r->next = s;//将结点s插入结点r之后
		r = s;
	}
	r->next = NULL;//尾结点的next域置为NULL
}
void PrintList(LinkNode* L) {
	L = L->next;
	while (L->next != NULL)
	{
		cout << L->data << " ";
		L = L->next;
	}
	cout << L->data << endl;
}
void InsertNode(LinkNode*& L, LinkNode Node) {
	LinkNode* s;
	s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = Node.data;//创建数据结点s
	s->next = L->next;//将结点s插入到原首结点之前，头结点之后
	L->next = s;
}
void DeletNode(LinkNode*& L, int n) {
	while (L->next != NULL)
	{
		if (L->next->next != NULL)
		{
			L = L->next;
			if (L->next->data == n) {
				L->next = L->next->next;
				cout << "结点已删除" << endl;
				break;
			}
			else {
				if (L->next->data == n) {
					L->next = NULL;
					cout << "结点已删除" << endl;
				}
			}
		}
	}
}
void SearchNode(LinkNode*& L, ElemType data) {
	L = L->next;
	while (L->next != NULL) {
		if (L->data == data) {
			cout << "got it!" << endl;
			break;
		}
		else {
			L = L->next;
		}
	}
}

int main() {

	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
	LinkNode* t = p;
	ElemType a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int n;
	cin >> n;
	//增
	CreateListF(p, a, 10);
	PrintList(t);
	/*LinkNode tmp{9999,NULL};
	cout <<tmp.data<<" "<< &tmp << endl;
	InsertNode(p, tmp);
	cout << p->next->data;*/
	//删
	//DeletNode(p, n);
	//PrintList(t);
	//改
	//查
	SearchNode(p, n);
	return 0;
}