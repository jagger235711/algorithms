/*
����



�ȴ�����Lagrishan��������������һ�����⣺����ǰ��һ����Ԯ�ʽ�����ά������֮��ĵ�·�������深ï�Ĵ����������ʴ�Ŵ���ĵ�·�����µ�·ά�޿����޴󣬳��ϻ᲻�ò��������ֵ�·��ά������ͼ���ͼ��ʾ��������ʹ�õ�·�ļ�ͼ�Լ�ÿ��·ÿ���µ�ά�޷��ã���λΪaacms�������ڳ��ϻ���Ҫ���һ�ַ���������Ҫ��֤����֮�䶼���Ի��ൽ���Ҫ��ÿ���µĵ�·ά�޷��ÿ�������С�����ӱ��Ϊ��A��I����ͼ�Ҳ���ʾ�ķ�����Сά�޿���Ϊ216 aacmsÿ�¡�

����
�������1~100�����ݼ������һ��Ϊ0.ÿ�����ݼ���һ��Ϊ������Ŀn, 1 < n < 27,��������ĸ���ǰn����ĸ��ǡ���������n-1�У�ÿ�еĵ�һ�����ݱ��ǰ���ĸ˳�����еĴ��ӱ�ţ����������һ����ׯ����ÿ����ׯ���������k����ô�ׯͨ���������֮��Ĵ�ׯ�ĵ�·��Ŀ����A 2 B 12 I 25������A��ׯ��2�������A֮��Ĵ�ׯ������������k����0��k��������θ�����k����ׯ�ı���Լ����Ե���ʼ��ׯ�ĵ�·ά�޷��ã���A 2 B 12 I 25������A��B֮���·ά�޷���Ϊ12�� A��I֮���·ά�޷���Ϊ25��ά�޷���Ϊ������100����������.·������Ŀ������75����ÿ����ׯ��������ׯ�����г���15��·�������������֮ǰ��֮��ģ���
���
ÿ�����ݼ���һ���������Խ������ÿ����ά�޵�·��С���á�
��ʾ�������㷨�����ҳ���������������ᳬ��ʱ�����ơ�
��������
9
A 2 B 12 I 25
B 3 C 10 H 40 I 8
C 2 D 18 G 55
D 1 E 44
E 2 F 60 G 38
F 0
G 1 H 35
H 1 I 35
3
A 2 B 10 C 40
B 1 C 20
0
�������
216
30
�������
����С������ 
�����ǳ���ͼ��ѡ������ķ�㷨
������������ʽ�ʺ����ڽӱ�����
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
typedef string VType;
const int VN = 10;
const int INF = 32767;
typedef struct {
	VType  vex[VN];
	int adj[VN][VN];
	int n, e;//���� ��
}AdjMatrix;
void create(AdjMatrix& g);
int locate(AdjMatrix g, VType v);
void output(AdjMatrix g);
void prim(AdjMatrix g);
int select(AdjMatrix g, bool* 
	state, int* nearcost);

typedef struct {
	int start, end;
	int weight;
}EType;

int main(void) {
	AdjMatrix g;
		create(g);
		prim(g);
	//create(g);
	//output(g);

	//prim(g); // gentree.txt
	//kruskal(g);
	//dijkstra(g);
	//floyd(g);

	return 0;
}
void create(AdjMatrix& g) {
	cin >> g.n;
	for (int i = 0; i < g.n; i++)	g.vex[i]= 'A' +i;
	for (int i = 0; i < g.n; i++)
		for (int j = 0; j < g.n; j++)
			if (i == j)
				g.adj[i][j] = 0;
			else
				g.adj[i][j] = INF;
	//�Ƚ������Խ�������ľ����ʼ��Ϊ������Խ���Ϊ0 
	for (int i = 0; i < g.n; i++) {
		VType inVex1;
		int n;
		cin >> inVex1>>n;
		int vex1 = locate(g, inVex1);
		for (int j = 0; j < n; j++) {
			VType inVex2;
			int w;
			cin >> inVex2>>w;
			int vex2 = locate(g, inVex2);
			g.adj[vex1][vex2] = w;
			g.adj[vex2][vex1] = w;
			//Ϊ����ͼ ������ Ҳ�����������Ǿ���棬Ȼ��ӳ�����
		}
	}

	//cin >> g.e;
	//VType u, v;
	//int w;
	//for (int i = 0; i < g.e; i++) {
	//	cin >> u >> v;
	//	cin >> w;
	//	int ui, vi;
	//	ui = locate(g, u), vi = locate(g, v);
	//	g.adj[ui][vi] = w;
	//	g.adj[vi][ui] = w;
	//}
}
int locate(AdjMatrix g, VType v)//���ص�Ϊ�õ���±�
{
	for (int i = 0; i < g.n; i++)
		if (g.vex[i] == v) return i;
	return -1;
}
int select(AdjMatrix g, bool* state, int* lowcost)
{
	int mincost = INF, k;
	for (int i = 0; i < g.n; i++) {
		if (!state[i] && lowcost[i] < mincost) {
			mincost = lowcost[i]; k = i;
		}
	}
	return k;
}
void prim(AdjMatrix g) {

	int* ansvex = new int[g.n];
	EType* ansedge = new EType[g.n];
	int* nearvex = new int[g.n]; // nearvex[i]���i��Ӧ������������������ĵ� 
	int* lowcost = new int[g.n];// lowcost[i]���i��Ӧ������������������ľ��� 
	bool* state = new bool[g.n];// state[i]���i��Ӧ����Ƿ������������� 

	for (int i = 0; i < g.n; i++) {// ���������ʼ�� 
		lowcost[i] = INF;
		state[i] = false;
	}
	VType u;
	cout << "�������ѡ�Ķ���:";
	u = "A";

	int ui = locate(g, u);
	ansvex[0] = ui;
	state[ui] = true;

	for (int i = 0; i < g.n; i++)
	{// �޸�u���ڽӵ��nearvexΪu�㣬��lowcost
		if (g.adj[ui][i] != 0 && g.adj[ui][i] != INF) {
			lowcost[i] = g.adj[ui][i];
			nearvex[i] = ui;
		}
	}
	EType e;
	int total = 0;
	for (int i = 1; i < g.n; i++)
	{// ѡg.n - 1����ӵ��������� 
		int k = select(g, state, lowcost);
		ansvex[i] = k;
		e.start = nearvex[k], e.end = k, e.weight = lowcost[k];
		ansedge[i] = e;
		state[k] = true;
		total += lowcost[k];
		for (int j = 0; j < g.n; j++) {
			if (!state[j] && g.adj[k][j] < lowcost[j]) {
				lowcost[j] = g.adj[k][j];
				nearvex[j] = k;
			}
		}
	}
	// �����ѡ����� 
	cout << "�����Ϊ: " << u << endl;
	for (int i = 1; i < g.n; i++) {// ѡ�ĵ� ��Ӧ�ı� Ȩֵ 
		cout << g.vex[ansvex[i]] << "   "
			<< g.vex[ansedge[i].start] << "----" << g.vex[ansedge[i].end]
			<< " ��" << lowcost[ansvex[i]] << endl;
	}
	cout << "��Ȩֵ��" << total << endl;
	delete[] state;
	delete[] lowcost;
	delete[] nearvex;
}
void output(AdjMatrix g) {
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++)
			if (g.adj[i][j] == INF) printf("��  ");
			else printf("%-4d", g.adj[i][j]);
		cout << endl;
	}
}