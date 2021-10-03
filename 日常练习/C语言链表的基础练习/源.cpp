/*
链表的基础练习：实现一个链表，完成链表的插入，查找，删除
1、申请一个链表
2、向队列中压入一数据，添加到队列头部
3、向队列中压入一数据，添加到队列尾部
4、将队列头部成员出列
5、释放链表
*/
#include<stdio.h>
#include<stdlib.h>

struct student
{
	char name[20];
	int age;
	float score;

	struct student* next;
};

void showOP()
{
    printf("****************************************\n");
    printf("***** 1               显示全部数据 *****\n");
    printf("***** 2               头部添加数据 *****\n");
    printf("***** 3               末尾添加数据 *****\n");
    printf("***** 4               删除头部数据 *****\n");
    printf("***** 5               释放整个链表 *****\n");
    printf("****************************************\n");
}

int main() {
    int choice;

    struct strdent* pNew, * pTail, * head = NULL;

    struct strdent* p1 = NULL, * p4 = NULL, * p5 = NULL;

    pNew = (struct student*)malloc(sizeof(struct student));

    printf("请先输入姓名，年龄和收入创建一个链表\n");
    scanf("%s%d%f", pNew->name, &pNew->age, &pNew->socre);


    return 0;
}