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
��һ������ȷ������ô���״̬��ȷ����
*/
#include <iostream>
#include<math.h>
#include <string.h>
using namespace std;
void FlipLock(int u,int len,int *p)//���ô���
{
	if (u>0)
	{
		*(p - 1) = abs(*(p-1) - 1);
	}
	*(p) = abs(*p - 1);
	if (u <len-1)
	{
		*(p + 1) = abs(*(p + 1) - 1);
	}
}

int main()
{
	string lock, passPort;
	cin >> lock >> passPort;
	int len = lock.length();
	int Lock[30], Passport[30];
	//ת��Ϊ����
	for (int i = 0; i < len; i++)
	{
		Lock[i] = lock[i] - '0';
		Passport[i] = passPort[i] - '0';
	}

	int counter = 0;
	for (int i = 0; i < len; i++)
	{
		if (Lock[i] != Passport[i])
		{
			counter++;
			FlipLock(i+1, len, &Lock[i+1]);//�����ͬ���ĺ�һ����ť
		}
		else continue;
	}

	int t;
	for ( t=0;t<len;t++)
	{
		if (!(Lock[t] == Passport[t])) break;
	}
	if (t == len ) cout << counter;
	else cout << "impossible";
	return 0;
}