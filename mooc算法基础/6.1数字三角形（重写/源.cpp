#include<iostream>
#include<algorithm>
#define Max 101;
using namespace std;
int n;
int d[101][101] ;
int MaxSum(int i, int j)
{
	if (i == n)
		return d[i][j];
	int x = MaxSum(i + 1, j);
	int y = MaxSum(i + 1, j + 1);
	return max(x, y) + d[i][j];

}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> d[i][j];
		}
	}
	cout << MaxSum(1, 1) << endl;
	return 0;
}