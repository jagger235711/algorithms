#include <iostream>
using namespace std;
typedef char ElemType;
typedef struct BTNode {
	ElemType data;
	struct BTNode* lchild, * rchild;
	int ltag=0, rtag=0;
}BTNode, * BTree;

void create(BTree& bt);// ���򴴽�������bt 
void inorder(BTree bt);// �������������bt 
void inthread(BTree& bt, BTree& pre);// ��������Զ�����bt����������
void createthread(BTree& bt); // �Զ�����bt����������������ͷ��� 

void visitthread(BTree bt);// �Ժ�ͷ��������������bt����������� 

int main(void) {//ABD#G###CE##F##
	BTree bt;
	BTree head;

	create(bt);  // ���򴴽�������bt
	cout << "�������У�";
	inorder(bt); // �������������bt
	cout << endl;

	createthread(bt);	// �Զ�����bt����������������ͷ���
	//inthread(bt, head);
	visitthread(bt);    // �Ժ�ͷ��������������bt�����������

	return 0;
}
void create(BTree& bt) {
	ElemType x;
	cin >> x;
	if (x == '#') 	bt = NULL;
	else {
		bt = new BTNode;
		bt->data = x;
		create(bt->lchild);
		create(bt->rchild);
	}
}
void inorder(BTree bt) {
	if (bt) {
		inorder(bt->lchild);
		cout << bt->data << " ";
		inorder(bt->rchild);
	}
}
void inthread(BTree& bt, BTree& pre)
{
	if (bt != NULL) {
		inthread(bt->lchild, pre);//�ݹ飬������������
		if (bt->lchild == NULL) {//������Ϊ�գ�����ǰ������
			bt->lchild = pre;
			bt->ltag = 1;
		}
		if (pre != NULL && pre->rchild == NULL) {//������Ϊ�գ������������
			pre->rchild = bt;//����ǰ���ڵ�ĺ������
			pre->rtag = 1;
		}
		pre = bt;//��ǵ�ǰ�ڵ�Ϊ�շ��ʹ��Ľڵ�
		inthread(bt->rchild, pre);//�ݹ飬������������
	}
}
//void inthread(BTree& bt, BTNode*& pre) {
//	if (bt) {
//		inthread(bt->lchild, pre); // bt���������������������� 
//		// ��bt��ltag���и�ֵ��ͬʱ��bt�Ŀ�lchild���и�ֵ 
//		if (bt->lchild)	bt->ltag = 0;
//		else {
//			bt->ltag = 1;
//			bt->lchild = pre;
//		}
//		if (pre) {// ��pre��ltag���и�ֵ��ͬʱ��bt�Ŀ�lchild���и�ֵ 
//			if (pre->rchild) pre->rtag = 0;
//			else {
//				pre->rchild = bt; pre->rtag = 1;
//			}
//		}
//		pre = bt;// pre��ֵ�޸ĳ�bt
//
//		inthread(bt->rchild, pre);// bt���������������������� 
//	}
//}
//void visitthread(BTree bt) {
//	BTNode* p = bt->lchild; // pָ��������ĸ� 
//	while (p != bt) {
//		// Ѱ��bt��Ӧ��������������еĵ�һ����p
//		while (p->ltag == 0) 	p = p->lchild;
//		cout << p->data << " ";// visit p
//		// next p
//		while (p->rtag == 1 && p->rchild != bt)
//		{
//			p = p->rchild;
//			cout << p->data << " ";
//		}
//		p = p->rchild;
//	}
//}

void visitthread(BTree bt) {
	BTNode* p = bt->lchild; // pָ��������ĸ� 
	while (p != NULL) {
		// Ѱ��bt��Ӧ��������������еĵ�һ����p
		while (p->ltag == 0) 	p = p->lchild;
		cout << p->data << " ";// visit p
		// next p
		while (p->rtag == 1 && p->rchild != NULL)
		{
			p = p->rchild;
			cout << p->data << " ";
		}
		p = p->rchild;
	}
}

//void createthread(BTree& bt)
//{
//	BTNode* head = new BTNode;//��ͷ���
//
//	head->ltag = 0; head->rtag = 1;//���Ӵ��� ���Һ���
//	head->rchild = bt;
//	if (bt==NULL) head->lchild = head;
//	else {
//		head->lchild = bt;
//		BTNode* pre = head;
//		inthread(bt, pre);
//		pre->rtag = 1;
//		pre->rchild = head;
//		head->rchild = pre;
//	}
//	bt = head;
//}
void createthread(BTree& bt)
{
	BTNode* head = new BTNode;//ͷ��� ��bt�ҵ�������
	if (bt != NULL) {//�ǿն�������������
		inthread(bt, head);
		head->rchild = NULL;//������������һ���ڵ�
		head->rtag = 1;
	}
	
}


