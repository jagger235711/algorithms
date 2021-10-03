#include <iostream>

using namespace std;
bool ismatch(char* s)
{
	char sta[60];
	int top = -1;

	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '(' || s[i] == '[')//������������ŵ�ʱ�����ջ
			sta[++top] = s[i];
		//�������Ұ����ţ���ջһ�Σ�������Ž���ƥ��
		else if (s[i] == ')')
		{
			if (top != -1 && sta[top] == '(')//���ж�ջ�Ƿ�Ϊ��
				top--;
			else 	return false;
		}
		else if (s[i] == ']')
		{
			if (top != -1 && sta[top] == '[')
				top--;
			else 	return false;
		}
	}
	if (top == -1) return true;//�պ�ƥ����
	else return false;//������Ŷ�
}
int main()
{
	char str[60];

	cin >> str;
	if (ismatch(str)) cout << "matched" << endl;
	else cout << "no" << endl;

	return 0;
}
