#include <iostream>
using namespace std;
typedef char ElemType;
typedef struct BTNode {
	ElemType data;
	struct BTNode* lchild, * rchild;
	int ltag=0, rtag=0;
}BTNode, * BTree;

void create(BTree& bt);// 先序创建二叉树bt 
void inorder(BTree bt);// 中序遍历二叉树bt 
void inthread(BTree& bt, BTree& pre);// 中序遍历对二叉树bt进行线索化
void createthread(BTree& bt); // 对二叉树bt进行线索化，并含头结点 

void visitthread(BTree bt);// 对含头结点的线索二叉树bt进行中序遍历 

int main(void) {//ABD#G###CE##F##
	BTree bt;
	BTree head;

	create(bt);  // 先序创建二叉树bt
	cout << "中序序列：";
	inorder(bt); // 中序遍历二叉树bt
	cout << endl;

	createthread(bt);	// 对二叉树bt进行线索化，并含头结点
	//inthread(bt, head);
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
void inthread(BTree& bt, BTree& pre)
{
	if (bt != NULL) {
		inthread(bt->lchild, pre);//递归，线索化左子树
		if (bt->lchild == NULL) {//左子树为空，建立前驱线索
			bt->lchild = pre;
			bt->ltag = 1;
		}
		if (pre != NULL && pre->rchild == NULL) {//右子树为空，建立后继线索
			pre->rchild = bt;//建立前驱节点的后继线索
			pre->rtag = 1;
		}
		pre = bt;//标记当前节点为刚访问过的节点
		inthread(bt->rchild, pre);//递归，线索化右子树
	}
}
//void inthread(BTree& bt, BTNode*& pre) {
//	if (bt) {
//		inthread(bt->lchild, pre); // bt的左子树进行中序线索化 
//		// 对bt的ltag进行赋值，同时对bt的空lchild进行赋值 
//		if (bt->lchild)	bt->ltag = 0;
//		else {
//			bt->ltag = 1;
//			bt->lchild = pre;
//		}
//		if (pre) {// 对pre的ltag进行赋值，同时对bt的空lchild进行赋值 
//			if (pre->rchild) pre->rtag = 0;
//			else {
//				pre->rchild = bt; pre->rtag = 1;
//			}
//		}
//		pre = bt;// pre的值修改成bt
//
//		inthread(bt->rchild, pre);// bt的右子树进行中序线索化 
//	}
//}
//void visitthread(BTree bt) {
//	BTNode* p = bt->lchild; // p指向二叉树的根 
//	while (p != bt) {
//		// 寻找bt对应二叉树中序遍历中的第一个点p
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
	BTNode* p = bt->lchild; // p指向二叉树的根 
	while (p != NULL) {
		// 寻找bt对应二叉树中序遍历中的第一个点p
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
//	BTNode* head = new BTNode;//带头结点
//
//	head->ltag = 0; head->rtag = 1;//左孩子存在 无右孩子
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
	BTNode* head = new BTNode;//头结点 将bt挂到左子树
	if (bt != NULL) {//非空二叉树，线索化
		inthread(bt, head);
		head->rchild = NULL;//处理遍历的最后一个节点
		head->rtag = 1;
	}
	
}


