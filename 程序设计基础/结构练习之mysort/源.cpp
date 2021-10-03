/*
输入
多组数据。每组数据以整数 n开头(n<10)，然后是n个整数
输出
对每组数据，输出三行。
第一行是整数从小倒大排序的结果
第二行是按个位数从小到大排序的结果(如果个位数相同，小的排在前面)
第三行还是整数从小倒大排序的结果
样例输入
5 21 3 76 48 445
6 73 29 45 8737 2 1
样例输出
3,21,48,76,445,
21,3,445,76,48,
3,21,48,76,445,
1,2,29,45,73,8737,
1,2,73,45,8737,29,
1,2,29,45,73,8737,
*/
#include <iostream>
using namespace std;
struct A {
	int nouse1;
	int nouse2;
	int n;
};
// 在此处补充你的代码
// 数组名 数据个数 单个类型大小 比较规则
void mysort(void* a,int Size,int Wide,
	int MyCompare(const void *e1, const void *e2))
{
	//BubbleSort
	char* s = (char*)a;
	for (int i = 0; i < Size - 1; i++)
	{
		for (int j = 0; j < Size - i - 1; j++)
		{
			char* p = (char*)a;
			if (MyCompare(&p[j],&p[j+1])>0)
			{
				for (int k = 0; k < Wide; ++k)//变成字符了，要一字节一字节的换 
				{
					char tmp = p[k];
					p[k] = p[k];
					p[k] = tmp;
				}
			}
		}
	}
}
int MyCompare1( const void * e1,const void * e2) 
{
	int * p1 = (int * ) e1;
	int * p2 = (int * ) e2;
	return * p1 - * p2;
}
int MyCompare2( const void * e1,const void * e2) 
{
	int * p1 = (int * ) e1;
	int * p2 = (int * ) e2;
	if( (* p1 %10) - (* p2 % 10))
		return (* p1 %10) - (* p2 % 10);
	else
		return * p1 - * p2;
}
int MyCompare3( const void * e1,const void * e2) 
{
	A * p1 = (A*) e1;
	A * p2 = (A*) e2;
	return p1->n - p2->n;
}
int a[20];
A b[20];
int main ()
{	
	int n;
	while(cin >> n) {
		for(int i = 0;i < n; ++i) {
			cin >> a[i];
			b[i].n = a[i];
		}
		mysort(a,n,sizeof(int),MyCompare1);
		for(int i = 0;i < n; ++i) 
			cout << a[i] << "," ;
		cout << endl;
		mysort(a,n,sizeof(int),MyCompare2);
		for(int i = 0;i < n; ++i) 
			cout << a[i] << "," ;
		cout << endl;
		mysort(b,n,sizeof(A),MyCompare3);
		for(int i = 0;i < n; ++i) 
			cout << b[i].n << "," ;
		cout << endl;
	}
	return 0;
}