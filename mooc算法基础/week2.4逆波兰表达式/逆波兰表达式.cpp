#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
double exp()
{
	char s[20];
	cin >> s;
	switch (s[0])
	{
	case '+':return exp() + exp();
	case '-':return exp() - exp();
	case '*':return exp() * exp();
	case '/':return exp() / exp();
	default:return atof(s);//C �⺯�� double atof(const char *str) �Ѳ��� str ��ָ����ַ���ת��Ϊһ��������������Ϊ double �ͣ���
		break;
	}
}
int main()
{
	printf("%lf", exp());
		return 0;
}