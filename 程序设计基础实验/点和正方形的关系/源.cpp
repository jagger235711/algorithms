#include<iostream>
using namespace std;
int main()
{
	int x, y;
	cin >> x >> y;
	if (x <= 1 && x>=-1)
	{
		if (y<=1 && y>=-1) cout << "yes";
		else cout << "no";
	}
	else cout << "no";
	return 0;
}