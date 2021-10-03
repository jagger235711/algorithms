/*
描述
给出一个图的结构，输出其拓扑排序序列，要求在同等条件下，编号小的顶点在前

输入
若干行整数，第一行有2个数，分别为顶点数v和弧数a，接下来有a行，每一行有2个数，分别是该条弧所关联的两个顶点编号
输出
若干个空格隔开的顶点构成的序列(用小写字母)
样例输入
6 8
1 2
1 3
1 4
3 2
3 5
4 5
6 4
6 5
样例输出
v1 v3 v2 v6 v4 v5
*/
#include<iostream>
using namespace std;
typedef int VType;
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
void topsort(AdjList g, int* order);//拓扑排序
int main() {
	AdjList g;
	create(g);	
	int* p = new int[g.n];
	topsort(g, p);
	int i = 0;
	while (i<g.n)
		cout << "v" << p[i++] << " ";
	return 0;
}
void create(AdjList& g) {
	VType u, v;
	cin >> g.n >> g.e;
	for (int i = 1; i < g.n+1; i++)
	{
		g.vex[i].data=i;
		g.vex[i].firstarc = NULL;
	}
	for (int i = 0; i < g.e; i++)
	{
		cin >> u >> v;//始点 终点
		//
		ArcNode* p = new ArcNode;
		p->adjvex = v;
		p->nextarc = g.vex[u].firstarc;
		g.vex[u].firstarc = p;
		//头插法
	}
}
int locate(AdjList g, VType v)//用于定位顶点，从具体顶点转化为数组下标 
{
	for (int i = 0; i < g.n; i++)
		if (g.vex[i].data == v) return i;
	return -1;
}
void topsort(AdjList g, int* order) {//编号小的顶点在前
	int* indegree = new int[g.n+1]; // indegree[i]存放i对应顶点的入度
	for (int i = 1; i < g.n+1; i++) indegree[i] = 0;//当置为-1表示这个点已用
	for (int i = 1; i < g.n + 1; i++) {
		for (ArcNode* p = g.vex[i].firstarc; p; p = p->nextarc)	
			indegree[p->adjvex]++;
	}
	//初始化所有点的入度
	int k = 0;
	for (int i = 1; i < g.n + 1; i++) {
		if (indegree[i] == -1) continue;
		if (indegree[i] == 0) {
			order[k++] = i;
			indegree[i]--;
			//遇到入度为0的即入队
			for (ArcNode* p = g.vex[i].firstarc; p; p = p->nextarc){
				if(indegree[p->adjvex]!=-1)
				indegree[p->adjvex]--;
			}//有关的点入度减一
			i = 1;//重置i即表示下次扫描从头开始
		}
	}
	//int* q = new int[g.n + 1], front, rear;
	//front = rear = 0;
	//for (int i = 1; i < g.n+1; i++)
	//	if (indegree[i] == 0) {
	//		q[rear] = i; rear = (rear + 1) % (g.n + 1);
	//	}
	//int k = 0;
	//while (front != rear) {
	//	order[k++] = q[front];
	//	for (ArcNode* p = g.vex[q[front]].firstarc; p; p = p->nextarc) {
	//		indegree[p->adjvex]--;
	//		if (indegree[p->adjvex] == 0) {
	//			q[rear] = p->adjvex; rear = (rear + 1) % (g.n + 1);
	//		}
	//	}
	//	front = (front + 1) % (g.n + 1);
	//}
	delete[] indegree;
}