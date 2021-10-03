#include <iostream>
#include <stdlib.h>
#include <ctime>  
// �й�ʱ�亯����������ο� http://zhidao.baidu.com/question/52856667.html?si=3
#include "SortAlgorithm.h"    //ʵ��ĸ��������㷨��ʵ�ֶ������ͷ�ļ���
#define MAX_SIZE  10000 //�����б��ģ
using namespace std;

int main(int argc, char* argv[])
{

    clock_t start, finish;
    double duration=0;

    int a[MAX_SIZE];
    srand((unsigned)time(NULL));   //��������ӣ�����ÿ�������������ݲ�ͬ
    for (int k = 0; k < 5; k++) {
   for (int i = 0; i < MAX_SIZE; i++)
        a[i] = rand();
    start = clock();
    SelectSort(a,MAX_SIZE);   //�����㷨
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
    //     NaturalMergeSort(a, MAX_SIZE);   //�����㷨
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
