#include<iostream>
using namespace std;
//创建单链表
typedef int ElemType;

typedef struct LNode {
	ElemType data;//存放元素值
	struct LNode* next;//指向后继结点
}LinkNode,LinkList;//单链表结点类型
void OrderlyInsertNode(LinkNode*& L, ElemType x) {
	LinkNode* s, * p;
	p = L->next;
	s = new LinkNode;
	s->data = x;//创建数据结点s
	while (p)
	{
		if (x >= p->data && x < p->next->data) {//如果x大于p且小于p的next
			s->next = p->next;//将结点s插入到p的后面
			p->next = s;
			break;
		}
		p = p->next;
	}
}
void CreateListF(LinkNode* &L, ElemType a[], int n) {//linknode * &L,即引用了这个结构体指针类型的变量L，引用L则会改变L
	L = new LNode;
	L->next = NULL;//创建头结点，其next域置为NULL
	LNode* p = L;
	for (int i = 0; i < n; i++)//循环建立数据结点s
	{
		LNode *s;
		s= new LNode;
		s->data = a[i];//创建数据结点s
		s->next = p->next;//将结点s插入到原首结点之前，头结点之后
		p->next = s;
	}
}
void CreateListR(LinkNode*& L, ElemType a[], int n) {
	LinkNode* s, * r;
	L= (LinkNode*)malloc(sizeof(LinkNode));//创建头结点
	r = L;//r始终指向尾结点，初始时指向头结点
	for (int i = 0; i < n; i++)//循环建立数据结点
	{
		s= (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];//创建数据结点s
		r->next = s;//将结点s插入结点r之后
		r = s;
	}
	r->next = NULL;//尾结点的next域置为NULL
}
void PrintList(LinkNode* L) {
	L = L->next;
	while (L->next!=NULL)
	{
		cout << L->data << " ";
		L = L->next;
	}
	cout <<L->data<< endl;
}
void InsertNode(LinkNode*& L, LinkNode Node) {
	LinkNode* s;
	s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = Node.data;//创建数据结点s
	s->next = L->next;//将结点s插入到原首结点之前，头结点之后
	L->next = s;
}
void DeletNode(LinkNode*& L, int n) {
	while (L->next!=NULL)
	{
		if (L->next->next!=NULL)
		{
			L = L->next;
			if (L->next->data == n) {
				L->next = L->next->next;
				//cout << "结点已删除" << endl;
				break;
			}
			else {
				if (L->next->data == n) {
					L->next = NULL;
					//cout << "结点已删除" << endl;
				}
			}
		}
	}
}
void SearchNode(LinkNode*& L, ElemType data) {
	L = L->next;
	while (L->next != NULL) {
		if (L->data==data) {
			cout << "got it!" << endl;
			break;
		}
		else {
			L = L->next;
		}
	}
}
//链表去重操作
//双重循环查找相同数 调用删除函数删除重复数
void deletNode(LinkNode* L,LNode *p) {
	LNode* q;
	q = L->next;
	while (q) {
		if (q->next == p) {
			q->next = p->next;
			delete(p);
		}
		else q = q->next;
	}

}
void deWeight(LinkNode*& L) {
	LNode* p;
	p = L->next;//p指向首元结点
	while (p) {//保证p不为空
		LNode* q = p->next;
		while(q){
			if (p->data == q->data) {
			deletNode(L, q);
			q = p->next;//删除完之后将q重置为p->next
			}
			else q = q->next;
		}
		p = p->next;
	}
}
void sortlink(LinkList L) {
	LNode* n = new LNode;
	n = head;
	if (n->next == NULL) {
		L->next = head->next;
		head->next = L;
		return;
	}
int main() {

	LinkNode* head = new LNode;
	
	ElemType a[10] = { 1,10,9,9,8,7,4,4,4,1 };
	//增
	CreateListF(head, a, 10);
	PrintList(head);
	/*LinkNode tmp{9999,NULL};
	cout <<tmp.data<<" "<< &tmp << endl;
	InsertNode(head, tmp);
	cout << head->next->data;*/
	//删
	//DeletNode(head, n);
	//PrintList(p);
	//改
	//查
	//SearchNode(head, n);
	//OrderlyInsertNode(p, n);
	deWeight(head);
	PrintList(head);
	return 0;
}