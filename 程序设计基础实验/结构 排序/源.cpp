/*
����
��n�����ݡ�ÿ��4�����ݡ���һ��������һ���ַ������ַ������Ȳ�����10���ַ����ַ�����û�пո񣩣�����ͬѧ�����֣���������3���������ֱ�����ѧ��Ӣ��ͳ�����ƿεĳɼ���
����
��һ����һ������n����ʾ���»���n�С�ÿ��4�����ݡ���һ��������һ���ַ������ַ������Ȳ�����10���ַ���������ͬѧ�����֣���������3���������ֱ�����ѧ��Ӣ��ͳ�����ƿεĳɼ���
���
��ƽ���ɼ����Ӹߵ������ͬѧ�ǵ����κ���Ϣ��ÿ�����һ��ͬѧ����Ϣ��ÿ������֮���Կո����������м�λͬѧƽ���ɼ���ȣ���ԭ�����е�˳�����(��ƽ���ɼ���ȵ�ͬѧ����ԭ�������ȳ��ֵ�Ӧ�������)��
��������
6
Mary 86 75 90
James 77 80 92
Nancy 80 85 78
John 67 89 95
Annie 90 92 83
Jack 91 80 85
�������
1 Annie 90 92 83
2 Jack 91 80 85
3 Mary 86 75 90
4 John 67 89 95
5 James 77 80 92
6 Nancy 80 85 78
�㷨˼��
����һ���ṹ��
��ƽ���ɼ�
�Ƚ�ƽ���ɼ�
*/
#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
//�ṹ��
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
	//���� ��ƽ����
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
	//ð������ 
	for (int i = 0; i < n; i++)
	{
		printf("%d %s %d %d %d \n",i+1, man[i].name, man[i].math, man[i].english, man[i].design);
	}
	//���
	return 0;
}