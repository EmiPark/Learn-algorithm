// ������������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#define MAX_SIZE 100
using namespace std;
int fun(int d[][MAX_SIZE], int m[], int length);
int main()
{
	int m[MAX_SIZE];
	int d[MAX_SIZE][MAX_SIZE];
	memset(d, 0, sizeof(d));
	int length;
	cout << "����������ĳ��ȣ�"<< endl;
	cin >> length;
	cout << "����������������:" << endl;
	for (size_t i = 0; i < length; i++)
		cin >> m[i];
	cout<<fun(d, m, length)<<endl;
	system("pause");
    return 0;
}

//d�����ž�����������ֵ��m�����ž�������������Ϣ��length��ž������ĳ���
int fun(int d[][MAX_SIZE],int m[],int length)
{
	for (size_t i = 1; i < length; i++)
	{
		for (size_t left = 1,right= left + i; right < length; left++, right++)
		{
			int min = 100000;
			for (size_t k = left; k < right; k++)
			{
				int count = d[left][k] + d[k + 1][right] + m[left - 1] * m[k] * m[right];
				if (count < min) min = count;
			}
			d[left][right] = min;		//��left�����󵽵�right�����������ֵ
		}
	}
	return d[1][length -1];
}

void MatrixMultiply(int a[][MAX_SIZE], int b[][MAX_SIZE], int rowA, int colA_rowB, int colB)
{
	int sum[MAX_SIZE][MAX_SIZE];
	memset(sum, 0, sizeof(sum));		//��sum�����Ԫ��ȫ����0
	for (size_t i = 0; i < rowA; i++)
		for (size_t j = 0; j < colB; j++)
			for (size_t k = 0; k < colA_rowB; k++)
				sum[i][j] += a[i][k] * b[k][j];
}
