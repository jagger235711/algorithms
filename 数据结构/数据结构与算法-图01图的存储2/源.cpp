#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
typedef string VType;
const int VN = 10005;
const int INF = 32767;

typedef struct ArcNode		//�ڽӱ�߽ڵ� 
{
    int adjvex;              //��ָ��ĵ��ţ�������0��4 
    struct ArcNode* nextarc; //����ָ����һ��arcnode��� 
} ArcNode;

typedef struct
{
    VType data;        //�����������Ϣ
    ArcNode* firstarc; //�ڽӱ��б߽ڵ������ͷָ��,ָ���һ���߽ڵ�
} VNode;               //�ڽӱ��ͷ�������

typedef struct
{
    VNode vex[VN]; //�ڽӱ��ͷ�������
    int n, e;      //ͼ�еĶ�����n�ͱ���e                                 
} AdjList;         //������ͼ�ڽӱ�����

void create(AdjList& g, int n, int m); // �����ڽӱ��ʾ��ͼg
void output(AdjList g, int k);         //���g���ڽӱ�

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
        g.n = n;//���� 
        g.e = m;//���� 
        ArcNode* p = new ArcNode;
        g.vex[i].firstarc = p;//��ʼ�� 
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
        p->nextarc = next; //ͷ�巨 
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
            cout << "0 " << endl;//û���ڽӵ㣬���Ϊ0 
        }
        else
        {
            p = p->nextarc;
            while (p)
            {
                cout << g.vex[p->adjvex].data << ' ';//����� 
                p = p->nextarc;
            }
            cout << endl;
        }
    }
    cout << endl;


}

