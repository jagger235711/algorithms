/*
描述
很久很久之前，森林里住着一群兔子。有一天，兔子们希望去赏樱花，但当他们到了上野公园门口却忘记了带地图。现在兔子们想求助于你来帮他们找到公园里的最短路。

输入
输入分为三个部分。
第一个部分有P+1行（P<30），第一行为一个整数P，之后的P行表示上野公园的地点。
第二个部分有Q+1行（Q<50），第一行为一个整数Q，之后的Q行每行分别为两个字符串与一个整数，表示这两点有直线的道路，并显示二者之间的矩离（单位为米）。
第三个部分有R+1行（R<20），第一行为一个整数R，之后的R行每行为两个字符串，表示需要求的路线。
输出
输出有R行，分别表示每个路线最短的走法。其中两个点之间，用->(矩离)->相隔。
样例输入
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
样例输出
Uenokouen->(35)->Ginza->(80)->Sensouji->(60)->Meijishinguu->(35)->Yoyogikouen
3 0 1 5 4
Meijishinguu

思路：
问题抽象为求两点间的最短路径 并输出路径
使用弗洛伊德算法。
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
	int n, e;//顶点 边
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
	//先将除主对角线以外的距离初始化为无穷。主对角线为0 
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
int locate(AdjMatrix g, VType v)//返回的为该点的下标
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
	for (int k = 0; k < g.n; k++)   // 依次考察所有顶点
		for (int i = 0; i < g.n; i++)
			for (int j = 0; j < g.n; j++) {
				if (a[i][j] > a[i][k] + a[k][j]) {
					a[i][j] = a[i][k] + a[k][j];  // 修改最短路径长度
					path[i][j] = path[k][j];       // 修改最短路径
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
		int ui, vi;//始点 终点
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

