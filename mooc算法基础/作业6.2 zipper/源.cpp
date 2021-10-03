/*

描述
Given three strings, you are to determine whether the third string can be formed by combining the characters in the first two strings. The first two strings can be mixed arbitrarily, but each must stay in its original order.

For example, consider forming "tcraete" from "cat" and "tree":

String A: cat
String B: tree
String C: tcraete

As you can see, we can form the third string by alternating characters from the two strings. As a second example, consider forming "catrtee" from "cat" and "tree":

String A: cat
String B: tree
String C: catrtee

Finally, notice that it is impossible to form "cttaree" from "cat" and "tree".
输入
The first line of input contains a single positive integer from 1 through 1000. It represents the number of data sets to follow. The processing for each data set is identical. The data sets appear on the following lines, one data set per line.

For each data set, the line of input consists of three strings, separated by a single space. All strings are composed of upper and lower case letters only. The length of the third string is always the sum of the lengths of the first two strings. The first two strings will have lengths between 1 and 200 characters, inclusive.
输出
For each data set, print:

Data set n: yes

if the third string can be formed from the first two, or

Data set n: no

if it cannot. Of course n should be replaced by the data set number. See the sample output below for an example.
样例输入
3
cat tree tcraete
cat tree catrtee
cat tree cttaree
样例输出
Data set 1: yes
Data set 2: yes
Data set 3: no
*/
#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

int n;
char str1[51], str2[51], str3[103];
int tmp[102];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str1 >> str2 >> str3;
		int len1 = strlen(str1), len2 = strlen(str2), len3 = strlen(str3);
		int ans = 0;

		for (int i = 0, j = 0; i < len3, j < len1; i++) {
				if (str3[i] == str1[j]) {
					tmp[i] = 1;
					j++;
				}
				if (j == len1)
					ans = 1;
			}
		if (ans == 0) {
			printf("Data set %d: no\n", i + 1);
			break;
		}

		for (int i = 0,j=0; i < len3,j<len2; i++) {
			if (tmp[i] != 1) {
				if (str3[i] == str2[j]) {
					tmp[i] = 1;
					j++;
					}
					else break;
				}
			}

		for (int j = 0; j < len3; j++) {
			if (tmp[j] == 0) {
				printf("Data set %d: no\n", i + 1);
				break;
			}
			else if (j == len3 - 1 && tmp[j]==1)
				printf("Data set %d: yes\n", i + 1);
		

		}
	}
	return 0;
}