#include<stdio.h>
void PrintMin(int a, int b)
{
	if (a < b)
		printf("%d", a);
	else
		printf("%d", b);
}
int main()
{
	void(*pf)(int, int);//set a point to function
	int x = 4, y = 5;
	pf = PrintMin;//指向函数首地址、函数名也是地址
	pf(x, y);
	return 0;
}