#include<iostream>
using namespace std;
void judge(int n);
int main()
{
	int n;
	while (cin >> n)
	{
		judge(n);
	}
	return 0;
}
void judge(int n)
{
	if (n % 2 == 0) cout << "even";
	else cout << "odd";
}