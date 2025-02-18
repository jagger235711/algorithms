//指针作为函数参数的练习
#include<iostream>
using namespace std;
void Swap(int* p1, int* p2);
int main()
{
	int a, b;
	cin >> a >> b;
	Swap(&a, &b);
	cout << a << " " << b;
	return 0;
}
void Swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}