#include<iostream>
using namespace std;
void Reverse(int* p, int size);
int main()
{
	int a[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	Reverse(a[1], 4);
	for (int i = 0; i < 4; i++)
	{
		cout << a[1][i] << " ";
	}
	return 0;
}
void Reverse(int* p, int size)
{
	for (int i = 0; i < size / 2; i++)
	{
		int Temp = p[i];
		p[i] = p[size - 1 - i];
		p[size - 1 - i] = Temp;
	}
}
