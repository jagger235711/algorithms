/*
描述
在一个非降序列中，查找与给定值最接近的元素。
输入
第一行包含一个整数n，为非降序列长度。1 <= n <= 100000。
第二行包含n个整数，为非降序列各元素。所有元素的大小均在0-1,000,000,000之间。
第三行包含一个整数m，为要询问的给定值个数。1 <= m <= 10000。
接下来m行，每行一个整数，为要询问最接近元素的给定值。所有给定值的大小均在0-1,000,000,000之间。
输出
m行，每行一个整数，为最接近相应给定值的元素值，保持输入顺序。若有多个值满足条件，输出最小的一个。
样例输入
3
2 5 8
2
10
5
样例输出
8
5
*/
#include<iostream>
#include<algorithm>
using namespace std;
int LowerBound(int a[], int size, int p)
{
	int l = 0;
	int r = size - 1;
	int lastPos = -1;
	while (l<=r)
	{
		int mid = l + (r - l) / 2;
		if (a[mid]>=p)
		{
			if (a[mid]=p)
			{
				return a[mid];
			}
			r = mid - 1;
		} 
		else
		{
			lastPos = mid;
			l = mid + 1;
		}
	}
	return a[lastPos];
}
int main()
{
	int n, Num[1000], m;
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> Num[i];
	
	//sort(Num, Num + n);//默认升序排列

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int Question;
		cin >> Question;
		cout<<LowerBound(Num, n, Question)<<endl;//自己写一个二分查找函数
	}
	return 0;
}