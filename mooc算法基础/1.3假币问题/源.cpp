/*
枚举
例题3：假币问题
有12枚硬币。其中有11枚真币和1枚假币。假币和真币重量不同，但不知道假币比真币轻还是重。现在，用一架天平称了这些币三次，告诉你称的结果，
请你找出假币并且确定假币是轻是重（数据保证一定能找出来）。

输入第一行是测试数据组数。
每组数据有三行，每行表示一次称量的结果。银币标号为 A-L。每次称量的结果用三个以空格隔开的字符串表示：天平左边放置的硬币 天平右边放置的
硬币 平衡状态。其中平衡状态用``up'', ``down'', 或 ``even''表示, 分别为右端高、右端低和平衡。天平左右的硬币数总是相等的。
输出输出哪一个标号的银币是假币，并说明它比真币轻还是重。
输入样例
1
ABCD EFGH even
ABCI EFJK up
ABIJ EFGH even
输出样例
K is the counterfeit coin and it is light.
*/
#include <iostream>
#include <string>
using namespace std;
char Left[3][7], Right[3][7], Result[3][7];
bool IsFake(char c,bool light);
int main()
{
	int t;
	cin >> t;
	for (int p = 0; p < t; p++)
	{
/*		string left[3], right[3],result[3];这里用char好一点，因为之后要进行每个字母的检索*/
		for (int i=0;i<3;i++)
		{
			cin >> Left[i] >> Right[i] >> Result[i];
		}
		for (char c='A';c<='L';c++)
		{
			if (IsFake(c,true))
			{
				cout << c << "is the counterfeit coin and it is light.\n";
					break;
			}
			else if(IsFake(c,false))
			{
				cout << c << " is the counterfeit coin and it is heavy.\n";
				break;
			}
		}
	}
	return 0;
}
bool IsFake(char c, bool light)
{
	for (int i = 0; i < 3; i++)
	{
		char* pLeft, * pRight;
		if (light)
		{
			pLeft = Left[i];
			pRight = Right[i];
		}
		else
		{
			pLeft = Right[i];
			pRight = Left[i];
		}
		switch (Result[i][0])
		{
		case 'u':
			if (strchr(pRight, c) == NULL) return false;
			break;
		case 'e':
			if (strchr(pRight, c) || strchr(pLeft, c)) return false;
			break;
		case 'd':
			if (strchr(pLeft, c) == NULL) return false;
			break;
		}
	}
	return true;
}