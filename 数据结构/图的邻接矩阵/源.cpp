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
void create(AdjMatrix& g); // 创建邻接矩阵表示的图g 
int locate(AdjMatrix g, VType v);// 返回图中g中顶点v的序号 
void output(AdjMatrix g);//输出g的邻接矩阵 


void create(AdjMatrix& g) {

	char fname[20];
	cout << "输入数据文件名：（输入create.txt）";
	cin >> fname;
	ifstream in(fname);

	int gt, dg;
	//cout << "输入图的类型，0为非网，1为网：";
	in >> gt;
	//cout << "输入图是否为有向图，1为有向, 0为无向："; // 1为有向 
	in >> dg;
	//cout << "输入图中顶点数:";
	in >> g.n;
	//cout << "输入图的顶点:";
	for (int i = 0; i < g.n; i++)	in >> g.vex[i];
	//cout << "输入图中边数:";
	in >> g.e;
	//cout << "输入图中的边:"<< endl;
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
			if (g.adj[i][j] == INF) printf("∞  ");
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
