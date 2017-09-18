// �᳡��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
template<class elemType>
void bubbleSort(elemType ** a, int lenth);
int greedy(int **arr, int * rec, int num);
int main()
{
	int num = 0;
	cout << "��������Ŀ" << endl;
	cin >> num;
	int **arr = new int*[num];
	for (size_t i = 0; i < num; i++)
		arr[i] = new int[2];
	cout << "��������ÿ����Ŀ�ʼʱ��ͽ���ʱ��(��Ϊ������)��" << endl;
	for (size_t i = 0; i < num; i++)
	{
		cin >> arr[i][0] >> arr[i][1];
	}
	int * rec = new int[num];
	for (size_t i = 0; i < num; i++)
		rec[i] = -1;
	//memset(rec, 0, sizeof(rec));
	bubbleSort(arr, num);
	cout << "�ź���Ļ���ϣ�" << endl;
	cout << "��ʼʱ�䣺";
	for (size_t i = 0; i < num; i++)
		cout << arr[i][0] << "  ";
	cout << endl;
	cout << "����ʱ�䣺";
	for (size_t i = 0; i < num; i++)
		cout << arr[i][1] << "  ";
	cout << endl;
	cout << "���ٻ᳡����:"<< greedy(arr, rec, num)<<endl;
	system("pause");
	return 0;
}

int greedy(int **arr, int * rec, int num)		//��������arr���Ƿǵݼ��ź���Ķ�ά���飬���ز����ĸ���
{
	int i = 0, k = 0;
	rec[k] = 0;
	for (size_t j = 1; j < num; j++)
	{
		if (arr[j][0] >= arr[i][1])
		{
			rec[++k] = j;
			i = j;
		}
	}
	return k + 1;
}
void swap(int &a, int &b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}
template<class elemType>
void bubbleSort(elemType ** a, int length)
{
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = i + 1; j < length; j++)
		{
			if (a[i][0] >= a[j][0])
			{
				swap(a[i][0], a[j][0]);
				swap(a[i][1], a[j][1]);
			}
		}
		if (i > 0)
		{
			if ((a[i][0] == a[i - 1][0]) && (a[i][1] < a[i - 1][1]))
			{
				swap(a[i][0], a[i - 1][0]);
				swap(a[i][1], a[i - 1][1]);
			}
		}
	}
}
