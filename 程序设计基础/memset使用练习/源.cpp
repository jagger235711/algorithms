//void* memset(void* dest, int ch, int n)memste�Ķ���
//ע���һ�������ǵ�ַ
#include<iostream>
using namespace std;
int main()
{
	char szName[200] = "";//Ĭ�ϳ�ʼ��Ϊ������/0
	memset(szName, 'a', 10);
	for (int i = 0; i < 200; i++)
	{
		cout << szName[i] << " ";
	}
	return 0;
}
