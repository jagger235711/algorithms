#include <iostream>
#include <stdio.h>

using namespace std;
const int RN = 4, CN = 4;
int mg[RN + 2][CN + 2] = //+2是围墙 1表示不能走
                         { {1, 1, 1, 1, 1, 1},
						   {1, 0, 0, 0, 1, 1},
						   {1, 0, 1, 0, 0, 1},
						   {1, 0, 0, 0, 1, 1},
						   {1, 1, 0, 0, 0, 1},
						   {1, 1, 1, 1, 1, 1} };
typedef struct
{
	int x, y, di;//di是下一个相邻可走方块的方位号
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
void mgpath(int x, int y)//x y 起点坐标
{
	BOX s[20];
	BOX path[20], e;
	int top = -1;
	int count = 0;

	e.x = x, e.y = y, e.di = -1;
	mg[x][y] = -1;
	s[++top] = e;
	//先把起点放进栈里
	int di;//用di来控制重新走已经探索过的路径
	while (top != -1)
	{
		e = s[top];
		x = e.x, y = e.y, di = e.di;
		if (x == ex && y == ey)//当走到终点了
		{
			count++;
			printf("第%d条路径为：", count);
			for (int i = 0; i <= top; i++)
				printf("(%d, %d) ", s[i].x, s[i].y);
			cout << endl;
			top--;
			mg[x][y] = 0;
		}
		else
		{
			// di的相邻可走方向探索
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
			// 有相邻方向，修改栈顶方向，向相邻方向走一步
			if (find)
			{
				s[top].di = d;
				e.x = x1, e.y = y1, e.di = -1;
				s[++top] = e;
				mg[x1][y1] = -1;
			}
			// 没有，回溯
			else
			{
				top--;
				mg[x][y] = 0;
			}
		}
	}
}
