#include<iostream>
using namespace std;
int DownStair(int n)
{
	if (n < 0) return 0;
	else if (n == 0 || n == 1) return 1;
	else return DownStair(n - 1) + DownStair(n - 2) + DownStair(n - 3);
}
int main()
{
	int n; 
	cin >> n;
    cout<<DownStair(n);
	return 0;
}