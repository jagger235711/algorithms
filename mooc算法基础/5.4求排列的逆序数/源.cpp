/*
http://cxsjsxmooc.openjudge.cn/2019t2summerall/011/
�����е�������
MergeSort
�鲢����
���Ӷȣ� n*log(n)
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
/*�鲢���� s �����鿪ʼ e �������β*/
// ������ a �ľֲ� a[s, m] �� a[m + 1, e] �ϲ��� tmp, ����֤ tmp ����Ȼ���ٿ����� a[s, m]
// �鲢����ʱ�临�Ӷȣ� O (e-m+1), �� O (n)
long long count(int a[], int s, int m, int e)
//�Ӵ�С�ϲ�[s,m], [m+1,e] 
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
    if (s < e) /*��ֻ��һ��Ԫ��ʱ���ݹ���ֹ��ֱ�ӵ���merge�������Ƚ� 13��27��С���������*/
    {
        int m;// cut array into half
        m = s + (e - s) / 2;
        result += MergeSort(a, s, m, tmp);/* �ź�������� ��ʱ������� */
        result += MergeSort(a, m + 1, e, tmp);//�ֱ������ߵ������� 
        result += count(a, s, m, e);//Ȼ����o(n)����ߺ��ұ���ɵ������� ����ʱҪ����ߺ��ұ߶��ǴӴ�С����ģ�������o(n)ʱ���������� 
        Merge(a, s, m, e, tmp);//�Ӵ�С�ϲ���ȷ������ 
    }
    return result;

}
void Merge(int a[], int s, int m, int e, int tmp[])
//�Ӵ�С�ϲ�[s,m], [m+1,e] 
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