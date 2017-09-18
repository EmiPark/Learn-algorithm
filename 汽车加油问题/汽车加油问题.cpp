// 汽车加油问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
int findGas(int * arr, int n, const int k);
int main()
{
	int n = 0, k = 0;
	cout << "输入正整数代表汽车加满油可行驶的公里数：" << endl;
	cin >> n;
	cout << "输入正整数代表途中经过的加油站数：" << endl;
	cin >> k;
	int * gasArr = new int[k+1];
	cout << "依次输入" << k << "个加油站之间的距离：" << endl;
	gasArr[0] = 0;
	for (size_t i = 1; i < k + 1; i++)
		cin >> gasArr[i];
	cout << "最少加油次数是：" << findGas(gasArr, n, k) << endl;
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
