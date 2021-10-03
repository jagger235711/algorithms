/*
描述



热带岛屿Lagrishan的首领现在面临一个问题：几年前，一批外援资金被用于维护村落之间的道路，但日益繁茂的丛林无情的侵蚀着村民的道路，导致道路维修开销巨大，长老会不得不放弃部分道路的维护。上图左侧图显示的是正在使用道路的简图以及每条路每个月的维修费用（单位为aacms）。现在长老会需要提出一种方案，即需要保证村落之间都可以互相到达，又要将每个月的道路维修费用控制在最小。村子编号为从A到I。上图右侧显示的方案最小维修开销为216 aacms每月。

输入
输入包含1~100个数据集，最后一行为0.每个数据集第一行为村落数目n, 1 < n < 27,依次用字母表的前n个字母标记。接下来有n-1行，每行的第一个数据便是按字母顺序排列的村子编号（不包括最后一个村庄）。每个村庄后面的数据k代表该村庄通往编号在其之后的村庄的道路数目，如A 2 B 12 I 25，代表A村庄有2个编号在A之后的村庄和其相连。若k大于0，k后面会依次给出这k个村庄的编号以及各自到起始村庄的道路维修费用，如A 2 B 12 I 25，代表A和B之间道路维修费用为12， A和I之间道路维修费用为25（维修费用为不超过100的正整数）.路的总数目不超过75条，每个村庄到其他村庄不会有超过15条路（包括编号在其之前和之后的）。
输出
每个数据集有一个输出：针对解决方案每个月维修道路的小费用。
提示：蛮力算法虽能找出解决方案，但将会超出时间限制。
样例输入
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
样例输出
216
30
问题抽象：
求最小生成树 
由于是稠密图，选择普利姆算法
给出的数据形式适合用邻接表来做
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
	int n, e;//顶点 边
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
	//先将除主对角线以外的距离初始化为无穷。主对角线为0 
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
			//为无向图 存两遍 也可以用上三角矩阵存，然后映射过来
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
int locate(AdjMatrix g, VType v)//返回的为该点的下标
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
	int* nearvex = new int[g.n]; // nearvex[i]存放i对应结点距离生成树上最近的点 
	int* lowcost = new int[g.n];// lowcost[i]存放i对应结点距离生成树上最近的距离 
	bool* state = new bool[g.n];// state[i]存放i对应结点是否已在生成树中 

	for (int i = 0; i < g.n; i++) {// 辅助数组初始化 
		lowcost[i] = INF;
		state[i] = false;
	}
	VType u;
	cout << "输入最初选的顶点:";
	u = "A";

	int ui = locate(g, u);
	ansvex[0] = ui;
	state[ui] = true;

	for (int i = 0; i < g.n; i++)
	{// 修改u的邻接点的nearvex为u点，及lowcost
		if (g.adj[ui][i] != 0 && g.adj[ui][i] != INF) {
			lowcost[i] = g.adj[ui][i];
			nearvex[i] = ui;
		}
	}
	EType e;
	int total = 0;
	for (int i = 1; i < g.n; i++)
	{// 选g.n - 1个点加到生成树中 
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
	// 输出，选点过程 
	cout << "最初点为: " << u << endl;
	for (int i = 1; i < g.n; i++) {// 选的点 对应的边 权值 
		cout << g.vex[ansvex[i]] << "   "
			<< g.vex[ansedge[i].start] << "----" << g.vex[ansedge[i].end]
			<< " ：" << lowcost[ansvex[i]] << endl;
	}
	cout << "总权值：" << total << endl;
	delete[] state;
	delete[] lowcost;
	delete[] nearvex;
}
void output(AdjMatrix g) {
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++)
			if (g.adj[i][j] == INF) printf("∞  ");
			else printf("%-4d", g.adj[i][j]);
		cout << endl;
	}
}