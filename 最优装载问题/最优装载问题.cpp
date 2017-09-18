// ����װ������.cpp : �������̨Ӧ�ó������ڵ㡣
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
	cout << "�����ִ�����������������" << endl;
	cin >> c;
	string input;		//��ȡ������
	vector<int>  w;
	w.reserve(1);		//����capacityΪ1��֮�����Ԫ�ض�̬��չ�ռ���Ԫ��
	cout << "����������Ҫװ��Ļ������������Ϊ������������#����" << endl;
	while (true)
	{
		cin >> input;		//ע��ֱ����>>��ȡstring��Ҫstringͷ�ļ�
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
	cout << "װ�ط�����";
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
