/*
����
�ܾúܾ�֮ǰ��ɭ����ס��һȺ���ӡ���һ�죬������ϣ��ȥ��ӣ�����������ǵ�����Ұ��԰�ſ�ȴ�����˴���ͼ�������������������������������ҵ���԰������·��

����
�����Ϊ�������֡�
��һ��������P+1�У�P<30������һ��Ϊһ������P��֮���P�б�ʾ��Ұ��԰�ĵص㡣
�ڶ���������Q+1�У�Q<50������һ��Ϊһ������Q��֮���Q��ÿ�зֱ�Ϊ�����ַ�����һ����������ʾ��������ֱ�ߵĵ�·������ʾ����֮��ľ��루��λΪ�ף���
������������R+1�У�R<20������һ��Ϊһ������R��֮���R��ÿ��Ϊ�����ַ�������ʾ��Ҫ���·�ߡ�
���
�����R�У��ֱ��ʾÿ��·����̵��߷�������������֮�䣬��->(����)->�����
��������
6
Ginza               0
Sensouji			1
Shinjukugyoen		2
Uenokouen			3
Yoyogikouen			4
Meijishinguu		5
6
Ginza Sensouji 80
Shinjukugyoen Sensouji 40
Ginza Uenokouen 35
Uenokouen Shinjukugyoen 85
Sensouji Meijishinguu 60
Meijishinguu Yoyogikouen 35
2
Uenokouen Yoyogikouen
Meijishinguu Meijishinguu
�������
Uenokouen->(35)->Ginza->(80)->Sensouji->(60)->Meijishinguu->(35)->Yoyogikouen
3 0 1 5 4
Meijishinguu

˼·��
�������Ϊ�����������·�� �����·��
ʹ�ø��������㷨��
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
typedef string VType;
const int VN = 30;
const int INF = 32767;
typedef struct {
	VType  vex[VN];
	int adj[VN][VN];
	int n, e;//���� ��
}AdjMatrix;
void create(AdjMatrix& g);
int locate(AdjMatrix g, VType v);
void output(AdjMatrix g);
typedef struct {
	int start, end;
	int weight;
}EType;
void floyd(AdjMatrix g);
void floydpath(AdjMatrix g, int a[][VN], int p[][VN]);
int main(void) {
	AdjMatrix g;

	create(g);
	//output(g);

	//prim(g); // gentree.txt
	//kruskal(g);
	//dijkstra(g);
	floyd(g);

	return 0;
}
void create(AdjMatrix& g) {
	cin >> g.n;
	for (int i = 0; i < g.n; i++)	cin >> g.vex[i];
	cin >> g.e;
	for (int i = 0; i < g.n; i++)
		for (int j = 0; j < g.n; j++)
			if (i == j) 
				g.adj[i][j] = 0;
			else 
				g.adj[i][j] = INF;
	//�Ƚ������Խ�������ľ����ʼ��Ϊ������Խ���Ϊ0 
	VType u, v;
	int w;
	for (int i = 0; i < g.e; i++) {
		cin >> u >> v;
		cin >> w;
		int ui, vi;
		ui = locate(g, u), vi = locate(g, v);
		g.adj[ui][vi] = w;
		g.adj[vi][ui] = w;
	}
}
int locate(AdjMatrix g, VType v)//���ص�Ϊ�õ���±�
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
void floyd(AdjMatrix g)
{
	int a[VN][VN] = { 0 }, path[VN][VN];

	for (int i = 0; i < g.n; i++)
		for (int j = 0; j < g.n; j++) {
			if (i != j && g.adj[i][j] < INF) {
				a[i][j] = g.adj[i][j];
				path[i][j] = i;
			}
			else if (i != j) {
				a[i][j] = INF;
				path[i][j] = -1;
			}
			else path[i][j] = -1;
		}
	for (int k = 0; k < g.n; k++)   // ���ο������ж���
		for (int i = 0; i < g.n; i++)
			for (int j = 0; j < g.n; j++) {
				if (a[i][j] > a[i][k] + a[k][j]) {
					a[i][j] = a[i][k] + a[k][j];  // �޸����·������
					path[i][j] = path[k][j];       // �޸����·��
				}
			}
	floydpath(g, a, path);
}
void floydpath(AdjMatrix g, int a[][VN], int path[][VN])
{
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		VType u, v;
		cin >> u >> v;
		int ui, vi;//ʼ�� �յ�
		ui = locate(g, u), vi = locate(g, v);
		int* stack = new int[g.n], top = -1;
		if (ui != vi && a[ui][vi] < INF) {
			stack[++top] = vi;
			int k = path[ui][vi];
			while (k != -1 && k != ui) {
				stack[++top] = k;
				k = path[ui][k];
			}
			stack[++top] = ui;
		}
		bool start = true;
		while (top != -1) {
			if (!start) cout << "->";
			int p = stack[top--];
			int q= stack[top];
			cout << g.vex[p];
			if (top!=-1&&a[p][q] ) {
			cout << "->(" << a[p][q] << ")";
			}
			start = false;
		}
		cout << endl;
	}

	/*for (int i = 0; i < g.n; i++)
		for (int j = 0; j < g.n; j++) {
			if (i != j && a[i][j] < INF) {
				stack[++top] = j;
				int k = path[i][j];
				while (k != -1 && k != i) {
					stack[++top] = k;
					k = path[i][k];
				}
				stack[++top] = i;
				cout << g.vex[i] << "-->" << g.vex[j] << ":" << a[i][j] << "  ";
				bool start = true;
				while (top != -1) {
					if (!start) cout << "->";
					cout << g.vex[stack[top--]];
					start = false;
				}
				cout << endl;
			}
		}*/

}

