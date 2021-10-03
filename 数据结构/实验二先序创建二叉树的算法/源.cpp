#include<iostream>
#include<queue>
#include<stack>
#include<math.h>
using namespace std;

typedef char elemType;
typedef struct node {
	elemType data;
	node* lChild, * rChild;
}BTNode, * BTree;
void preCreate(BTNode*& T)  //输入前序序列创建二叉树（递归算法 ）  
{//为什么用到引用参数？
	char ch;
	cin >> ch;
	if (ch == '.') T = NULL;  //递归出口，"."表示空树 
	else    //前序创建二叉树 
	{
		T = new BTNode;
		T->data = ch;
		preCreate(T->lChild);
		preCreate(T->rChild);
	}
}
void postCreat(BTree bt,char ch) {
	if (ch == '.') bt = NULL;  //递归出口，"."表示空树 
	else    //前序创建二叉树 
	{
		bt = new BTNode;
		preCreate(bt->lChild);
		preCreate(bt->rChild);
		bt->data = ch;
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
void InOrder2(BTNode* t)
{
	if (t) {
		if (t->lChild && t->lChild->lChild && t->lChild->rChild) cout << "(";
		InOrder2(t->lChild);
		if (t->lChild && t->lChild->lChild && t->lChild->rChild) cout << ")";
		cout << t->data;
		if (t->rChild && t->rChild->lChild && t->rChild->rChild) cout << "(";
		InOrder2(t->rChild);
		if (t->rChild && t->rChild->lChild && t->rChild->rChild) cout << ")";
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
/*
思路

采用层次遍历的方法，类似bfs的解法

每遍历一层，depth++;
每一层，需使用一个变量len记录该层的结点个数，也就是队列的当前长度，然后依次在队列中访
问该层的len个结点（将队列中len个元素出队列），并将下一层如队列。
*/
int height2(BTree bt)
{
	queue<BTree> q;
	if (!bt) return 0;
	q.push(bt);
	int level = 0;
	while (!q.empty()) {
		int len = q.size();
		level++;
		while (len--) {
			BTree tmp = q.front();
			q.pop();
			if (tmp->lChild) q.push(tmp->lChild);
			if (tmp->rChild) q.push(tmp->rChild);
		}
	}
	return level;
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
void countNode(BTree root, int& sum) {
	if (root) {
		sum += 1;
		countNode(root->lChild,sum);
		countNode(root->rChild,sum);
	}
}
bool isFull(BTree bt) {
	int nodeNum = pow(2, height1(bt)) - 1;
	int sum = 0;
	countNode(bt, sum);
	if (nodeNum == sum)return true;
	else return false;
}
/*
bool isop(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}
int priority(char c)
{
	int res;
	switch (c)
	{
	case '#': res = 0; break;
	case '(': res = 1; break;
	case '+':
	case '-': res = 2; break;
	case '*':
	case '/': res = 3; break;
	case '^': res = 4; break;
	}
	return res;
}
void topoststr(char* str, char* poststr)//中缀式变为后缀式
{
	stack<char>s;
	s.push('#');
	int k = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{// 操作数对应的数字依次送入后缀式poststr，最后加一个空格
			while (str[i] && str[i] >= '0' && str[i] <= '9')
			{
				poststr[k++] = str[i];
				i++;
			}
			poststr[k++] = ' ';
			i--;
		}
		else if (str[i] == '(')	s.push(str[i]); // (入操作符栈
		else if (str[i] == ')')
		{// 需要把()之间的栈中字符送入后缀式poststr
			while (s.top() != '(')
			{
				poststr[k++] = s.top();
				s.pop();
			}
			s.pop(); // ( 出栈
		}
		else if (isop(str[i]))
		{// 操作符时:将高于当前所读操作符str[i]的栈顶字符送入后缀式poststr
			while (!s.empty() && priority(s.top()) >= priority(str[i]))
			{
				poststr[k++] = s.top();
				s.pop();
			}
			s.push(str[i]);// 当前所读操作符str[i]入栈
		}
	}
	while (!s.empty() && s.top() != '#')
	{// 栈内其他操作符送入后缀式poststr
		poststr[k++] = s.top();
		s.pop();
	}
	poststr[k] = '\0';
}
*/
void inorder(BTree bt)
{
	if (bt)
	{
		inorder(bt->lChild);
		cout << bt->data << " ";
		inorder(bt->rChild);
	}
}
/*3.中缀表达式建树过程：代码中InTree（）为递归函数、有三个参数、s - 字符串的首地址，i和j分别为子串起始位置和终止位置。如果i == j，说明子串只有一个字符，即为叶子节点，则创建只有一个根节点的二叉树并返回之。如果i != j，根据运算规则（先乘除后加减），在串中找‘+’和‘-’，以最后的‘+’或‘-’为根（体现从左到右的原则）；如果没有‘+’或‘-’时，则进一步找‘*’或’/‘（体现先乘除后加减），同样以最后的运算符为根，将串分为两部分，即左子树和右子树。创建一个根节点，将找到的运算符放入，递归调用自身进入左子树的建树过程，之后递归调用自身进入右子树的建树过程。
*/
//中缀表达式建树过程  - 递归过程 

BTree InTree(char s[], int i, int j)  //s - 表达式字符串、i - 字符串起始位置、j - 字符串最后一个字符的位置 
{
	//动态生成的树节点 
	BTree p;
	int k, flag = 0, pos;//pos表示位置

	//如果i == j，则说明字符串只有一个字符，即为叶子节点、则创建只有一个根节点的二叉树并返回
	if (i == j)
	{
		p = (BTree)malloc(sizeof(BTNode));
		p->data = s[i];
		p->lChild = NULL;
		p->rChild = NULL;
		return p;
	}
	//以下是 i != j的情况
	//从左往右找最后一个+或-，先找+或-为了体现先乘除后加减的原则 
	for (k = i; k <= j; k++)
	{
		if (s[k] == '+' || s[k] == '-')
		{
			flag = 1;
			pos = k;
		}
	}
	//若没有+或-，则寻找字符串中最后一个*或/ 
	if (flag == 0)
	{
		for (k = i; k <= j; k++)
		{
			if (s[k] == '*' || s[k] == '/')
			{
				flag = 1;
				pos = k;
			}
		}
	}
	//若flag不等于0，则以pos为界将字符串分为左右两部分，分别对应表达式二叉树的左、右子树 
	//同样以最后的运算符为根，将串分为两部分
	//创建一个根节点、将找到的运算符放入 
	if (flag != 0)
	{
		p = new BTNode();
		p->data = s[pos];
		p->lChild = InTree(s, i, pos - 1);      //递归调用自身进入其左子树建树过程 
		p->rChild = InTree(s, pos + 1, j);     //递归调用自身进入其右子树建树过程 
		return p;
	}
	else
		return NULL;
}

int main() {
	BTNode btn;
	BTree bt = &btn;
	// ABD.G...CE..F..
	//++a..*b..c..*+*d..e..f..g..先序序列
	/*preCreate(bt);//先序创建
	postorder(bt);//后续遍历
	cout << endl;
	InOrder2(bt);
	cout << endl;
	cout<<height2(bt)<<endl;
	cout << countleaf1(bt) << endl;
	if (isFull(bt)) {
		cout <<"yes"<< endl;
	}
	else 	cout <<"no"<< endl;*/
	// 2-3+1/2-9-2*4	20 30 10 2 /+9 -2 4 ^--
	char str[100];

	cin >> str;              // 输入中缀式 
	InTree(str,0, strlen(str)-1);
	return 0;
	}