/*
http://cxsjsxmooc.openjudge.cn/2019t2summerall/011/
求排列的逆序数
MergeSort
归并排序
复杂度： n*log(n)
*/
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;
long long MergeSort(int a[], int s, int e, int tmp[]);
void Merge(int a[], int s, int m, int e, int tmp[]);
//int a[] = { 2,6,3,4,5,1 };
//int b[6];
int a[100010];
int b[100010];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    printf("%lld", MergeSort(a, 0, n - 1, b));
    return 0;

    //int size = sizeof(a) / sizeof(int);
    //long long result = MergeSort(a, 0, size - 1, b);
    //for (int k = 0; k < size; k++)
    //    cout << a[k] << " ";
    //cout << "\n" ;
    //cout << result << endl;
    //return 0;
}
/*归并排序 s ：数组开始 e ：数组结尾*/
// 将数组 a 的局部 a[s, m] 和 a[m + 1, e] 合并到 tmp, 并保证 tmp 有序，然后再拷贝回 a[s, m]
// 归并操作时间复杂度： O (e-m+1), 即 O (n)
long long count(int a[], int s, int m, int e)
//从大到小合并[s,m], [m+1,e] 
{
    long long result = 0;
    int p1 = s;
    int p2 = m + 1;
    while (p1 <= m && p2 <= e)
    {
        if (a[p1] > a[p2])
        {
            result += e - p2 + 1;
            p1++;
        }
        else
        {
            p2++;
        }
    }
    return result;

}

long long MergeSort(int a[], int s, int e, int tmp[])
{
    long long result = 0;
    if (s < e) /*当只有一个元素时，递归终止，直接调用merge函数，比较 13和27大小，最后排序*/
    {
        int m;// cut array into half
        m = s + (e - s) / 2;
        result += MergeSort(a, s, m, tmp);/* 排好序的数组 临时放在哪里？ */
        result += MergeSort(a, m + 1, e, tmp);//分别求两边的逆序数 
        result += count(a, s, m, e);//然后再o(n)算左边和右边造成的逆序数 。此时要求左边和右边都是从大到小有序的，才能在o(n)时间内算出结果 
        Merge(a, s, m, e, tmp);//从大到小合并，确保排序 
    }
    return result;

}
void Merge(int a[], int s, int m, int e, int tmp[])
//从大到小合并[s,m], [m+1,e] 
{
    int i = 0;
    int p1 = s;
    int p2 = m + 1;
    while (p1 <= m && p2 <= e)
    {
        if (a[p1] > a[p2])
        {
            tmp[i++] = a[p1++];
        }
        else
        {
            tmp[i++] = a[p2++];
        }
    }
    while (p1 <= m)
        tmp[i++] = a[p1++];
    while (p2 <= e)
        tmp[i++] = a[p2++];
    for (int j = 0; j < e - s + 1; j++)
    {
        a[s + j] = tmp[j];
    }

}