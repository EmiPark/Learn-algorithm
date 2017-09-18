// 活动选择问题.cpp : 定义控制台应用程序的入口点。
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
	string input;		//获取输入流
	vector<int>  iStart,iFinish;
	iStart.reserve(1);		//设置capacity为1，之后添加元素动态扩展空间存放元素
	iFinish.reserve(1);
	int mark = 0, n=0;
	cout << "依次输入每个活动的开始时间和结束时间(均为正整数)，以#结束。" << endl;
	while (true)
	{
		cin >> input;		//注意直接用>>获取string需要string头文件
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
	cout << "排好序的活动集合：" << endl;
	cout << "开始时间：";
	for (size_t i = 0; i < n; i++)
		cout << arr[i][0] << "  ";
	cout << endl;
	cout << "结束时间：";
	for (size_t i = 0; i < n; i++)
		cout << arr[i][1] << "  ";
	cout << endl;
	greedy(arr, rec, n);
	cout << "执行活动的顺序是:";
	for (size_t i = 0; i < n; i++)
	{
		if (rec[i] != -1) cout <<"活动"<< rec[i]+1 << " ";
		else continue;
	}
	cout << endl;
	system("pause");
    return 0;
}

void greedy(int **arr, int * rec,int num)		//传进来的arr需是非递减排好序的二维数组
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