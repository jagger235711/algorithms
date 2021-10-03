#include<iostream>
#include<string.h>
using namespace std;
struct student
{
	char Name[21];
	int Num;
};
int main()
{
	student Stu[100];
	int n;
	cin >> n;
	
	//cin
	for (int i = 0; i < n; i++)
	{
		cin >> Stu[i].Name >> Stu[i].Num;
	}
	
	//BubbleSort
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n - i-1; j++) 
		{
			if (Stu[j].Num < Stu[j+1].Num)
			{
				student Temp= Stu[j];
				Stu[j] = Stu[j+1];
				Stu[j+1] = Temp;
			}
		}
	}

	//cout
	for (int i = 0; i < n; i++)
	{
		cout << Stu[i].Name << " " << Stu[i].Num << endl;
	}
	return 0;
}