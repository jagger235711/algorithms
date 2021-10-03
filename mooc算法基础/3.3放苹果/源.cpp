#include<iostream>
using namespace std;

int setApples(int m,int n)
{
	if (n>m)
	{
		return setApples(m, m);
	}
	if (m == 0)
	{
		return 1;
	}
	if (n == 0)
	{
		return 0;
	}

	return setApples(m - n, n) + setApples(m, n - 1);
}

int main()
{
	int m, n;
	while (cin>>m>>n)
	{
		cout << setApples(m, n);
	}
	return 0;
}