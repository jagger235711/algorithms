#include "SortAlgorithm.h"
#include<iostream>
using namespace std;
//升序排列
void InsertSort(SortType A[], int n)
{
    int i, j;
    SortType tmp;
    for (i = 1; i < n; i++) {
        if (A[i] < A[i - 1]) {
            tmp = A[i];
            j = i - 1;
            do {
                A[j + 1] = A[j];
                j--;
            } while (j >= 0 && A[j] > tmp);
            A[j + 1] = tmp;
        }
    }
}

void BinInsertSort(SortType A[], int n)
{
    int i, j, low, high, mid;
    SortType tmp;
    for (i = 1; i < n; i++) {
        if (A[i] < A[i - 1]) {
            tmp = A[i];
            low = 0, high = i - 1;
            while (low <= high){//当还有数据时
                mid = floor((low + high) / 2);//下取整
                if (tmp < A[mid]) {
                    high = mid - 1;
                }
                else low = mid + 1;
            }//找位置high 注意要下探到没有元素的位置。此时high=low-1
            for (j = i - 1; j >= high+1; j--) 
                A[j + 1] = A[j];
            A[high+1] = tmp;
            }
    }
}

void ShellSort(SortType A[], int n)
{
    int i, j, d;
    SortType tmp;
    d = n / 2;//增量置初值
    while (d > 0) {
        for (i = d; i < n; i++) {
            tmp = A[i];
            j = i - d;
            while (j >= 0 && tmp < A[j]) {
                A[j + d] = A[j];
                j = j - d;
            }
            A[j + d] = tmp;
        }
        d = d / 2;//缩小增量
    }
}

void SelectSort(SortType A[], int n)
{
    int i, j, k;
    for ( i = 0; i < n-1; i++)
    {
        k = i;
        for ( j = i+1; j < n; j++)
            if (A[j] < A[k])
                k = j;
        if (k != i) {
            SortType tmp = A[i];
            A[i] = A[k];
            A[k] = tmp;
            }
    }
}

void sift(SortType A[], int low, int high)
{
    int i = low, j = 2 * i;//j是i的左孩子
    SortType tmp = A[i];
    while (j <= high) {
        if (j < high && A[j] < A[j + 1])
            j++;//如果右孩子较大，把就指向右孩子
        if (tmp < A[j]) {
            A[i] = A[j];//与大的孩子交换形成大根堆
            i = j;//修改i，j的值以便继续向下筛选
            j = 2 * i;
        }
        else break;
    }
    A[i] = tmp;//将被筛选结点放入最终位置
}

void HeapSort(SortType A[], int n)
{
    int i;
    for (i = n / 2; i >= 0; i--)
        sift(A, i, n-1);//循环建立初始堆
    for (i = n-1; i >= 1; i--) {
        SortType tmp = A[0];
        A[0] = A[i];
        A[i] = tmp;
        sift(A, 0, i - 1);
    }
}

void BubbleSort(SortType A[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = n - 1; j > i; j--)//最后一个元素数组下标为n-1
            if (A[j] < A[j - 1]) {
                SortType tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
            }
}

void BubbleSort_improve(SortType A[], int n)
{
    int i, j;
    bool exchange;
    for (i = 0; i < n - 1; i++) {
        exchange = false;
        for (j = n - 1; j > i; j--)//最后一个元素数组下标为n-1
            if (A[j] < A[j - 1]) {
                SortType tmp=A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
                exchange = true;
            }
        if (!exchange) break;
    }
       
}

int partition(SortType A[], int s, int t)
{
    int i = s, j = t;
    SortType tmp = A[i];
    while (i < j) {
        while (j > i && A[j] >= tmp) j--;
        A[i] = A[j];
        while (i < j && A[i] <= tmp) i++;
        A[j] = A[i];
    }
    A[i] = tmp;
    return i;
}

void QuickSort(SortType A[], int s, int t)
{
    int i;
    if (s < t) {
        i = partition(A, s, t);
        QuickSort(A, s, i - 1);
        QuickSort(A, i + 1, t);
    }
}

void Merge(SortType A[], int low, int mid, int high)
{
    SortType* A1;
    int i = low, j = mid + 1, k = 0;
    A1 = new SortType[high - low + 1];
    //A1 = (SortType*)malloc((high - low - 1) * sizeof(SortType));
    while (i<=mid&&j<=high)
    {
        if (A[i] <= A[j]) A1[k++] = A[i++];
        else A1[k++] = A[j++];
    }
    while (i <= mid) 
        A1[k++] = A[i++];
    while (j <= high) 
        A1[k++] = A[j++];
    for (k = 0, i = low; i <= high; k++, i++)
        A[i] = A1[k];
    delete(A1);
}

void MergeSort(SortType A[], int n)
{
    MSort(A, 0, n - 1);
}

void MSort(SortType A[], int low, int high)
{
    if (high > low) {
        int mid = (high + low) / 2;   //把序列分成两个子序列（分）
        MSort(A, low, mid);       //第一个子序列排序（治）
        MSort(A, mid + 1, high);    //第二个子序列排序（治）
        Merge(A, low, mid, high);  //合并两个有序表为一个有序表
    }
}

void NaturalMergeSort(SortType A[], int n)
{
    int i, i1, i2, j1, j2;
    int SubCount = 2; //有序序列的个数，设一个大小1的数，目的是while循环至少执行一次
    while (SubCount > 1)  // 如果一次扫描数组A后SubCount=1,说明已经有序，算法结束
    {
        i = 0;
        SubCount = 0;   //每趟归并前初始化为0
        while (i < n) {
            j1 = i1 = i; SubCount++;
            while (i < n - 1 && A[j1 + 1] >= A[j1]) { i++; j1++; }
            if (i < n - 1) { i++; i2 = j2 = i; SubCount++; }
            while (i < n - 1 && A[j2 + 1] >= A[j2]) { i++; j2++; }
            if (SubCount % 2 == 0)  Merge(A, i1, j1, j2);
            i++;
        }
    }
}

void RadixSort(SortType A[], int n, int d)
{
    int* B = new int[n];
    int* count = new int[10];   //计算第i位值为j的元素个数

    int i = 0, k, r = 10;
    while (i < d)
    {   //第一趟A→B，第二趟B→A
        for (int j = 0; j < 10; j++) count[j] = 0;
        for (int j = 0; j < n; j++)
        {
            k = (A[j] % r) / (r / 10); //分离出第i位
            count[k]++;
        }
        count[0]--;    //因为数组元素的起始下标为0
        for (int j = 1; j < 10; j++) count[j] = count[j - 1] + count[j];
        //计算出每趟“收集”后元素存放的位置，思想与快速转置思想相同
        for (int j = n - 1; j >= 0; j--)    //从后向前扫描元素，完成一趟过程的收集工作
        {
            k = (A[j] % r) / (r / 10);
            B[count[k]] = A[j];
            count[k]--;
        }
        r = r * 10;    i++;
        if (i < d)
        {
            for (int j = 0; j < 10; j++) count[j] = 0;
            for (int j = 0; j < n; j++)
            {
                k = (B[j] % r) / (r / 10);
                count[k]++;
            }
            count[0]--;
            for (int j = 1; j < 10; j++) count[j] = count[j - 1] + count[j];
            for (int j = n - 1; j >= 0; j--)
            {
                k = (B[j] % r) / (r / 10);
                A[count[k]] = B[j];
                count[k]--;
            }
            r = r * 10;  i++;
        }
    }
    if (d % 2 == 1) for (int j = 0; j < n; j++) A[j] = B[j];
}
