/*描述
本题目考察大家图的存储的基本能力（建议大家将两种图的储存方式都试一下），题目将给大家n个点的信息（字符串，长度<=30),再给大家m条边的信息，最后提出k个问题，每个问题都是寻找每个点的邻接点。
输入
第一行：n,m,k
接下来n行，每行一个字符串，表示每个顶点的信息（字符串长度<=30)
接下来m行，每行两个数字a b，(0<=a,b ＜n 且a!=b)表示存在一条第a个点指向第b个点的边；
接下来k行，每行一个数字z，表示询问第z顶点所有的邻接点信息；
输出
一共k行，分别对应k个问题的答案：
如果询问的点，没有邻接点，那么输出0；
如果询问的点有多个邻接点，那么按照每个点（注意不是边）的输入顺序，进行输出，每个点的信息用空格隔开。
样例输入
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
样例输出
B E 
F 
C 
A B 
C 
提示
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
	int n, e;//当前图的顶点数和弧数
}AdjList;
void create(AdjList& g);
void ans(AdjList g,int k);
int main()
{
	AdjList g;
	int  k;
	cin >> g.n >> g.e >> k;//顶点个数 边数 问题数
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
		int ui, vi;//始点 终点
		cin >> ui >> vi;
		//
		ArcNode* p = new ArcNode;
		p->adjvex = vi;
		p->nextarc = g.vex[ui].firstarc;
		g.vex[ui].firstarc = p;
		//头插法
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