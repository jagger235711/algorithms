#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
		for (int i = 0; i < n; i++)
		{
			int len=0,t;
			char a[31];
			cin >> a;
			len = strlen(a);
			t = len;
			if (len + 1 % 2 == 0)//Å¼Êý
			{
				for (int i = 0; i < (len + 1) / 2; i++)
				{
					if (a[i] == a[t])

					{
						t--;
						continue;
					}
					else break;
				}
			}
		}
	return 0;
}