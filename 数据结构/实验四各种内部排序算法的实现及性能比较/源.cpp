#include <iostream>
#include <stdlib.h>
#include <ctime>  
// �й�ʱ�亯����������ο� http://zhidao.baidu.com/question/52856667.html?si=3
#include "SortAlgorithm.h"    //ʵ��ĸ��������㷨��ʵ�ֶ������ͷ�ļ���
#define MAX_SIZE  10000//�����б��ģ
//#define MAX_SIZE  20//�����б��ģ

using namespace std;

int main(int argc, char* argv[])
{

    clock_t start, finish;
    double duration = 0;

    int a[MAX_SIZE];


    srand((unsigned)time(NULL));   //��������ӣ�����ÿ�������������ݲ�ͬ
        for (int i = 0; i < MAX_SIZE; i++)
            a[i] = rand();
        //for (int i = 0; i < MAX_SIZE; i++)
        //    cout << a[i] << " ";
        cout << endl;
            start = clock();
            QuickSort_improve(a, MAX_SIZE);   //�����㷨
            finish = clock();
            duration += (double)(finish - start) / CLOCKS_PER_SEC;
        cout << "The during time is:" << duration << " seconds\n" << endl;


 /*      for (int i = 0; i < MAX_SIZE; i++)
           cout << a[i] << " ";*/



//        for (int j = 1; j <=12 ; j++) {
//
//        srand((unsigned)time(NULL));   //��������ӣ�����ÿ�������������ݲ�ͬ
//        for (int i = 0; i < MAX_SIZE; i++)
//            a[i] = rand();
//      start = clock();
//    for (int k = 0; k < 5; k++) {
//             
//            switch (j){ //�����㷨
//            case 1: InsertSort(a, MAX_SIZE); break;
//            case 2: BinInsertSort(a, MAX_SIZE); break;
//            case 3: ShellSort(a, MAX_SIZE); break;
//            case 4: SelectSort(a, MAX_SIZE); break;
//            case 5: HeapSort(a, MAX_SIZE); break;
//            case 6: BubbleSort(a, MAX_SIZE); break;
//            case 7: BubbleSort_improve(a, MAX_SIZE); break;
//            case 8: BiBubbleSort(a, MAX_SIZE); break;
//            //case 9: QuickSort(a, MAX_SIZE);break;
//            case 10: IterQuickSort(a, MAX_SIZE); break;
//            //case 11: QuickSort_improve(a, MAX_SIZE); break;
//            case 12: MergeSort(a, MAX_SIZE);break;
//            default:
//                break;
//            }
//        }
//        finish = clock();
//        duration += (double)(finish - start) / CLOCKS_PER_SEC;
//    cout << "The during time is:" << duration / 5 << " seconds\n" << endl;
//    duration = 0;
//}

//    bool flag = true;
//    for (int i = 1; i < MAX_SIZE; i++)
//        if (a[i] >= a[i - 1]) flag = true;
//        else flag = false;
//    if (!flag)  cout << "wrong!!" << endl;
//    else  cout << "ok!!" << endl;
    return 0;
}
