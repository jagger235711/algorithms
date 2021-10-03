#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
typedef string VType;
const int VN = 10005;
const int INF = 32767;

typedef struct ArcNode		//邻接表边节点 
{
    int adjvex;              //边指向的点编号，例子是0到4 
    struct ArcNode* nextarc; //用于指向下一个arcnode结点 
} ArcNode;

typedef struct
{
    VType data;        //顶点的其他信息
    ArcNode* firstarc; //邻接表中边节点链表的头指针,指向第一个边节点
} VNode;               //邻接表的头结点类型

typedef struct
{
    VNode vex[VN]; //邻接表的头结点数组
    int n, e;      //图中的顶点数n和边数e                                 
} AdjList;         //完整的图邻接表类型

void create(AdjList& g, int n, int m); // 创建邻接表表示的图g
void output(AdjList g, int k);         //输出g的邻接表

int main()
{
    AdjList g;
    int n, m, k;
    cin >> n >> m >> k;
    create(g, n, m);

    output(g, k);
}
//5 7 5
//A
//B
//C
//E
//F
//0 1
//1 2
//2 4
//0 3
//4 0
//4 1
//3 2
//0
//2
//3
//4
//1
void create(AdjList& g, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        cin >> g.vex[i].data;
        g.n = n;//点数 
        g.e = m;//边数 
        ArcNode* p = new ArcNode;
        g.vex[i].firstarc = p;//初始化 
        p->adjvex = -1;
        p->nextarc = NULL;
    }
    for (int i = 0; i < m; i++)
    {

        int bt1, bt2;
        cin >> bt1 >> bt2;
        ArcNode* p = g.vex[bt1].firstarc;
        while (p->nextarc && p->nextarc->adjvex < bt2)
        {

            p = p->nextarc;
        }
        ArcNode* next = new ArcNode;
        next->adjvex = bt2;
        next->nextarc = p->nextarc;
        p->nextarc = next; //头插法 
    }
}

void output(AdjList g, int k)
{
    for (int i = 0; i < k; i++)
    {

        int num;
        cin >> num;
        ArcNode* p = g.vex[num].firstarc;
        if (p->nextarc == NULL)
        {
            cout << "0 " << endl;//没有邻接点，输出为0 
        }
        else
        {
            p = p->nextarc;
            while (p)
            {
                cout << g.vex[p->adjvex].data << ' ';//输出点 
                p = p->nextarc;
            }
            cout << endl;
        }
    }
    cout << endl;


}

