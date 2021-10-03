#include <iostream>
#include "sqstack.h" 
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

string dec2base(int num, int base);

int main(int argc, char** argv)
{
    //	SqStack s;

    //	init(s);
    //	int x; 
    //	while (1)
    //	{
    //		cin>>x;
    //		if(x==0) break;
    //	//	push(s, x); 
    //	} 
    //	
    //	pop(s);
    //	cout << top(s);   
    while (1)
    {
        int s;
        int x;
        cin >> s >> x;
        cout << dec2base(s, x);
    }

    return 0;

}
SqStack s;
string dec2base(int num, int base)
{
    string digitChar = "0123456789ABCDEF";//实现数字到字符间的转换 
    string numStr = "";

    //初始化空栈（顺序栈或链栈）
    do
    {
        push(s, digitChar[num % base]);   //将余数入栈
        num /= base;
    } while (num != 0);

    char temp;
    while (!empty(s))
    {
        temp = top(s);   //取栈顶
        pop(s);         //出栈
        numStr += temp;  //将余数出栈并附到numStr字符串中
    }
    return numStr;
}

