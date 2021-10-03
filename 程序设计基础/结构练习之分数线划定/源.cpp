#include<iostream>
using namespace std;
struct Student
{
	int Id, Score;
};
int main()
{
	int n, m;
	Student Stu[100];
	
	//cin
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> Stu[i].Id >> Stu[i].Score;
	}

	//BubbleSort
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (Stu[j].Score < Stu[j + 1].Score)
			{
				Student Temp = Stu[j];
				Stu[j] = Stu[j + 1];
				Stu[j + 1] = Temp;
			}
		}
	}

	//calculate the score line\cout the number of people 
	int Num0 = m * 1.5,Num1;
	int scoreLine = Stu[Num0 - 1].Score;
	for (int i = Num0; i < n; i++)
	{
		if (Stu[i].Score != scoreLine)
		{
			cout << scoreLine << " " << i << endl;
			Num1 = i;
			break;
		}
	}

	//cout the people
	for (int i = 0; i < Num1; i++)
	{
		cout<< Stu[i].Id <<" "<< Stu[i].Score<<endl;
	}
	return 0;
}