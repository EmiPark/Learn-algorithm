// ��������������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int row;
	cout << "���������ε�������" << endl;
	cin >> row;
	//��ʼ����������εĶ�ά����
	int ** A = new int * [row];
	for (size_t i = 0; i < row; i++)
		A[i] = new int[row];
	int ** max = new int *[row];
	for (size_t i = 0; i < row; i++)
		max[i] = new int[row];
	for (size_t i = 0; i < row; i++)
		for (size_t j = 0; j < row; j++)
			A[i][j] = 0;
	cout << "Ϊ�����ε����ָ�ֵ��" << endl;
	for (size_t i = 0; i < row; i++)
		for (size_t j = 0; j < i+1; j++)
			cin >> A[i][j];
	cout << "�����������ǣ�" << endl;
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < row; j++)
		{
			if (A[i][j] == 0) cout << "  ";
			else cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	//��������һ���ֵ��ʼ����max����
	for (size_t i = 0; i < row; i++)
		max[row - 1][i] = A[row - 1][i];
	//�ӵ����ڶ��㿪ʼ�������ϱ���
	for (int i = row-2; i >=0 ; i--)
	{
		for (size_t j = 0; j <= i; j++)
		{
			if ((A[i][j] + max[i + 1][j]) > (A[i][j] + max[i + 1][j + 1]))	max[i][j] = A[i][j] + max[i + 1][j];
			else max[i][j] = A[i][j] + max[i + 1][j + 1];
		}
	}
	cout << "�·���ǣ�" << max[0][0] << endl;
	system("pause");
    return 0;
}

