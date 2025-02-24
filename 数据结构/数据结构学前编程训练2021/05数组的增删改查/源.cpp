/*
描述
“增删改查”是数据库的几种基本操作，现在我们用数组DataBase[]来模拟一个数据库，来实现这几种功能。

1. 增：+ p v（将数据v插入到DataBase[p]位置上，保证p不会超过数据库末尾元素位置）

2. 删：- p  （将DataBase[p]位置的元素删除，保证p不会超过数据库末尾元素位置）

3. 改：* p v（将DataBase[p]位置的数据修改为v，保证p不会超过数据库末尾元素位置）

4. 查：? v  （查找DataBase中是否有值为v的元素，若查找成功输出其首次出现时的下标，否则输出“Failed”）

输入
第1行1个整数N（N<=1000），表示共有N次操作
第2~N+1行，每行1次操作
输出
对于每一次查找操作，给出结果；如果查找失败，输出“Failed”；
每个结果独自占一行
样例输入
6
+ 0 1
+ 0 2
? 2
* 1 3
- 1
? 1
样例输出
0
Failed
提示
1. 数组DataBase[]中的数据都为int
2. 数组DataBase[]初始为空
*/
#include<iostream>
using namespace std;

void add(int* DB, int p, int v);//增：+ p v（将数据v插入到DataBase[p]位置上，保证p不会超过数据库末尾元素位置）
void delet(int* DB, int p);//删：- p  （将DataBase[p]位置的元素删除，保证p不会超过数据库末尾元素位置）
void alter(int* DB, int p, int v);//改：* p v（将DataBase[p]位置的数据修改为v，保证p不会超过数据库末尾元素位置）
int check(int* DB, int v);//查：? v  （查找DataBase中是否有值为v的元素，若查找成功输出其首次出现时的下标，否则输出“Failed”）
int length = 0;

int main() {
	int n;
	int DB[100];
	cin >> n;

	for (int i = 0; i < n; i++) {
		char op;
		cin >> op;
		switch (op)
		{
			int p, v;
		case '+':		
			cin >> p >> v;
			add(DB, p, v);
			break;
		case '-':
			cin >> p;
			delet(DB, p);
			break;
		case '*':
			cin >> p >> v;
			alter(DB, p, v);
			break;
		case '?':
			cin >> v;
			int ans = check(DB, v);
			if (ans == -1)
				cout << "Failed"<<endl;
			else
				cout << ans<<endl;
			break;
		}
	}
	return 0;
}

void add(int* DB, int p, int v)
{
	for (int j = length - 1; j >= p; j--)
		DB[j + 1] = DB[j];
	DB[p] = v;
	length++;
}

void delet(int* DB, int p)
{
	for (int j = p + 1; j <= length - 1; j++)
		DB[j - 1] = DB[j];
	length--;
}

void alter(int* DB, int p, int v)
{
	DB[p] = v;
}

int check(int* DB, int v)
{
	for (int i = 0; i < length; i++)
		if (DB[i] == v) return i;
	return -1;
}
