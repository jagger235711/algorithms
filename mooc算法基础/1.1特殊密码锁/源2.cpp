//ö��
/*
����
��һ������Ķ���������������n�������İ�ť��ɣ�n<30������ť�а�/͹����״̬�����ְ���ť��ı���״̬��
Ȼ������ͷ�۵��ǣ����㰴һ����ťʱ���������ڵ�������ť״̬Ҳ�ᷴת����Ȼ������㰴��������������ұߵİ�ť���ð�ťֻ��Ӱ�쵽�������ڵ�һ����ť��
��ǰ������״̬��֪����Ҫ����������ǣ���������Ҫ�����ٴΰ�ť�����ܽ�������ת��Ϊ��������Ŀ��״̬��
����
���У�����������0��1��ɵĵȳ��ַ�������ʾ��ǰ/Ŀ��������״̬������0������1����͹��
���
������Ҫ���еİ���ť��������������޷�ʵ��ת�䣬�����impossible��
��������
011
000
�������
1
*/
#include <iostream>
#include<math.h>
#include <string.h>
using namespace std;
void* change(char* p)
{
	if (*(p - 1) != NULL)*(p - 1) = abs(*(p - 1) - 1);
	*p = abs(*p - 1);
	if (*(p + 1) != NULL)*(p + 1) = abs(*(p + 1) - 1);
	return 0;
}
int main()
{
	string lock, passPort;
	cin >> lock >> passPort;
	int len = lock.length();
	int counter = 0;
	for (int i = 0; i < len; i++)
	{
		if (lock[i] != passPort[i])
		{
			counter++;
			if (i == 0) change(&lock[i]);
			else change(&lock[i + 1]);
		}
		else continue;
	}
	if (lock == passPort)
	{
		cout << counter;
	}
	else cout << "impossible";
	return 0;
}