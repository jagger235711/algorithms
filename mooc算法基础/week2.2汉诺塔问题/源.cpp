#include <iostream>
using namespace std;
void Hanoi(int n, char src, char mid, char dest)
{
	if (n==1)
	{
		cout << src << "->" << dest << endl;
	}
	else
	{
		Hanoi(n - 1, src, dest, mid);//�Ƚ�n-1�����Ӵ�src�Ƶ�mid��
		cout << src << "->" << dest << endl;//�ٽ�һ�����Ӵ�src�ƶ���dest 
		Hanoi(n - 1, mid, src, dest);//���n-1�����Ӵ�mid�ƶ���dest 
	}
}
int main()
{
	int n;
	cin >> n;
	Hanoi(n, 'A', 'B', 'C');
	return 0;
}