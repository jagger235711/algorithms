#include "SortAlgorithm.h"
#include<iostream>
using namespace std;
//��������
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
            while (low <= high){//����������ʱ
                mid = floor((low + high) / 2);//��ȡ��
                if (tmp < A[mid]) {
                    high = mid - 1;
                }
                else low = mid + 1;
            }//��λ��high ע��Ҫ��̽��û��Ԫ�ص�λ�á���ʱhigh=low-1
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
    d = n / 2;//�����ó�ֵ
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
        d = d / 2;//��С����
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
    int i = low, j = 2 * i;//j��i������
    SortType tmp = A[i];
    while (j <= high) {
        if (j < high && A[j] < A[j + 1])
            j++;//����Һ��ӽϴ󣬰Ѿ�ָ���Һ���
        if (tmp < A[j]) {
            A[i] = A[j];//���ĺ��ӽ����γɴ����
            i = j;//�޸�i��j��ֵ�Ա��������ɸѡ
            j = 2 * i;
        }
        else break;
    }
    A[i] = tmp;//����ɸѡ����������λ��
}

void HeapSort(SortType A[], int n)
{
    int i;
    for (i = n / 2; i >= 0; i--)
        sift(A, i, n-1);//ѭ��������ʼ��
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
        for (j = n - 1; j > i; j--)//���һ��Ԫ�������±�Ϊn-1
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
        for (j = n - 1; j > i; j--)//���һ��Ԫ�������±�Ϊn-1
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
        int mid = (high + low) / 2;   //�����зֳ����������У��֣�
        MSort(A, low, mid);       //��һ�������������Σ�
        MSort(A, mid + 1, high);    //�ڶ��������������Σ�
        Merge(A, low, mid, high);  //�ϲ����������Ϊһ�������
    }
}

void NaturalMergeSort(SortType A[], int n)
{
    int i, i1, i2, j1, j2;
    int SubCount = 2; //�������еĸ�������һ����С1������Ŀ����whileѭ������ִ��һ��
    while (SubCount > 1)  // ���һ��ɨ������A��SubCount=1,˵���Ѿ������㷨����
    {
        i = 0;
        SubCount = 0;   //ÿ�˹鲢ǰ��ʼ��Ϊ0
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
    int* count = new int[10];   //�����iλֵΪj��Ԫ�ظ���

    int i = 0, k, r = 10;
    while (i < d)
    {   //��һ��A��B���ڶ���B��A
        for (int j = 0; j < 10; j++) count[j] = 0;
        for (int j = 0; j < n; j++)
        {
            k = (A[j] % r) / (r / 10); //�������iλ
            count[k]++;
        }
        count[0]--;    //��Ϊ����Ԫ�ص���ʼ�±�Ϊ0
        for (int j = 1; j < 10; j++) count[j] = count[j - 1] + count[j];
        //�����ÿ�ˡ��ռ�����Ԫ�ش�ŵ�λ�ã�˼�������ת��˼����ͬ
        for (int j = n - 1; j >= 0; j--)    //�Ӻ���ǰɨ��Ԫ�أ����һ�˹��̵��ռ�����
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
