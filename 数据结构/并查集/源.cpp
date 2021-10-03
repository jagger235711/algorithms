//10 7
//2 4
//5 7
//1 3
//8 9
//1 2
//5 6
//2 3
//3
//3 4
//7 10
//8 9

#include<iostream>
using namespace std;

typedef struct node {
	int data;//����Ӧ�˵ı��
	int rank;//������ ���ڱ�ʶ�����ĸ߶�
	int parent;//����˫�׵��±�
}UFSTree;
void make_set(UFSTree t[],int n);//��ʼ�����鼯��
int find_set(UFSTree t[], int x);//��x���ڵ������в��Ҽ��ϱ�� ���Ҹ����
void Union(UFSTree t[], int x, int y);//��x��y���ڵ������ϲ�

int main() {
	int N, M, Q;
	cin >> N >> M;
	UFSTree* t = new UFSTree[N];
	make_set(t, N);
	
	for (int i = 0; i < M; i++) {
		int first, second;
		cin >> first >> second;
		Union(t, first, second);
	}

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int first, second;
		cin >> first >> second;
		first = find_set(t, first);
		second = find_set(t, second);
		if (first == second)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}

void make_set(UFSTree t[], int n)
{
	int i;
	for (i = 1; i <= n; i++) {
		t[i].data = i;
		t[i].parent = i;
		t[i].rank = 0;
	}
}

int find_set(UFSTree t[], int x)
{
	if (x != t[x].parent) {
		return find_set(t, t[x].parent);
	}
	else
		return x;
}

void Union(UFSTree t[], int x, int y)
{
	x = find_set(t, x);
	y = find_set(t, y);
	if (t[x].rank > t[y].rank)
		t[y].parent = x;
	else {
		t[x].parent = y;
		if (t[x].rank == t[y].rank)
			t[y].rank++;
	}
}
