#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
using namespace std;

typedef char elemType;
typedef struct node {
	elemType data;
	node* lChild, * rChild;
}BTNode,*BTree;

void create(BTree& bt); // 先序创建，#为空 
void preorder(BTree bt);// 先序遍历 
void inorder(BTree bt); // 中序遍历
void postorder(BTree bt);// 后序遍历
int countleaf1(BTree bt);// 返回bt的叶子数 
void countleaf2(BTree bt, int& n);// 求bt的叶子数 
int height1(BTree bt);// 返回bt的高度 
void height2(BTree bt, int h); // 求bt的高度
int height = 0;
void exchange(BTree bt);//左右交换 
int levelnodes(BTree bt, int k);//递归求第k层结点数
BTNode* parent(BTree bt, elemType x); // 求x的双亲 
BTNode* lchild(BTree bt, elemType x); // 求x的左孩子 
BTNode* rsibling(BTree bt, elemType x);// 求x的右兄弟 
void preorderfdg(BTree bt);// 先序遍历 
void inorderfdg(BTree bt); // 中序遍历
void postorderfdg(BTree bt);// 后序遍历
void FloorPrint(BTree bt); //层序遍历_队列实现
int main(void)
{// ABD#G###CE##F##
	BTree bt;

	cout << "输入结点数据，#表示空：" << endl;
	create(bt);
	cout << "先序递归：";
	preorder(bt);
	cout << endl;
	cout << "中序递归：";
	inorder(bt);
	cout << endl;
	cout << "后序递归：";
	postorder(bt);
	cout << endl;

	cout << "叶子数为：" << endl;
	cout << countleaf1(bt) << endl;
	int leaves = 0;
	countleaf2(bt, leaves);
	cout << leaves << endl;

	cout << "高度为：" << endl;
	cout << height1(bt) << endl;
	height2(bt, 1);
	cout << height << endl;

	/*//求第k层结点数 
	int k;
	printf("input level: ");
	while (1)
	{
		scanf_s("%d", &k);
		if (k == -1) break;
		printf("%d 层结点数为： %d\n", k, levelnodes(bt, k));
	}

	elemType x;
	printf("测试左孩子\n");
	while (1)
	{
		cin >> x;
		if (x == '#') break;
		BTNode* p = rsibling(bt, x);
		if (p == NULL) cout << x << "不存在或无左孩子" << endl;
		else cout << p->data << endl;
	}*/
	printf("按层遍历\n");
	FloorPrint(bt);
	return 0;
}
void create(BTree& bt)
{
	char x;

	cin >> x;
	if (x == '#')
		bt = NULL;
	else {
		bt = new BTNode;
		bt->data = x;
		create(bt->lChild);
		create(bt->rChild);
	}
}

void preorder(BTree bt)
{
	if (bt) {
		cout << bt->data << " ";
		preorder(bt->lChild);
		preorder(bt->rChild);
	}
}

void inorder(BTree bt)
{
	if (bt)
	{
		inorder(bt->lChild);
		cout << bt->data << " ";
		inorder(bt->rChild);
	}
}

void postorder(BTree bt)
{
	if (bt)
	{
		postorder(bt->lChild);
		postorder(bt->rChild);
		cout << bt->data << " ";
	}
}

int countleaf1(BTree bt)
{
	if (bt == NULL)
		return 0;//树为空的情况
	else if (bt->lChild == NULL && bt->rChild == NULL)//将树遍历完的情况 返回1因为还有一个根结点
		return 1;
	else
		return countleaf1(bt->lChild) + countleaf1(bt->rChild);
	return 0;
}

void countleaf2(BTree bt, int& n)
{
	if (bt) {
		if (bt->lChild == NULL && bt->rChild == NULL)
			n++;
		countleaf2(bt->lChild, n);
		countleaf2(bt->rChild, n);
	}
}

int height1(BTree bt)
{
	if (!bt)
		return 0;
	else {
		int lh = height1(bt->lChild);
		int rh = height1(bt->rChild);
		return (lh >= rh ? lh : rh) + 1;
	}
}

void height2(BTree bt, int h)
{
	if (bt)
	{
		if (h > height) height = h;
		height2(bt->lChild, h + 1);
		height2(bt->rChild, h + 1);
	}
}

void exchange(BTree bt)
{
	if (bt)
	{
		BTNode* tmp;
		tmp = bt->lChild;
		bt->lChild = bt->rChild;
		bt->rChild = tmp;
		exchange(bt->lChild);
		exchange(bt->rChild);
	}
}

int levelnodes(BTree bt, int k)
{
	if (!bt)
		return 0;
	else if (k == 1)
		return 1;
	else return levelnodes(bt->lChild, k - 1) + levelnodes(bt->rChild, k - 1);//求第k层节点数量，等于求以根节点的左孩子为根的k-1层节点数，加上以根节点的右孩子为根的k-1层节点数。
}

BTNode* parent(BTree bt, elemType x)
{
	if (!bt || bt->data == x)//空或为根节点
		return NULL;
	if (bt->lChild && bt->lChild->data == x || bt->rChild && bt->rChild->data == x)
		return bt;
	BTNode* lp = parent(bt->lChild, x);
	if (lp) return lp;
	return parent(bt->rChild, x);
}

BTNode* lchild(BTree bt, elemType x)
{
	if (!bt) return NULL;
	if (bt->data == x) return bt->lChild;
	BTNode* lp = lchild(bt->lChild, x);
	if (lp) return lp;
	return lchild(bt->rChild, x);
}

BTNode* rsibling(BTree bt, elemType x)
{
	if (!bt) return NULL;
	if (bt->lChild && bt->lChild->data == x) return bt->rChild;
	BTNode* tmp = rsibling(bt->lChild, x);
	if (tmp) return tmp;
	return rsibling(bt->rChild, x);
}

void preorderfdg(BTree bt)
{
	stack<BTNode*> s;
	BTNode* p = bt;

	while (p || !s.empty())//p存在或栈不空
	{
		if (p)
		{
			cout << p->data << " ";
			s.push(p);
			p = p->lChild;
		}
		else
		{
			p = s.top();
			s.pop();
			p = p->rChild;
		}
	}
}

void inorderfdg(BTree bt)
{
	stack<BTNode*> s;
	BTNode* p = bt;

	while (p || !s.empty())
	{
		if (p)
		{
			s.push(p);
			p = p->lChild;
		}
		else
		{
			p = s.top();
			cout << p->data << " ";
			s.pop();
			p = p->rChild;
		}
	}
}
/**
  * 思路：首先要搞清楚什么时候才能输出根节点的值，必须等到左节点和右节点都访问完的情况才能访问根节点
  * 因此，访问根节点的情况有两种：
  * 一、当前节点的左右子树都为null时，可以直接访问根节点
  * 二、当前节点的左右子树都访问过时，则可以直接访问根节点
  * 则可以设置一个标志，让他标识上一个访问的结点
  * 遍历栈时，得到栈顶元素，判断他的左右子树为空或者pre标志是否等于当前结点的左右孩子的其中一个时，
  * 当这两种情况满足其中一种，则就可以访问当前根节点。
  *
  * 至于为什么要判断pre标志是否等于当前结点的左右孩子的其中一个，而不是判断它是否等于当前结点的右孩子？
  * 原因是这样的：因为可能存在这样一种情况，当前结点只有左孩子结点，则如果去判断它是否等于当前结点的右孩子结点
  * 得到的一定是false，这样当前结点永远都不会被访问，并且会陷入死循环，左孩子一直循环入栈的情况。当根结点左
  * 子树访问完，如果存在右子树，则会从栈顶得到右子树结点，而此时pre标志等于根节点的左子女，因此第二个条件不成立（
  * 即pre不会等于根节点右子女的任何一个子女结点）
  */
void postorderfdg(BTree bt)
{
	stack <BTNode*> s;
	BTNode* p = bt;
	BTNode* pre = NULL;

	while (p || !s.empty())
	{
		if (p)
		{
			s.push(p);
			p = p->lChild;
		}
		else
		{
			p = s.top();
			if (p->rChild == NULL || p->rChild == pre)
			{
				cout << p->data << " ";
				s.pop();
				pre = p;
				p = NULL;
			}
			else
				p = p->rChild;
		}
	}
}

void FloorPrint(BTree bt)
{
	queue <BTree> q;
	if (bt != NULL)
	{
		q.push(bt);   //根节点进队列
	}

	while (q.empty() == false)  //队列不为空判断
	{
		cout << q.front()->data << "  ";

		if (q.front()->lChild != NULL)   //如果有左孩子，leftChild入队列
		{
			q.push(q.front()->lChild);
		}

		if (q.front()->rChild != NULL)   //如果有右孩子，rightChild入队列
		{
			q.push(q.front()->rChild);
		}
		q.pop();  //已经遍历过的节点出队列
	}
}
