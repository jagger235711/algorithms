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
		Hanoi(n - 1, src, dest, mid);//先将n-1个盘子从src移到mid上
		cout << src << "->" << dest << endl;//再将一个盘子从src移动到dest 
		Hanoi(n - 1, mid, src, dest);//最后将n-1个盘子从mid移动到dest 
	}
}
int main()
{
	int n;
	cin >> n;
	Hanoi(n, 'A', 'B', 'C');
	return 0;
}