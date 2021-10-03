#include<iostream>
#include <string> 
using namespace std;
typedef char ElemType;
//#define MSize 20;
constexpr auto MSize = 20;

typedef struct {
	ElemType data[MSize];
	int top;
}sqStack;
void InitStack(sqStack*& p) {
	p = new sqStack();
	p->top = -1;
}
bool empty(sqStack p) {
	if (p.top == -1)
		return true;
	else
		return false;
}
int size(sqStack* p) {
	return p->top + 1;
}
void pop(sqStack& p) {
	if (p.top != -1) {
		p.top--;
	}
}
ElemType top(sqStack p) {
	if (p.top != -1) {
		return p.data[p.top];
	}
}

void push(sqStack& p, ElemType x)
{
	if (p.top != MSize - 1) {
		p.top++;
		p.data[p.top] = x;
	}
}
sqStack stk;
string dec2base(int num, int base)
{ //��ʮ����ת��Ϊ�����������������2��16֮�䣩
  //string��C++�Ĵ��࣬��Ҫ #include <string> 

    string digitChar = "0123456789ABCDEF";//ʵ�����ֵ��ַ����ת�� 
    string numStr = "";

    //��ʼ����ջ��˳��ջ����ջ��
        do
        {
            push(stk, digitChar[num % base]);   //��������ջ
            num /= base;
        } while (num != 0);

        char temp;
        while (!empty(stk))
        {
            temp = top(stk);   //ȡջ��
            pop(stk);         //��ջ
            numStr += temp;  //��������ջ������numStr�ַ�����
        }
        return numStr;
}
int main() {
	int num, base;
	cin >> num >> base;
	cout << dec2base(num, base);
	return 0;
}
