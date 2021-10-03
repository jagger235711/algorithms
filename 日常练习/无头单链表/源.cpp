#include<iostream>
using namespace std;
//����������
typedef int ElemType;

typedef struct LNode {
	ElemType data;//���Ԫ��ֵ
	struct LNode* next;//ָ���̽��
}LinkNode;//������������
void CreateListF(LinkNode*& L, ElemType a[], int n) {//linknode * &L,������������ṹ��ָ�����͵ı���L������L���ı�L
	LinkNode* s;
	//L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;//����ͷ��㣬��next����ΪNULL
	for (int i = 0; i < n; i++)//ѭ���������ݽ��s
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];//�������ݽ��s
		s->next = L->next;//�����s���뵽ԭ�׽��֮ǰ��ͷ���֮��
		L->next = s;
	}
}
void CreateListR(LinkNode*& L, ElemType a[], int n) {
	LinkNode* s, * r;
	//L = (LinkNode*)malloc(sizeof(LinkNode));//����ͷ���
	s = new LinkNode();
	r = L;//rʼ��ָ��β��㣬��ʼʱָ��ͷ���
	
	for (int i = 1; i < n; i++)//ѭ���������ݽ��
	{
		//s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];//�������ݽ��s
		r->next = s;//�����s������r֮��
		r = s;
	}
	r->next = NULL;//β����next����ΪNULL
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
	s->data = Node.data;//�������ݽ��s
	s->next = L->next;//�����s���뵽ԭ�׽��֮ǰ��ͷ���֮��
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
				cout << "�����ɾ��" << endl;
				break;
			}
			else {
				if (L->next->data == n) {
					L->next = NULL;
					cout << "�����ɾ��" << endl;
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
	//��
	CreateListF(p, a, 10);
	PrintList(t);
	/*LinkNode tmp{9999,NULL};
	cout <<tmp.data<<" "<< &tmp << endl;
	InsertNode(p, tmp);
	cout << p->next->data;*/
	//ɾ
	//DeletNode(p, n);
	//PrintList(t);
	//��
	//��
	SearchNode(p, n);
	return 0;
}