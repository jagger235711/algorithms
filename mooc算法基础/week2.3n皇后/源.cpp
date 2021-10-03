#include <iostream>
#include <cmath>
using namespace std;
int N;
int queenpos[100];
//���������õĻʺ�λ�á������Ͻ���(0,0) 
void NQueen(int k);
int main()
{
	cin >> N;
	NQueen(0);
	return 0;
}
void NQueen(int k)//��0~k-1�лʺ��Ѿ��ںõ�����£��ڵ�k�м����Ļʺ� 
{
	int i;
	if (k == N) // N ���ʺ��Ѿ��ں�
	{
		for (i = 0; i < N; i++)
			cout << queenpos[i] + 1 << " ";
		cout << endl;
	}
	else
	{
		for (i = 0; i < N; i++)//�����ǵ�k���ʺ��λ�� 
		{
			int j;
			for (j = 0; j < k; j++)//���Ѿ��ںõ� k ���ʺ��λ�ñȽϣ����Ƿ��ͻ
			{
				if (queenpos[j] == i || abs(queenpos[j] - i) == abs(k - j))
				{
					break;//��ͻ��������һ��λ��
				}
			}
			if (j == k) //��ǰѡ��λ�� i ����ͻ 
			{
				queenpos[k] = i;//����k���ʺ�ڷ���λ�� i
					NQueen(k + 1);
			}
		}
	}
}