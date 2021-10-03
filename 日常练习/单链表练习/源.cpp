#include<iostream>
using namespace std;
//����������
typedef int ElemType;

typedef struct LNode {
	ElemType data;//���Ԫ��ֵ
	struct LNode* next;//ָ���̽��
}LinkNode,LinkList;//������������
void OrderlyInsertNode(LinkNode*& L, ElemType x) {
	LinkNode* s, * p;
	p = L->next;
	s = new LinkNode;
	s->data = x;//�������ݽ��s
	while (p)
	{
		if (x >= p->data && x < p->next->data) {//���x����p��С��p��next
			s->next = p->next;//�����s���뵽p�ĺ���
			p->next = s;
			break;
		}
		p = p->next;
	}
}
void CreateListF(LinkNode* &L, ElemType a[], int n) {//linknode * &L,������������ṹ��ָ�����͵ı���L������L���ı�L
	L = new LNode;
	L->next = NULL;//����ͷ��㣬��next����ΪNULL
	LNode* p = L;
	for (int i = 0; i < n; i++)//ѭ���������ݽ��s
	{
		LNode *s;
		s= new LNode;
		s->data = a[i];//�������ݽ��s
		s->next = p->next;//�����s���뵽ԭ�׽��֮ǰ��ͷ���֮��
		p->next = s;
	}
}
void CreateListR(LinkNode*& L, ElemType a[], int n) {
	LinkNode* s, * r;
	L= (LinkNode*)malloc(sizeof(LinkNode));//����ͷ���
	r = L;//rʼ��ָ��β��㣬��ʼʱָ��ͷ���
	for (int i = 0; i < n; i++)//ѭ���������ݽ��
	{
		s= (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];//�������ݽ��s
		r->next = s;//�����s������r֮��
		r = s;
	}
	r->next = NULL;//β����next����ΪNULL
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
	s->data = Node.data;//�������ݽ��s
	s->next = L->next;//�����s���뵽ԭ�׽��֮ǰ��ͷ���֮��
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
				//cout << "�����ɾ��" << endl;
				break;
			}
			else {
				if (L->next->data == n) {
					L->next = NULL;
					//cout << "�����ɾ��" << endl;
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
//����ȥ�ز���
//˫��ѭ��������ͬ�� ����ɾ������ɾ���ظ���
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
	p = L->next;//pָ����Ԫ���
	while (p) {//��֤p��Ϊ��
		LNode* q = p->next;
		while(q){
			if (p->data == q->data) {
			deletNode(L, q);
			q = p->next;//ɾ����֮��q����Ϊp->next
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
	//��
	CreateListF(head, a, 10);
	PrintList(head);
	/*LinkNode tmp{9999,NULL};
	cout <<tmp.data<<" "<< &tmp << endl;
	InsertNode(head, tmp);
	cout << head->next->data;*/
	//ɾ
	//DeletNode(head, n);
	//PrintList(p);
	//��
	//��
	//SearchNode(head, n);
	//OrderlyInsertNode(p, n);
	deWeight(head);
	PrintList(head);
	return 0;
}