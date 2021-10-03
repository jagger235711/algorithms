#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef char HElemType;
const int N = 20; // 叶子最多数量 
const int M = 2 * N - 1;//哈夫曼树上最多结点数 
const int INF = 32767;  // 所给叶子权值和的最大值 
typedef struct {
	HElemType data;              // 待编码的数据 
	int parent, lchild, rchild;  // 结点双亲、左孩子、右孩子 
	int weight;// 权值 
}HuffNode, HuffTree[M]; // HuffTree为HuffNode[M]类型

void init(HuffTree& ht);
void output(HuffTree ht, int n);// 输出哈夫曼树ht的前n个结点的信息 
int n, w[M];      // n个叶子，w存放结点权值 
HElemType leaf[N];//leaf存放叶子结点的数据
void construct(HuffTree& ht);// 构建哈夫曼树ht 
void select(HuffTree ht, int k, int& k1, int& k2);// 从ht的前k个结点中选取权值最小k1和次小k2 
char huffcode[N][N];          // 各叶子的编码串 
void encode(HuffTree ht);    // 对哈夫曼树ht上的叶子进行编码 
void outputcode(HuffTree ht);// 输出ht上各叶子的编码 
void decode(HuffTree ht, char* s, char* decs);// 用哈夫曼树ht对串s进行译码，存放到decs中 
/*
8
abcdefgh
7 19 2 6 32 3 21 10
0101001010100110101011
*/
int main(void) {
	HuffTree ht;

	cout << "input n(叶子数)：";
	cin >> n; // 输入叶子数 
	cout << "输入n个叶子的数据: ";
	for (int i = 0; i < n; i++) cin >> leaf[i];// 输入n个叶子的数据 
	cout << "输入n个叶子的权值: ";
	for (int i = 0; i < n; i++) cin >> w[i]; // 输入n个叶子的权值 

	init(ht);// 初始化哈夫曼树ht 
	output(ht, n); // 输出哈夫曼树ht的前n个结点的信息 

	construct(ht);// 构建哈夫曼树ht 
	output(ht, 2 * n - 1);// 输出哈夫曼树ht的所有结点的信息

	encode(ht); // 对哈夫曼树ht进行编码 
	outputcode(ht);	// 输出哈夫曼树ht的所有叶子的编码 

	char str[100], decs[100];
	cout << "input ...01...: ";
	cin >> str; // 输入01串 
	decode(ht, str, decs);// 使用哈夫曼树ht对串str进行译码 
	cout << "decs: " << decs << endl;//输出译码串 

	return 0;
}

void init(HuffTree& ht) {
	int m = 2 * n - 1;

	for (int i = 0; i < m; i++) {//m个结点双亲、左孩子、右孩子置空	
		ht[i].parent = ht[i].lchild = ht[i].rchild = -1; //
		ht[i].data = '-';
	}
	for (int i = 0; i < n; i++) {//叶子权值及数据赋值
		ht[i].data = leaf[i];
		ht[i].weight = w[i];
	}
	// n-1次选点，生成第n~m-1个结点	 
}

void output(HuffTree ht, int n) {
	printf("i data weight parent lchild rchild\n");
	for (int i = 0; i < n; i++)
		printf("%2d %4c %6d %6d %6d %6d\n", i, ht[i].data, ht[i].weight, ht[i].parent, ht[i].lchild, ht[i].rchild);
}
void construct(HuffTree& ht) {
	for (int i = n; i < 2 * n - 1; i++) {// n - 1次选点建树，n~2n-2 
		int k1, k2;
		select(ht, i, k1, k2);
		ht[i].weight = ht[k1].weight + ht[k2].weight;
		ht[i].lchild = k1, ht[i].rchild = k2;
		ht[k1].parent = ht[k2].parent = i;
	}
}

void select(HuffTree ht, int k, int& k1, int& k2) {
	int minw = INF;
	for (int i = 0; i < k; i++) {// 选择权值最小的二叉树k1	
		if (ht[i].parent == -1 && ht[i].weight < minw) {
			minw = ht[i].weight;
			k1 = i;
		}
	}
	minw = INF;
	for (int i = 0; i < k; i++) {// 选择权值最小的二叉树k2	
		if (i != k1 && ht[i].parent == -1 && ht[i].weight < minw) {
			minw = ht[i].weight;
			k2 = i;
		}
	}
}
void encode(HuffTree ht) {
	char tmpstr[N];
	for (int i = 0; i < n; i++) {
		memset(tmpstr, 0, sizeof(tmpstr));
		int start = n - 2;
		int c = i, f = ht[c].parent;
		while (f != -1) {
			if (ht[f].lchild == c) tmpstr[start--] = '0';
			else tmpstr[start--] = '1';
			c = f;
			f = ht[c].parent;
		}
		strcpy_s(huffcode[i], tmpstr + start + 1);
	}
}

void outputcode(HuffTree ht) {
	for (int i = 0; i < n; i++)
		cout << ht[i].data << ": " << huffcode[i] << endl;
}
void decode(HuffTree ht, char* s, char* decs) {
	int m = 2 * n - 1 - 1, k = 0; // k存放huffman树树根下标,k存放译码各个字符下标 
	int f = m, c;
	for (int i = 0; s[i]; i++) {
		if (s[i] == '0') c = ht[f].lchild;
		else  c = ht[f].rchild;
		f = c;
		if (ht[f].lchild == -1 && ht[f].rchild == -1) {
			decs[k++] = ht[f].data;
			f = m;
		}
	}
	decs[k] = '\0';
}


