#include <iostream>
#include <stdlib.h>
#include <ctime>  
// 有关时间函数的内容请参考 http://zhidao.baidu.com/question/52856667.html?si=3
#include "SortAlgorithm.h"    //实验的各个排序算法的实现都放入此头文件中
#define MAX_SIZE  10000 //排序列表规模
using namespace std;

int main(int argc, char* argv[])
{

    clock_t start, finish;
    double duration=0;

    int a[MAX_SIZE];
    srand((unsigned)time(NULL));   //随机数种子，这样每次运行序列内容不同
    for (int k = 0; k < 5; k++) {
   for (int i = 0; i < MAX_SIZE; i++)
        a[i] = rand();
    start = clock();
    SelectSort(a,MAX_SIZE);   //排序算法
    finish = clock();
    duration += (double)(finish - start) / CLOCKS_PER_SEC;
    }
    cout << "The during time is:" << duration/5 << " seconds\n" << endl;

    // for (int i = 0; i < MAX_SIZE; i++)
    //     a[i] = rand();
    // for (int i = 0; i < MAX_SIZE; i++)
    //     cout << a[i] << " ";
    // cout << endl;
    //     start = clock();
    //     NaturalMergeSort(a, MAX_SIZE);   //排序算法
    //     finish = clock();
    //     duration += (double)(finish - start) / CLOCKS_PER_SEC;
    // cout << "The during time is:" << duration << " seconds\n" << endl;

    //for (int i = 0; i < MAX_SIZE; i++)
    //    cout << a[i] << " ";

    bool flag = true;
    for (int i = 0; i < MAX_SIZE-1; i++)
        if (a[i] > a[i + 1]) flag = false;
    if (!flag)  cout << "wrong!!" << endl;
    else  cout << "ok!!" << endl;
    return 0;
}
