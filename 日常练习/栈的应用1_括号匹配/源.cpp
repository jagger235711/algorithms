#include <iostream>

using namespace std;
bool ismatch(char* s)
{
	char sta[60];
	int top = -1;

	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '(' || s[i] == '[')//当遇到左半括号的时候就入栈
			sta[++top] = s[i];
		//当遇到右半括号，出栈一次，与该括号进行匹配
		else if (s[i] == ')')
		{
			if (top != -1 && sta[top] == '(')//先判断栈是否为空
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
	if (top == -1) return true;//刚好匹配完
	else return false;//左半括号多
}
int main()
{
	char str[60];

	cin >> str;
	if (ismatch(str)) cout << "matched" << endl;
	else cout << "no" << endl;

	return 0;
}
