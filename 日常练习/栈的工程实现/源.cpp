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
    string digitChar = "0123456789ABCDEF";//ʵ�����ֵ��ַ����ת�� 
    string numStr = "";

    //��ʼ����ջ��˳��ջ����ջ��
    do
    {
        push(s, digitChar[num % base]);   //��������ջ
        num /= base;
    } while (num != 0);

    char temp;
    while (!empty(s))
    {
        temp = top(s);   //ȡջ��
        pop(s);         //��ջ
        numStr += temp;  //��������ջ������numStr�ַ�����
    }
    return numStr;
}

