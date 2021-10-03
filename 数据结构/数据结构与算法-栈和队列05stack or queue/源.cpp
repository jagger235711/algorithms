/*
描述
栈和队列都是常用的线性结构，它们都提供两个操作：

Push：加入一个元素。

Pop：弹出一个元素。

不同的是，栈是”先进后出”，而队列则是”先进先出”。

给出一个线性结构的进出顺序，判定这个结构是栈还是队列。

输入
第一行输入一个整数t，代表有t组测试数据
对于每组测试数据，第一行输入一个整数n，代表操作的次数。
随后输入n行，每行包含两个整数 type val。
当type = 1时，表示该次操作为push操作，val表示进入的数字。当type=2时，表示该次操作为pop操作，val代表出来的数字。
3<=n<=2000
输出
每组测试数据输出一行。
输出改组数据对应的线性结构，”Stack” 或者 “Queue”。
题目保证是栈或者队列的一种。
样例输入
2
6
1 1
1 2
1 3
2 3
2 2
2 1
4
1 1
1 2
2 1
2 2
样例输出
Stack
Queue
本题主要考查栈和队列的基本性质。我们可以发现，对于栈而言，第一个序列和第二个序列是完全相反的。对于队列而言，第一个序列和第二个序列式完全一样的。 这样我们通过两个判断就可以的出正确的答案。
1、运用模拟的方法来做
*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void stackqueue();

int main()
{

	int n;
	cin >> n;
	while (n--)
	{
		stackqueue();
	}
	return 0;
}

void stackqueue()
{
	stack<int> s;
	queue<int> q;
	int m, * t, * d;

	cin >> m;//读入指令数 
	t = new int[m]; d = new int[m];

	for (int i = 0; i < m; i++) cin >> t[i] >> d[i];//读入操作及数 
	for (int i = 0; i < m; i++)
	{
		if (t[i] == 1)
		{
			s.push(d[i]); q.push(d[i]);
		}
		else if (t[i] == 2)
		{
			if ((d[i] == s.top()) && (d[i] != q.front()))
			{
				cout << "Stack\n"; return;
			}
			else if ((d[i] != s.top()) && (d[i] == q.front()))
			{
				cout << "Queue\n"; return;
			}
			else
			{
				s.pop(); q.pop();
			}
		}

	}
}
