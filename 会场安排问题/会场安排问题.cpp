// 会场安排问题.cpp : 定义控制台应用程序的入口点。
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
	cout << "输入活动的数目" << endl;
	cin >> num;
	int **arr = new int*[num];
	for (size_t i = 0; i < num; i++)
		arr[i] = new int[2];
	cout << "依次输入每个活动的开始时间和结束时间(均为正整数)：" << endl;
	for (size_t i = 0; i < num; i++)
	{
		cin >> arr[i][0] >> arr[i][1];
	}
	int * rec = new int[num];
	for (size_t i = 0; i < num; i++)
		rec[i] = -1;
	//memset(rec, 0, sizeof(rec));
	bubbleSort(arr, num);
	cout << "排好序的活动集合：" << endl;
	cout << "开始时间：";
	for (size_t i = 0; i < num; i++)
		cout << arr[i][0] << "  ";
	cout << endl;
	cout << "结束时间：";
	for (size_t i = 0; i < num; i++)
		cout << arr[i][1] << "  ";
	cout << endl;
	cout << "最少会场数是:"<< greedy(arr, rec, num)<<endl;
	system("pause");
	return 0;
}

int greedy(int **arr, int * rec, int num)		//传进来的arr需是非递减排好序的二维数组，返回参与活动的个数
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
