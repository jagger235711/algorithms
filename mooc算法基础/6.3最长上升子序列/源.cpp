#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MaxN = 1010;
int a[MaxN];
int maxLen[MaxN];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		maxLen[i] = 1;
	}
	//����������a[i]
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++)//�Ա�ǰ���Ԫ�غ�ǰ����������
			if (a[i] > a[j])
				maxLen[i] = max(maxLen[i], maxLen[j] + 1);
	}
	cout << *max_element(maxLen + 1, maxLen + n + 1);
	return 0;
}