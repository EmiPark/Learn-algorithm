// 回溯法解01背包问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
template<class elemType>
elemType* vec2arr(vector<elemType> vec);
void backtrack(int i);
double bound(int i);
int n;//物品数量
double c;//背包容量
double *v = new double[1];
double *w = new double[1];
double cw = 0.0;//当前背包重量
double cp = 0.0;//当前背包中物品价值
double bestp = 0.0;//当前最优价值
int put[100];//设置是否装入

int main()
{
	string input;		//获取输入流
	vector<double>  wVec;
	vector<double>  vVec;
	wVec.reserve(1);		//设置capacity为1，之后添加元素动态扩展空间存放元素
	vVec.reserve(1);
	int mark = 0;
	cout << "依次输入每一个物品的重量和价值，以#结束" << endl;
	while (true)
	{
		cin >> input;		//注意直接用>>获取string需要string头文件
		if (input == "#") break;
		else
		{
			if (mark == 0)
			{
				wVec.push_back(atoi(input.c_str()));
				mark = 1;
			}
			else
			{
				vVec.push_back(atoi(input.c_str()));
				mark = 0;
			}
		}
	}
	n = vVec.size();
	cout << "输入背包总容量：" << endl;
	cin >> c;
	w= vec2arr(wVec);
	v = vec2arr(vVec);
	backtrack(1);
	cout <<"背包可放入的最大价值是："<< bestp << endl;
	system("pause");
	return 0;
}

//回溯函数
void backtrack(int i)
{
	if (i>n)
	{
		bestp = cp;
		return;
	}
	if (cw + w[i] <= c)
	{
		cw += w[i];
		cp += v[i];
		put[i] = 1;
		backtrack(i + 1);
		cw -= w[i];
		cp -= v[i];
	}
	if (bound(i + 1)>bestp)//符合条件搜索右子数
		backtrack(i + 1);
}

//计算上界函数
double bound(int i)
{
	double leftw = c - cw;
	double b = cp;
	while (i <= n&&w[i] <= leftw)
	{
		leftw -= w[i];
		b += v[i];
		i++;
	}
	if (i <= n)
		b += v[i] / w[i] * leftw;
	return b;
}

template<class elemType>
elemType* vec2arr(vector<elemType> vec)
{
	elemType* arr = new elemType[vec.size()];
	for (size_t i = 0; i < vec.size(); i++)
		arr[i] = vec[i];
	return arr;
}