#include <iostream>
#define MSize 5     // 线性表的最大长度 
using namespace std;
typedef int ElemType;
typedef struct SqList
{
	ElemType data[MSize];
	int length; // 线性表的长度 
}SqList;

void createList(SqList& L); // 创建一个线性表L 
void output(SqList L);      // 输出线性表L 
void clearList(SqList& L);  // 清空线性表L
bool isEmpty(SqList L);     // 判断线性表L是否为空 
bool isFull(SqList L);      // 判断线性表L是否满 
int getLength(SqList L);    // 获取线性表L的长度 
bool getElem(SqList L, int i, ElemType& e);// 获取线性表L的第i个元素的值 
int locate(SqList L, ElemType e);// 查找线性表L中是否有e,如有返回e的位序 
bool setElem(SqList& L, int i, ElemType e);// 将线性表L的第i个元素设置为e 
bool insertList(SqList& L, int i, ElemType e);// 在线性表L的第i个元素前插入e 
bool deleteList(SqList& L, int i, ElemType& e);// 删除线性表L的第ｉ个元素 
void welcome();//欢迎界面 
void process();// 操作函数 
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
bool getElem(SqList L, int i, ElemType& e)
{
	if (isEmpty(L))
	{
		cout << "List is empty\n";
		return false;
	}
	else if (i < 1 || i > L.length)
	{
		cout << "position is illegal\n";
		return false;
	}
	else
	{
		e = L.data[i - 1];
		return true;
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
bool setElem(SqList& L, int i, ElemType e)
{
	if (isEmpty(L))
	{
		cout << "List is empty\n";
		return false;
	}
	else if (i < 1 || i > L.length)
	{
		cout << "position is illegal\n";
		return false;
	}
	else
	{
		cout << "set Element success \n";
		L.data[i - 1] = e;
		return true;
	}
}
bool insertList(SqList& L, int i, ElemType e)
{
	if (isFull(L))
	{
		cout << "List is full\n";
		return false;
	}
	else if (i < 1 || i > L.length + 1)
	{
		cout << "insert position is illegal\n";
		return false;
	}
	else
	{
		for (int j = L.length - 1; j >= i - 1; j--)
			L.data[j + 1] = L.data[j];
		L.data[i - 1] = e;
		L.length++;
		return true;
	}
}
bool deleteList(SqList& L, int i, ElemType& e)
{
	if (isEmpty(L))
	{
		cout << "List is empty\n";
		return false;
	}
	else if (i < 1 || i > L.length - 1)
	{
		cout << "delete position is illegal\n";
		return false;
	}
	else
	{
		e = L.data[i - 1];
		for (int j = i - 1; j <= L.length - 1; j++)
			L.data[j - 1] = L.data[j];
		L.length--;
		return true;
	}
}
void welcome()
{
	cout << "========顺序表基本操作========" << endl;
	cout << "1.创建顺序表         2.清空" << endl;
	cout << "3.输出顺序表         4.判空" << endl;
	cout << "5.判满               6.长度" << endl;
	cout << "7.按位取元素         8.查找元素" << endl;
	cout << "9.插入              10.插入" << endl;
	cout << "11.删除                     " << endl;
	cout << "0.退出" << endl;
	cout << "===============================" << endl;
	cout << "输入0-10：";
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
			if (getElem(sl, i, e))
				cout << e << endl;
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
			if (!setElem(sl, i, e))
				cout << "set element unsuccess" << endl;
			break;
		case 10:
			cout << "input the insert position and element : ";
			cin >> i >> e;
			res = insertList(sl, i, e);
			if (res)
				cout << "insert success\n";
			else cout << "insert unsuccess\n";
			break;
		case 11:
			cout << "input the delete position: ";
			cin >> i;
			int res = deleteList(sl, i, e);
			if (res)
				cout << "delete success and delete element is " << e << endl;
			else cout << "delete unsuccess\n";
			break;
		}
	}
}

