#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char s1[100] = "12345";
	char s2[100] = "abcdefg";
	char s3[100] = "ABCDE";
	strncat_s(s1, s2, 3);
	cout << "1)" << s1 << endl;

}