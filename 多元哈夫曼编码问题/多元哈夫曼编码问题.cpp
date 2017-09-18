// 多元哈夫曼编码问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
void swap(int &a, int &b);
template<class elemType>
elemType * bubbleSortMin2Max(elemType * a, int length);
template<class elemType>
elemType * bubbleSortMax2Min(elemType * a, int length);
int findMax(int * stone, int n, const int k);
int findMin(int * stone, int n, const int k);
int main()
{
	int n = 0, k = 0;
	cout << "输入石堆的个数：" << endl;
	cin >> n;
	cout << "输入一次至多合并多少个石堆" << endl;
	cin >> k;
	int * stone = new int[n];
	cout << "一次输入各石堆的石子数：" << endl;
	for (size_t i = 0; i < n; i++)
	{
		cin >> stone[i];
	}
	cout << "最大总费用：" << findMax(stone, n, k) << endl << endl;;
	cout << "最小总费用：" << findMin(stone, n, k) << endl;
	system("pause");
    return 0;
}

int findMin(int * stone, int n, const int k)
{
	int count , sum=0;
	int * tempArr = new int[n];
	for (size_t i = 0; i < n; i++)
	{
		tempArr[i] = stone[i];
	}
	while (n >= 2)
	{
		count = 0;
		tempArr = bubbleSortMax2Min(tempArr, n);
		if (n >= k)
		{
			for (int i = n - 1; i > n - k - 1; i--)
			{
				cout << "取出：" << tempArr[i] << " ";
				count += tempArr[i];
				tempArr[i] = 0;
			}
			cout << endl;
			n = n - k + 1;
			tempArr[n - 1] = count;
			cout <<"单次费用："<< count << endl;
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				cout << "取出：" << tempArr[i] << " ";
				count += tempArr[i];
				if (i > 0)
					tempArr[i] = 0;
			}
			cout << endl;
			tempArr[0] = count;
			cout << "单次费用：" << count << endl;
			n = 1;
		}
		sum += count;
	}
	return sum;
}

int findMax(int * stone, int n, const int k)
{
	int count = 0, sum = 0;
	int * tempArr = new int[n];
	for (size_t i = 0; i < n; i++)
	{
		tempArr[i] = stone[i];
	}
	while (n >= 2)
	{
		tempArr = bubbleSortMin2Max(tempArr, n);
		if (n >= k)
		{
			for (int i = n - 1; i > n - k - 1; i--)
			{
				cout << "取出：" << tempArr[i] << " ";
				count += tempArr[i];
				tempArr[i] = 0;
			}
			cout << endl;
			n = n - k + 1;
			tempArr[n - 1] = count;
			cout << "单次费用：" << count << endl;
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				cout << "取出：" << tempArr[i] << " ";
				count += tempArr[i];
				if (i > 0)
					tempArr[i] = 0;
			}
			cout << endl;
			tempArr[0] = count;
			cout << "单次费用：" << count << endl;
			n = 1;
		}
		sum += count;
	}
	return sum;
}

template<class elemType>
elemType * bubbleSortMin2Max(elemType * a, int length)
{
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = i + 1; j < length; j++)
		{
			if (a[i] >= a[j])
				swap(a[i], a[j]);
		}
	}
	return a;
}

template<class elemType>
elemType * bubbleSortMax2Min(elemType * a, int length)
{
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = i + 1; j < length; j++)
		{
			if (a[i] <= a[j])
				swap(a[i], a[j]);
		}
	}
	return a;
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}