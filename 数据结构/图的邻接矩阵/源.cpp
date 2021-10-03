#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
using namespace std;
typedef string VType;
const int VN = 10;
const int INF = 32767;
typedef struct {
	VType  vex[VN];
	int adj[VN][VN];
	int n, e;
}AdjMatrix;
void create(AdjMatrix& g); // �����ڽӾ����ʾ��ͼg 
int locate(AdjMatrix g, VType v);// ����ͼ��g�ж���v����� 
void output(AdjMatrix g);//���g���ڽӾ��� 


void create(AdjMatrix& g) {

	char fname[20];
	cout << "���������ļ�����������create.txt��";
	cin >> fname;
	ifstream in(fname);

	int gt, dg;
	//cout << "����ͼ�����ͣ�0Ϊ������1Ϊ����";
	in >> gt;
	//cout << "����ͼ�Ƿ�Ϊ����ͼ��1Ϊ����, 0Ϊ����"; // 1Ϊ���� 
	in >> dg;
	//cout << "����ͼ�ж�����:";
	in >> g.n;
	//cout << "����ͼ�Ķ���:";
	for (int i = 0; i < g.n; i++)	in >> g.vex[i];
	//cout << "����ͼ�б���:";
	in >> g.e;
	//cout << "����ͼ�еı�:"<< endl;
	for (int i = 0; i < g.n; i++)
		for (int j = 0; j < g.n; j++)
			if (i == j) g.adj[i][j] = 0;
			else {
				if (gt) g.adj[i][j] = INF;
				else g.adj[i][j] = 0;
			}
	VType u, v;
	int w;
	for (int i = 0; i < g.e; i++) {
		in >> u >> v;
		if (gt) in >> w;
		int ui, vi;
		ui = locate(g, u), vi = locate(g, v);
		if (gt) {
			g.adj[ui][vi] = w;
			if (!dg) g.adj[vi][ui] = w;
		}
		else {
			g.adj[ui][vi] = 1;
			if (!dg) g.adj[vi][ui] = 1;
		}
	}

}
int locate(AdjMatrix g, VType v)
{
	for (int i = 0; i < g.n; i++)
		if (g.vex[i] == v) return i;
	return -1;
}
void output(AdjMatrix g) {
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++)
			if (g.adj[i][j] == INF) printf("��  ");
			else printf("%-4d", g.adj[i][j]);
		cout << endl;
	}
}
int main(void) {
	AdjMatrix g;

	create(g);
	output(g);

	return 0;
}
