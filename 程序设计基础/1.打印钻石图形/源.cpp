#include<iostream>
using namespace std;
void DaYing(int num, char c);
int main()
{
	int num;
	char c;
	cin >> num >> c;
	DaYing(num, c);
	return 0;
}
void DaYing(int num, char c)
{
	if (c == 'y')
	{
		for (int i = 0; i < num; i++)
		{
			for (int t = 0; t < num - i-1; t++)
			{
				cout << " ";
			}
			for (int t = 0; t < 2*i+1; t++)
			{
				cout << "*";
			}
			cout << endl;
		}
		for (int i = num-2; i >= 0; i--)
		{
			for (int t = 0; t < num - i - 1; t++)
			{
				cout << " ";
			}
			for (int t = 0; t < 2 * i + 1; t++)
			{
				cout << "*";
			}
			cout << endl;
		}
	}
	else if (c == 'n')
	{
		for (int i = 0; i < num; i++)
		{
			for (int t = 0; t < num - i - 1; t++)
			{
				cout << " ";
			}
			for (int t = 0; t < 2 * i + 1; t++)
			{
				if (t == 0 || t == 2*i) cout << "*";
				else cout << " ";
			}
			cout << endl;
		}
		for (int i = num - 2; i >= 0; i--)
		{
			for (int t = 0; t < num - i - 1; t++)
			{
				cout << " ";
			}
			for (int t = 0; t < 2 * i + 1; t++)
			{
				if (t == 0 || t == 2 * i) cout << "*";
				else cout << " ";
			}
			cout << endl;
		}
	}
}