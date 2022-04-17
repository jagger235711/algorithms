#include <iostream>
#include<stdio.h>
#include<assert.h>
using namespace std;
typedef struct tagTeacher {//结构体标签
	int id;
	string dept;
	string name;
	string sex;
}_teacher;
typedef struct tagSubject {//结构体标签
	int id;
	string name;
	int amount;
}_subject;
typedef struct tagClassroom {//结构体标签
	int id;
	string className;
	int amount;
}_classroom;
//bool readerAndWriter(bool flag) {
//	//打开文件
//	FILE* r = fopen("监考人员名单.txt", "r");
//	assert(r != NULL);//断言函数，用于在调试过程中捕捉程序的错误。
//
//	//读写文件
//	_teacher teacher[80];
//	int i=0;
//	while (fscanf(r,"%d %s %s %s",teacher[i].id,teacher[i].dept,teacher[i].name, teacher[i].sex)!=EOF)
//	{
//		printf("%d %s %s %s", teacher[i].id, teacher[i].dept, teacher[i].name, teacher[i].sex);//输出到显示器屏幕
//		i++;
//	}
//	return false;
//}


int main() {

	//打开文件
	FILE* r;
	fopen_s(&r, "监考人员名单.txt", "r");
	assert(r != NULL);//断言函数，用于在调试过程中捕捉程序的错误。

	//读写文件
	_teacher teacher[80];
	int i = 0;
	while (fscanf(r, "%d %s %s %s", &teacher[i].id, &teacher[i].dept, &teacher[i].name, &teacher[i].sex) != EOF)
	{
		printf("%d %s %s %s", &teacher[i].id, &teacher[i].dept, &teacher[i].name, &teacher[i].sex);//输出到显示器屏幕
		i++;
	}
	return 0;
}