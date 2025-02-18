//
// Created by jagger on 25-2-18.
//
/**
* 字符串与整数处理：输入一个以回车结束且不超过10个字符的字符串，将其中的数字字符取出组成一个整数后输出，其余字符组成一个新的字符串输出。例如：输入“5ab3c4d8h2”，则输出整数53482和字符串“abcdh”。
*/
#include<iostream>
using namespace std;

int main()
{
    string input;
    string str;
    string num;

    cin >> input;
    for (int i = 0; i < input.length(); i++)
    {
        char c = input[i];
        if (c >= '0' && c <= '9') num += c;
        else str += c;
    }
    cout << "num " << num << endl;
    cout << "str " << str << endl;

    return 0;
}
