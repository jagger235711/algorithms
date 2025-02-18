
#include <iostream>

#include <cstdio>

#include <algorithm>

using namespace std;

struct student

{

	char id[15];

	int month, date;

	int xu;          // ��¼ѧ��������˳����Ϊ�����ᵽ��������ͬ��ѧ����������˳�����

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

			return a.date < b.date;  // ����ĿҪ����нṹ������

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

					printf("%d %d %s", stu[i].month, stu[i].date, stu[i].id);   // ��������գ���һ���������Ҫ����

					isFirst = false;

				}

				else

					printf("\n%d %d %s", stu[i].month, stu[i].date, stu[i].id);   // ֮��ÿ��������Ȼ��У����Ҷ����������

				isBegin = false;

			}

			printf(" %s", stu[i + 1].id);   // ֮����������ѧ��ѧ��

		}

		else

			isBegin = true;

	}

	return 0;

}
