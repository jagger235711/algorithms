#include <iostream>
#include<stdio.h>
#include<assert.h>
using namespace std;
typedef struct tagTeacher {//�ṹ���ǩ
	int id;
	string dept;
	string name;
	string sex;
}_teacher;
typedef struct tagSubject {//�ṹ���ǩ
	int id;
	string name;
	int amount;
}_subject;
typedef struct tagClassroom {//�ṹ���ǩ
	int id;
	string className;
	int amount;
}_classroom;
//bool readerAndWriter(bool flag) {
//	//���ļ�
//	FILE* r = fopen("�࿼��Ա����.txt", "r");
//	assert(r != NULL);//���Ժ����������ڵ��Թ����в�׽����Ĵ���
//
//	//��д�ļ�
//	_teacher teacher[80];
//	int i=0;
//	while (fscanf(r,"%d %s %s %s",teacher[i].id,teacher[i].dept,teacher[i].name, teacher[i].sex)!=EOF)
//	{
//		printf("%d %s %s %s", teacher[i].id, teacher[i].dept, teacher[i].name, teacher[i].sex);//�������ʾ����Ļ
//		i++;
//	}
//	return false;
//}


int main() {

	//���ļ�
	FILE* r;
	fopen_s(&r, "�࿼��Ա����.txt", "r");
	assert(r != NULL);//���Ժ����������ڵ��Թ����в�׽����Ĵ���

	//��д�ļ�
	_teacher teacher[80];
	int i = 0;
	while (fscanf(r, "%d %s %s %s", &teacher[i].id, &teacher[i].dept, &teacher[i].name, &teacher[i].sex) != EOF)
	{
		printf("%d %s %s %s", &teacher[i].id, &teacher[i].dept, &teacher[i].name, &teacher[i].sex);//�������ʾ����Ļ
		i++;
	}
	return 0;
}