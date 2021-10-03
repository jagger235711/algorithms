#include <iostream> 
#include <cstdio>
using namespace std;
int find(int* group, int x);
void merge(int* group, int x, int y);
int main(void) {
	int n, m, k = 0;

	while (1) {
		cin >> n >> m;
		if (n == 0) break;
		k++;
		int* group = new int[n + 1];
		for (int i = 1; i <= n; i++) group[i] = i;
		int x, y;
		for (int i = 1; i <= m; i++) {
			cin >> x >> y;
			if (find(group, x) != find(group, y))
				merge(group, x, y);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (group[i] == i) ans++;
		printf("Case %d: %d\n", k, ans);
	}
}
int find(int* group, int x) {
	int r = x;
	while (group[r] != r) r = group[r]; // 查找x的集合号
	// x--r的所有结点的集合号修改成r
	while (r != x) {
		int tmpf = group[x];
		group[x] = r;
		x = tmpf;
	}

	return r;
}

void merge(int* group, int x, int y)
{
	int r1 = find(group, x);
	int r2 = find(group, y);
	group[r2] = r1;

}
