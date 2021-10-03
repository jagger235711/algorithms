#include<iostream>
#include<time.h>
using namespace std;

double f1(double a[], int n, double x) {
	int i;
	double p = a[0];
	for (i = 1; i <= n; i++)
	{
		p += a[i] * pow(x, i);
	}
	return p;
}

double f2(double a[], int n, double x) {
	int i;
	double p = a[n];
	for ( i = n-1; i >=0; i--)
	{
		p = a[i] + x * p;
	}
	return p;
}

int main() {
	double a[10] = { 1,1,1,1,1,}, durationf1, durationf2;
	cout << f1(a, 2, 2)<<endl;
	cout << f2(a, 2, 2) << endl;
	return 0;
}