#include <iostream>
using namespace std;
typedef char ElemType;
typedef struct BTNode {
	ElemType data;
	struct BTNode* lchild, * rchild;
	int ltag, rtag;
}BTNode, * BTree;

void create(BTree& bt);// ���򴴽�������bt 
void inorder(BTree bt);// �������������bt 
void inthread(BTree& bt, BTNode& pre);// �Զ�����bt��������������
void createthread(BTree& bt); // �Զ�����bt����������������ͷ��� 
void visitthread(BTree bt);// �Ժ�ͷ��������������bt����������� 

int main(void) {//ABD#G###CE##F##
	BTree bt;

	create(bt);  // ���򴴽�������bt
	cout << "�������У�";
	inorder(bt); // �������������bt
	cout << endl;

	createthread(bt);	// �Զ�����bt����������������ͷ���
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
void inthread(BTree& bt, BTNode*& pre) {
	if (bt) {
		inthread(bt->lchild, pre); // bt���������������������� 
		// ��bt��ltag���и�ֵ��ͬʱ��bt�Ŀ�lchild���и�ֵ 
		if (bt->lchild)	bt->ltag = 0;
		else {
			bt->ltag = 1;
			bt->lchild = pre;
		}
		if (pre) {// ��pre��ltag���и�ֵ��ͬʱ��bt�Ŀ�lchild���и�ֵ 
			if (pre->rchild) pre->rtag = 0;
			else {
				pre->rchild = bt; pre->rtag = 1;
			}
		}
		pre = bt;// pre��ֵ�޸ĳ�bt

		inthread(bt->rchild, pre);// bt���������������������� 
	}
}
void visitthread(BTree bt) {
	BTNode* p = bt->lchild; // pָ��������ĸ� 
	while (p != bt) {
		// Ѱ��bt��Ӧ��������������еĵ�һ����p
		while (p->ltag == 0) 	p = p->lchild;
		cout << p->data << " ";// visit p
		// next p
		while (p->rtag == 1 && p->rchild != bt)
		{
			p = p->rchild;
			cout << p->data << " ";
		}
		p = p->rchild;
	}
}
void createthread(BTree& bt)
{
	BTNode* head = new BTNode;//��ͷ���

	head->ltag = 0; head->rtag = 1;
	head->rchild = bt;
	if (!bt) head->lchild = head;
	else {
		head->lchild = bt;
		BTNode* pre = head;
		inthread(bt, pre);
		pre->rtag = 1;
		pre->rchild = head;
		head->rchild = pre;
	}
	bt = head;
}


