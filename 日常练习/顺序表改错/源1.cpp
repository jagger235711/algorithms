#include <iostream>
#define MSize 5     // ���Ա����󳤶� 
using namespace std;
typedef int ElemType;
typedef struct SqList
{
	ElemType data[MSize];
	int length; // ���Ա�ĳ��� 
}SqList;

void createList(SqList& L); // ����һ�����Ա�L 
void output(SqList L);      // ������Ա�L 
void clearList(SqList& L);  // ������Ա�L
bool isEmpty(SqList L);     // �ж����Ա�L�Ƿ�Ϊ�� 
bool isFull(SqList L);      // �ж����Ա�L�Ƿ��� 
int getLength(SqList L);    // ��ȡ���Ա�L�ĳ��� 
void getElem(SqList L, int i, ElemType& e);// ��ȡ���Ա�L�ĵ�i��Ԫ�ص�ֵ 
int locate(SqList L, ElemType e);// �������Ա�L���Ƿ���e,���з���e��λ�� 
void setElem(SqList& L, int i, ElemType e);// �����Ա�L�ĵ�i��Ԫ������Ϊe 
void insertList(SqList& L, int i, ElemType e);// �����Ա�L�ĵ�i��Ԫ��ǰ����e 
void deleteList(SqList& L, int i, ElemType& e);// ɾ�����Ա�L�ĵڣ��Ԫ�� 
void welcome();//��ӭ���� 
void process();// �������� 
int main(void)
{
	process();
	return 0;
}
void createList(SqList& L)
{
	ElemType e;
	cout << "create list , -1 will be end.\n";
	int i = 0;
	while (1)
	{
		cin >> e;
		if (e == -1) break;
		L.data[i++] = e;
	}
	L.length = i;
}
void output(SqList L)
{
	if (L.length == 0) cout << "list is empty!";
	else
		for (int i = 0; i < L.length; i++)
			cout << L.data[i] << " ";
	cout << endl;

}
void clearList(SqList& L)
{
	L.length = 0;
}
bool isEmpty(SqList L)
{
	return L.length == 0;
}
bool isFull(SqList L)
{
	return L.length == MSize;
}
int getLength(SqList L)
{
	return L.length;
}
void getElem(SqList L, int i, ElemType& e)
{
	if (isEmpty(L))
	{
		throw "List is empty\n";
	}
	else if (i < 1 || i > L.length)
	{
		throw "position is illegal\n";
	}
	else
	{
		e = L.data[i - 1];
		throw e;
	}
}
int locate(SqList L, ElemType e)
{
	int i = 0;
	while (i < L.length && L.data[i] != e)
		i++;
	if (i < L.length) return i + 1;
	return 0;
}
void setElem(SqList& L, int i, ElemType e)
{
	if (isEmpty(L))
	{
		throw "List is empty\n";
	}
	else if (i < 1 || i > L.length)
	{
		throw "position is illegal\n";
	}
	else
	{
		L.data[i - 1] = e;
		throw "set Element success \n";
	}
}
void insertList(SqList& L, int i, ElemType e)
{
	if (isFull(L))
	{
		throw "List is full\n";
	}
	else if (i < 1 || i > L.length + 1)
	{
		throw "insert position is illegal\n";
	}
	else
	{
		for (int j = L.length - 1; j >= i - 1; j--)
			L.data[j + 1] = L.data[j];
		L.data[i - 1] = e;
		L.length++;
		throw - 1;
	}
}
void deleteList(SqList& L, int i, ElemType& e)
{
	if (isEmpty(L))
	{
		throw "List is empty\n";
	}
	else if (i < 1 || i > L.length - 1)
	{
		throw "delete position is illegal\n";
	}
	else
	{
		e = L.data[i - 1];
		for (int j = i - 1; j <= L.length - 1; j++)
			L.data[j - 1] = L.data[j];
		L.length--;
		throw e;
	}
}
void welcome()
{
	cout << "========˳����������========" << endl;
	cout << "1.����˳���         2.���" << endl;
	cout << "3.���˳���         4.�п�" << endl;
	cout << "5.����               6.����" << endl;
	cout << "7.��λȡԪ��         8.����Ԫ��" << endl;
	cout << "9.����              10.����" << endl;
	cout << "11.ɾ��                     " << endl;
	cout << "0.�˳�" << endl;
	cout << "===============================" << endl;
	cout << "����0-10��";
}
void process()
{
	int choice;
	bool res;
	int k;
	SqList sl;
	while (1)
	{
		welcome();
		cin >> choice;
		if (choice == 0) break;
		switch (choice)
		{
		case 1:
			createList(sl);	break;
		case 2:
			clearList(sl); break;
		case 3:
			output(sl); break;
		case 4:
			if (isEmpty(sl))
				cout << "List is empty!\n";
			else
				cout << "List isn't empty!\n";
			break;
		case 5:
			if (isFull(sl))
				cout << "List is full!\n";
			else
				cout << "List isn't full!\n";
			break;
		case 6:
			cout << "The length's list is " << getLength(sl) << endl;
			break;
		case 7:
			int i;
			ElemType e;
			cout << "input the position of element : ";
			cin >> i;
			try {
				getElem(sl, i, e);
			}
			catch (const char* mssg) {
				cout << mssg;
			}
			catch (int k) {
				cout << k << endl;
			}
			break;
		case 8:
			cout << "input the search element: ";
			cin >> e;
			k = locate(sl, e);
			if (k)
				cout << "The position of " << e << " is " << k << endl;
			else
				cout << "not find\n";
			break;
		case 9:
			cout << "input the position of setting element and element: ";
			cin >> i >> e;
			try {
				setElem(sl, i, e);
			}
			catch (const char* mssg) {
				cout << mssg;
				if (mssg != "set Element success \n") {
					cout << "set element unsuccess" << endl;
				}
			}

			break;
		case 10:
			cout << "input the insert position and element : ";
			cin >> i >> e;

			try {
				insertList(sl, i, e);
			}
			catch (const char* mssg) {
				cout << mssg;
				cout << "insert unsuccess\n";
			}
			catch (int k) {
				cout << "insert success\n";
			}
			break;
		case 11:
			cout << "input the delete position: ";
			cin >> i;
			try {
				deleteList(sl, i, e);
			}
			catch (const char* mssg) {
				cout << mssg;
				cout << "delete unsuccess\n";
			}
			catch (int k) {
				cout << "delete success and delete element is " << k << endl;
			}
			break;
		}
	}
}

