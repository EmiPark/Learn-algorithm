// �ѡ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
template<class elemType>
void bubbleSort(elemType ** a, int lenth);
void greedy(int **arr, int * rec, int num);
int main()
{
	string input;		//��ȡ������
	vector<int>  iStart,iFinish;
	iStart.reserve(1);		//����capacityΪ1��֮�����Ԫ�ض�̬��չ�ռ���Ԫ��
	iFinish.reserve(1);
	int mark = 0, n=0;
	cout << "��������ÿ����Ŀ�ʼʱ��ͽ���ʱ��(��Ϊ������)����#������" << endl;
	while (true)
	{
		cin >> input;		//ע��ֱ����>>��ȡstring��Ҫstringͷ�ļ�
		if (input == "#") break;
		else
		{
			if (mark==0)
			{
				iStart.push_back(atoi(input.c_str()));
				mark = 1;
			}
			else
			{
				iFinish.push_back(atoi(input.c_str()));
				mark = 0;
			}
		}
	}
	n = iStart.size();
	int **arr = new int*[n];	
	for (size_t i = 0; i < n; i++)
		arr[i] = new int[2];
	for (size_t i = 0; i < n; i++)
	{
		arr[i][0] = iStart[i];
		arr[i][1] = iFinish[i];
	}
	int * rec = new int[n];
	for (size_t i = 0; i < n; i++)
		rec[i] = -1;
	//memset(rec, 0, sizeof(rec));
	bubbleSort(arr, n);
	cout << "�ź���Ļ���ϣ�" << endl;
	cout << "��ʼʱ�䣺";
	for (size_t i = 0; i < n; i++)
		cout << arr[i][0] << "  ";
	cout << endl;
	cout << "����ʱ�䣺";
	for (size_t i = 0; i < n; i++)
		cout << arr[i][1] << "  ";
	cout << endl;
	greedy(arr, rec, n);
	cout << "ִ�л��˳����:";
	for (size_t i = 0; i < n; i++)
	{
		if (rec[i] != -1) cout <<"�"<< rec[i]+1 << " ";
		else continue;
	}
	cout << endl;
	system("pause");
    return 0;
}

void greedy(int **arr, int * rec,int num)		//��������arr���Ƿǵݼ��ź���Ķ�ά����
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
}
void swap(int &a, int &b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}
template<class elemType>
void bubbleSort(elemType ** a,int length)
{
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = i+1; j < length; j++)
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