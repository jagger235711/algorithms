#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
using namespace std;
typedef string VType;
const int VN = 20;
const int INF = 32767;
typedef struct ArcNode {
	int adjvex;
	int weight;
	struct ArcNode* nextarc;
}ArcNode;//Arc��  Node�ڵ�
typedef struct {
	VType data;
	ArcNode* firstarc;
}VNode;//vex���� vertex
typedef struct {
	VNode  vex[VN];
	int n, e;
}AdjList;//�ڽӱ� adjacent���ڵ�
void create(AdjList& g);// �����ڽӱ��ʾ��ͼg 
int locate(AdjList g, VType v);// ����ͼ��g�ж���v����� 
void output(AdjList g);//���g���ڽӱ� 
void DFS(AdjList g);
void DFS(AdjList g, bool* visited, int k);
void DFSfdg(AdjList g);
void DFSfdg(AdjList g, bool* visited, int v);
void BFS(AdjList g);
void BFS(AdjList g, bool* visited, int k);
bool connect(AdjList g);

int main(void) {
	AdjList g;

	create(g);
	output(g);

	return 0;
}
int gt, dg;
void create(AdjList& g) {

	char fname[20];
	cout << "���������ļ�����������create.txt��";
	cin >> fname;
	ifstream in(fname);


	//cout << "����ͼ�����ͣ�0Ϊ������1Ϊ����";
	in >> gt;
	//cout << "����ͼ�Ƿ�Ϊ����ͼ��1Ϊ����, 0Ϊ����"; // 1Ϊ���� 
	in >> dg;
	//cout << "����ͼ�ж�����:";
	in >> g.n;
	//cout << "����ͼ�Ķ���:";
	for (int i = 0; i < g.n; i++) {
		in >> g.vex[i].data;
		g.vex[i].firstarc = NULL;
	}
	//cout << "����ͼ�б���:";
	in >> g.e;
	//cout << "����ͼ�еı�:"<< endl;

	VType u, v;
	int w;
	for (int i = 0; i < g.e; i++) {
		in >> u >> v;
		w = 0;
		if (gt) in >> w;
		int ui, vi;
		ui = locate(g, u), vi = locate(g, v);
		ArcNode* p = new ArcNode;
		p->adjvex = vi; p->weight = w;
		p->nextarc = g.vex[ui].firstarc;
		g.vex[ui].firstarc = p;
		if (!dg) {
			p = new ArcNode;
			p->adjvex = ui;
			p->weight = w;
			p->nextarc = g.vex[vi].firstarc;
			g.vex[vi].firstarc = p;
		}
	}

}
int locate(AdjList g, VType v)
{
	for (int i = 0; i < g.n; i++)
		if (g.vex[i].data == v) return i;
	return -1;
}
void output(AdjList g) {
	for (int i = 0; i < g.n; i++) {
		printf("%2d ", i);
		cout << g.vex[i].data << " ";
		ArcNode* p = g.vex[i].firstarc;
		if (p == NULL) cout << "^";
		else
			while (p)
			{
				cout << "-->" << p->adjvex;
				if (gt) cout << "  " << p->weight;
				p = p->nextarc;
			}
		cout << endl;

	}
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
void DFSfdg(AdjList g)
{
	bool* visited = new bool[g.n];

	for (int i = 0; i < g.n; i++) visited[i] = false;
	for (int i = 0; i < g.n; i++) {
		if (!visited[i])
			DFSfdg(g, visited, i);
	}
	delete[] visited;
}
void DFSfdg(AdjList g, bool* visited, int v)
{
	int sta[VN], top = -1;

	sta[++top] = v;
	while (top != -1) {
		int u = sta[top--];
		if (!visited[u]) {
			cout << g.vex[u].data << " ";
			visited[u] = true;
			for (ArcNode* p = g.vex[u].firstarc; p; p = p->nextarc) {
				int j = p->adjvex;
				if (!visited[j])	sta[++top] = j;
			}
		}

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
bool connect(AdjList g)
{
	bool* visited = new bool[g.n];

	for (int i = 0; i < g.n; i++)	visited[i] = false;
	DFS(g, visited, 0);
	for (int i = 0; i < g.n; i++)
		if (!visited[i])	return false;
	return true;
}
//void existPath(AdjList g, int u, int v, bool &has) // ����������hasֵ��ʼΪfalse 
//{	
//	visited[u] = true;	
//	if(u == v)
//	{
//		has = true;	return;
//	}
//	ArcNode *p = G.vex[u].firstarc;
//	while(p)
//	{
//		int w = p -> adjvex;		
//		if(!visited[w])	
//			existPath(G, w, v, has);
//		p = p -> nextarc;
//	}
//}
//void printPath(AdjList g, int u, int v, int len)
//{
//	visited[u] = true;
//	path[++len] = u;
//	if(u == v && len >= 0)
//	{		
//		for(int i = 0; i <= len; i++)
//			printf("%c ", G.vex[path[i]].data);
//		printf("\n");
//		return;
//	}
//	ArcNode *p = G.vex[u].firstarc;
//	while(p)
//	{
//		int w = p -> adjvex;
//		if(!visited[w])
//			printPath(G, w, v, len);
//		p = p -> nextarc;		
//	}
//}
//void printAllPath(AdjList G, int u, int v, int len)
//{
//	visited[u] = true;
//	path[++len] = u;
//	if(u == v  && len >= 0)
//	{		
//		for(int i = 0; i <= len; i++)
//			printf("%c ", G.vex[path[i]].data);
//		printf("\n");
//	}
//	ArcNode *p = G.vex[u].firstarc;
//	while(p)
//	{
//		int w = p -> adjvex;
//		if(!visited[w])
//			printAllPath(G, w, v, len);			
//		p = p -> nextarc;		
//	}	
//	visited[u] = false;	
//}
//void printkPath(AdjList G, int u, int v, int len, int k)
//{
//	visited[u] = true;
//	path[++len] = u;
//	if(u == v && len == k)
//	{
//		for(int i = 0; i <= len; i++)
//			printf("%c ", G.vex[path[i]].data);
//		printf("\n");
//	}
//	ArcNode *p = G.vex[u].firstarc;
//	while(p)
//	{
//		int w = p -> adjvex;
//		if(!visited[w])
//			printkPath(G, w, v, len, k);
//		p = p -> nextarc;
//	}
//	visited[u] = false;
//}
//void printCPath(AdjList G, int u, int v, int len)
//{
//	visited[u] = true;
//	path[++len] = u;
//	
//	ArcNode *p = G.vex[u].firstarc;
//	while(p)
//	{
//		int w = p -> adjvex;
//		if(w == v && len > 1)
//		{
//			for(int i = 0; i <= len; i++)
//				printf("%c ", G.vex[path[i]].data);
//			printf("%c ", G.vex[v].data);
//			printf("\n");
//		}
//		if(!visited[w])	printCPath(G, w, v, len);
//		p = p -> nextarc;
//	}
//	visited[u] = false;
//}


