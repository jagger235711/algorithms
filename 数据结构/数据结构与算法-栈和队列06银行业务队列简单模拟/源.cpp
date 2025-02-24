/*
描述
设某银行有A、B两个业务窗口，且处理业务的速度不一样，其中A窗口处理速度是B窗口的2倍---即当A窗口处理完2个顾客时，B窗口处理完一个顾客。给定到达银行的顾客序列，请按业务完成的顺序输出顾客序列。假定不考虑顾客先后到达的时间间隔，并且当不同窗口同时处理完2个顾客时，A窗口顾客优先输出。

输入
输入为一行正整数，其中第1个数字N（N<=1000）为顾客总数，后面跟着N位顾客的编号。编号为奇数的顾客需要到A窗口办理业务，为偶数的顾客则去B窗口。数字间以空格分隔。
输出
按业务处理完成的顺序输出顾客的编号。数字间以空格分隔，但最后一个编号后不能有多余的空格。
样例输入
8 2 1 3 9 4 11 13 15
样例输出
1 3 2 9 11 4 13 15
处理方式
队列
算法思想
创建两个队列A、B用以存放顾客编号
判断奇数偶数，存入队列
模拟处理过程。当A输出两个，B输出一个
*/
#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int N;
	queue<int>A, B;//队列A、B用以存放顾客编号
	cin >> N;
	//入队
	for (int i = 0; i < N; i++) {
		int customer;
		cin >> customer;
		if (customer % 2 == 0) {//偶数
			B.push(customer);
		}
		else {//奇数
			A.push(customer);
		}
	}
	//模拟处理过程且出队
	for (int i = 0; i < N; i++) {
		if (!A.empty()&&(i+1)%3!=0 ) {//奇数
			cout<<A.front();
			A.pop();
		}
		else {//偶数
			cout << B.front();
			B.pop();
		}
		if (i < N - 1) {
			cout << " ";
		}
	}
	return 0;
}