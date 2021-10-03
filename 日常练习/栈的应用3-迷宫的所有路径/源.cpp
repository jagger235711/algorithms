#include <iostream>
#include <stdio.h>

using namespace std;
const int RN = 4, CN = 4;
int mg[RN + 2][CN + 2] = //+2��Χǽ 1��ʾ������
                         { {1, 1, 1, 1, 1, 1},
						   {1, 0, 0, 0, 1, 1},
						   {1, 0, 1, 0, 0, 1},
						   {1, 0, 0, 0, 1, 1},
						   {1, 1, 0, 0, 0, 1},
						   {1, 1, 1, 1, 1, 1} };
typedef struct
{
	int x, y, di;//di����һ�����ڿ��߷���ķ�λ��
}BOX;
int xd[] = { -1, 0, 1, 0 };
int yd[] = { 0, 1, 0, -1 };
int sx, sy, ex, ey;
void mgpath(int x, int y);

int main(void)
{
	cin >> sx >> sy >> ex >> ey;
	mgpath(sx, sy);

	return 0;
}
void mgpath(int x, int y)//x y �������
{
	BOX s[20];
	BOX path[20], e;
	int top = -1;
	int count = 0;

	e.x = x, e.y = y, e.di = -1;
	mg[x][y] = -1;
	s[++top] = e;
	//�Ȱ����Ž�ջ��
	int di;//��di�������������Ѿ�̽������·��
	while (top != -1)
	{
		e = s[top];
		x = e.x, y = e.y, di = e.di;
		if (x == ex && y == ey)//���ߵ��յ���
		{
			count++;
			printf("��%d��·��Ϊ��", count);
			for (int i = 0; i <= top; i++)
				printf("(%d, %d) ", s[i].x, s[i].y);
			cout << endl;
			top--;
			mg[x][y] = 0;
		}
		else
		{
			// di�����ڿ��߷���̽��
			int d, x1, y1;
			bool find = false;
			for (d = di + 1; !find && d <= 3; d++)
			{
				x1 = x + xd[d];
				y1 = y + yd[d];
				if (mg[x1][y1] == 0)
				{
					find = true;
					break;
				}
			}
			// �����ڷ����޸�ջ�����������ڷ�����һ��
			if (find)
			{
				s[top].di = d;
				e.x = x1, e.y = y1, e.di = -1;
				s[++top] = e;
				mg[x1][y1] = -1;
			}
			// û�У�����
			else
			{
				top--;
				mg[x][y] = 0;
			}
		}
	}
}
