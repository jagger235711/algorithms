/*描述
给出一个无向图顶点和边的信息，输出这个无向图的深度优先遍历序列和广度优先遍历序列。从一个顶点出发如果有2个以上的顶点可以访问时，我们约定先访问编号大的那个顶点。示例输入对应的图如下图所示：



输入
输入的第1行有2个整数m和n。表示图g有m个顶点和n条边。
第2行是m个以空格隔开的字符串，依次是图中第1个顶点的名字，第2个顶点的名字.....第m个顶点的名字。
此后还有n行，每行由2个字符串构成，分别是构成图中1条边的两个顶点。我们约定不会有重边。
输出
输出有2行。
第1行是从第1个顶点出发对图g做深度优先遍历得到的顶点序列。
第2行是从第1个顶点出发对图g做广度优先遍历得到的顶点序列。
样例输入
8 9
v1 v2 v3 v4 v5 v6 v7 v8
v1 v2
v1 v3
v1 v6
v2 v3
v2 v4
v3 v4
v4 v6
v5 v6
v7 v8
样例输出
v1 v6 v5 v4 v3 v2 v7 v8
v1 v6 v3 v2 v5 v4 v7 v8
提示
注意：从一个顶点出发如果有2个以上的顶点可以访问时，我们约定先访问编号大的那个顶点。*/
#include<iostream>
using namespace std;
typedef string VType;
const int VN = 20;
const int INF = 32767;
typedef struct ArcNode {
	int adjvex;
	int weight;
	struct ArcNode* nextarc;
}ArcNode;
typedef struct {
	VType data;
	ArcNode* firstarc;
}VNode;
typedef struct {
	VNode  vex[VN];
	int n, e;
}AdjList;
void create(AdjList& g);// 创建邻接表表示的图g 
int locate(AdjList g, VType v);// 返回图中g中顶点v的序号 
void DFS(AdjList g);
void DFS(AdjList g, bool* visited, int k);
void BFS(AdjList g);
void BFS(AdjList g, bool* visited, int k);
void output(AdjList g);//输出g的邻接表 
int main() {
	AdjList g;
	create(g);
	DFS(g);
	cout << endl;
	BFS(g);
	return 0;
}
void create(AdjList& g) {
	VType u, v;
	cin >> g.n >> g.e;
	for (int i = 0; i < g.n; i++)
	{
		cin >> g.vex[i].data;
		g.vex[i].firstarc = NULL;
	}
	for (int i = 0; i < g.e; i++)
	{
		cin >> u >> v;
		int ui, vi;//始点 终点
		ui = locate(g, u), vi = locate(g, v);
		//
		ArcNode* p = new ArcNode;
		p->adjvex = vi;
		p->nextarc = g.vex[ui].firstarc;
		g.vex[ui].firstarc = p;
		//头插法
		//if (!dg) {//当为无向图时，反过来存一遍
		if(1){
			p = new ArcNode;
			p->adjvex = ui;
			//p->weight = w;
			p->nextarc = g.vex[vi].firstarc;
			g.vex[vi].firstarc = p;
		}
	}
}
int locate(AdjList g, VType v)//用于定位顶点，从具体顶点转化为数组下标 
{
	for (int i = 0; i < g.n; i++)
		if (g.vex[i].data == v) return i;
	return -1;
}
void DFS(AdjList g) {
	bool* visited = new bool[g.n];

	for (int i = 0; i < g.n; i++) visited[i] = false;
	for (int i = 0; i < g.n; i++) {
		if (visited[i] == false)
			DFS(g, visited, i);
	}
	delete[] visited;
}
void DFS(AdjList g, bool* visited, int k) {
	cout << g.vex[k].data << " ";
	visited[k] = true;
	for (ArcNode* p = g.vex[k].firstarc; p; p = p->nextarc)
	{
		int j = p->adjvex;
		if (!visited[j]) DFS(g, visited, j);
	}
}
void BFS(AdjList g)
{
	bool* visited = new bool[g.n];

	for (int i = 0; i < g.n; i++) visited[i] = false;
	for (int i = 0; i < g.n; i++) {
		if (visited[i] == false)
			BFS(g, visited, i);
	}
	delete[] visited;
}
void BFS(AdjList g, bool* visited, int k)
{
	int q[VN], front, rear;

	front = rear = 0;
	q[rear++] = k;
	while (front != rear)
	{
		int u = q[front++];
		if (!visited[u])
		{
			cout << g.vex[u].data << " ";
			visited[u] = true;
			for (ArcNode* p = g.vex[u].firstarc; p; p = p->nextarc) {
				int j = p->adjvex;
				if (!visited[j]) q[rear++] = j;
			}
		}
	}
}