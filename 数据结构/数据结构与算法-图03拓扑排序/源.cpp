/*
����
����һ��ͼ�Ľṹ������������������У�Ҫ����ͬ�������£����С�Ķ�����ǰ

����
��������������һ����2�������ֱ�Ϊ������v�ͻ���a����������a�У�ÿһ����2�������ֱ��Ǹ�����������������������
���
���ɸ��ո�����Ķ��㹹�ɵ�����(��Сд��ĸ)
��������
6 8
1 2
1 3
1 4
3 2
3 5
4 5
6 4
6 5
�������
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
void create(AdjList& g);// �����ڽӱ��ʾ��ͼg 
int locate(AdjList g, VType v);// ����ͼ��g�ж���v����� 
void topsort(AdjList g, int* order);//��������
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
		cin >> u >> v;//ʼ�� �յ�
		//
		ArcNode* p = new ArcNode;
		p->adjvex = v;
		p->nextarc = g.vex[u].firstarc;
		g.vex[u].firstarc = p;
		//ͷ�巨
	}
}
int locate(AdjList g, VType v)//���ڶ�λ���㣬�Ӿ��嶥��ת��Ϊ�����±� 
{
	for (int i = 0; i < g.n; i++)
		if (g.vex[i].data == v) return i;
	return -1;
}
void topsort(AdjList g, int* order) {//���С�Ķ�����ǰ
	int* indegree = new int[g.n+1]; // indegree[i]���i��Ӧ��������
	for (int i = 1; i < g.n+1; i++) indegree[i] = 0;//����Ϊ-1��ʾ���������
	for (int i = 1; i < g.n + 1; i++) {
		for (ArcNode* p = g.vex[i].firstarc; p; p = p->nextarc)	
			indegree[p->adjvex]++;
	}
	//��ʼ�����е�����
	int k = 0;
	for (int i = 1; i < g.n + 1; i++) {
		if (indegree[i] == -1) continue;
		if (indegree[i] == 0) {
			order[k++] = i;
			indegree[i]--;
			//�������Ϊ0�ļ����
			for (ArcNode* p = g.vex[i].firstarc; p; p = p->nextarc){
				if(indegree[p->adjvex]!=-1)
				indegree[p->adjvex]--;
			}//�йصĵ���ȼ�һ
			i = 1;//����i����ʾ�´�ɨ���ͷ��ʼ
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