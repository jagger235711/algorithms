/*
目标
链表的创建与输入。
插入
删除
修改
*/
#include<iostream>
#include<cstdio>
using namespace std;
typedef struct lnode
{
	string name, sid;
	int mark, age;
	struct lnode  *next;
}lnode,*link;
int main()
{
	lnode stulist[100], head;
	link p;
	head.next = NULL;
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		p = new(lnode);
		cin >> p->name;
		p->next = head.next;
		head.next = p;
	}
	return 0;
}