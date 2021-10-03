#pragma once
typedef int SortType;
// ֱ�Ӳ������� ��0��n-1��������
void InsertSort(SortType A[], int n);    

//�۰����
void BinInsertSort(SortType A[], int n);

//ϣ������ ��С������
void ShellSort(SortType A[], int n);

/*----------------------------------------��������-------------------------------------------------------------------*/

//��ѡ������
void SelectSort(SortType A[], int n);

//������
void sift(SortType A[], int low, int high);    
void HeapSort(SortType A[], int n);

    //������
/*---------------------------------------ѡ������------------------------------------------------------------------------------*/


//ð������
void BubbleSort(SortType A[], int n);

//�Ľ���ð������
void BubbleSort_improve(SortType A[], int n);

//˫��ð������
void BiBubbleSort(SortType A[], int n);

//һ�˻���
int partition(SortType A[], int s, int t);
//�ݹ�Ŀ��������㷨
void QuickSort(SortType A[], int s, int t);

//�ǵݹ�Ŀ��������㷨
void IterQuickSort(SortType A[], int n);
    
//�����Ľ��Ŀ�������ݹ�汾���㷨��

/*-------------------------------------��������--------------------------------------------------------------------------------------------*/

//�۰�鲢������·�鲢����
void Merge(SortType A[], int low, int mid, int high);

// ���ڷ��β��Ը����鲢����ĵݹ�汾
void MergeSort(SortType A[], int n);
void MSort(SortType A[], int low, int high);

//��Ȼ�鲢����
void NaturalMergeSort(SortType A[], int n);

//��������
void RadixSort(SortType A[], int n, int d);
/*------------------------------------�鲢����-------------------------------------------------------------------------*/
