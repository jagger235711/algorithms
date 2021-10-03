#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef char HElemType;
const int N = 20; // Ҷ��������� 
const int M = 2 * N - 1;//����������������� 
const int INF = 32767;  // ����Ҷ��Ȩֵ�͵����ֵ 
typedef struct {
	HElemType data;              // ����������� 
	int parent, lchild, rchild;  // ���˫�ס����ӡ��Һ��� 
	int weight;// Ȩֵ 
}HuffNode, HuffTree[M]; // HuffTreeΪHuffNode[M]����

void init(HuffTree& ht);
void output(HuffTree ht, int n);// �����������ht��ǰn��������Ϣ 
int n, w[M];      // n��Ҷ�ӣ�w��Ž��Ȩֵ 
HElemType leaf[N];//leaf���Ҷ�ӽ�������
void construct(HuffTree& ht);// ������������ht 
void select(HuffTree ht, int k, int& k1, int& k2);// ��ht��ǰk�������ѡȡȨֵ��Сk1�ʹ�Сk2 
char huffcode[N][N];          // ��Ҷ�ӵı��봮 
void encode(HuffTree ht);    // �Թ�������ht�ϵ�Ҷ�ӽ��б��� 
void outputcode(HuffTree ht);// ���ht�ϸ�Ҷ�ӵı��� 
void decode(HuffTree ht, char* s, char* decs);// �ù�������ht�Դ�s�������룬��ŵ�decs�� 
/*
8
abcdefgh
7 19 2 6 32 3 21 10
0101001010100110101011
*/
int main(void) {
	HuffTree ht;

	cout << "input n(Ҷ����)��";
	cin >> n; // ����Ҷ���� 
	cout << "����n��Ҷ�ӵ�����: ";
	for (int i = 0; i < n; i++) cin >> leaf[i];// ����n��Ҷ�ӵ����� 
	cout << "����n��Ҷ�ӵ�Ȩֵ: ";
	for (int i = 0; i < n; i++) cin >> w[i]; // ����n��Ҷ�ӵ�Ȩֵ 

	init(ht);// ��ʼ����������ht 
	output(ht, n); // �����������ht��ǰn��������Ϣ 

	construct(ht);// ������������ht 
	output(ht, 2 * n - 1);// �����������ht�����н�����Ϣ

	encode(ht); // �Թ�������ht���б��� 
	outputcode(ht);	// �����������ht������Ҷ�ӵı��� 

	char str[100], decs[100];
	cout << "input ...01...: ";
	cin >> str; // ����01�� 
	decode(ht, str, decs);// ʹ�ù�������ht�Դ�str�������� 
	cout << "decs: " << decs << endl;//������봮 

	return 0;
}

void init(HuffTree& ht) {
	int m = 2 * n - 1;

	for (int i = 0; i < m; i++) {//m�����˫�ס����ӡ��Һ����ÿ�	
		ht[i].parent = ht[i].lchild = ht[i].rchild = -1; //
		ht[i].data = '-';
	}
	for (int i = 0; i < n; i++) {//Ҷ��Ȩֵ�����ݸ�ֵ
		ht[i].data = leaf[i];
		ht[i].weight = w[i];
	}
	// n-1��ѡ�㣬���ɵ�n~m-1�����	 
}

void output(HuffTree ht, int n) {
	printf("i data weight parent lchild rchild\n");
	for (int i = 0; i < n; i++)
		printf("%2d %4c %6d %6d %6d %6d\n", i, ht[i].data, ht[i].weight, ht[i].parent, ht[i].lchild, ht[i].rchild);
}
void construct(HuffTree& ht) {
	for (int i = n; i < 2 * n - 1; i++) {// n - 1��ѡ�㽨����n~2n-2 
		int k1, k2;
		select(ht, i, k1, k2);
		ht[i].weight = ht[k1].weight + ht[k2].weight;
		ht[i].lchild = k1, ht[i].rchild = k2;
		ht[k1].parent = ht[k2].parent = i;
	}
}

void select(HuffTree ht, int k, int& k1, int& k2) {
	int minw = INF;
	for (int i = 0; i < k; i++) {// ѡ��Ȩֵ��С�Ķ�����k1	
		if (ht[i].parent == -1 && ht[i].weight < minw) {
			minw = ht[i].weight;
			k1 = i;
		}
	}
	minw = INF;
	for (int i = 0; i < k; i++) {// ѡ��Ȩֵ��С�Ķ�����k2	
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
	int m = 2 * n - 1 - 1, k = 0; // k���huffman�������±�,k�����������ַ��±� 
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


