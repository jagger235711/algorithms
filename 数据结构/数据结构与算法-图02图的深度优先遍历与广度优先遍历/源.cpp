/*����
����һ������ͼ����ͱߵ���Ϣ������������ͼ��������ȱ������к͹�����ȱ������С���һ��������������2�����ϵĶ�����Է���ʱ������Լ���ȷ��ʱ�Ŵ���Ǹ����㡣ʾ�������Ӧ��ͼ����ͼ��ʾ��



����
����ĵ�1����2������m��n����ʾͼg��m�������n���ߡ�
��2����m���Կո�������ַ�����������ͼ�е�1����������֣���2�����������.....��m����������֡�
�˺���n�У�ÿ����2���ַ������ɣ��ֱ��ǹ���ͼ��1���ߵ��������㡣����Լ���������رߡ�
���
�����2�С�
��1���Ǵӵ�1�����������ͼg��������ȱ����õ��Ķ������С�
��2���Ǵӵ�1�����������ͼg��������ȱ����õ��Ķ������С�
��������
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
�������
v1 v6 v5 v4 v3 v2 v7 v8
v1 v6 v3 v2 v5 v4 v7 v8
��ʾ
ע�⣺��һ��������������2�����ϵĶ�����Է���ʱ������Լ���ȷ��ʱ�Ŵ���Ǹ����㡣*/
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
void create(AdjList& g);// �����ڽӱ��ʾ��ͼg 
int locate(AdjList g, VType v);// ����ͼ��g�ж���v����� 
void DFS(AdjList g);
void DFS(AdjList g, bool* visited, int k);
void BFS(AdjList g);
void BFS(AdjList g, bool* visited, int k);
void output(AdjList g);//���g���ڽӱ� 
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
		int ui, vi;//ʼ�� �յ�
		ui = locate(g, u), vi = locate(g, v);
		//
		ArcNode* p = new ArcNode;
		p->adjvex = vi;
		p->nextarc = g.vex[ui].firstarc;
		g.vex[ui].firstarc = p;
		//ͷ�巨
		//if (!dg) {//��Ϊ����ͼʱ����������һ��
		if(1){
			p = new ArcNode;
			p->adjvex = ui;
			//p->weight = w;
			p->nextarc = g.vex[vi].firstarc;
			g.vex[vi].firstarc = p;
		}
	}
}
int locate(AdjList g, VType v)//���ڶ�λ���㣬�Ӿ��嶥��ת��Ϊ�����±� 
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