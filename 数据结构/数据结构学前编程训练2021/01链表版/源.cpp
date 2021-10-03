/*
描述
定义一个含10个元素的整型数组，从键盘输入数组所有元素的值，并求该数组中的最小值和最小值的下标。如果最小值在数组中出现多次，输出最小的那个下标。

输入
10个整数
输出
最小值和最小值的下标。如果最小值在数组中出现多次，输出最小的那个下标。
样例输入
5 4 6 3 1 8 9 7 15 34
样例输出
The minimum number is 1.
It's subscript is 4.
创建链表储存输入数字
用循环查出最小值并储存最小下标
输出
*/
#include<iostream>
using namespace std;
typedef int ElemType;

typedef struct LNode {
	ElemType data;//存放元素值
	struct LNode* next;//指向后继结点
}LinkNode;//单链表结点类型
void CreateListF(LinkNode*& L, ElemType a[], int n) {//linknode * &L,即引用了这个结构体指针类型的变量L，引用L则会改变L
	LinkNode* s;
	//L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;//创建头结点，其next域置为NULL
	for (int i = 0; i < n; i++)//循环建立数据结点s
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];//创建数据结点s
		s->next = L->next;//将结点s插入到原首结点之前，头结点之后
		L->next = s;
	}
}

int main() {

	return 0;
}