/*
����
����ɾ�Ĳ顱�����ݿ�ļ��ֻ�����������������������DataBase[]��ģ��һ�����ݿ⣬��ʵ���⼸�ֹ��ܡ�

1. ����+ p v��������v���뵽DataBase[p]λ���ϣ���֤p���ᳬ�����ݿ�ĩβԪ��λ�ã�

2. ɾ��- p  ����DataBase[p]λ�õ�Ԫ��ɾ������֤p���ᳬ�����ݿ�ĩβԪ��λ�ã�

3. �ģ�* p v����DataBase[p]λ�õ������޸�Ϊv����֤p���ᳬ�����ݿ�ĩβԪ��λ�ã�

4. �飺? v  ������DataBase���Ƿ���ֵΪv��Ԫ�أ������ҳɹ�������״γ���ʱ���±꣬���������Failed����

����
��1��1������N��N<=1000������ʾ����N�β���
��2~N+1�У�ÿ��1�β���
���
����ÿһ�β��Ҳ���������������������ʧ�ܣ������Failed����
ÿ���������ռһ��
��������
6
+ 0 1
+ 0 2
? 2
* 1 3
- 1
? 1
�������
0
Failed
��ʾ
1. ����DataBase[]�е����ݶ�Ϊint
2. ����DataBase[]��ʼΪ��
*/
#include<iostream>
using namespace std;

void add(int* DB, int p, int v);//����+ p v��������v���뵽DataBase[p]λ���ϣ���֤p���ᳬ�����ݿ�ĩβԪ��λ�ã�
void delet(int* DB, int p);//ɾ��- p  ����DataBase[p]λ�õ�Ԫ��ɾ������֤p���ᳬ�����ݿ�ĩβԪ��λ�ã�
void alter(int* DB, int p, int v);//�ģ�* p v����DataBase[p]λ�õ������޸�Ϊv����֤p���ᳬ�����ݿ�ĩβԪ��λ�ã�
int check(int* DB, int v);//�飺? v  ������DataBase���Ƿ���ֵΪv��Ԫ�أ������ҳɹ�������״γ���ʱ���±꣬���������Failed����
int length = 0;

int main() {
	int n;
	int DB[100];
	cin >> n;

	for (int i = 0; i < n; i++) {
		char op;
		cin >> op;
		switch (op)
		{
			int p, v;
		case '+':		
			cin >> p >> v;
			add(DB, p, v);
			break;
		case '-':
			cin >> p;
			delet(DB, p);
			break;
		case '*':
			cin >> p >> v;
			alter(DB, p, v);
			break;
		case '?':
			cin >> v;
			int ans = check(DB, v);
			if (ans == -1)
				cout << "Failed"<<endl;
			else
				cout << ans<<endl;
			break;
		}
	}
	return 0;
}

void add(int* DB, int p, int v)
{
	for (int j = length - 1; j >= p; j--)
		DB[j + 1] = DB[j];
	DB[p] = v;
	length++;
}

void delet(int* DB, int p)
{
	for (int j = p + 1; j <= length - 1; j++)
		DB[j - 1] = DB[j];
	length--;
}

void alter(int* DB, int p, int v)
{
	DB[p] = v;
}

int check(int* DB, int v)
{
	for (int i = 0; i < length; i++)
		if (DB[i] == v) return i;
	return -1;
}
