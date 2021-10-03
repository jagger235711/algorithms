#include <iostream>
using namespace std;
typedef char ElemType;
typedef struct BTNode {
	ElemType data;
	struct BTNode* lchild, * rchild;
	int ltag, rtag;
}BTNode, * BTree;

void create(BTree& bt);// 先序创建二叉树bt 
void inorder(BTree bt);// 中序遍历二叉树bt 
void inthread(BTree& bt, BTNode& pre);// 对二叉树bt进行中序线索化
void createthread(BTree& bt); // 对二叉树bt进行线索化，并含头结点 
void visitthread(BTree bt);// 对含头结点的线索二叉树bt进行中序遍历 

int main(void) {//ABD#G###CE##F##
	BTree bt;

	create(bt);  // 先序创建二叉树bt
	cout << "中序序列：";
	inorder(bt); // 中序遍历二叉树bt
	cout << endl;

	createthread(bt);	// 对二叉树bt进行线索化，并含头结点
	visitthread(bt);    // 对含头结点的线索二叉树bt进行中序遍历

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
		inthread(bt->lchild, pre); // bt的左子树进行中序线索化 
		// 对bt的ltag进行赋值，同时对bt的空lchild进行赋值 
		if (bt->lchild)	bt->ltag = 0;
		else {
			bt->ltag = 1;
			bt->lchild = pre;
		}
		if (pre) {// 对pre的ltag进行赋值，同时对bt的空lchild进行赋值 
			if (pre->rchild) pre->rtag = 0;
			else {
				pre->rchild = bt; pre->rtag = 1;
			}
		}
		pre = bt;// pre的值修改成bt

		inthread(bt->rchild, pre);// bt的右子树进行中序线索化 
	}
}
void visitthread(BTree bt) {
	BTNode* p = bt->lchild; // p指向二叉树的根 
	while (p != bt) {
		// 寻找bt对应二叉树中序遍历中的第一个点p
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
	BTNode* head = new BTNode;//带头结点

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


