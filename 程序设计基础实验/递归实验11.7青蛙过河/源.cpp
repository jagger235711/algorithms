/*
描述
有一条河，左边一个石墩(A区)上有编号为1，2，3，4，…，n的n只青蛙，河中有k个荷叶(C区)，还有h个石墩(D区)，右边有一个石墩(B区)，如下图2—5所示。n只青蛙要过河(从左岸石墩A到右岸石墩B)，规则为
(1)石墩上可以承受任意多只青蛙，荷叶只能承受一只青蛙(不论大小)；
(2)青蛙可以：A→B(表示可以从A跳到B，下同)，A→C，A→D，C→B，D→B，D→C，C→D；
(3)当一个石墩上有多只青蛙时，则上面的青蛙只能跳到比它大1号的青蛙上面。
你的任务是对于给出的h，k，计算并输出最多能有多少只青蛙可以根据以上规则顺利过河?

输入
两个数：h k（h<=61,k<=100)
输出
最多能有多少只青蛙可以根据以上规则顺利过河
样例输入
2 3
样例输出
16
算法思想
递归算法
边界条件 d区无石墩
*/
#include<iostream>
using namespace std;
long long passriver(int h, int k)
{
	if (h == 0) return k + 1;
	else return 2*passriver(h - 1, k);
}
int main()
{
	int  h, k;
	cin >> h >> k;
	cout << passriver(h, k);
	return 0;
}