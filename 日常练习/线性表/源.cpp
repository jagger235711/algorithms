#include<iostream>
using namespace std;
#define MaxSize 50;
typedef int ElementType;
//�������Ա�
typedef struct {
	ElementType data[50];
	int length;
}sqList;
//�������Ա�
void CreatList(sqList*& L, ElementType a[], int n) {
	int i = 0, k = 0;
	L = (sqList*)malloc(sizeof(sqList));
	while (i<n)
	{
		L->data[k] = a[i];
		k++; i++;
	}
	L->length = k;
}
void CreatList1(sqList& L, ElementType a[], int n) {
	int i = 0, k = 0;
	while (i < n)
	{
		L.data[k] = a[i];
		k++; i++;
	}
	L.length = k;
}
//���Ա��������
//�Ƚ�Ҫ����λ�ü�֮�������Ԫ������ƶ�һ��λ��
//Ȼ�����Ŀ��Ԫ��
void insertList(sqList*& L, ElementType a, int n) {
	int k = L->length;
	//���ǽ�׳�� ����λ�ô���
	if (n > L->length||n<0) {
		cout <<endl<< "����λ������"<<endl;
	}
	else {
	//�ƶ�Ҫ����λ��ֱ��ĩβ��������
	while (k+1 >= n) {
		L->data[k + 1] = L->data[k];
		k--;
	}
	//����a Ҫע�������±��λ��֮�����1
	L->data[n-1] = a;
	L->length++;
	}
}
void deleteList(sqList *& L, int i)
{
	if (i == L->length-1) {
		L->length--;
	}
	else
	{
		for (int j = i ; j <= L->length - 1; j++)
			L->data[j-1] = L->data[j];
		L->length--;
	}

}
//���Ա�ȥ�ز���
//˫��ѭ��������ͬ�� ����ɾ������ɾ���ظ���
void deWeight(sqList*& L) {
	for (int i = 0; i < L->length-1; i++)
	{
		for (int j = i+1; j < L->length;) {
			if (L->data[i] == L->data[j])
				deleteList(L, j);
			else j++;
		}
	}
}
void deWeight2(sqList& L){//ע��˴�����˳���Ϊ�ǵݼ��� ��Ϊ��̬����
	if (L.length != 0)//������Ϊ��ʱ
	{
		int i = 0;//ָ���һ��Ԫ��
		for (int j = 1; j < L.length; j++)//�ӵڶ���Ԫ�����������һ��Ԫ�رȣ���ͬ������һ��Ԫ�غ����
		{
			if (L.data[i] != L.data[j])
			{
				L.data[++i] = L.data[j];//��֤������֮ǰ�����Ԫ��
			}
		}
		L.length = i + 1;
	}
}
void printList(sqList*& L) {
	int i = 0;
	cout <<endl<< "���" << endl;
	while (i<L->length)
	{
		cout << L->data[i]<<" ";
		i++;
	}
}
void printList1(sqList L) {
	int i = 0;
	cout << endl << "���" << endl;
	while (i < L.length)
	{
		cout << L.data[i] << " ";
		i++;
	}
}
int main() {
	ElementType a[10] = { 1,1,1,2,2,2,3,3,4,6 };
	sqList L;
	CreatList1(L, a, 10);
	/*printList(L);
	insertList(L, 9, 2);*/
	printList1(L);
	deWeight2(L);
	printList1(L);
	return 0;
}