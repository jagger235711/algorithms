#include<iostream>
using namespace std;

#define MaxSize 50
typedef int ElemType;

struct {
	ElemType data[MaxSize];//存放线性表中的元素
	int length;//线性表的长度
}SqList;//声明一个结构体变量

//建立顺序表
void CreateList(SqList*& L, ElemType a[], int n) { //通过指针间接提供顺序表
	int i = 0, k = 0;//k为L中元素个数
	L = (SqList*)malloc(sizeof(SqList));//分配存放线性表的空间 （强制类型转换）  malloc（）动态分配空间
	while (i < n) {
		L->data[k] = a[i];
		k++, i++;
	}
	L->length = k;
}
