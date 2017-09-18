// 找零问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#define INFINITY_MAX 10000
using namespace std;
template<class elemType>
elemType* vec2arr(vector<elemType> vec);
template<class elemType>
void quickSort(elemType a[], int begin, int end);
void greedy(int *arr, int arrSize, int remaning);
void dynamic(int *arr, int arrSize, int money);
int main()
{
	int money;
	string input;		//获取输入流
	vector<int>  A;
	A.reserve(1);		//设置capacity为1，之后添加元素动态扩展空间存放元素
	cout << "输入POS机中存有的货币（均为正整数），以#结束" << endl;
	while (true)
	{
		cin >> input;		//注意直接用>>获取string需要string头文件
		if (input == "#") break;
		else A.push_back(atoi(input.c_str()));
	}
	int *arr = new int[1];		//new初始化必须指定数组大小
	arr = vec2arr(A);
	quickSort(arr, 0, A.size() - 1);
	cout << "输入需支付的金额：" << endl;
	cin >> money;
	cout << "贪心算法求解：" << endl;
	cout << "---------------------------------------------------------" << endl;
	greedy(arr, A.size(), money);
	cout << "---------------------------------------------------------" << endl;
	cout << "动态规划求解：" << endl;
	cout << "---------------------------------------------------------" << endl;
	dynamic(arr, A.size(), money);
	cout << "---------------------------------------------------------" << endl;
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
template<class elemType>
void quickSort(elemType a[], int begin, int end)		//从大到小的快排
{
	if (begin < end)
	{
		int i = begin, j = end;
		elemType key = a[i];
		while (i<j)
		{
			while (i<j&&a[j]<key)		j--;	//j向前找比key小的数，注意随时检查i<j
			if (i < j)		a[i++] = a[j];
			while (i < j&&a[i] > key)		i++;	 //i向后找比key大的数
			if (i < j)		a[j--] = a[i];
		}
		//将key赋值给i与j相遇的地方
		a[i] = key;
		//两侧递归
		quickSort(a, begin, i - 1);
		quickSort(a, i + 1, end);
	}
}
void greedy(int *arr,int arrSize,int remaning)
{
	int paid = 0;		//已付金额
	int needPay = remaning;
	for (size_t i = 0; i < arrSize; i++)
	{
		if (remaning == 0)	break;
		else 
		{
			if (remaning >= arr[i])
			{
				paid += arr[i];
				remaning -= arr[i];
				cout << "支付一张" << arr[i] << "元货币。" << endl;
			}
			else continue;
		}
	}
	if (paid==needPay)
		cout << "支付完成！" << endl;
	else cout << "POS机内货币不足，支付失败！" << endl;
}
//参考文章：http://blog.csdn.net/wdxin1322/article/details/9501163
void dynamic(int *values, int types, int total, int coinUsed[], int cointTrack[]) 
{
	coinUsed[0] = 0;
	cointTrack[0] = 0;
	for (int i = 1; i <= total; i++)
	{
		int mincoin = i;
		int lastin = 0;
		for (int j = 0; j < types; j++) {
			if (values[j] <= i) {
				if (coinUsed[i - values[j]] + 1 < mincoin) {
					mincoin = coinUsed[i - values[j]] + 1;
					lastin = values[j];
				}
			}
		}
		coinUsed[i] = mincoin;
		cointTrack[i] = lastin;
	}
	while (total>0)
	{
		cout << cointTrack[total] << " ";
		total -= cointTrack[total];
	}
}

void dynamic(int *cashArr, int arrSize, int money)			//针对已经从大到小排好序的数组进行动态规划
{
	int cur = INFINITY_MAX, i = 0, typeSize = 0;
	int *typeArr = new int[arrSize*2];		//用于统计货币的种类、每个种类的个数、每个种类的面值
	for (; i < arrSize*2; i++)
			typeArr[i] = 0; 
	i = 0;
	for (size_t k = 0; k < arrSize; k++)
	{
		if (cashArr[k]<cur)
		{
			typeSize++;
			typeArr[++i]++;
			typeArr[arrSize+i] = cashArr[k];  //用typeArr[arrSize+i]来存储每种货币的面值
			cur = cashArr[k]; 
		}
		else typeArr[i]++;
	}
	//for (size_t k = 1; k <= typeSize; k++)
	//	cout << "第" << k << "种货币有" << typeArr[k] << "个" << ",其面值为" <<typeArr[arrSize+k]<< endl;
	//开始动态规划
	//只能就每种货币个数无限的情况进行动态规划，暂未找到限制货币数量时的改进策略
	int * used = new int[money+1];
	int * track = new int[money+1];
	for (size_t m = 1; m <= money; m++)
	{
		int min = m; 
		int lastin = 0;
		//int *recNum = new int[typeSize];
		for (size_t n = 1; n <= typeSize; n++)
		{
			if (typeArr[arrSize +n] <= m)
			{
				if (used[m-typeArr[arrSize +n]]+1<min)
				{
						min = used[m - typeArr[arrSize + n]] + 1;
						lastin = typeArr[arrSize + n];
				}
			}
		}
		used[m] = min;
		track[m] = lastin;
	}
	while (money>0)
	{
		cout <<"支付一张"<< track[money] << "元货币" << endl;
		money -= track[money];
	}
	if (money == 0) cout << "支付成功！" << endl;
	else cout << "POS机内货币不足，支付失败！" << endl;
}