/*����
����Ŀ������ͼ�Ĵ洢�Ļ��������������ҽ�����ͼ�Ĵ��淽ʽ����һ�£�����Ŀ�������n�������Ϣ���ַ���������<=30),�ٸ����m���ߵ���Ϣ��������k�����⣬ÿ�����ⶼ��Ѱ��ÿ������ڽӵ㡣
����
��һ�У�n,m,k
������n�У�ÿ��һ���ַ�������ʾÿ���������Ϣ���ַ�������<=30)
������m�У�ÿ����������a b��(0<=a,b ��n ��a!=b)��ʾ����һ����a����ָ���b����ıߣ�
������k�У�ÿ��һ������z����ʾѯ�ʵ�z�������е��ڽӵ���Ϣ��
���
һ��k�У��ֱ��Ӧk������Ĵ𰸣�
���ѯ�ʵĵ㣬û���ڽӵ㣬��ô���0��
���ѯ�ʵĵ��ж���ڽӵ㣬��ô����ÿ���㣨ע�ⲻ�Ǳߣ�������˳�򣬽��������ÿ�������Ϣ�ÿո������
��������
5 7 5
A
B
C
E
F
0 1
1 2
2 4
0 3
4 0
4 1
3 2
0
2
3
4
1
�������
B E 
F 
C 
A B 
C 
��ʾ
20% n<=10 m<=20 k<=n;
50% n<=500 m<=1000 k<=n;
70% n<=3000 m<=6000 k<=n;
100% n<=10000 m<=20000 k<=n;*/
#include<iostream>
using namespace std;
typedef string VType;
const int VN = 10000;
typedef struct ArcNode
{
	int adjvex;
	struct ArcNode* nextarc;
}ArcNode;
typedef struct 
{
	VType data;
	ArcNode* firstarc;
}VNode;
typedef struct 
{
	VNode vex[VN];
	int n, e;//��ǰͼ�Ķ������ͻ���
}AdjList;
void create(AdjList& g);
void ans(AdjList g,int k);
int main()
{
	AdjList g;
	int  k;
	cin >> g.n >> g.e >> k;//������� ���� ������
	create(g);
	ans(g, k);
	return 0;
}
void create(AdjList& g) {
	for (int i = 0; i < g.n; i++)
	{
		cin >> g.vex[i].data;
		g.vex[i].firstarc = NULL;
	}
	for (int i = 0; i < g.e; i++)
	{
		int ui, vi;//ʼ�� �յ�
		cin >> ui >> vi;
		//
		ArcNode* p = new ArcNode;
		p->adjvex = vi;
		p->nextarc = g.vex[ui].firstarc;
		g.vex[ui].firstarc = p;
		//ͷ�巨
	}
}
void ans(AdjList g,int k) {
	for (int i = 0; i < k; i++)
	{
		int L;
		string s;
		cin >> L;
		ArcNode* p = g.vex[L].firstarc;
		if (p) {
		while (p)
		{
		s = g.vex[p->adjvex].data + " " + s;
		p = p->nextarc;
		}
		}
		else {
			s = "0 ";
		}
		cout <<s<< endl;
	}
}