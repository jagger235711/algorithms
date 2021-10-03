#pragma once
typedef int SortType;
// 直接插入排序 对0到n-1进行排序
void InsertSort(SortType A[], int n);    

//折半插入
void BinInsertSort(SortType A[], int n);

//希尔排序 缩小增量法
void ShellSort(SortType A[], int n);

/*----------------------------------------插入排序-------------------------------------------------------------------*/

//简单选择排序
void SelectSort(SortType A[], int n);

//堆排序
void sift(SortType A[], int low, int high);    
void HeapSort(SortType A[], int n);

    //树排序
/*---------------------------------------选择排序------------------------------------------------------------------------------*/


//冒泡排序
void BubbleSort(SortType A[], int n);

//改进的冒泡排序
void BubbleSort_improve(SortType A[], int n);

//双向冒泡排序
void BiBubbleSort(SortType A[], int n);

//一趟划分
int partition(SortType A[], int s, int t);
//递归的快速排序算法
void QuickSort(SortType A[], int s, int t);

//非递归的快速排序算法
void IterQuickSort(SortType A[], int n);
    
//经过改进的快速排序递归版本的算法。

/*-------------------------------------交换排序--------------------------------------------------------------------------------------------*/

//折半归并排序（两路归并排序）
void Merge(SortType A[], int low, int mid, int high);

// 基于分治策略给出归并排序的递归版本
void MergeSort(SortType A[], int n);
void MSort(SortType A[], int low, int high);

//自然归并排序
void NaturalMergeSort(SortType A[], int n);

//基数排序
void RadixSort(SortType A[], int n, int d);
/*------------------------------------归并排序-------------------------------------------------------------------------*/
