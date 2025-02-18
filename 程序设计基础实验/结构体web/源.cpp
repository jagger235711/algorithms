
#include <iostream>

#include <cstdio>

#include <algorithm>

using namespace std;

struct student

{

	char id[15];

	int month, date;

	int xu;          // 记录学生的输入顺序，因为题中提到对生日相同的学生，按输入顺序输出

};

bool cmp(student a, student b)

{

	if (a.month == b.month)

	{

		if (a.date == b.date)

		{

			return a.xu < b.xu;

		}

		else

		{

			return a.date < b.date;  // 按题目要求进行结构体排序

		}

	}
	return a.month < b.month;
}
int main()
{
	student stu[105];

	int n;

	bool isBegin = true, isFirst = true;

	scanf_s("%d", &n);

	for (int i = 0; i < n; i++)

	{
		cin >> stu[i].id >> stu[i].month >> stu[i].date;
		stu[i].xu = i;

	}

	sort(stu, stu + n, cmp);

	for (int i = 0; i < n - 1; i++)

	{

		if (stu[i].month == stu[i + 1].month && stu[i].date == stu[i + 1].date)

		{

			if (isBegin)

			{

				if (isFirst)

				{

					printf("%d %d %s", stu[i].month, stu[i].date, stu[i].id);   // 先输出生日，第一组输出不需要换行

					isFirst = false;

				}

				else

					printf("\n%d %d %s", stu[i].month, stu[i].date, stu[i].id);   // 之后每组输出得先换行，并且都先输出生日

				isBegin = false;

			}

			printf(" %s", stu[i + 1].id);   // 之后跟的是输出学生学号

		}

		else

			isBegin = true;

	}

	return 0;

}
