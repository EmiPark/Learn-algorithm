// 数字三角形问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int row;
	cout << "输入三角形的行数：" << endl;
	cin >> row;
	//初始化存放三角形的二维数组
	int ** A = new int * [row];
	for (size_t i = 0; i < row; i++)
		A[i] = new int[row];
	int ** max = new int *[row];
	for (size_t i = 0; i < row; i++)
		max[i] = new int[row];
	for (size_t i = 0; i < row; i++)
		for (size_t j = 0; j < row; j++)
			A[i][j] = 0;
	cout << "为三角形的数字赋值：" << endl;
	for (size_t i = 0; i < row; i++)
		for (size_t j = 0; j < i+1; j++)
			cin >> A[i][j];
	cout << "数字三角形是：" << endl;
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
	//将最下面一层的值初始化给max数组
	for (size_t i = 0; i < row; i++)
		max[row - 1][i] = A[row - 1][i];
	//从倒数第二层开始从下至上遍历
	for (int i = row-2; i >=0 ; i--)
	{
		for (size_t j = 0; j <= i; j++)
		{
			if ((A[i][j] + max[i + 1][j]) > (A[i][j] + max[i + 1][j + 1]))	max[i][j] = A[i][j] + max[i + 1][j];
			else max[i][j] = A[i][j] + max[i + 1][j + 1];
		}
	}
	cout << "最长路径是：" << max[0][0] << endl;
	system("pause");
    return 0;
}

