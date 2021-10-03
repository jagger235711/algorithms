#include<iostream>
using namespace std;
struct Student
{
	char Id[11];
	int  Age;
};
int main()
{
	int n;
	Student Stu[100];

	//cin
	cin >> n ;
	for (int i = 0; i < n; i++)
	{
		cin >> Stu[i].Id >> Stu[i].Age;
	}

	//InsertionSort
	for (int i = 0; i < n - 1; i++)//第i个无序元素
	{
		if (Stu[i].Age >= 60)//老的先
		{
          for (int j = 0; j < i; j++)
			if ( Stu[i].Age > Stu[j].Age)
				//不小于60的先
			{
				Student Temp = Stu[i];
				for (int k = i; k > j; --k)
				{
					Stu[k] = Stu[k + 1];
					Stu[j] = Temp;
					break;
				}
			}
		}
		
	}

	//cout the people
	for (int i = 0; i < n; i++)
	{
		cout << Stu[i].Id << " " << Stu[i].Age << endl;
	}
	return 0;
}