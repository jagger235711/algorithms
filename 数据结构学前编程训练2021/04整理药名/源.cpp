/*
����
ҽ������дҩƷ����ʱ�򾭳���ע���Сд����ʽ�Ƚϻ��ҡ���Ҫ����дһ������ҽ����д���ҵ�ҩƷ�������ͳһ�淶�ĸ�ʽ����ҩƷ���ĵ�һ���ַ��������ĸҪ��д��������ĸСд���罫ASPIRIN��aspirin�����Aspirin��

����
��һ��һ������n����ʾ��n��ҩƷ��Ҫ����n������100��
������n�У�ÿ��һ�����ʣ����Ȳ�����20����ʾҽ�������ҩƷ����ҩƷ������ĸ�����ֺ�-��ɡ�
���
n�У�ÿ��һ�����ʣ���Ӧ�����ҩƷ���Ĺ淶д����
��������
4
AspiRin
cisapride
2-PENICILLIN
Cefradine-6
�������
Aspirin
Cisapride
2-penicillin
Cefradine-6
1.�ҵ���һ���ַ�
2.�ж��Ƿ�����ĸ
3.��Сдת��
*/
#include<iostream>
using namespace std;

const int N = 100;
char medname[N][20 + 1];//�����ݱ�š������������ݡ�
void modify(char s[][20 + 1], int n);

int main() {
	int n;
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> medname[i];

	modify(medname, n);
	for (int i = 0; i < n; i++)
		cout << medname[i] << endl;

	return 0;
}

void modify(char s[][20 + 1], int n)
{
	for (int i = 0; i < n; i++) {
		if (s[i][0] >= 'a' && s[i][0] <= 'z')
			s[i][0] = s[i][0] - 'a' + 'A';
		for (int j = 1; s[i][j]; j++)
			if (s[i][j] >= 'A' && s[i][j] <= 'Z')
				s[i][j] = s[i][j] - 'A' + 'a';
	}
}