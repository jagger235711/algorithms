#include<iostream>
#include<algorithm>
#define Max 101
using namespace std;
int d[Max][Max], maxSum[Max][Max];
int n;
int MaxSum(int i, int j)
{
	if (maxSum[i][j]!=-1)
		return maxSum[i][j];
	if (i==n)
		maxSum[i][j]=d[i][j];
	else {
		int x = MaxSum(i + 1, j);
		int y = MaxSum(i + 1, j + 1);
		maxSum[i][j] = max(x, y)+d[i][j];
	}
		return maxSum[i][j];
}
int main() {
	int i, j;
	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= i; j++) {
			cin >> d[i][j];
			maxSum[i][j] = -1;
		}
			
	cout << MaxSum(1, 1) << endl;
}