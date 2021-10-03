#include "SortAlgorithm.h"
#include<iostream>
#include <stack>
using namespace std;
void Swap(int &num_a, int &num_b)
{
        int temp = num_b;
        num_b = num_a;
        num_a = temp;
}
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
        if (k != i) Swap(A[i], A[k]);
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
            if (A[j] < A[j - 1]) Swap(A[j], A[j - 1]);
}

void BubbleSort_improve(SortType A[], int n)
{
    int i, j;
    bool exchange;
    for (i = 0; i < n - 1; i++) {
        exchange = false;
        for (j = n - 1; j > i; j--)//最后一个元素数组下标为n-1
            if (A[j] < A[j - 1]) {
                Swap(A[j], A[j - 1]);
                exchange = true;
            }
        if (!exchange) break;
    }
       
}

void BiBubbleSort(SortType A[], int n)
{
    int low, high, flag, i;
    low = 0;
    high = n - 1;
    while (low < high)
    {
        flag = 0;
        for (i = low; i < high; i++)  //正向冒泡
        {
            if (A[i] > A[i + 1]) //找到剩下中最大的
            {
                Swap(A[i], A[i + 1]);
                flag = 1;    //标志， 有数据交换
            }
        }
        if (!flag)
            break;
        high--;
        for (i = high; i > low; i--) //反向冒泡
        {
            if (A[i] < A[i - 1])   //找到剩下中最小的
                Swap(A[i], A[i - 1]);
        }
        low++;
    }
}

int partition(SortType A[], int s, int t)
{
//假设每次都以第一个元素作为枢轴值，进行一趟划分：
    int low = s, high = t;

    SortType tmp = A[low];
    while (low < high) {
        while (high > low && A[high] >= tmp) high--;//从右向左扫描，找一个小于tmp的下标
        A[low] = A[high];//停下来做交换 
        while (low < high && A[low] <= tmp) low++;//从左向右扫描，找一个大于于tmp的下标
        A[high] = A[low];//停下来做交换 
    }
    A[low] = tmp;//tmp的最终落点 
    return low;
}

void QSort(SortType A[], int s, int t)
{
  int i;
    if (s < t) {
        i = partition(A, s, t);
        QSort(A, s, i - 1);
        QSort(A, i + 1, t);
    }
}

void QuickSort(SortType A[], int n)
{
    QSort(A, 0, n - 1);
}

void IterQuickSort(SortType A[], int n){
    //手动利用栈来存储每次分块快排的起始点
    //栈非空时循环获取中轴入栈
    stack<int> s;
    int left = 0, right = n - 1;
    if (left < right){
        int boundary = partition(A, left, right);

        if (boundary - 1 > left){ //确保左分区存在 
            //将左分区端点入栈 
            s.push(left);
            s.push(boundary - 1);
        }
        if (boundary + 1 < right){ //确保右分区存在 
            s.push(boundary + 1);
            s.push(right);
        }
        while (!s.empty()){
            //得到某分区的左右边界 
            int r = s.top();
            s.pop();
            int l = s.top();
            s.pop();

            boundary = partition(A, l, r);
            if (boundary - 1 > l){ //确保左分区存在 
                //将左分区端点入栈 
                s.push(l);
                s.push(boundary - 1);
            }
            if (boundary + 1 < r){ //确保右分区存在 
                s.push(boundary + 1);
                s.push(r);
            }
        }
    }
}
/*	基准的选择
一种选择基准的通用方法是采用三数取中规则，
即选取子列表的第一个、中间一个和最后一个
元素的中间一个来作为基准。事实上，许多列
表都是部分有序的，此时三数取中规则很有可
能选出一个与子列表的中位数相近的基准数字，
而不再是“首元素”规则。
*/
//三数取中
int GetMid(SortType A[], int left, int right)
{
    int mid = left + ((right - left)/2);
    if (A[left] <= A[right]){
        if (A[mid] < A[left])
            return left;
        else if (A[mid] > A[right])
            return right;
        else
            return mid;
    }
    else{
        if (A[mid] < A[right])
            return right;
        else if (A[mid] > A[left])
            return left;
        else
            return mid;
    }
}

int PartSort1(SortType A[], int left, int right)
{
    int mid = GetMid(A, left, right);
    Swap(A[mid], A[right]);

    int& key = A[right];
    while (left < right)
    {
        while (left < right && A[left] <= key)//因为有可能有相同的值，防止越界，所以加上left < right
            ++left;
        while (left < right && A[right] >= key)
            --right;

        Swap(A[left], A[right]);
    }

    Swap(A[left], key);
    return left;
}

int PartSort2(SortType A[], int left, int right)
{
    int mid = GetMid(A, left, right);//三数取中
    Swap(A[mid], A[right]);

    int key = A[right];
    while (left < right)
    {
        while (left < right && A[left] <= key)
            ++left;
        A[right] = A[left];

        while (left < right && A[right] >= key)
            --right;
        A[left] = A[right];
    }
    A[right] = key;
    return right;
}

int PartSort3(SortType A[], int left, int right)
{
    int mid = GetMid(A, left, right);
    Swap(A[mid], A[right]);
    if (left < right) {
        int key = A[right];
        int cur = left;
        int pre = left - 1;
        while (cur < right)
        {
            while (A[cur] < key && ++pre != cur)
            {
                Swap(A[cur], A[pre]);
            }
            ++cur;
        }
        Swap(A[++pre], A[right]);
        return pre;
    }
    return -1;
}

void QSort_improve(SortType A[], int s, int t)//s为第一个元素下标 t为最后一个元素下标 从0开始
{
 int i,t2=t+1;
 
    if (s < t) {
        if ((t - s + 1) <= 20) InsertSort(A, t+1);
        else {
        i = PartSort2(A, s, t);
        QSort(A, s, i - 1);
        QSort(A, i + 1, t);
        }
    }
}

void QuickSort_improve(SortType A[], int n)
{
    QSort_improve(A, 0, n - 1);
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
