/*
����
ũ��Լ����һ�������Ļ��ʦ������ʶ���Լ�����û���㹻��Ǯ��ά��ũ������ת�ˡ������������¼���˽����� N (1 �� N �� 100,000) ����ÿ����Ҫ�Ŀ�����

Լ������Ϊ������M (1 �� M �� N) ���������ڴ���Ԥ�㰸������һ��������������Ϊfajo�¡�ÿ��fajo�°���һ��������Ķ��죬ÿ�챻ǡ�ð�����һ��fajo���

Լ����Ŀ���Ǻ�����ÿ��fajo�°�����������ʹ�ÿ�������fajo�µĿ����������١�



����
��һ�а�����������N,M���õ����ո������
������N�У�ÿ�а���һ��1��10000֮�����������˳�����������N����ÿ��Ŀ�����
���
һ��������������¶ȿ�������Сֵ��
��������
7 5
100
400
300
100
500
101
400
�������
500
*/
#include<iostream>
using namespace std;

int N, M, cost[100001];
bool judge(int temp) {//�ж�mid���޶�������Ĺ�ϵ
	int sum = 0, group = 1;
	for (int i = 0; i < N; i++) {
		if (sum + cost[i] <= temp) {
			sum += cost[i];
		}
		else {
			group++;//������һ
			sum = cost[i];//���黨��
		}
	}
	if (group < M)
		return false;
	else
		return true;
}
int main() {
	int l = 0, r = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> cost[i];
		r += cost[i];
	}

	while (l<r) {
		int mid = (l + r) / 2;
		if (judge(mid))//mid��С
			l = mid+1;
		else
			r = mid-1;
	}
	printf("%d\n", l);
	return 0;
}

