/*描述
你将产生的程序的目标是计算布尔表达式如下图所示:
表达式:(V | V) & F & (F | V)
其中V为真，F为假。表达式可能包括以下操作符:!for not， & for and， | for or，也允许使用圆括号进行操作分组。
要执行表达式的计算，它将被认为是操作符的优先级，没有最高的操作符，和最低的操作符。程序必须生成V或F，作为输入文件中每个表达式的结果。
输入
表达式的长度是可变的，但不会超过100个符号。符号可以由任意数量的空格分隔，也可以完全没有空格，因此，表达式的总长度(作为字符的数量)是未知的。
输入文件中的表达式数量是可变的，并且永远不会大于20。每个表达式在一个新行中显示，如下所示。
输出
对于每个测试表达式，打印“表达式”及其序列号“:”，以及相应测试表达式的结果值。用新行分隔连续测试表达式的输出。
使用与下面示例输出相同的格式。
样例输入
(V | V) & F & (F| V)
V | V & V & !F & (F | V) & (!F | F | !V & V)
V (F&F | | ! V ! F (F | F&V))
样例输出
表达式1:F
表达式2:V
表达式3:V*/
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
char s[100005] = { 0 };
int cnt = 0;
bool expression_bool();
bool term_bool();
bool factor_bool();
int main()
{
    int k = 0;
    while (cin.getline(s, 100000))
    {
        char t[100001] = { 0 };
        int len = strlen(s);
        for (int i = 0, k = 0; i < len; i++)
        {
            if (s[i] != ' ')
                t[k++] = s[i];
        }

        len = strlen(t);
        for (int i = 0; i < len; i++)
            s[i] = t[i];
        s[len] = '\0';

        cout << "Expression " << ++k << ": " << (expression_bool() ? "V" : "F") << endl;
        cnt = 0;
        memset(s, 0, sizeof(s));
    }
    return 0;
}
bool expression_bool()
{
    bool result = term_bool();
    bool more = true;
    while (more)
    {
        char op = s[cnt];
        if (op == '&' || op == '|')
        {
            cnt++;
            bool value = term_bool();
            if (op == '&')
                result = result & value;
            else
                result = result | value;
        }
        else
            more = false;
    }
    return result;

}
bool term_bool()
{
    bool result;
    char op = s[cnt];
    if (op == '!')
    {
        cnt++;
        result = !factor_bool();
    }
    else
        result = factor_bool();
    return result;
}
bool factor_bool()
{
    bool result;
    char c = s[cnt];
    if (c == '(')
    {
        cnt++;
        result = expression_bool();
        cnt++;
    }
    else if (c == 'V')
    {
        result = true;
        cnt++;
    }
    else if (c == 'F')
    {
        result = false;
        cnt++;
    }
    else if (c == '!')
        result = term_bool();

    return result;
}