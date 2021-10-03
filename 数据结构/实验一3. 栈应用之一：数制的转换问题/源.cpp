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
{ //将十进制转换为任意进制数（基介于2和16之间）
  //string是C++的串类，需要 #include <string> 

    string digitChar = "0123456789ABCDEF";//实现数字到字符间的转换 
    string numStr = "";

    //初始化空栈（顺序栈或链栈）
        do
        {
            push(stk, digitChar[num % base]);   //将余数入栈
            num /= base;
        } while (num != 0);

        char temp;
        while (!empty(stk))
        {
            temp = top(stk);   //取栈顶
            pop(stk);         //出栈
            numStr += temp;  //将余数出栈并附到numStr字符串中
        }
        return numStr;
}
int main() {
	int num, base;
	cin >> num >> base;
	cout << dec2base(num, base);
	return 0;
}
