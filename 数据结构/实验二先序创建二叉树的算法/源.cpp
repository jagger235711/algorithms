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
void preCreate(BTNode*& T)  //����ǰ�����д������������ݹ��㷨 ��  
{//Ϊʲô�õ����ò�����
	char ch;
	cin >> ch;
	if (ch == '.') T = NULL;  //�ݹ���ڣ�"."��ʾ���� 
	else    //ǰ�򴴽������� 
	{
		T = new BTNode;
		T->data = ch;
		preCreate(T->lChild);
		preCreate(T->rChild);
	}
}
void postCreat(BTree bt,char ch) {
	if (ch == '.') bt = NULL;  //�ݹ���ڣ�"."��ʾ���� 
	else    //ǰ�򴴽������� 
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
˼·

���ò�α����ķ���������bfs�Ľⷨ

ÿ����һ�㣬depth++;
ÿһ�㣬��ʹ��һ������len��¼�ò�Ľ�������Ҳ���Ƕ��еĵ�ǰ���ȣ�Ȼ�������ڶ����з�
�ʸò��len����㣨��������len��Ԫ�س����У���������һ������С�
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
		return 0;//��Ϊ�յ����
	else if (bt->lChild == NULL && bt->rChild == NULL)//�������������� ����1��Ϊ����һ�������
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
void topoststr(char* str, char* poststr)//��׺ʽ��Ϊ��׺ʽ
{
	stack<char>s;
	s.push('#');
	int k = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{// ��������Ӧ���������������׺ʽpoststr������һ���ո�
			while (str[i] && str[i] >= '0' && str[i] <= '9')
			{
				poststr[k++] = str[i];
				i++;
			}
			poststr[k++] = ' ';
			i--;
		}
		else if (str[i] == '(')	s.push(str[i]); // (�������ջ
		else if (str[i] == ')')
		{// ��Ҫ��()֮���ջ���ַ������׺ʽpoststr
			while (s.top() != '(')
			{
				poststr[k++] = s.top();
				s.pop();
			}
			s.pop(); // ( ��ջ
		}
		else if (isop(str[i]))
		{// ������ʱ:�����ڵ�ǰ����������str[i]��ջ���ַ������׺ʽpoststr
			while (!s.empty() && priority(s.top()) >= priority(str[i]))
			{
				poststr[k++] = s.top();
				s.pop();
			}
			s.push(str[i]);// ��ǰ����������str[i]��ջ
		}
	}
	while (!s.empty() && s.top() != '#')
	{// ջ�����������������׺ʽpoststr
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
/*3.��׺���ʽ�������̣�������InTree����Ϊ�ݹ麯����������������s - �ַ������׵�ַ��i��j�ֱ�Ϊ�Ӵ���ʼλ�ú���ֹλ�á����i == j��˵���Ӵ�ֻ��һ���ַ�����ΪҶ�ӽڵ㣬�򴴽�ֻ��һ�����ڵ�Ķ�����������֮�����i != j��������������ȳ˳���Ӽ������ڴ����ҡ�+���͡�-���������ġ�+����-��Ϊ�������ִ����ҵ�ԭ�򣩣����û�С�+����-��ʱ�����һ���ҡ�*����/���������ȳ˳���Ӽ�����ͬ�������������Ϊ����������Ϊ�����֣�����������������������һ�����ڵ㣬���ҵ�����������룬�ݹ������������������Ľ������̣�֮��ݹ������������������Ľ������̡�
*/
//��׺���ʽ��������  - �ݹ���� 

BTree InTree(char s[], int i, int j)  //s - ���ʽ�ַ�����i - �ַ�����ʼλ�á�j - �ַ������һ���ַ���λ�� 
{
	//��̬���ɵ����ڵ� 
	BTree p;
	int k, flag = 0, pos;//pos��ʾλ��

	//���i == j����˵���ַ���ֻ��һ���ַ�����ΪҶ�ӽڵ㡢�򴴽�ֻ��һ�����ڵ�Ķ�����������
	if (i == j)
	{
		p = (BTree)malloc(sizeof(BTNode));
		p->data = s[i];
		p->lChild = NULL;
		p->rChild = NULL;
		return p;
	}
	//������ i != j�����
	//�������������һ��+��-������+��-Ϊ�������ȳ˳���Ӽ���ԭ�� 
	for (k = i; k <= j; k++)
	{
		if (s[k] == '+' || s[k] == '-')
		{
			flag = 1;
			pos = k;
		}
	}
	//��û��+��-����Ѱ���ַ��������һ��*��/ 
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
	//��flag������0������posΪ�罫�ַ�����Ϊ���������֣��ֱ��Ӧ���ʽ���������������� 
	//ͬ�������������Ϊ����������Ϊ������
	//����һ�����ڵ㡢���ҵ������������ 
	if (flag != 0)
	{
		p = new BTNode();
		p->data = s[pos];
		p->lChild = InTree(s, i, pos - 1);      //�ݹ��������������������������� 
		p->rChild = InTree(s, pos + 1, j);     //�ݹ��������������������������� 
		return p;
	}
	else
		return NULL;
}

int main() {
	BTNode btn;
	BTree bt = &btn;
	// ABD.G...CE..F..
	//++a..*b..c..*+*d..e..f..g..��������
	/*preCreate(bt);//���򴴽�
	postorder(bt);//��������
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

	cin >> str;              // ������׺ʽ 
	InTree(str,0, strlen(str)-1);
	return 0;
	}