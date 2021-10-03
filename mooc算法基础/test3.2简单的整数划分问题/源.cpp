#include<iostream>
using namespace std;

int devide(int n,int m)
{
	if (n == 1 || m == 1)
		return 1;
	if (n < m)
		return devide(n, n);
	if (n == m)
		return 1 + devide(n, m - 1);
	if (n > m)
		return devide(n - m, m) + devide(n, m - 1);
	}
int main()
{
	int n;
	while (cin >> n)
	{
		cout << devide(n,n);
	}
	return 0;
}