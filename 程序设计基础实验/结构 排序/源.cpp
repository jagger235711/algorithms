/*
描述
有n行数据。每行4个数据。第一个数据是一个字符串（字符串长度不超过10个字符，字符串中没有空格），代表同学的名字，接下来有3个整数，分别是数学，英语和程序设计课的成绩。
输入
第一行是一个整数n，表示以下会有n行。每行4个数据。第一个数据是一个字符串（字符串长度不超过10个字符），代表同学的名字，接下来有3个整数，分别是数学，英语和程序设计课的成绩。
输出
按平均成绩，从高到低输出同学们的名次和信息。每行输出一个同学的信息，每个数据之间以空格隔开。如果有几位同学平均成绩相等，则按原名单中的顺序输出(即平均成绩相等的同学，在原名单中先出现的应该先输出)。
样例输入
6
Mary 86 75 90
James 77 80 92
Nancy 80 85 78
John 67 89 95
Annie 90 92 83
Jack 91 80 85
样例输出
1 Annie 90 92 83
2 Jack 91 80 85
3 Mary 86 75 90
4 John 67 89 95
5 James 77 80 92
6 Nancy 80 85 78
算法思想
定义一个结构体
求平均成绩
比较平均成绩
*/
#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
//结构体
typedef struct 
{
	char name[20];
	int math, english, design;
	float everge;
}stu;
int main()
{
	int n;
	cin >> n;
	stu man[31],temp;
	for (int i = 0; i < n; i++)
	{
		cin >> man[i].name >> man[i].math >> man[i].english >> man[i].design;
		man[i].everge = (man[i].math*1.0 + man[i].english*1.0 + man[i].design*1.0) / 3;
	}
	//输入 求平均数
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n - j; i++)
		{
			if (man[i].everge < man[i + 1].everge)
			{
				temp = man[i];
				man[i] = man[i + 1];
				man[i + 1] = temp;
			}
		}
	}
	//冒泡排序 
	for (int i = 0; i < n; i++)
	{
		printf("%d %s %d %d %d \n",i+1, man[i].name, man[i].math, man[i].english, man[i].design);
	}
	//输出
	return 0;
}