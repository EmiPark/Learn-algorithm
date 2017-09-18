// �㷨��ҵ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include<stdlib.h>
#include <ctime>
#include <vector>
using namespace std;
#define maxSize 100
long CountFib(int n);
int Fib(int n);
void perm(int list[], int k, int m);
int ack(int m, int n);
void hanoi(int n, char from, char depend, char to);
template<class elemType>
void quickSort(elemType a[], int begin, int end);
template<class elemType>
elemType* vec2arr(vector<elemType> vec);
int step=1;
int main()
{
	string input;		//��ȡ������
	vector<int>  A;		
	A.reserve(1);		//����capacityΪ1��֮�����Ԫ�ض�̬��չ�ռ���Ԫ��
	cout << "Ϊ���鸳����ֵ��������Ч����#����" << endl;
	while (true)
	{
		cin >> input;		//ע��ֱ����>>��ȡstring��Ҫstringͷ�ļ�
		if (input=="#") break;
		else A.push_back(atoi(input.c_str()));
	}
	cout << "����֮ǰ�����飺" << endl;
	int *arr=new int[1];		//new��ʼ������ָ�������С
	arr = vec2arr(A);
	for (size_t i = 0; i < A.size(); i++)
		cout << arr[i] << " " ;
	cout << endl;
	quickSort(arr, 0, A.size() - 1);
	cout << "����֮��ǰ�����飺" << endl;
	for (size_t i = 0; i < A.size(); i++)
		cout << arr[i] << " " ;
	cout << endl;
	system("pause");
    return 0;
}
template<class elemType>
elemType* vec2arr(vector<elemType> vec)
{
	elemType* arr = new elemType [vec.size()];
	for (size_t i = 0; i < vec.size(); i++)
		arr[i] = vec[i];
	return arr;
}
template<class elemType>
void quickSort(elemType a[], int begin, int end)
{
	if (begin < end)
	{
		int i = begin, j = end;
		elemType key = a[i];
		while (i<j)
		{
			while (i<j&&a[j]>key)		j--;	//j��ǰ�ұ�keyС������ע����ʱ���i<j
			if (i < j)		a[i++] = a[j];
			while (i < j&&a[i] < key)		i++;	 //i����ұ�key�����
			if (i < j)		a[j--] = a[i];
		}
		//��key��ֵ��i��j�����ĵط�
		a[i] = key;
		//����ݹ�
		quickSort(a, begin, i - 1);
		quickSort(a, i + 1, end);
	}
}

long CountFib(int n)
{
	int i=0,sum = 0;
	while (i < n)
	{
		sum += Fib(i++);
	}
	return sum;
}
int Fib(int n)
{
	if (n <=1) return 1;
	else return Fib(n - 1) + Fib(n - 2);
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void perm(int list[], int k, int m)
{
	if (k == m)
	{
		for (int i = 0; i <=m ; i++)
		{
			cout << list[i]<<"	";
		}
		cout << endl;
	}
	else
	{
		for (int i = k; i <= m; i++)
		{
			swap(list[k], list[i]);
			perm(list, k + 1, m);
			swap(list[k], list[i]);
		}
	}
}

int ack(int m, int n)
{
	if (m == 0)
		return n + 1;
	else if (n == 0)
		return ack(m - 1, 1);
	else
		return ack(m - 1, ack(m, n - 1));
}

void move(int n, char from, char to)
{
	cout << "��" << step++ << "������" << n << "�����Ӵ�" << from << "�ƶ���" << to << endl;
}
void hanoi(int n, char from, char depend, char to)
{
	if (n == 1) move(1, from, to);
	else
	{
		hanoi(n - 1, from, to, depend);
		move(n, from, to);
		hanoi(n - 1, depend, from, to);
	}
}
#define SIGN(A) ((A > 0) ? 1 : -1) 
int divideConquer(int X, int Y, int n) {
	int sign = SIGN(X) * SIGN(Y);
	int x = abs(X);
	int y = abs(Y);
	if (x == 0 || y == 0) {
		return 0;
	}
	else if (n == 1) {
		return sign * x * y;
	}
	else {
		int A = (int)x / pow(10, (int)(n / 2));
		int B = x - A * pow(10, n / 2);
		int C = (int)y / pow(10, (int)(n / 2));
		int D = y - C * pow(10, n / 2);
		int AC = divideConquer(A, C, n / 2);
		int BD = divideConquer(B, D, n / 2);
		int ABDC = divideConquer((A - B), (D - C), n / 2) + AC + BD;
		return sign * (AC * pow(10, n) + ABDC * pow(10, (int)(n / 2)) + BD);
	}
}