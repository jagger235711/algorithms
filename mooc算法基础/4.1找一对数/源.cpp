#include<iostream>
using namespace std;

int num[100001];

int BinarySearch(int num[], int size, int m) {
	int L = 0;
	int R = size - 1;
	while (L <= R) {
		int mid = L + (R - L) / 2;
		if (m == num[mid])
			return mid;
		else if (m > num[mid])
			L = mid + 1;
		else
			R = mid - 1;
	}
	return -1;
}

void method1(int m, int num[],int size) {
	//a[i]+(m-a[i])=m
	for (int i = 0; i < size / 2; i++) {
		int que = m - num[i];
		int ans = 0;

		ans=BinarySearch(num, size, que);
		if (ans == -1)
			continue;
		else
			cout << num[i] << "+" << num[ans] << "=" << m;
	}
}

void method2(int m,int num[], int size) {

}