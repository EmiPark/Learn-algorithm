// ������������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
int findGas(int * arr, int n, const int k);
int main()
{
	int n = 0, k = 0;
	cout << "�����������������������Ϳ���ʻ�Ĺ�������" << endl;
	cin >> n;
	cout << "��������������;�о����ļ���վ����" << endl;
	cin >> k;
	int * gasArr = new int[k+1];
	cout << "��������" << k << "������վ֮��ľ��룺" << endl;
	gasArr[0] = 0;
	for (size_t i = 1; i < k + 1; i++)
		cin >> gasArr[i];
	cout << "���ټ��ʹ����ǣ�" << findGas(gasArr, n, k) << endl;
	system("pause");
    return 0;
}
int findGas(int * arr,int n,const int k)
{
	int num = 0, full = n;
	for (size_t i = 0; i < k+1; i++)
	{
		if (arr[i] > full)
		{
			cout << "No Solution" << endl;
			return 0;
		}
		else
		{
			n -= arr[i];
			if (n - arr[i+1] > 0)	continue;
			else
			{
				n = full;
				num++;
			}
		}
	}
	return num;
}
