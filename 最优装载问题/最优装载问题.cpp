// 最优装载问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
template<class elemType>
elemType* vec2arr(vector<elemType> vec);
template<class elemType>
void bubbleSort(elemType * a, int length);
void greedy(int *arr, int *rec, int c, int n);
int main()
{
	int c;
	cout << "输入轮船载重量（正整数）" << endl;
	cin >> c;
	string input;		//获取输入流
	vector<int>  w;
	w.reserve(1);		//设置capacity为1，之后添加元素动态扩展空间存放元素
	cout << "依次输入需要装入的货物的重量（均为正整数），以#结束" << endl;
	while (true)
	{
		cin >> input;		//注意直接用>>获取string需要string头文件
		if (input == "#") break;
		else w.push_back(atoi(input.c_str()));
	} 
	int * wArr = new int[1];
	wArr = vec2arr(w);
	int n = w.size();
	int * rec = new int[n];
	for (size_t i = 0; i < n; i++)
		rec[i] = 0;
	bubbleSort(wArr, n);
	greedy(wArr, rec, c, n);
	cout << "装载方案：";
	for (size_t i = 0; i < n; i++)
	{
		if (rec[i] != 0) cout << rec[i] << " ";
	}
	cout << endl;
	system("pause");
    return 0;
}
template<class elemType>
elemType* vec2arr(vector<elemType> vec)
{
	elemType* arr = new elemType[vec.size()];
	for (size_t i = 0; i < vec.size(); i++)
		arr[i] = vec[i];
	return arr;
}
void greedy(int *arr, int *rec, int c,int n)
{
	rec[0] = arr[0];
	c -= arr[0];
	for (size_t i = 1; i < n; i++)
	{
		if (c - arr[i] >= 0)
		{
			c -= arr[i];
			rec[i] = arr[i];
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
void bubbleSort(elemType * a, int length)
{
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = i + 1; j < length; j++)
		{
			if (a[i] >= a[j])
				swap(a[i], a[j]);
		}
	}
}
