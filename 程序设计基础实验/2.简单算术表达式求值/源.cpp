
#include<iostream>

using namespace std;

int a, b;

char c;

int main()

{

	cin >> a >> c >> b;//cin�����Զ�ȥ���ո� 

	switch (c)

	{

	case '+':cout << a + b << endl; break;

	case '-':cout << a - b << endl; break;

	case '*':cout << a * b << endl; break;

	case '/':cout << a / b << endl; break;

	case '%':cout << a % b << endl; break;

	}

	return 0;

}
