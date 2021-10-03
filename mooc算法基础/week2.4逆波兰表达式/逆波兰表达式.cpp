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
	default:return atof(s);//C 库函数 double atof(const char *str) 把参数 str 所指向的字符串转换为一个浮点数（类型为 double 型）。
		break;
	}
}
int main()
{
	printf("%lf", exp());
		return 0;
}