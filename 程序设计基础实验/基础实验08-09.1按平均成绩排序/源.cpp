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
struct stu
{
	string name;
	float math, english, design;
	float everge;
};
int main()
{
	int n;
	cin >> n;
	struct stu man[31];
	for (int i = 0; i < n; i++)
	{
		scanf("%s %d %d %d", man[i].name, man[i].math, man[i].english, man[i].design);
		man[i].everge=(man[i].math+man[i].english+man[i].design)/3
	}
	for (int i = 0; i < n; i++)
	{
		printf("%s %d %d %d %d", man[i].name, man[i].math, man[i].english, man[i].design, man[i].everge);
	}
	return 0;
}