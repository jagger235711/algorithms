#include<iostream>
using namespace std;

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
void QuickSort(int a[], int s, int e,int n)
{
	if (s >= e)
		return;
	int k = a[s];
	int i = s, j = e;
	while (i != j) {
		while (j > i && a[j] >= k)
			--j;
		swap(a[i], a[j]);
		while (i < j && a[i] <= k)
			++i;
		swap(a[i], a[j]);
	}
	if (n > i+1)//less
		QuickSort(a, i+1, j,n-i+1 );
	if (n < i+1)//more
		QuickSort(a, 0, i, i+1-n);

	//QuickSort(a, s, i - 1);
	//QuickSort(a, i + 1, e);
}
int a[] = { 1,2,3,4,5,6,7,8,9,10 };
int main()
{
	int size = sizeof(a) / sizeof(int),k;
	cin >> k;
	QuickSort(a, 0, size - 1,size-k);
	for (int i = size-1,c=0;c<k; i--,c++)
		cout << a[i] << ",";
	cout << endl;
	return 0;
}