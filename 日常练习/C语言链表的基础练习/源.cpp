/*
����Ļ�����ϰ��ʵ��һ�������������Ĳ��룬���ң�ɾ��
1������һ������
2���������ѹ��һ���ݣ���ӵ�����ͷ��
3���������ѹ��һ���ݣ���ӵ�����β��
4��������ͷ����Ա����
5���ͷ�����
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
    printf("***** 1               ��ʾȫ������ *****\n");
    printf("***** 2               ͷ��������� *****\n");
    printf("***** 3               ĩβ������� *****\n");
    printf("***** 4               ɾ��ͷ������ *****\n");
    printf("***** 5               �ͷ��������� *****\n");
    printf("****************************************\n");
}

int main() {
    int choice;

    struct strdent* pNew, * pTail, * head = NULL;

    struct strdent* p1 = NULL, * p4 = NULL, * p5 = NULL;

    pNew = (struct student*)malloc(sizeof(struct student));

    printf("����������������������봴��һ������\n");
    scanf("%s%d%f", pNew->name, &pNew->age, &pNew->socre);


    return 0;
}