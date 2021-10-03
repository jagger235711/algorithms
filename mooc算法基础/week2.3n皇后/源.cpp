#include <iostream>
#include <cmath>
using namespace std;
int N;
int queenpos[100];
//用来存放算好的皇后位置。最左上角是(0,0) 
void NQueen(int k);
int main()
{
	cin >> N;
	NQueen(0);
	return 0;
}
void NQueen(int k)//在0~k-1行皇后已经摆好的情况下，摆第k行及其后的皇后 
{
	int i;
	if (k == N) // N 个皇后已经摆好
	{
		for (i = 0; i < N; i++)
			cout << queenpos[i] + 1 << " ";
		cout << endl;
	}
	else
	{
		for (i = 0; i < N; i++)//逐尝试是第k个皇后的位置 
		{
			int j;
			for (j = 0; j < k; j++)//和已经摆好的 k 个皇后的位置比较，看是否冲突
			{
				if (queenpos[j] == i || abs(queenpos[j] - i) == abs(k - j))
				{
					break;//冲突，则试下一个位置
				}
			}
			if (j == k) //当前选的位置 i 不冲突 
			{
				queenpos[k] = i;//将第k个皇后摆放在位置 i
					NQueen(k + 1);
			}
		}
	}
}